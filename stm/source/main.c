#include <3ds.h>
#include <stdlib.h>

u32 test1();

int main() {

    // Initialize graphics
    gfxInitDefault();

    consoleInit(GFX_BOTTOM, NULL);
    printf("Testing...\n");

    printf("test1: %lx\n", test1());

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
