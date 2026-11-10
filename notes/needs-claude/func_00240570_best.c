// range: 0x240570 0x240610
#include "common.h"

typedef struct Cell Cell;

struct Row {
    Cell *slots[8];
};

struct Cell {
    u8 pad[0x114];
    f32 vals[8];
};

typedef struct {
    u8 pad[0x130];
    struct Row rows[0xC0];
    Cell *cells;
} Board;

s32 func_00240570(Board *arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4) {
    Cell *base;
    Cell *c;
    u32 xoff;
    u32 yoff;
    u32 addr;

    if (arg1 < 0 || 8 <= arg1) {
        return 0;
    }
    if (arg3 < 0) {
        base = arg0->cells;
        if (base == 0) {
            return 0;
        }
        base->vals[arg1] = arg4;
        return 1;
    }
    if (arg2 < 0 || 0xC0 <= arg2 || 8 <= arg3) {
        return 0;
    }
    xoff = arg2 * 0x20;
    yoff = arg3 * 4;
    addr = xoff + (u32)arg0 + 0x130;
    c = *(Cell **)(addr + yoff);
    if (c == 0) {
        return 0;
    }
    c->vals[arg1] = arg4;
    return 1;
}
