// range: 0x105980 0x105A40
// Hands a 16-bit value to this translation unit's Reader: when the reader is
// in its flush state (field_65 set, field_66 clear) the value and the stream
// behind field_1C go to the SDK stream helper func_00135DF8 instead; otherwise
// the value is stored below the get pointer at field_08, which is always moved
// down by four first.  Returns -1 without a stream, on an exhausted buffer or
// on a failed helper call, and 0 for the -1 sentinel.
#include "common.h"

extern "C" {

extern s32 func_00135DF8(s32, void *);

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
    u8 *eback() const { return field_04; }
    u8 *gptr() const { return field_08; }
    void gbump(s32 n) { field_08 += n; }
    /* 0x04 */ u8 *field_04;
    /* 0x08 */ u8 *field_08;
    /* 0x0C */ u32 field_0C;
    /* 0x10 */ u32 field_10;
    /* 0x14 */ u32 field_14;
    /* 0x18 */ u32 field_18;
    /* 0x1C */ void *field_1C;
    /* 0x20 */ u8 unk_20[0x45];
    /* 0x65 */ u8 field_65;
    /* 0x66 */ u8 field_66;
};

static inline bool is_eof(s32 c) {
    return c == -1;
}

s32 func_00105980(struct Reader *reader, s32 value) {
    if (reader->field_1C == 0) {
        return -1;
    }
    if (reader->field_66 != 0 || reader->field_65 == 0) {
        if (reader->gptr() <= reader->eback()) {
            return -1;
        }
        bool store = !is_eof(value);
        reader->gbump(-4);
        if (store) {
            *(u16 *)reader->gptr() = value;
        }
    } else {
        if (value == -1) {
            return -1;
        }
        if (func_00135DF8(value, reader->field_1C) == -1) {
            return -1;
        }
    }
    if (value == -1) {
        value = 0;
    }
    return value;
}

}
