// range: 0x1EB0B0 0x1EB150
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
} Arg;

typedef struct {
    char pad0[0x190];
    s32 unk190;
    f32 unk194;
    f32 unk198;
} Unk3E0748;

extern f32 D_003DF3D0;
extern Unk3E0748 *D_003E0748;
extern f32 func_0013BCA0(f32);
extern f32 func_00166780(Arg *);
extern s32 func_001667C0(void);

s32 func_001EB0B0(Arg *args, s32 count) {
    args++;
    D_003E0748->unk190 = func_001667C0();
    D_003E0748->unk194 = func_00166780(args++);
    if (count >= 3) {
        D_003E0748->unk198 = func_0013BCA0((D_003DF3D0 * func_00166780(args)) / 180.0f);
    }
    return 1;
}
