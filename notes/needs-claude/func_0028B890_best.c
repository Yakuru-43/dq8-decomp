// range: 0x28B890 0x28B930
#include "common.h"

typedef struct {
    char pad0[0x14];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
} Slot;

extern Slot *func_0028B9D0(char *);
extern f32 func_00166780(char *);

s32 func_0028B890(char *arg, s32 a1) {
    Slot *slot;

    slot = func_0028B9D0(arg);
    arg = arg + 0x10;
    if (slot == 0) { return 0; }
    if (a1 >= 3) {
        slot->unk14 = func_00166780(arg);
    }
    arg = arg + 8;
    if (a1 >= 4) {
        slot->unk1C = func_00166780(arg);
    }
    slot->unk18 = 1.0f;
    return 1;
}
