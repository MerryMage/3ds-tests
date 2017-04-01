#include <3ds.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Test {
    uint32_t initial_fpscr;
    uint32_t a;
    uint32_t b;
    uint32_t result;
    uint32_t final_fpscr;
};

#define THREEOP(op) void test_##op##_f32(struct Test*);
#include "instrs.inc"
#undef THREEOP

const u32 numbers[] = {
    0x00000000, // positive zero
    0x00000001, // smallest positive denormal
    0x00000076, //
    0x00002b94, //
    0x00636d24, //
    0x007fffff, // largest positive denormal
    0x00800000, // smallest positive normalised real
    0x00800002, //
    0x01398437, //
    0x0ba98d27, //
    0x0ba98d7a, //
    0x751f853a, //
    0x7f7ffff0, //
    0x7f7fffff, // largest positive normalised real
    0x7f800000, // positive infinity
    0x7f800001, // first positive SNaN
    0x7f984a37, //
    0x7fbfffff, // last positive SNaN
    0x7fc00000, // first positive QNaN
    0x7fd9ba98, //
    0x7fffffff, // last positive QNaN
    0x80000000, // negative zero
    0x80000001, // smallest negative denormal
    0x80000076, //
    0x80002b94, //
    0x80636d24, //
    0x807fffff, // largest negative denormal
    0x80800000, // smallest negative normalised real
    0x80800002, //
    0x81398437, //
    0x8ba98d27, //
    0x8ba98d7a, //
    0xf51f853a, //
    0xff7ffff0, //
    0xff7fffff, // largest negative normalised real
    0xff800000, // negative infinity
    0xff800001, // first negative SNaN
    0xff984a37, //
    0xffbfffff, // last negative SNaN
    0xffc00000, // first negative QNaN
    0xffd9ba98, //
    0xffffffff, // last negative QNaN
    // some random numbers follow
    0x4f3495cb,
    0xe73a5134,
    0x7c994e9e,
    0x6164bd6c,
    0x09503366,
    0xbf5a97c9,
    0xe6ff1a14,
    0x77f31e2f,
    0xaab4d7d8,
    0x0966320b,
    0xb26bddee,
    0xb5c8e5d3,
    0x317285d3,
    0x3c9623b1,
    0x51fd2c7c,
    0x7b906a6c,
};

const u32 fpscrs[] = {
    0x03c00000,
    0x03800000,
    0x03400000,
    0x03000000,
};

const size_t numbers_count = sizeof(numbers) / sizeof(u32);
const size_t fpscrs_count = sizeof(fpscrs) / sizeof(u32);

void test_threeop(const char* filename, const char* opname, void (*fn)(struct Test*)) {
    FILE* f = fopen(filename, "w");
    printf("Testing %s...\n", opname);

    for (size_t k = 0; k < fpscrs_count; ++k)
    for (size_t i = 0; i < numbers_count; ++i)
    for (size_t j = 0; j < numbers_count; ++j) {
        struct Test test = {
            fpscrs[k],
            numbers[i],
            numbers[j]
        };
        (*fn)(&test);
        fprintf(f, "{0x%lx, 0x%lx, 0x%lx, 0x%lx, 0x%lx},\n", test.initial_fpscr, test.a, test.b, test.result, test.final_fpscr);
    }

    fclose(f);
}

int main() {
    // Initialize graphics
    gfxInitDefault();
    consoleInit(GFX_BOTTOM, NULL);

#define THREEOP(op) test_threeop("vfp_" #op "_f32.inc", #op, &test_##op##_f32);
#include "instrs.inc"
#undef THREEOP

    gfxExit();
    return 0;
}
