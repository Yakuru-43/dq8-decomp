// range: 0x30B380 0x30B4A0
#include "common.h"

s32 func_0030AFA0(s32);                                  /* extern */
s32 func_0030A890(s32);                                  /* extern */
s32 func_0030B4A0(s32);                                  /* extern */
s32 func_0030B4B0(s32);                                  /* extern */
s32 func_0030A720(s32);                                  /* extern */
u32 func_00342850(s32);                                  /* extern */
void *func_00359CF0(M2C_UNK *, s32);                     /* extern */
void func_003568F0(char *, f32);                         /* extern */
void func_00356910(char *, s32);                         /* extern */
extern s32 D_003E1168;
extern M2C_UNK D_00421AD0 __attribute__((section(".data")));

typedef struct {
    char pad0[0x110];
    s32 unk110;
    s32 unk114;
    char pad1[0x1C];
    s32 unk134;
} S_arg1;

void func_0030B380(char *arg0, S_arg1 *arg1) {
    s32 value;
    s32 v;

    v = arg1->unk114;
    if (v == 0) {
        goto fail0;
    }
    value = func_0030AFA0(v);
    if (value < 2) {
        v = func_0030A890(arg1->unk110);
        if (v == D_003E1168) {
            value = 1;
        } else if (v == 0x85) {
            if (func_00359CF0(&D_00421AD0, func_0030B4B0(arg1->unk110)) != 0) {
                v = func_00342850(func_0030B4A0(arg1->unk110));
                if (v == 0) {
                    goto fail1;
                }
                if ((*(u16 *)(v + 0x24) & 2) != 0) {
                    value = 2;
                }
            }
        }
    }
    func_003568F0(arg0, (f32)value / (f32)func_0030A720(arg1->unk134));
    return;

fail1:
    func_00356910(arg0, 0);
    return;

fail0:
    func_00356910(arg0, 0);
    return;
}
