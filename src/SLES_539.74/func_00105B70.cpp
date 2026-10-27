// range: 0x105B70 0x105D00
// Reader get-char, wide twin of func_00104FE0 (filebuf-style underflow over
// 4-byte slots): flushes a pending put area first, returns the 16-bit char at
// the cursor if one is buffered, else pulls one from the stream and stages it
// in the get area, keeping the last slot of a full 16-slot buffer as putback.
// Returns the char, -1 on failure.
#include "common.h"

extern "C" {

extern s32 func_00105D80(void *, s32);
extern s32 func_00105E30(void *, s32, s32);

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
    u32 *eback() const { return field_04; }
    u32 *gptr() const { return field_08; }
    void setg(u32 *b, u32 *g, u32 *e) { field_04 = b; field_08 = g; field_0C = e; }
    /* 0x04 */ u32 *field_04;
    /* 0x08 */ u32 *field_08;
    /* 0x0C */ u32 *field_0C;
    /* 0x10 */ u32 field_10;
    /* 0x14 */ u32 field_14;
    /* 0x18 */ u32 field_18;
    /* 0x1C */ void *field_1C;
    /* 0x20 */ u8 unk_20[4];
    /* 0x24 */ u32 buf_24[16];
    /* 0x64 */ u8 field_64;
    /* 0x65 */ u8 field_65;
    /* 0x66 */ u8 field_66;
};

s32 func_00105B70(struct Reader *reader) {
    bool bad;
    s32 result;
    u16 ch;
    s32 n;

    if (reader->field_1C == 0) {
        return -1;
    }
    if (reader->field_66 != 0 && reader->field_08 == 0) {
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
    reader->field_64 = 0;
    if (reader->field_08 < reader->field_0C) {
        return *(u16 *)reader->field_08;
    }
    if (reader->field_65 != 0) {
        result = func_00105D80(reader, reader->field_08 == 0);
    } else {
        result = func_00105E30(reader, 4, reader->field_08 == 0);
    }
    if (result == -1) {
        return -1;
    }
    ch = result;
    if (reader->field_08 != 0) {
        n = reader->field_0C - reader->eback();
        if (n == 16) {
            reader->buf_24[0] = reader->buf_24[15];
            n = 1;
        }
        n++;
        reader->setg(reader->buf_24, reader->buf_24 + n - 1, reader->buf_24 + n);
        *(u16 *)reader->gptr() = ch;
    }
    return result;
}

}
