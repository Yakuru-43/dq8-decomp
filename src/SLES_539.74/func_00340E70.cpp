// range: 0x340E70 0x340E90
#include "common.h"

struct Record {
    u8 pad0[0xC];
    s16 id;
};

extern "C" s32 func_00340E70(Record **slot) {
    Record *record = *slot;

    if ((record != 0) != false) {
        return record->id;
    }
    return -1;
}
