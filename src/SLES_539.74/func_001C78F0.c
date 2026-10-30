// range: 0x1C78F0 0x1C7950
#include "common.h"

typedef struct Slot1C78F0 {
    /* 0x00 */ s32 type;
    /* 0x04 */ char *ptr;
} Slot1C78F0;

s32 func_001A83A0(void *);
extern void *D_003E06F4 __attribute__((section(".sdata")));

s32 func_001C78F0(Slot1C78F0 *arg0) {
    u32 r;
    s32 flag;

    r = func_001A83A0(D_003E06F4);
    flag = (u8)!(0 < r);
    if (arg0->type == 3) {
        *(s32 *)(arg0->ptr + 4) = flag;
    }
    return 1;
}
