// range: 0x182570 0x182620
#include "common.h"

extern "C" {

typedef struct FlaggedObj {
    /* 0x00 */ s32 data[26];    /* 26 words: vptr lands at +0x68 */
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();          /* slot 0x24 */
} FlaggedObj;

typedef struct Entry {
    /* 0x00 */ u8 pad_00[4];
    /* 0x04 */ s32 f_4;
    /* 0x08 */ u8 pad_08[0x7B0 - 0x08];
    /* 0x7B0 */ s32 f_7B0;
    /* 0x7B4 */ FlaggedObj *p_7B4;
} Entry;

extern Entry *D_0040F9D0[16] __attribute__((section(".data")));
s32 func_0016B7E0(char *, s32, s32);
s32 func_002BAB80();

void func_00182570(char *self) {
    s32 i;

    if (func_002BAB80() != 0) {
        return;
    }
    i = 0;
    do {
        Entry *e = D_0040F9D0[i];
        if (e != 0 && e->f_7B0 != 0) {
            if (func_0016B7E0(self, 1, e->f_4) != 0) {
                D_0040F9D0[i]->p_7B4->v7();
            }
        }
    } while (++i < 16);
}

}
