// range: 0x13F980 0x13FA20
#include "common.h"

extern "C" {

struct Flags70 {
    u8 low4 : 4;
    bool bit4 : 1;
    bool bit5 : 1;
    bool bit6 : 1;
    bool bit7 : 1;
};

struct Stream {
    char pad00[0x10];      /* 0x00: mode + tail */
    char buf[0x60];        /* 0x10: streambuf sub-object */
    Flags70 flags;         /* 0x70 */
    char pad74[0xE4 - 0x74];
    s32 e4;                /* 0xE4 */
};

void func_00157990(void *, s32);
void func_00157930(void *, s32);
void func_00157B30(void *, s32, u32);
void func_00157A40(void *, s32);

/* Rewind the stream: seek its buffer to 0, refresh the put pointer. */
void func_0013F980(Stream *o) {
    u8 b;

    func_00157990(o->buf, 0);
    o->e4 = 1;
    func_00157930(o->buf, o->e4);
    func_00157990(o->buf, 0);
    b = M2C_FIELD(o, u8 *, 0x70);
    o->flags.bit6 = 0;
    func_00157B30(o->buf, 0, b);
    func_00157A40(o->buf, 0);
    o->flags.bit4 = 0;
}

}
