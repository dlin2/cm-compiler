#include <cm/cm.h>

_GENX_MAIN_
void test() {
}

#define STRING2(x) #x
#define STRING(x) STRING2(x)

#ifdef CM_GENX
#pragma message ( "CM_GENX defined with value " STRING(CM_GENX) )
#else
#warning CM_GENX not defined
#endif

#ifdef CM_GEN7_5
#warning CM_GEN7_5 defined
#endif

#ifdef CM_GEN8
#warning CM_GEN8 defined
#endif

#ifdef CM_GEN8_5
#warning CM_GEN8_5 defined
#endif

#ifdef CM_GEN9
#warning CM_GEN9 defined
#endif

#ifdef CM_GEN9_5
#warning CM_GEN9_5 defined
#endif

#ifdef CM_GEN10
#warning CM_GEN10 defined
#endif

#ifdef CM_GEN10_5
#warning CM_GEN10_5 defined
#endif

#ifdef CM_GEN11
#warning CM_GEN11 defined
#endif

// We test a number of different ways to specify a BXT jit target option.
// All are equivalent, and should produce the same results, so we only need
// one set of CHECK values for all of these tests.
// We check the expected Gen variant macros are defined (and no others), and
// that the Finalizer is called with the expected platform option.
// We also check that the expected files are generated by deleting them, 
// which also leaves things tidy for the next test.

// RUN: %cmc -Qxcm_jit_target=bxt %w 2>&1 | FileCheck %w
// RUN: rm %W.isa %W_0.visaasm %W_0.asm %W_0.dat

// RUN: %cmc -Qxcm_jit_target:bxt %w 2>&1 | FileCheck %w
// RUN: rm %W.isa %W_0.visaasm %W_0.asm %W_0.dat

// RUN: %cmc -Qxcm_jit_targetbxt %w 2>&1 | FileCheck %w
// RUN: rm %W.isa %W_0.visaasm %W_0.asm %W_0.dat

// RUN: %cmc -Qxcm_jit_target=gen9lp %w 2>&1 | FileCheck %w
// RUN: rm %W.isa %W_0.visaasm %W_0.asm %W_0.dat

// RUN: %cmc -Qxcm_jit_target=GEN9LP %w 2>&1 | FileCheck %w
// RUN: rm %W.isa %W_0.visaasm %W_0.asm %W_0.dat

// RUN: %cmc /Qxcm_jit_target=BXT %w 2>&1 | FileCheck %w
// RUN: rm %W.isa %W_0.visaasm %W_0.asm %W_0.dat

// RUN: %cmc /Qxcm_jit_target:bxT %w 2>&1 | FileCheck %w
// RUN: rm %W.isa %W_0.visaasm %W_0.asm %W_0.dat

// RUN: %cmc /Qxcm_jit_targetBxt %w 2>&1 | FileCheck %w
// RUN: rm %W.isa %W_0.visaasm %W_0.asm %W_0.dat

// RUN: %cmc /Qxcm_jit_targetbXt %w 2>&1 | FileCheck %w
// RUN: rm %W.isa %W_0.visaasm %W_0.asm %W_0.dat

// RUN: %cmc -Qxcm_jit_target -mcpu=BXT %w 2>&1 | FileCheck %w
// RUN: rm %W.isa %W_0.visaasm %W_0.asm %W_0.dat

// RUN: %cmc -Qxcm_jit_target -mcpu=gEN9lP %w 2>&1 | FileCheck %w
// RUN: rm %W.isa %W_0.visaasm %W_0.asm %W_0.dat

// RUN: %cmc -march=Bxt -Qxcm_jit_target %w 2>&1 | FileCheck %w
// RUN: rm %W.isa %W_0.visaasm %W_0.asm %W_0.dat

// RUN: %cmc -Qxcm_jit_target -march=Gen9LP %w 2>&1 | FileCheck %w
// RUN: rm %W.isa %W_0.visaasm %W_0.asm %W_0.dat

// CHECK: cm_jit_target_bxt.cpp(11,9) :  warning: CM_GENX defined with value 920 [-W#pragma-messages]
// CHECK: cm_jit_target_bxt.cpp(29,2) :  warning: CM_GEN9 defined [-W#warnings]
// CHECK: 2 warnings generated.
// CHECK: -platform BXT
