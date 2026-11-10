// range: 0x460160 0x4601F0
#include "common.h"

s32 func_00460D70(void *);                           /* extern */
M2C_UNK func_37E170(s32, s16);                       /* extern */
s32 func_370E00(s32, s32, s32);                      /* extern */
M2C_UNK func_004603F0(void *, s32, f32);             /* extern */
M2C_UNK func_371490(void *);                         /* extern */
s32 func_004603A0(void);                             /* extern */
M2C_UNK func_37DD00(s32, s32);                       /* extern */

extern f32 D_003DF744 __attribute__((section(".sdata")));
extern s16 D_003E1A90 __attribute__((section(".sdata")));

typedef struct {
    char pad0[0x20];
    s32 unk20;
} S_arg0;

s32 func_00460160(S_arg0 *arg0) {
    s32 id;
    s32 kind;

    kind = func_00460D70(arg0);
    id = arg0->unk20;
    if (kind == 4) {
        func_37E170(id, D_003E1A90);
    } else {
        func_370E00(id, 2, 3);
        func_004603F0(arg0, 1, D_003DF744);
        func_371490(arg0);
    }
    func_37DD00(kind, func_004603A0());
    return 1;
}
