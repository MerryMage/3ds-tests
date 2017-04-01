.text
.arm
.align 4

#define THREEOP(op)                \
.global test_##op##_f32;           \
.type test_##op##_f32, %function;  \
test_##op##_f32:                   \
    vmrs r3, fpscr;                \
                                   \
    ldr r1, [r0];                  \
    vmsr fpscr, r1;                \
                                   \
    ldmib r0, {r1, r2};            \
                                   \
    vmov.f32 s1, r1;               \
    vmov.f32 s2, r2;               \
    op.f32 s0, s1, s2;             \
    vmov.f32 r1, s0;               \
    str r1, [r0, #12];             \
                                   \
    vmrs r1, fpscr;                \
    str r1, [r0, #16];             \
                                   \
    vmsr fpscr, r3;                \
    bx lr

#include "instrs.inc"
