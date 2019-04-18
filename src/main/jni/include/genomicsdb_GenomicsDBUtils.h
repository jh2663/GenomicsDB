/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class org_genomicsdb_GenomicsDBUtilsJni */

#ifndef _Included_org_genomicsdb_GenomicsDBUtilsJni
#define _Included_org_genomicsdb_GenomicsDBUtilsJni
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     org_genomicsdb_GenomicsDBUtilsJni
 * Method:    jniCreateTileDBWorkspace
 * Signature: (Ljava/lang/String;Z)I
 */
JNIEXPORT jint JNICALL Java_org_genomicsdb_GenomicsDBUtilsJni_jniCreateTileDBWorkspace
  (JNIEnv *, jclass, jstring, jboolean);

/*
 * Class:     org_genomicsdb_GenomicsDBUtilsJni
 * Method:    jniIsTileDBArray
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_genomicsdb_GenomicsDBUtilsJni_jniIsTileDBArray
  (JNIEnv *, jclass, jstring, jstring);

/*
 * Class:     org_genomicsdb_GenomicsDBUtilsJni
 * Method:    jniListTileDBArrays
 * Signature: (Ljava/lang/String;)[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_org_genomicsdb_GenomicsDBUtilsJni_jniListTileDBArrays
  (JNIEnv *, jclass, jstring);

/*
 * Class:     org_genomicsdb_GenomicsDBUtilsJni
 * Method:    jniListTileDBFragments
 * Signature: (Ljava/lang/String;)[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_org_genomicsdb_GenomicsDBUtilsJni_jniListTileDBFragments
  (JNIEnv *, jclass, jstring);

/*
 * Class:     org_genomicsdb_GenomicsDBUtilsJni
 * Method:    jniDeleteFile
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_org_genomicsdb_GenomicsDBUtilsJni_jniDeleteFile
  (JNIEnv *, jclass, jstring);

/*
 * Class:     org_genomicsdb_GenomicsDBUtilsJni
 * Method:    jniWriteToFile
 * Signature: (Ljava/lang/String;Ljava/lang/String;J)I
 */
JNIEXPORT jint JNICALL Java_org_genomicsdb_GenomicsDBUtilsJni_jniWriteToFile
  (JNIEnv *, jclass, jstring, jstring, jlong);

/*
 * Class:     org_genomicsdb_GenomicsDBUtilsJni
 * Method:    jniMoveFile
 * Signature: (Ljava/lang/String;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_org_genomicsdb_GenomicsDBUtilsJni_jniMoveFile
  (JNIEnv *, jclass, jstring, jstring);

/*
 * Class:     org_genomicsdb_GenomicsDBUtilsJni
 * Method:    jniReadEntireFile
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_genomicsdb_GenomicsDBUtilsJni_jniReadEntireFile
  (JNIEnv *, jclass, jstring);

#ifdef __cplusplus
}
#endif
#endif
