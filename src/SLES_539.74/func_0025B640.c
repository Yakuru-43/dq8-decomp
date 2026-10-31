// range: 0x25B640 0x25B760
#include "common.h"

typedef struct Channel {
    u8 pad0[0x128];
} Channel;

extern Channel D_0041CBC0[6];
extern s32 D_0041D2B0[6];

char *func_0024EE40(void);
void func_0024F100(s32 *, char *, s32 *);
void func_0024F160(s32 *, s32);
s32 func_0024F1F0(s32 *);
s32 func_00251950(s32, s32 *, s32 *);
s32 func_00251A40(s32, s32 *, s32 *);

void func_0025B640(s32 arg0, s32 *arg1) {
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    Channel *ch;
    char *temp_a1;
    s32 temp_s1;
    s32 temp_s1_2;
    s32 temp_v0;

    if (arg0 >= 0 && arg0 < 6) {
        ch = &D_0041CBC0[arg0];
    } else {
        ch = NULL;
    }
    if (ch == NULL || D_0041D2B0[arg0] == 0) {
        ch = NULL;
    }
    if (ch == NULL) {
        arg1[3] = 0;
        arg1[2] = 0;
        arg1[1] = 0;
        arg1[0] = 0;
        return;
    }
    temp_a1 = func_0024EE40();
    sp3C = *(s32 *)((char *)ch + 4);
    func_0024F100(&sp4C, temp_a1, &sp3C);
    temp_s1 = func_0024F1F0(&sp4C) + 4;
    temp_s1_2 = func_00251A40(temp_s1, &sp44, &sp48);
    temp_v0 = func_00251950(temp_s1, &sp40, &sp48);
    arg1[0] = sp48;
    arg1[1] = sp44;
    arg1[2] = temp_s1_2;
    arg1[3] = temp_v0;
    func_0024F160(&sp4C, -1);
}
