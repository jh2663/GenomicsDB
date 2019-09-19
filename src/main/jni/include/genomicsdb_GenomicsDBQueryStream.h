/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class org_genomicsdb_reader_GenomicsDBQueryStream */

#ifndef _Included_org_genomicsdb_reader_GenomicsDBQueryStream
#define _Included_org_genomicsdb_reader_GenomicsDBQueryStream
#ifdef __cplusplus
extern "C" {
#endif
#undef org_genomicsdb_reader_GenomicsDBQueryStream_MAX_SKIP_BUFFER_SIZE
#define org_genomicsdb_reader_GenomicsDBQueryStream_MAX_SKIP_BUFFER_SIZE 2048L
#undef org_genomicsdb_reader_GenomicsDBQueryStream_DEFAULT_READ_AS_BCF
#define org_genomicsdb_reader_GenomicsDBQueryStream_DEFAULT_READ_AS_BCF 1L
#undef org_genomicsdb_reader_GenomicsDBQueryStream_DEFAULT_USE_MISSING_ONLY_NOT_VECTOR_END
#define org_genomicsdb_reader_GenomicsDBQueryStream_DEFAULT_USE_MISSING_ONLY_NOT_VECTOR_END 1L
#undef org_genomicsdb_reader_GenomicsDBQueryStream_DEFAULT_KEEP_IDX_FIELDS_IN_HEADER
#define org_genomicsdb_reader_GenomicsDBQueryStream_DEFAULT_KEEP_IDX_FIELDS_IN_HEADER 0L
/*
 * Class:     org_genomicsdb_reader_GenomicsDBQueryStream
 * Method:    jniGenomicsDBInit
 * Signature: (Ljava/lang/String;[BLjava/lang/String;IIIJJZZZZ)J
 */
JNIEXPORT jlong JNICALL Java_org_genomicsdb_reader_GenomicsDBQueryStream_jniGenomicsDBInit
  (JNIEnv *, jobject, jstring, jbyteArray, jstring, jint, jint, jint, jlong, jlong, jboolean, jboolean, jboolean, jboolean);

/*
 * Class:     org_genomicsdb_reader_GenomicsDBQueryStream
 * Method:    jniGenomicsDBClose
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_org_genomicsdb_reader_GenomicsDBQueryStream_jniGenomicsDBClose
  (JNIEnv *, jobject, jlong);

/*
 * Class:     org_genomicsdb_reader_GenomicsDBQueryStream
 * Method:    jniGenomicsDBGetNumBytesAvailable
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_org_genomicsdb_reader_GenomicsDBQueryStream_jniGenomicsDBGetNumBytesAvailable
  (JNIEnv *, jobject, jlong);

/*
 * Class:     org_genomicsdb_reader_GenomicsDBQueryStream
 * Method:    jniGenomicsDBReadNextByte
 * Signature: (J)B
 */
JNIEXPORT jbyte JNICALL Java_org_genomicsdb_reader_GenomicsDBQueryStream_jniGenomicsDBReadNextByte
  (JNIEnv *, jobject, jlong);

/*
 * Class:     org_genomicsdb_reader_GenomicsDBQueryStream
 * Method:    jniGenomicsDBRead
 * Signature: (J[BII)I
 */
JNIEXPORT jint JNICALL Java_org_genomicsdb_reader_GenomicsDBQueryStream_jniGenomicsDBRead
  (JNIEnv *, jobject, jlong, jbyteArray, jint, jint);

/*
 * Class:     org_genomicsdb_reader_GenomicsDBQueryStream
 * Method:    jniGenomicsDBSkip
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_org_genomicsdb_reader_GenomicsDBQueryStream_jniGenomicsDBSkip
  (JNIEnv *, jobject, jlong, jlong);

#ifdef __cplusplus
}
#endif
#endif
