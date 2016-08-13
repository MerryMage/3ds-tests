.text
.arm
.align 4

.global test1
.type test1, %function
test1:
    stmfd r13!, {pc}
    ldmfd r13!, {r0}
    bx lr
