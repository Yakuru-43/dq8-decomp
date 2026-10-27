// range: 0x104FE0 0x105160
// Reader get-byte (filebuf-style underflow): flushes a pending put area first,
// returns the byte at the cursor if one is buffered, else pulls one from the
// stream and stages it in the get area, keeping the last 4 bytes of a full
// 16-byte buffer as putback. Returns the byte, -1 on failure.
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
    virtual s32 v_0x24(s32);
    virtual s32 v_0x28(s32);
    virtual s32 v_0x2C(s32);
    virtual s32 v_0x30(s32);
    virtual s32 v_0x34(s32);
    u8 *eback() const { return field_04; }
    u8 *gptr() const { return field_08; }
    void setg(u8 *b, u8 *g, u8 *e) { field_04 = b; field_08 = g; field_0C = e; }
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

s32 func_00104FE0(struct Reader *reader) {
    bool bad;
    s32 result;
    s8 ch;
    u32 n;

    if (reader->field_1C == 0) {
        return -1;
    }
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
    reader->field_34 = 0;
    if (reader->field_08 < reader->field_0C) {
        return *reader->field_08;
    }
    if (reader->field_35 != 0) {
        result = func_00106080(reader, reader->field_08 == 0);
    } else {
        result = func_00106130(reader, 1, reader->field_08 == 0);
    }
    if (result == -1) {
        return -1;
    }
    ch = result;
    if (reader->field_08 != 0) {
        n = reader->field_0C - reader->eback();
        if (n == 0x10) {
            *(u32 *)&reader->buf_24[0] = reader->field_30;
            n = 4;
        }
        n++;
        reader->setg(reader->buf_24, reader->buf_24 + n - 1, reader->buf_24 + n);
        *reader->gptr() = ch;
    }
    return result;
}

}
