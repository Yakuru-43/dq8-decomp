// range: 0x292E70 0x292EC0
#include "common.h"

struct Owner {
    char pad[0x58C];
    u32 table;
};

extern "C" {

extern s32 func_00296F00(u32 table);
extern s32 func_00296BB0(struct Owner *owner);

/* bump the selected table when it has fewer than 3 runs left */
s32 func_00292E70(struct Owner *owner) {
    s32 runs = func_00296F00(owner->table);

    if (runs <= 2) {
        func_00296BB0(owner);
        return 1;
    }
    return 0;
}

}
