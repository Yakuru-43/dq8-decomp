// range: 0x340E10 0x340E30
#include "common.h"

struct Record {
    u8 pad0[0x12];
    s16 id;
};

extern "C" s32 func_00340E10(Record **slot) {
    Record *record = *slot;

    if ((record != 0) != false) {
        return record->id;
    }
    return -1;
}
