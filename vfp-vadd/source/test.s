.text
.arm
.align 4

.global test_vadd_f32_result
.type test_vadd_f32_result, %function
test_vadd_f32_result:
    vmrs r3, fpscr
    vmsr fpscr, r0
    vmov.f32 s1, r1
    vmov.f32 s2, r2
    vadd.f32 s0, s1, s2
    vmov.f32 r0, s0
    vmsr fpscr, r3
    bx lr

.global test_vadd_f32_fpscr
.type test_vadd_f32_fpscr, %function
test_vadd_f32_fpscr:
    vmrs r3, fpscr
    vmsr fpscr, r0
    vmov.f32 s1, r1
    vmov.f32 s2, r2
    vadd.f32 s0, s1, s2
    vmrs r0, fpscr
    vmsr fpscr, r3
    bx lr