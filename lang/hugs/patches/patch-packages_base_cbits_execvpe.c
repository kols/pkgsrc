$NetBSD: patch-packages_base_cbits_execvpe.c,v 1.1 2014/10/14 14:04:19 joerg Exp $

--- packages/base/cbits/execvpe.c.orig	2014-10-14 12:37:00.000000000 +0000
+++ packages/base/cbits/execvpe.c
@@ -5,7 +5,7 @@
    -------------------------------------------------------------------------- */
 #include "HsBase.h"
 
-#if !(defined(_MSC_VER) || defined(__MINGW32__) || defined(_WIN32)) /* to the end */
+#if !(defined(_MSC_VER) || defined(__MINGW32__) || defined(_WIN32)) && !HAVE_EXECVPE /* to the end */
 
 /* Evidently non-Posix. */
 /* #include "PosixSource.h" */
