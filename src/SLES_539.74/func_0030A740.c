// range: 0x30A740 0x30A840
#include "common.h"

s32 func_0030A890(s32);                                /* extern */
s32 func_0030A880(s32);                                /* extern */
s32 func_0030A840();                                    /* extern */
char *func_003568F0(char *, f32);                       /* extern */
extern s32 D_003E1168;
extern f32 D_003DF384;
extern f32 D_003DF3B4;
extern f32 D_003DF3B8;
extern s32 D_004523E0[];

typedef struct {
    char pad0[0x110];
    s32 unk110;
} S_arg1;

void func_0030A740(char *arg0, S_arg1 *arg1) {
    s32 id;
    s32 idx;

    id = func_0030A890(arg1->unk110);
    if (D_003E1168 == id) {
        func_003568F0(arg0, 1.0f);
        return;
    }
    idx = func_0030A880(arg1->unk110) - 1000;
    if (id == func_0030A840(D_004523E0, idx, 0)) {
        func_003568F0(arg0, D_003DF3B4);
        return;
    }
    if (id == func_0030A840(D_004523E0, idx, 1)) {
        func_003568F0(arg0, D_003DF3B8);
        return;
    }
    if (id == func_0030A840(D_004523E0, idx, 2)) {
        func_003568F0(arg0, D_003DF384);
    } else {
        func_003568F0(arg0, 1.0f);
    }
}
