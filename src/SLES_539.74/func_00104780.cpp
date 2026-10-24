// range: 0x104780 0x104890
// Repositions the reader to a new 64-bit position: flushes the pushback byte
// through vtable slot 0x34, seeks the stream with func_0012F488, resets the
// buffer pointers and reports the position/size back; on failure the result
// holds -1.
#include "common.h"

extern "C" {

extern s32 func_0012F488(void *, u64, s32);

struct Reader {
    virtual s32 v_0x08(s32);
    virtual s32 v_0x0C(s32);
    virtual s32 v_0x10(s32);
    virtual s32 v_0x14(s32);
    virtual s32 v_0x18(s32);
    virtual s32 v_0x1C(s32);
    virtual s32 v_0x20(s32);
    virtual s32 v_0x24(s32);
    virtual s32 v_0x28(s32);
    virtual s32 v_0x2C(s32);
    virtual s32 v_0x30(s32);
    virtual s32 v_0x34(s32);
    /* 0x04 */ u32 field_04;
    /* 0x08 */ u32 field_08;
    /* 0x0C */ u32 field_0C;
    /* 0x10 */ u32 field_10;
    /* 0x14 */ u32 field_14;
    /* 0x18 */ u32 field_18;
    /* 0x1C */ void *field_1C;
    /* 0x20 */ u8 pad_20[0x14];
    /* 0x34 */ u8 field_34;
};

struct Pair {
    /* 0x00 */ u64 field_00;
    /* 0x08 */ u64 field_08;
};

struct Result {
    /* 0x00 */ s64 field_00;
    /* 0x08 */ u32 field_08;
};

void func_00104780(struct Result *result, struct Reader *reader,
                   struct Pair pair, u8 flags) {
    s32 check;
    bool bad;

    if (reader->field_1C == 0 || (u8)(flags & 0x18) == 0) {
        result->field_00 = -1;
        result->field_08 = 0;
        return;
    }
    bad = false;
    if (reader->field_14 > reader->field_10) {
        check = reader->v_0x34(-1);
        if (check == -1) {
            bad = true;
        }
    }
    if (bad) {
        result->field_00 = -1;
        result->field_08 = 0;
        return;
    }
    if (func_0012F488(reader->field_1C, pair.field_00, 0) != 0) {
        result->field_00 = -1;
        result->field_08 = 0;
        return;
    }
    reader->field_04 = 0;
    reader->field_08 = 0;
    reader->field_0C = 0;
    reader->field_14 = 0;
    reader->field_10 = 0;
    reader->field_18 = 0;
    reader->field_34 = 0;
    result->field_00 = pair.field_00;
    result->field_08 = (u32)pair.field_08;
}

}
