// range: 0x321080 0x3210C0
#include "common.h"

typedef struct {
    s32 field_00;
    s32 field_04;
} Entry;

typedef struct {
    s32 field_00;
    s32 *base;
    s32 count;
} Container;

s32 func_00321080(Container *arg0, s32 arg1) {
    Entry *temp_a0;

    temp_a0 = (Entry *)((char *)arg0->base + ((arg0->count + arg1 - 1) << 3));
    if (temp_a0->field_00 == 2) {
        return temp_a0->field_04;
    }
    return 0;
}
