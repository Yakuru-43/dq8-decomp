// range: 0x104DF0 0x104EB0
// Reader pushback (filebuf-style pbackfail): unbuffered streams hand the byte
// to func_00135DF8, buffered ones step the get pointer back and store it
// unless it is EOF. Returns the byte, 0 for EOF, -1 on failure.
#include "common.h"

extern "C" {

extern s32 func_00135DF8(s32, u32);

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
    /* 0x1C */ u32 field_1C;
    /* 0x20 */ u8 unk_20[0x14];
    /* 0x34 */ u8 field_34;
    /* 0x35 */ u8 field_35;
    /* 0x36 */ u8 field_36;
};

static inline bool is_eof(s32 c) {
    return c == -1;
}

s32 func_00104DF0(struct Reader *reader, s32 byte) {
    if (reader->field_1C == 0) {
        return -1;
    }
    if (reader->field_36 == 0 && reader->field_35 != 0) {
        if (byte == -1) {
            return -1;
        }
        if (func_00135DF8(byte, reader->field_1C) == -1) {
            return -1;
        }
    } else {
        if (reader->gptr() <= reader->eback()) {
            return -1;
        }
        bool store = !is_eof(byte);
        reader->gbump(-1);
        if (store) {
            *reader->gptr() = byte;
        }
    }
    if (byte == -1) {
        byte = 0;
    }
    return byte;
}

}
