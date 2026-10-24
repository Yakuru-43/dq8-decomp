// range: 0x105180 0x1051D0
// Reader constructor: installs the base then the final vtable, clears the
// buffer bookkeeping, adopts the stream handle and marks the stream open.
#include "common.h"

extern char D_003DD7E0[];
extern char D_003DD820[];

struct Reader {
    /* 0x00 */ u32 vptr;
    /* 0x04 */ u32 field_04;
    /* 0x08 */ u32 field_08;
    /* 0x0C */ u32 field_0C;
    /* 0x10 */ u32 field_10;
    /* 0x14 */ u32 field_14;
    /* 0x18 */ u32 field_18;
    /* 0x1C */ u32 field_1C;
    /* 0x20 */ u32 field_20;
    /* 0x24 */ u8 pad_24[0x10];
    /* 0x34 */ u8 field_34;
    /* 0x35 */ u8 field_35;
    /* 0x36 */ u8 field_36;
};

struct Reader *func_00105180(struct Reader *reader, u32 stream) {
    u32 base_vtbl;
    u32 final_vtbl;

    base_vtbl = (u32)&D_003DD7E0;
    final_vtbl = (u32)&D_003DD820;
    reader->vptr = base_vtbl;
    reader->field_04 = 0;
    reader->field_08 = 0;
    reader->field_0C = 0;
    reader->field_10 = 0;
    reader->field_14 = 0;
    reader->field_18 = 0;
    reader->vptr = final_vtbl;
    reader->field_1C = stream;
    reader->field_20 = 0;
    reader->field_34 = 0;
    reader->field_36 = 1;
    reader->field_35 = 1;
    return reader;
}
