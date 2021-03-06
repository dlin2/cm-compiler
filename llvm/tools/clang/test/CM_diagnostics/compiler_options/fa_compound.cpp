// We check that the Finalizer is run using FileCheck, and that the expected
// files are generated by deleting them (leaving things tidy)
// All of the /Fa name supplied is used up to the last '.' (if present).
// RUN: %cmc -Qxcm_jit_target=cnl -Fa=fa.compound.out.txt %w 2>&1 | FileCheck %w
// RUN: rm %W.isa fa.compound.out_0.visaasm fa.compound.out_0.asm fa.compound.out_0.dat

#include <cm/cm.h>

_GENX_MAIN_
void test() {
}

#ifdef CM_GENX
#warning CM_GENX defined
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

// CHECK: fa_compound.cpp(14,2) :  warning: CM_GENX defined [-W#warnings]
// CHECK: fa_compound.cpp(38,2) :  warning: CM_GEN10 defined [-W#warnings]
// CHECK: 2 warnings generated.
// CHECK: -platform CNL
