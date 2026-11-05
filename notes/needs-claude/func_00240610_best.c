// range: 0x240610 0x2406B0
#include "common.h"

typedef struct Cell Cell;

struct Row {
    Cell *slots[8];
};

struct Cell {
    u8 pad[0x114];
    s32 vals[8];
};

typedef struct {
    u8 pad[0x130];
    struct Row rows[0xC0];
    Cell *cells;
} Board;

s32 func_00240610(Board *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Cell *base;
    Cell *c;
    u32 xoff;
    u32 yoff;

    if (arg1 < 0 || 8 <= arg1) {
        return 0;
    }
    if (arg4 >= 0) {
        if (arg3 < 0 || 0xC0 <= arg3 || 8 <= arg4) {
            return 0;
        }
        xoff = arg3 * 0x20;
        yoff = arg4 * 4;
        xoff = xoff + (u32)arg0 + 0x130;
        c = *(Cell **)(xoff + yoff);
        if (c == 0) {
            return 0;
        }
        c->vals[arg1] = arg2;
        return 1;
    }
    base = arg0->cells;
    if (base == 0) {
        return 0;
    }
    base->vals[arg1] = arg2;
    return 1;
}
