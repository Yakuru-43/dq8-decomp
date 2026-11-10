// range: 0x105A40 0x105B70
// Fetches the next 16-bit value from this translation unit's Reader: a dirty
// put area (field_10 < field_14) is first pushed back through vtable slot 0x34,
// then the get area is pointed at the internal buffer at 0x24.  With an empty
// get area the stream is refilled through func_00105E30 / func_00105D80 and
// synced again, the value is read at slot 0x24 and the get pointer advanced.
// Returns -1 when any of those steps fails.
#include "common.h"

extern "C" {

struct Reader;

extern s32 func_00105D80(struct Reader *, s32);
extern s32 func_00105E30(struct Reader *, u32, s32);

struct Reader {
    virtual s32 v_0x08(s32);
    virtual s32 v_0x0C(s32);
    virtual s32 v_0x10(s32);
    virtual s32 v_0x14(s32);
    virtual s32 v_0x18(s32);
    virtual s32 v_0x1C(s32);
    virtual s32 v_0x20(s32);
    virtual s32 v_0x24(void);
    virtual s32 v_0x28(s32);
    virtual s32 v_0x2C(s32);
    virtual s32 v_0x30(s32);
    virtual s32 v_0x34(s32);
    /* 0x04 */ u8 *field_04;
    /* 0x08 */ u8 *field_08;
    /* 0x0C */ u8 *field_0C;
    /* 0x10 */ u32 field_10;
    /* 0x14 */ u32 field_14;
    /* 0x18 */ u32 field_18;
    /* 0x1C */ void *field_1C;
    /* 0x20 */ u8 unk_20[4];
    /* 0x24 */ u8 buf_24[0x40];
    /* 0x64 */ u8 field_64;
    /* 0x65 */ u8 field_65;
    /* 0x66 */ u8 field_66;
};

s32 func_00105A40(struct Reader *reader) {
    s32 result;
    bool failed;

    if (reader->field_66 != 0 && reader->field_08 == 0) {
        failed = false;
        if (reader->field_14 > reader->field_10) {
            result = reader->v_0x34(-1);
            if (result == -1) {
                failed = true;
            }
        }
        if (failed) {
            return -1;
        }
        reader->field_14 = 0;
        reader->field_10 = 0;
        reader->field_18 = 0;
        reader->field_04 = reader->buf_24;
        reader->field_08 = reader->buf_24;
        reader->field_0C = reader->buf_24;
    }
    while (reader->field_08 == 0) {
        reader->field_64 = 0;
        if (reader->field_1C == 0) {
            return -1;
        }
        if (reader->field_65 == 0) {
            if (func_00105E30(reader, 4, 0) == -1) {
                return -1;
            }
        } else {
            if (func_00105D80(reader, 0) == -1) {
                return -1;
            }
        }
        result = reader->v_0x34(-1);
        if (result == -1) {
            failed = true;
        }
        if (failed) {
            return -1;
        }
        reader->field_14 = 0;
        reader->field_10 = 0;
        reader->field_18 = 0;
        reader->field_04 = reader->buf_24;
        reader->field_08 = reader->buf_24;
        reader->field_0C = reader->buf_24;
    }
    result = reader->v_0x24();
    if (result == -1) {
        return -1;
    }
    result = *(u16 *)reader->field_08;
    reader->field_08 += 4;
    return result;
}

}
