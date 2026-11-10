// range: 0x14D0E0 0x14D260
#include "common.h"

typedef struct Buf {
    /* 0x00 */ u32 capacity;
    /* 0x04 */ char *data;
} Buf;

typedef struct St {
    /* 0x00 */ u8 pad00[0x10];
    /* 0x10 */ u8 elemSize;
    /* 0x11 */ u8 pad11[0xF];
    /* 0x20 */ u128 scale;
    /* 0x30 */ u8 pad30[0x30];
    /* 0x60 */ Buf *buf;
    /* 0x64 */ u8 pad64[0x8];
    /* 0x6C */ u16 flag6C;
} St;

void func_0014BAF0(char *arg0, char *arg1, char *arg2);
void func_0014BB60(char *arg0, char *arg1, char *arg2);
void func_0014BBF0(char *arg0, char *arg1);

s32 func_0014D0E0(St **arg0, char *arg1, s32 arg2, s32 arg3) {
    St *st;
    Buf *buf;
    u8 ok;
    s32 i;
    char *data;
    u128 scale;
    St *o;
    s32 esize;

    ok = 0;
    st = *arg0;
    if (st != 0 && st->flag6C == 0) {
        ok = 1;
    }
    if (ok == 0) {
        return 0;
    }
    buf = (st != 0) ? st->buf : 0;
    if (arg3 + arg2 >= buf->capacity) {
        arg2 = buf->capacity - arg3;
    }
    if (arg2 <= 0) {
        return 0;
    }
    data = buf->data;
    scale = st->scale;
    o = *arg0;
    esize = (o != 0) ? o->elemSize : 0x20;
    switch (esize) {
    case 0x20:
        for (i = 0; i < arg2; i++) {
            func_0014BBF0(arg1 + (i * 16), data + ((arg3 + i) * 12));
        }
        break;
    case 0x10:
        for (i = 0; i < arg2; i++) {
            func_0014BB60(arg1 + (i * 16), data + ((arg3 + i) * 6), (char *)&scale);
        }
        break;
    case 8:
        for (i = 0; i < arg2; i++) {
            func_0014BAF0(arg1 + (i * 16), data + ((arg3 + i) * 3), (char *)&scale);
        }
        break;
    default:
        return arg2;
    }
    return arg2;
}
