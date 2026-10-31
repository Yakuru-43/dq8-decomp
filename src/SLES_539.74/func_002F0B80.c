// range: 0x2F0B80 0x2F0BB0
#include "common.h"

struct Entry {
    /* 0x0000 */ u8 pad_00[0x159];
    /* 0x0159 */ u8 kind;
    /* 0x015A */ u8 pad_15A[0x11E4 - 0x15A];
    /* 0x11E4 */ u16 value;
};

void func_002F0B80(struct Entry *arg0) {
    if (arg0->kind == 2) {
        arg0->value = 0x14B;
    } else {
        arg0->value = 0x19E;
    }
}
