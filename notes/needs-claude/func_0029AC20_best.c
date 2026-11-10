// range: 0x29AC20 0x29ACD0
#include "common.h"

struct Unit;

struct Group {
    char pad[0x368];
    u8 *items;
};

typedef s32 (Unit::*Handler)(void);

extern "C" {

extern Handler D_003CAB80[];
extern s32 D_003CBEA0 __attribute__((section(".data")));

void func_00292CB0(struct Unit *unit, struct Group *group);
void func_00300CB0(s32 cond, s32 *file, s32 line);

/* dispatch the state handler the group picks for this unit */
u8 func_0029AC20(struct Unit *unit, struct Group *group, u8 key) {
    s32 sel;
    s32 idx;

    func_00292CB0(unit, group);
    sel = key;
    idx = *(group->items + sel + 7);
    if ((idx < 0) || (idx >= 118)) {
        func_00300CB0(0, &D_003CBEA0, 0x130C);
        idx = 0;
    }
    return (unit->*D_003CAB80[idx])();
}

}
