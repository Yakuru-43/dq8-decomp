// range: 0x25B1E0 0x25B270
#include "common.h"

typedef struct Channel {
    u8 pad0[0x128];
} Channel;

extern Channel D_0041CBC0[6];
extern s32 D_0041D2B0[6];

s32 func_0025D050(Channel *, Channel *);

s32 func_0025B1E0(s32 arg0) {
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
        return -1;
    }
    return func_0025D050(ch, ch) & 0xFF;
}
