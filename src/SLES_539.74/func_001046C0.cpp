// range: 0x1046C0 0x104780
// Rewinds the reader through its vtable slot 0x34 with -1; when that fails
// (or there is nothing left to read) it closes the stream behind it with
// func_0012EBB8.  Returns -1 on success, 0 when the close failed too.
#include "common.h"

extern "C" {

extern s32 func_0012EBB8(void *);

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
    /* 0x04 */ u8 pad_04[0xC];
    /* 0x10 */ u32 field_10;
    /* 0x14 */ u32 field_14;
    /* 0x18 */ u8 pad_18[4];
    /* 0x1C */ void *field_1C;
};

s32 func_001046C0(struct Reader *reader) {
    bool ok = true;
    bool keep;
    bool done;
    s32 result;

    keep = ok;
    if (reader->field_1C != 0) {
        done = false;
        if (reader->field_14 > reader->field_10) {
            result = reader->v_0x34(-1);
            if (result == -1) {
                done = ok;
            }
        }
        if (!done) {
            keep = false;
        }
    }
    if (!keep) {
        if (func_0012EBB8(reader->field_1C) == 0) {
            ok = false;
        }
    }
    return -ok;
}

}
