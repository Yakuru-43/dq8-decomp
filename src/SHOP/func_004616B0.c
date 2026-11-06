// range: 0x4616B0 0x461790
#include "common.h"

M2C_UNK func_0045F560(s32, M2C_UNK *);           /* extern */
s32 func_00462620(s32);                           /* extern */
M2C_UNK func_22AB50(s32);                         /* extern */
M2C_UNK func_24C7C0(s16, s32);                    /* extern */
M2C_UNK func_3766A0(void *, s32, s32);            /* extern */
M2C_UNK func_3768A0(void *);                      /* extern */
M2C_UNK func_3793B0(s32, s32, s32, s32);          /* extern */
M2C_UNK func_3794C0(s32, void *, s32);            /* extern */

extern u8 D_003E19C4;
extern M2C_UNK D_00474050 __attribute__((section(".data")));

typedef struct {
    u128 q[22];
} TextBuf;

typedef struct {
    s16 unk0;
    s16 pad2[2];
    s16 unk6;
} S_D00474058;

extern S_D00474058 *D_00474058 __attribute__((section(".data")));

s32 func_004616B0(s32 arg0, s32 arg1) {
    TextBuf buf;

    func_22AB50(0);
    D_003E19C4 = 1;
    func_0045F560(func_00462620(1), &D_00474050);
    if (func_24C7C0(D_00474058->unk0, 4) == 0) {
        if (D_00474058->unk6 > 1) {
            D_003E19C4 = 0;
        }
    } else {
        func_3768A0(&buf);
        func_3766A0(&buf, *(u16 *)0x415E98 + 0x2C, 0);
        func_3794C0(0, &buf, 0);
        func_3793B0(arg0, arg1, 0, 0x17A3);
        D_003E19C4 = 0x64;
    }
    return 0;
}
