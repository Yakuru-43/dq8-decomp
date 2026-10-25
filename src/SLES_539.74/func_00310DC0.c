// range: 0x310DC0 0x310E10
#include "common.h"

struct Owner {
    char pad0[0x60];
    s32 field60[3];
};

extern M2C_UNK *func_00168160(void);
extern char *func_0016D5B0(M2C_UNK *, s32);
extern void func_001E73E0(char *);

void func_00310DC0(struct Owner *o) {
    char *entry;

    entry = func_0016D5B0(func_00168160(), o->field60[o->field60[2]]);
    if (entry == 0) {
        return;
    }
    func_001E73E0(entry + 0x1F0);
}
