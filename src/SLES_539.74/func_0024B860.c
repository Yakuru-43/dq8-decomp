// range: 0x24B860 0x24B930
#include "common.h"

extern s32 func_00307780(void);
extern char *func_00130FD0(char *, const char *, u32);

typedef struct {
    char pad0[0x40];
    s32 unk40[7];
    f32 unk5C;
    s32 unk60[3];
    s8 unk6C;
} S_arg0;

void func_0024B860(S_arg0 *arg0, s32 *arg1, f32 arg2) {
    s32 buf[7];
    s32 *dst;
    s32 *src;
    s32 i;
    s32 idx;
    s32 count;
    s32 *counter;

    i = 7;
    src = arg1;
    dst = buf;
    do {
        *dst = *src;
        src++;
        dst++;
        i--;
    } while (i > 0);
    func_00130FD0((char *)&arg0->unk40, (const char *)buf, 0x1C);
    arg0->unk6C = 1;
    arg0->unk5C = arg2;
    idx = func_00307780() - 1;
    if (idx < 0) {
        idx = 0;
    }
    if (idx > 2) {
        idx = 2;
    }
    counter = (s32 *)((u8 *)arg0->unk60 + idx * 4);
    count = *counter + 1;
    if (count < 0) {
        count = 0;
    }
    if (count > 0x186A0) {
        count = 0x186A0;
    }
    *counter = count;
}
