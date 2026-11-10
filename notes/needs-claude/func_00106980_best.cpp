// range: 0x106980 0x106C00
// Builds a numeric field from a formatted string: bails out with a status code
// when the two locale checks reject the value, otherwise sprintf()s it into the
// shared 31-byte buffer, copies the result into the string, folds the digit
// tail into a running s16 value, flips the sign when the field ends in '-' and
// converts the whole buffer in place from ASCII to digit values.
#include "common.h"

extern "C" {

extern s32 func_001294A0(void *);
extern s32 func_001294E8(s32);
extern void func_001339E0(void *, char *, s32, s32);
extern void func_00107040(void *, char *);
extern void func_00107B90(void *, void *, s32, s32);
extern void func_00107C10(void *, void *, s32);
extern char D_003BEFC0[];

struct NumField {
    /* 0x00 */ u32 flags;
    /* 0x04 */ u32 len;
    /* 0x08 */ u32 ptr;
    /* 0x0C */ s16 value;
    /* 0x0E */ u16 status;
};

inline u32 Field_Data(struct NumField *f) {
    if ((f->flags & 1) != 0) {
        return f->ptr;
    }
    return (u32)f + 1;
}

inline u32 Field_Len(struct NumField *f) {
    if ((f->flags & 1) != 0) {
        return f->len;
    }
    return (u32)(*(u8 *)f >> 1);
}

struct NumField *func_00106980(struct NumField *field, s32 value) {
    u32 tail[2];
    u32 head[2];
    char buf[0x20];
    u32 cur;
    u8 *base;

    field->flags = 0;
    field->len = 0;
    field->ptr = 0;
    field->value = 0;
    field->status = 0;
    if (func_001294A0(field) != 0) {
        field->status = 2;
        return field;
    }
    if (func_001294E8(value) != 0) {
        field->status = 1;
        return field;
    }
    func_001339E0(buf, D_003BEFC0, 0x1F, value);
    func_00107040(field, buf);
    cur = Field_Data(field) + 0x23;
    while (cur != Field_Data(field) + Field_Len(field)) {
        field->value = field->value * 10;
        field->value = field->value + (s16)((s8)*(u8 *)cur - 0x30);
        cur = cur + 1;
    }
    base = (u8 *)Field_Data(field);
    if (base[0x22] == '-') {
        field->value = -field->value;
    }
    func_00107B90(tail, field, (s32)(base + 0x22) - 1,
                  (s32)(Field_Data(field) + Field_Len(field)));
    func_00107C10(head, field, (s32)(Field_Data(field) + 1));
    cur = Field_Data(field);
    while (cur != Field_Data(field) + Field_Len(field)) {
        *(u8 *)cur = (u8)((*(char *)cur) - 0x30);
        cur = cur + 1;
    }
    return field;
}

}
