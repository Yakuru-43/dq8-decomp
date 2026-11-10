// best C for func_00211AC0 (score 80, structural); do not paste — see note md.
// Attempt 3 additionally defined the matched func_00211370 body above the
// caller with the Vec*/s32/void* prototype: allocation unchanged (s0..s5),
// so an in-TU definition does NOT unlock CW's clobber-mask analysis.
// range: 0x211AC0 0x211BB0
#include "common.h"

typedef union {
    u128 q;
    struct { f32 x, y, z, w; } v;
} Vec;

typedef struct {
    char pad0[0x3C];
    u8 f3C;
    char pad3D[0x23];
    s32 f60;
    s32 f64;
    char pad68[0x38];
} Entry;

extern Entry *D_003E0928;
extern s16 D_003E092C;
extern s32 D_003E0918;
extern char *D_003E0908;

s32 func_00211370(Vec *, s32, void *);

s32 func_00211AC0(Vec *arg0) {
    Entry *table;
    Entry *e;
    Entry *found;
    Vec local;
    s32 id;
    s32 count;
    s32 i;

    table = D_003E0928;
    if (table == 0) {
        return 0;
    }
    local = *arg0;
    count = D_003E092C;
    if (count == 1) {
        found = table;
    } else {
        found = 0;
        id = D_003E0918;
        e = table;
        for (i = 0; i < count; i++, e++) {
            if (e->f60 != 0 && e->f64 == id) {
                found = e;
                break;
            }
        }
        if (found == 0) {
            for (e = table, i = 0; i < count; i++, e++) {
                if (e->f3C != 0) {
                    if (func_00211370(arg0, count, (char *)e + 0x50) != 0) {
                        found = e;
                        break;
                    }
                }
            }
        }
    }
    D_003E0908[0x47A] = 0;
    if (found == 0) {
        found = D_003E0928;
        D_003E0908[0x47A] = 1;
    }
    return (s32)found;
}
