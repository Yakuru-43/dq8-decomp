// range: 0x24DE20 0x24E020
#include "common.h"

typedef struct {
    u8 pad00[0xC];
    s32 count;
    u8 data[0x1C];
} Msg_0041B960; /* size 0x2C */

extern s32 D_003E0B80;
extern s32 D_003E0B84;
extern s32 D_003E0B88;
extern s32 D_003E0B94;
extern u8 D_003E0BAC;
extern s32 D_003E0BA0;
extern s32 D_003E0BA4;
extern u8 D_0041B960 __attribute__((section(".data")));
extern s32 D_0041B964 __attribute__((section(".data")));
extern s32 D_0041B968 __attribute__((section(".data")));
extern char D_0041B100[] __attribute__((section(".data")));

s32 WaitSema(s32);
s32 SignalSema(s32);
void DeleteSema(s32);
void ExitDeleteThread(void);
char *func_00130FD0(char *, const char *, u32);

void func_0024DE20(void) {
    s32 count;
    char buf[0x28];
    u8 has;

    while (D_003E0BAC != 0) {
        WaitSema(D_003E0BA0);
        has = (D_0041B960 != 0) && (D_0041B964 == D_0041B968);
        SignalSema(D_003E0BA0);
        if (has) {
            WaitSema(D_003E0BA4);
        }
        count = 0;
        WaitSema(D_003E0BA0);
        if (D_0041B960 == 0 || D_0041B964 != D_0041B968) {
            Msg_0041B960 *m;
            s32 *src;
            s32 *dst;
            s32 n;
            s32 next;

            m = (Msg_0041B960 *)((char *)&D_0041B960 + D_0041B964 * 0x2C);
            count = m->count;
            src = (s32 *)m->data;
            dst = (s32 *)buf;
            n = 5;
            do {
                dst[0] = src[0];
                dst[1] = src[1];
                src += 2;
                dst += 2;
                n--;
            } while (n > 0);
            next = (D_0041B964 + 1) & 0x3F;
            D_0041B964 = next;
            if (next == D_0041B968) {
                D_0041B960 = 1;
            } else {
                has++;
            }
        } else {
            has = 0;
        }
        SignalSema(D_003E0BA0);
        if (has == 0) {
            continue;
        }
        if (count == -1) {
            break;
        }
        if (WaitSema(D_003E0B84) < 0) {
            continue;
        }
        D_003E0B94 = count;
        if (buf != 0) {
            func_00130FD0(D_0041B100, buf, 0x28);
        }
        SignalSema(D_003E0B80);
        WaitSema(D_003E0B88);
        SignalSema(D_003E0B84);
    }
    if (D_003E0BA0 > 0) {
        DeleteSema(D_003E0BA0);
    }
    if (D_003E0BA4 > 0) {
        DeleteSema(D_003E0BA4);
    }
    D_003E0BA0 = -1;
    D_003E0BA4 = -1;
    ExitDeleteThread();
}
