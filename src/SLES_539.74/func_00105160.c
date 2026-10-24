// range: 0x105160 0x105180
// Bytes still available in the reader buffer: end minus cursor, as a signed
// 64-bit count (negative when the cursor has run past the end).
#include "common.h"

struct Reader {
    /* 0x00 */ void *vptr;
    /* 0x04 */ u32 field_04;
    /* 0x08 */ u32 field_08;
    /* 0x0C */ u32 field_0C;
};

s64 func_00105160(struct Reader *reader) {
    return (s32)(reader->field_0C - reader->field_08);
}
