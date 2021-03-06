$NetBSD: patch-mozilla_mfbt_Alignment.h,v 1.1 2014/11/02 05:40:31 ryoon Exp $

--- mozilla/mfbt/Alignment.h.orig	2014-10-14 06:36:32.000000000 +0000
+++ mozilla/mfbt/Alignment.h
@@ -9,11 +9,20 @@
 #ifndef mozilla_Alignment_h
 #define mozilla_Alignment_h
 
+#include "mozilla/Attributes.h"
+
 #include <stddef.h>
 #include <stdint.h>
 
 namespace mozilla {
 
+#if defined(MOZ_HAVE_CXX11_ALIGNAS)
+#define MOZ_ALIGNOF(T) alignof(T)
+#elif defined(__GNUC__)
+#define MOZ_ALIGNOF(T) __alignof__(T)
+#elif defined(_MSC_VER)
+#define MOZ_ALIGNOF(T) __alignof(T)
+#else
 /*
  * This class, and the corresponding macro MOZ_ALIGNOF, figures out how many
  * bytes of alignment a given type needs.
@@ -32,6 +41,7 @@ public:
 };
 
 #define MOZ_ALIGNOF(T) mozilla::AlignmentFinder<T>::alignment
+#endif
 
 /*
  * Declare the MOZ_ALIGNED_DECL macro for declaring aligned types.
@@ -43,7 +53,10 @@ public:
  * will declare a two-character array |arr| aligned to 8 bytes.
  */
 
-#if defined(__GNUC__)
+#if defined(MOZ_HAVE_CXX11_ALIGNAS)
+#  define MOZ_ALIGNED_DECL(_type, _align) \
+     alignas(_align) _type
+#elif defined(__GNUC__)
 #  define MOZ_ALIGNED_DECL(_type, _align) \
      _type __attribute__((aligned(_align)))
 #elif defined(_MSC_VER)
