// range: 0x104890 0x104A00
// Seeks the reader: flushes the pushback byte through vtable slot 0x34, maps
// the seek direction (4: end, 2: current, 1: begin) to a whence for
// func_0012F488, resets the buffer pointers and reports the new position; on
// failure the result holds -1.
#include "common.h"

extern "C" {

extern s32 func_0012F488(void *, u64, s32);
extern s64 func_0012F998(void *);

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

struct Result {
    /* 0x00 */ s64 field_00;
    /* 0x08 */ u32 field_08;
};

void func_00104890(struct Result *result, struct Reader *reader, s64 pos,
                   u8 code, u8 flags) {
    s32 check;
    s32 whence;
    bool bad;

    if (reader->field_1C == 0) {
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
    switch (code) {
    case 1:
        whence = 0;
        break;
    case 2:
        whence = 1;
        if ((u8)(flags & 8) != 0) {
            pos -= (s32)(reader->field_0C - reader->field_08);
        }
        break;
    case 4:
        whence = 2;
        break;
    default:
        result->field_00 = -1;
        result->field_08 = 0;
        return;
    }
    if (func_0012F488(reader->field_1C, pos, whence) != 0) {
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
    result->field_00 = func_0012F998(reader->field_1C);
    result->field_08 = 0;
}

}
