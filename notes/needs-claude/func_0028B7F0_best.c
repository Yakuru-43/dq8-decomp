// range: 0x28B7F0 0x28B890
#include "common.h"

typedef struct {
    char pad0[0x14];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
} Slot;

extern Slot *func_0028B9D0(char *);
extern f32 func_00166780(char *);

s32 func_0028B7F0(char *arg, s32 a1) {
    char *p;
    Slot *slot;

    slot = func_0028B9D0(arg);
    p = arg + 0x10;
    if (slot == 0) { return 0; }
    if (a1 >= 3) {
        slot->unk14 = func_00166780(p);
    }
    p = p + 8;
    if (a1 >= 4) {
        slot->unk1C = func_00166780(p);
    }
    slot->unk18 = -1.0f;
    return 1;
}
