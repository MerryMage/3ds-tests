#include <3ds.h>
#include <stdlib.h>
#include <stdio.h>

u64 test_vadd_f32_result(u32 fpscr, u32 a, u32 b);
u64 test_vadd_f32_fpscr(u32 fpscr, u32 a, u32 b);

int main() {
	// Initialize graphics
	gfxInitDefault();

    FILE* f = fopen("vfp_out.txt", "w");

	consoleInit(GFX_BOTTOM, NULL);
	printf("Testing...\n");

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

    for (size_t k = 0; k < fpscrs_count; ++k)
    for (size_t i = 0; i < numbers_count; ++i)
    for (size_t j = 0; j < numbers_count; ++j) {
        u32 initial_fpscr = fpscrs[k];
        u32 a = numbers[i];
        u32 b = numbers[j];
        u32 c = test_vadd_f32_result(initial_fpscr, a, b);
        u32 final_fpscr = test_vadd_f32_fpscr(initial_fpscr, a, b);
        fprintf(f, "{%lx, %lx, %lx, %lx, %lx},\n", initial_fpscr, a, b, c, final_fpscr);
        printf("{0x%lx, 0x%lx, 0x%lx, 0x%lx, 0x%lx},\n", initial_fpscr, a, b, c, final_fpscr);
    }

    fclose(f);

	gfxExit();
	return 0;
}
