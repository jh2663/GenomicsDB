#! /usr/bin/python3
''' misc functions for processing
        1) query_output2dfmsgpk - convert output of gt_mpi_gather --print-calls to pandas msgpack
'''
import os.path
import platform
import json
import time
import pandas as pd

if platform.system() == 'Linux':
    batch_size = 50000
    out_fn = ['1-qc_full_scan.output']
    out_dir = '/path/to/output'
else:
    batch_size = 420
    out_fn = ['1-qc_pos_10_1000-1000.output', '1-qc_pos_10_43-42.output', '1-qc_pos_1_1000-1000.output']
    out_dir = '/path/to/output'

cols = ['row', 'int_low', 'int_high']
col_flds = {'REF', 'ALT', 'GT', 'DP', 'GQ', 'MIN_DP', 'PL'}
def query_output2dfmsgpk(query_output):
    ''' query_output: generated by gt_mpi_gather -j query_cfg --print-calls
      example: '/path/to/1-qc_full_scan.output'
        convert to 1-qc_full_scan.msgpk @ query_output dir
      save df for every batch_size and print for every 10 batches
    '''
    start_time = time.time()
    with open(query_output) as ifd:
        input_json = json.load(ifd)
    elapsed_time = time.time() - start_time
    # True means save fields 'DP_FORMAT', 'MQ0', 'SB', 'AD', 'MQ','BaseQRankSum', 'MQRankSum', 'ReadPosRankSum',...
    print("INFO: Loaded JSON, #size=%d in %d min and %.1f sec" % (len(input_json), int(elapsed_time/60), elapsed_time%60))

    msgpack_fn = os.path.abspath("%s.msgpk" % query_output[:query_output.rfind('.')])
    bad_calls = []
    total_count = 0
    variants = []
    my_col_flds = col_flds
    start_time = time.time()
    for vcall in input_json['variant_calls']:
        try:
            if "<NON_REF>" in vcall["fields"]['ALT']:
                altval = [x for x in  vcall["fields"]['ALT'] if x != "<NON_REF>"]
            if altval:
                flds1 = {cols[0]: int(vcall['row']), cols[1]: int(vcall['interval'][0]), cols[2]: int(vcall['interval'][1])}
                flds2 = set(vcall['fields'].keys())
                if flds2:
                    extra = flds2 - my_col_flds
                    if extra:   # remove the extra2
                        my_col_flds.update(extra)
                # else:
                #     print("!!!WARN: no fields:", vcall)
                # variants.append({**flds1, **vcall['fields']})
                flds1.update(vcall['fields'])
                variants.append(flds1)
                if len(variants) == batch_size:
                    df = pd.DataFrame(variants, columns=cols + list(my_col_flds))
                    df.to_msgpack(msgpack_fn, append=total_count != 0, compress='zlib')
                    total_count += 1
                    if total_count % 10 == 1:
                        print("INFO: %.1f saved batch %d, #call=%d" % (time.time(), total_count, batch_size * total_count))
                    variants.clear()
                    my_col_flds = col_flds
        except Exception as ex:
            print("WARN %.1f exception=%s, vcall=%s" % (time.time(), ex, vcall))
            ex.printStackTrace()
            bad_calls.append(vcall)
    if len(variants) > 0:
        df = pd.DataFrame(variants, columns=cols + list(my_col_flds))
        df.to_msgpack(msgpack_fn, append=True, compress='zlib')

    num_calls = batch_size * total_count + len(variants)
    print("INFO: #calls=%d #batch=%d, , #last_save=%d in  %.1f sec, #bad_vcall=%d" % (num_calls, total_count, len(variants), time.time()-start_time, len(bad_calls)))
    return msgpack_fn, num_calls


def to_msgpack(qf_dir, qf_list):
    ''' qf_dir - root dir,
        qf_list - list of *.output
        return {output_basefn: (msgpack, num_calls)}
        calls query_output2dfmsgpk for convert a single .output => .msgpk
    '''
    def flsize(fn):
        return os.path.getsize(fn) / 1024.
    converted = {}
    for f in qf_list:
        print()
        query_output_fn = os.path.join(qf_dir, f)
        saved_fn, num_calls = query_output2dfmsgpk(query_output_fn)
        converted[f] = (saved_fn, num_calls)
        print('INFO converted %s %.1fKB, to %s %.1fKB @ %s' % (f, flsize(query_output_fn), os.path.basename(saved_fn), flsize(saved_fn), os.path.dirname(saved_fn)))
    return converted

def from_msgpack(converted_dict, n_iter=None):
    ''' converted_dict: {output_basefn: (msgpack, num_calls)}
        n_iter: number iterator
        return
        build df from .msgpk
    '''
    df_ret = {}
    for qf, (msgfn, n_calls) in converted_dict.items():
        print("INFO: ... reading %s" % os.path.basename(msgfn))
        n_row = 0
        n_read = 0
        df_all = None
        for df in pd.read_msgpack(msgfn, iterator=True):
            n_row += len(df.index)
            n_read += 1
            df_all = df if df_all is None else df_all.append(df, ignore_index=True)
            if n_iter and n_read == n_iter:
                break
            # print("type=%s, #row=%d" % (type(obj), len(obj.index)))
        print("INFO: %s, df=%s, n_iter=%s, n_read=%d, n_row=%d, n_calls=%d" % (qf, df_all.values.shape, 'NA' if n_iter==None else n_iter, n_read, n_row, n_calls))
        df_ret[qf] = df_all
    return df_ret

if __name__ == '__main__':
    msgpk_dict = to_msgpack(out_dir, out_fn)
    #from_msgpack(msgpk_dict)
    print('DONE ')