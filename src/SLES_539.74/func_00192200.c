// range: 0x192200 0x192230
#include "common.h"

extern char *func_00130FD0(char *dst, const char *src, u32 size);
extern char D_0040FBE8[];

void func_00192200(char *arg0) {
    if (arg0 != NULL) {
        func_00130FD0(arg0, D_0040FBE8, 0xC);
    }
}
