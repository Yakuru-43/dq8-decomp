// range: 0x104EB0 0x104FE0
// Reader get-byte (filebuf-style uflow): flushes a pending put area first,
// then takes the next byte from the get area through the virtual underflow
// (vtable +0x24), or pulls one straight from the stream when unbuffered.
// Returns the byte, -1 on failure. The gptr test is bare (`if (gptr())`):
// with `!= 0` CW lays the stream-pull arm out of line instead.
#include "common.h"

extern "C" {

extern s32 func_00106080(void *, s32);
extern s32 func_00106130(void *, s32, s32);

struct Reader {
    virtual s32 v_0x08(s32);
    virtual s32 v_0x0C(s32);
    virtual s32 v_0x10(s32);
    virtual s32 v_0x14(s32);
    virtual s32 v_0x18(s32);
    virtual s32 v_0x1C(s32);
    virtual s32 v_0x20(s32);
    virtual s32 v_0x24();
    virtual s32 v_0x28(s32);
    virtual s32 v_0x2C(s32);
    virtual s32 v_0x30(s32);
    virtual s32 v_0x34(s32);
    u8 *gptr() const { return field_08; }
    void gbump(s32 n) { field_08 += n; }
    /* 0x04 */ u8 *field_04;
    /* 0x08 */ u8 *field_08;
    /* 0x0C */ u8 *field_0C;
    /* 0x10 */ u32 field_10;
    /* 0x14 */ u32 field_14;
    /* 0x18 */ u32 field_18;
    /* 0x1C */ void *field_1C;
    /* 0x20 */ u8 unk_20[4];
    /* 0x24 */ u8 buf_24[0xC];
    /* 0x30 */ u32 field_30;
    /* 0x34 */ u8 field_34;
    /* 0x35 */ u8 field_35;
    /* 0x36 */ u8 field_36;
};

s32 func_00104EB0(struct Reader *reader) {
    bool bad;
    s32 result;

    if (reader->field_36 != 0 && reader->field_08 == 0) {
        bad = false;
        if (reader->field_14 > reader->field_10) {
            result = reader->v_0x34(-1);
            if (result == -1) {
                bad = true;
            }
        }
        if (bad) {
            return -1;
        }
        reader->field_14 = 0;
        reader->field_10 = 0;
        reader->field_18 = 0;
        reader->field_04 = reader->buf_24;
        reader->field_08 = reader->buf_24;
        reader->field_0C = reader->buf_24;
    }
    if (reader->gptr()) {
        result = reader->v_0x24();
        if (result != -1) {
            result = *reader->gptr();
            reader->gbump(1);
            return result;
        }
        return -1;
    }
    reader->field_34 = 0;
    if (reader->field_1C == 0) {
        return -1;
    }
    if (reader->field_35 != 0) {
        result = func_00106080(reader, 0);
    } else {
        result = func_00106130(reader, 1, 0);
    }
    if (result == -1) {
        return -1;
    }
    return result;
}

}
