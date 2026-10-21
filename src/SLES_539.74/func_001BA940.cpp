// range: 0x1BA940 0x1BA970
// Polls the "current object" (func_001A2160 returns it as an integer).
// The original dispatches through a virtual call: CodeWarrior emits its
// vcall idiom `lw t9,0xC0(v0); lw t9,0xC4(t9); jalr t9; move a0,v0` -- the
// only shape that loads the target into $t9 and keeps `this` in the jalr
// delay slot. That pins the object's layout: the vptr sits AFTER the 0xC0
// bytes of data (the data members must be declared before the first
// virtual) and the called method is the 48th virtual of the class
// (first slot is 0x8, so slot 0xC4 = 0x8 + 47 * 4).
#include "common.h"

extern "C" {

extern s32 func_001A2160(void);

struct CurrentObject {
    s32 data[0x30];            /* must precede the first virtual: vptr at +0xC0 */
    virtual s32 v_0x08();
    virtual s32 v_0x0C();
    virtual s32 v_0x10();
    virtual s32 v_0x14();
    virtual s32 v_0x18();
    virtual s32 v_0x1C();
    virtual s32 v_0x20();
    virtual s32 v_0x24();
    virtual s32 v_0x28();
    virtual s32 v_0x2C();
    virtual s32 v_0x30();
    virtual s32 v_0x34();
    virtual s32 v_0x38();
    virtual s32 v_0x3C();
    virtual s32 v_0x40();
    virtual s32 v_0x44();
    virtual s32 v_0x48();
    virtual s32 v_0x4C();
    virtual s32 v_0x50();
    virtual s32 v_0x54();
    virtual s32 v_0x58();
    virtual s32 v_0x5C();
    virtual s32 v_0x60();
    virtual s32 v_0x64();
    virtual s32 v_0x68();
    virtual s32 v_0x6C();
    virtual s32 v_0x70();
    virtual s32 v_0x74();
    virtual s32 v_0x78();
    virtual s32 v_0x7C();
    virtual s32 v_0x80();
    virtual s32 v_0x84();
    virtual s32 v_0x88();
    virtual s32 v_0x8C();
    virtual s32 v_0x90();
    virtual s32 v_0x94();
    virtual s32 v_0x98();
    virtual s32 v_0x9C();
    virtual s32 v_0xA0();
    virtual s32 v_0xA4();
    virtual s32 v_0xA8();
    virtual s32 v_0xAC();
    virtual s32 v_0xB0();
    virtual s32 v_0xB4();
    virtual s32 v_0xB8();
    virtual s32 v_0xBC();
    virtual s32 v_0xC0();
    virtual s32 v_0xC4();
};

s32 func_001BA940(void) {
    CurrentObject *obj = (CurrentObject *)func_001A2160();
    obj->v_0xC4();
    return 1;
}

}
