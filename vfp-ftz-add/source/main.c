#include <3ds.h>
#include <stdlib.h>

u32 test1();
u32 test2();
u32 test3();
u32 test4();
u32 test5();
u32 test6();

/*
Output:
test1: 0
test2: 1000008
test3: 0
test4: 80000000
test5: 0
test6: 1000080
*/

int main()
{
	// Initialize graphics
	gfxInitDefault();

	consoleInit(GFX_BOTTOM, NULL);
	printf("Testing...\n");

	printf("test1: %lx\n", test1());
	printf("test2: %lx\n", test2());
	printf("test3: %lx\n", test3());
	printf("test4: %lx\n", test4());
	printf("test5: %lx\n", test5());
	printf("test6: %lx\n", test6());

	// Main loop
	while (aptMainLoop())
	{
		hidScanInput();

		// Respond to user input
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START)
			break; // break in order to return to hbmenu
	}

	gfxExit();
	return 0;
}
