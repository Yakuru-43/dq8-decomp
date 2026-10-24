// range: 0x3012F0 0x301350
// flags: -flag divbyzerocheck
// (the original guards the divide with bnez + break 0, 7: #pragma divbyzerocheck)
#include "common.h"

typedef struct {
    s32 values[16];
} Record;

typedef struct {
    char pad0[4];
    Record *records; /* +0x04 */
    char pad8[0x14];
    s32 index; /* +0x1C */
} RecordSet;

s32 func_003012F0(RecordSet *set) {
    Record record;

    record = set->records[set->index];
    return record.values[3] / 100;
}
