// range: 0x476700 0x4767D0
#include "common.h"

typedef struct {                                   /* message window */
    u8 pad0[0xF8];                                 /* 0x00 */
    s32 unkF8;                                     /* 0xF8 */
    s32 unkFC;                                     /* 0xFC */
    u8 pad100[0x1F20 - 0x100];                     /* 0x100 */
} Msg;

extern s32 D_003E0154 __attribute__((section(".sdata")));
extern u8 D_003E1928 __attribute__((section(".sdata")));
extern s32 D_003E192C __attribute__((section(".sdata")));
extern s32 D_003E1930 __attribute__((section(".sdata")));
extern s32 D_003E1934 __attribute__((section(".sdata")));
extern s32 D_003E1938 __attribute__((section(".sdata")));
extern s32 D_003E193C __attribute__((section(".sdata")));

s32 func_0045ED00(s32);                            /* extern */
void func_2E19B0(void *, s8);                      /* extern */
void func_2E4D20(void *, s32);                     /* extern */
s32 func_2E6770(void *, s32);                      /* extern */
void func_2E72C0(void *, s32);                     /* extern */
void func_2EEE50(void *, f32, f32);                /* extern */
void func_2F60F0(void *);                           /* extern */
void func_2F6340(void *, s32);                      /* extern */
void func_2F6650(void *);                           /* extern */
void func_2F6960(void *);                           /* extern */

void func_00476700(s32 arg0) {
    Msg msg;
    s32 handle;
    s32 n;

    D_003E0154 = arg0;
    D_003E1928 = 1;
    if (arg0 >= 0) {
        func_2F6960(&msg);
        func_2F6650(&msg);
        func_2F6340(&msg, 0);
        func_2E4D20(&msg, -1);
        func_2EEE50(&msg, -1.0f, -1.0f);
        func_2E19B0(&msg, 1);
        msg.unkF8 = 0x10;
        msg.unkFC = 0x14;
        handle = func_0045ED00(D_003E0154);
        func_2E72C0(&msg, handle);
        func_2F60F0(&msg);
        n = func_2E6770(&msg, 0);
        D_003E1930 = 37;
        D_003E192C = 0;
        D_003E1934 = 0x181;
        D_003E1938 = n + 0xA7;
        D_003E193C = 0x181;
    }
}
