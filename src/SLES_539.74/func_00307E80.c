// range: 0x307E80 0x307F30
#include "common.h"

typedef struct {
    char pad0[0x50];
    s32 bits[0x40]; /* +0x50 */
} EventFlags;

static inline s32 IsValidFlag(s32 index) {
    if (index < 0 || index >= 0x800) {
        return 0;
    }
    return 1;
}

s32 func_00307E80(EventFlags *flags, s32 id) {
    s32 slot;
    s32 mask;
    s32 bit;
    s32 word;
    s32 result;

    slot = id - 500;
    if (slot < 0 || slot >= 100) {
        return 0;
    }
    if (!IsValidFlag(slot + 100)) {
        result = 0;
    } else {
        mask = 1;
        bit = (slot + 100) % 32;
        mask = mask << bit;
        word = flags->bits[(slot + 100) / 32];
        result = (word & mask) != 0;
    }
    return result;
}
