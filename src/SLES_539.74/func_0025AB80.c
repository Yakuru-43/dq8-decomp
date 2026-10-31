// range: 0x25AB80 0x25AC00
#include "common.h"

typedef struct Channel {
    u8 pad0[0x128];
} Channel;

extern Channel D_0041CBC0[6];
extern s32 D_0041D2B0[6];

s32 func_0025AB80(s32 arg0) {
    Channel *ch;

    if (arg0 >= 0 && arg0 < 6) {
        ch = &D_0041CBC0[arg0];
    } else {
        ch = NULL;
    }
    if (ch == NULL || D_0041D2B0[arg0] == 0) {
        ch = NULL;
    }
    if (ch == NULL) {
        return 0;
    }
    return *(s32 *)((char *)ch + 0xEC);
}
