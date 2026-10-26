// range: 0x104A00 0x104DF0
// Writer flush: takes the put area over when the buffer is unclaimed, then
// pushes the buffered bytes into the file buffer (flushing on newline when it
// runs dry) or hands them to func_00106250; finally writes c and returns it.
// BEST DRAFT (factory-1 2026-10-26, try_match CLASS structural score=248,
// 808 vs 1008 B) — kept here, NOT in src/.
#include "common.h"

extern "C" {

extern void *func_00130FD0(void *, void *, s32);
extern s32 func_00106250(struct Writer *, s32, s32);

extern s32 func_00138828(s32);

struct File {
    s32 PutByte(s32 byte) {
        s32 count;
        u8 *old;
        s32 got;

        count = this->count - 1;
        this->count = count;
        if (count < 0) {
            if (this->count < this->limit) {
                return func_00138828(byte);
            }
            *(this->ptr) = byte;
            if (*(this->ptr) == 10) {
                return func_00138828(10);
            }
            old = this->ptr;
            this->ptr = old + 1;
            got = *old;
        } else {
            *(this->ptr) = byte;
            old = this->ptr;
            this->ptr = old + 1;
            got = *old;
        }
        if (got == -1) {
            return -1;
        }
        return byte & 0xFF;
    }
    /* 0x00 */ u8 *ptr;
    /* 0x08 */ s32 count;
    /* 0x0C */ u8 pad_0C[0x0C];
    /* 0x18 */ s32 limit;
};

typedef s32 (*Slot0x10)(s64 *, struct Writer *, s32, s32, s32);

struct Writer {
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
    /* 0x08 */ u32 get_cur;
    /* 0x0C */ u32 get_end;
    /* 0x10 */ s8 *put_base;
    /* 0x14 */ s8 *put_cur;
    /* 0x18 */ s8 *put_end;
    /* 0x1C */ struct File *file;
    /* 0x20 */ u8 pad_20[4];
    /* 0x24 */ s8 buf[0x10];
    /* 0x34 */ u8 b34;
    /* 0x35 */ u8 b35;
    /* 0x36 */ u8 b36;
};

s32 func_00104A00(struct Writer *w, s32 c) {
    s64 out;
    s8 *cursor;
    s32 byte;
    bool keep;

    if (w->file == 0) {
        return -1;
    }
    if (w->b36 != 0 && w->put_cur == 0) {
        if (w->get_cur < w->get_end) {
            Slot0x10 *table = (Slot0x10 *)*(u32 **)w;
            table[4](&out, w, 0, 2, 8);
            if (out == -1) {
                return -1;
            }
        }
        w->put_cur = w->buf;
        w->put_base = w->buf;
        w->put_end = w->buf + 0x10;
    }
    w->b34 = 1;
    if (w->b35 != 0) {
        cursor = w->put_base;
        while (cursor < w->put_cur) {
            byte = *cursor;
            if (w->file->PutByte(byte) == -1) {
                if (w->put_base < cursor) {
                    func_00130FD0(w->put_base, cursor, w->put_cur - cursor);
                    w->put_cur = w->put_cur + (w->put_base - cursor);
                }
                return -1;
            }
            cursor++;
        }
    } else {
        cursor = w->put_base;
        while (cursor < w->put_cur) {
            if (func_00106250(w, 1, *cursor) == -1) {
                if (w->put_base < cursor) {
                    func_00130FD0(w->put_base, cursor, w->put_cur - cursor);
                    w->put_cur = w->put_cur + (w->put_base - cursor);
                }
                return -1;
            }
            cursor++;
        }
    }
    keep = (c != -1);
    w->put_cur = w->put_cur + (w->put_base - w->put_cur);
    if (keep != false) {
        if (w->file->PutByte((s8)c) == -1) {
            return -1;
        }
    }
    if (c == -1) {
        c = 0;
    }
    return c;
}

}
