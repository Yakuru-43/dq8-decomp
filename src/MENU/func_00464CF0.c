// range: 0x464CF0 0x464D50
#include "common.h"

struct Entry {
    char pad[0xA];
    s16 fA;
    char pad2[6];
    s16 f12;
};

struct Menu {
    char pad[0x18];
    struct Entry *f18;
    char pad2[4];
    void *f20;
};

extern s32 func_370E00(void *arg0, s32 arg1, s32 arg2);
extern s32 func_37EB60(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

/* reports the entry's two ids and asks the message code to show them */
s32 func_00464CF0(struct Menu *menu) {
    func_370E00(menu->f20, menu->f18->fA, 0);
    func_37EB60(0x273A, 0x18703, menu->f18->f12, 0);
    return 1;
}
