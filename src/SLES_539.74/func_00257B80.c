// range: 0x257B80 0x257BF0
#include "common.h"

s32 func_001667C0(void);
char *func_0014EA80(s32, s32);
extern char *D_003E0BD0;
extern u16 D_003E0BD4;
extern s32 D_003E0BD8;
extern u16 D_003E0BE4;

s32 func_00257B80(void) {
    char *ptr;
    u16 cnt;
    s32 i;

    D_003E0BE4 = func_001667C0();
    ptr = func_0014EA80((D_003E0BE4 + 1) << 5, D_003E0BD8);
    cnt = D_003E0BE4;
    D_003E0BD0 = ptr;
    D_003E0BD4 = 0;
    i = 0;
    while (i < (cnt + 1)) {
        *(s32 *)(ptr + 4) = 0;
        i++;
        ptr += 0x20;
    }
    return 1;
}
