.text
.arm
.align 4

.global test1
.type test1, %function
test1:
    ldr r0, =0x01000000
    vmsr fpscr, r0
    ldr r0, =0x81784441
    vmov.f32 s1, r0
    ldr r0, =0x0142e1d7
    vmov.f32 s18, r0
    vadd.f32 s14, s1, s18
    vmov.f32 r0, s14
    bx lr

.global test2
.type test2, %function
test2:
    ldr r0, =0x01000000
    vmsr fpscr, r0
    ldr r0, =0x81784441
    vmov.f32 s1, r0
    ldr r0, =0x0142e1d7
    vmov.f32 s18, r0
    vadd.f32 s14, s1, s18
    vmrs r0, fpscr
    bx lr

.global test3
.type test3, %function
test3:
    ldr r0, =0x01000000
    vmsr fpscr, r0
    ldr r0, =0x806ac4d4
    vmov.f32 s2, r0
    ldr r0, =0x00000000
    vmov.f32 s3, r0
    vadd.f32 s0, s2, s3
    vmov.f32 r0, s0
    bx lr

.global test4
.type test4, %function
test4:
    ldr r0, =0x01000000
    vmsr fpscr, r0
    ldr r0, =0x80000000
    vmov.f32 s2, r0
    ldr r0, =0x80000000
    vmov.f32 s3, r0
    vadd.f32 s0, s2, s3
    vmov.f32 r0, s0
    bx lr

.global test5
.type test5, %function
test5:
    ldr r0, =0x01000000
    vmsr fpscr, r0
    ldr r0, =0x80000F00
    vmov.f32 s2, r0
    ldr r0, =0x8000F000
    vmov.f32 s3, r0
    vadd.f32 s0, s2, s3
    vmov.f32 r0, s0
    bx lr

.global test6
.type test6, %function
test6:
    ldr r0, =0x01000000
    vmsr fpscr, r0
    ldr r0, =0x80000F00
    vmov.f32 s2, r0
    ldr r0, =0x8000F000
    vmov.f32 s3, r0
    vadd.f32 s0, s2, s3
    vmrs r0, fpscr
    bx lr