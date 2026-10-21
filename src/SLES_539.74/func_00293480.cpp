// range: 0x293480 0x2934D0
#include "common.h"

struct Owner {
    char pad[0x58C];
    u32 table;
};

extern "C" {

extern s32 func_00296F00(u32 table);
extern s32 func_00296BB0(struct Owner *owner);

/* bump the selected table when it has fewer than 4 runs left */
s32 func_00293480(struct Owner *owner) {
    s32 runs = func_00296F00(owner->table);

    if (runs <= 3) {
        func_00296BB0(owner);
        return 1;
    }
    return 0;
}

}
