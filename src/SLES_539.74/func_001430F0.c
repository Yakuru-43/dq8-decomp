// range: 0x1430F0 0x143160
#include "common.h"

struct S0 {
    u8 pad_00[0x14];
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
    u8 pad_28[0x1C];
    f32 f44;
    u8 pad_48[0x68];
    u8 field_B0[0xC0];
    u8 field_170[0x10];
};

struct Arg0 {
    u8 pad_00[0xF20];
    struct S0 *ptr_F20;
};

extern void func_001431E0(f32, f32, f32, f32);
extern void func_00156C40(struct S0 *, char *, char *);
extern void func_001488C0(char *);
extern void func_00148830(char *);

void func_001430F0(char *arg0) {
    struct Arg0 *a = (struct Arg0 *)arg0;
    struct S0 *s0 = a->ptr_F20;
    struct S0 *temp_a0;

    if (s0 != NULL) {
        func_001431E0(s0->f14, s0->f20, s0->f24, s0->f44);
        temp_a0 = a->ptr_F20;
        if (temp_a0 != NULL) {
            func_00156C40(temp_a0, (char *)s0 + 0xB0, (char *)s0 + 0x170);
        }
        func_001488C0(arg0);
        func_00148830(arg0);
    }
}
