// best draft 2026-10-26 factory-1 (uncommitted; CLASS structural score=168)
// range: 0x1031F0 0x1034A0
#include "common.h"

struct Ctrl {                         /* &D_003A0788: control block pointer */
    char pad0[4];
    s32 f4;
    s32 f8;
    s32 fC;
};

struct BootCb {
    s32 next;
    void (*fn)(s32, s32);
    s32 arg;
};

struct SbufVt {
    void (*f00)(void);
    void (*f04)(void);
    void (*f08)(void);
    void (*f0C)(void *, s32, s32);
};

struct Sbuf {                         /* &D_003E2140 etc. */
    struct SbufVt *vt;
    s32 f4;
};

struct Payload {                      /* *Counted.f0 */
    char pad0[0x40];
    void *f40;
};

struct Payload2 {                     /* *SubObject.field_00 */
    char pad0[0x38];
    u16 f38;
};

struct Counted {                      /* &D_003E1EB0 */
    struct Payload *payload;
};

struct SubObject {                    /* &D_003E1F20 etc. */
    struct Payload2 *payload;
};

extern s8 D_003E2128 __attribute__((section(".data")));
extern s8 D_003E21A8 __attribute__((section(".data")));
extern s8 D_003E2228 __attribute__((section(".data")));
extern struct BootCb D_003E2130 __attribute__((section(".data")));
extern struct BootCb D_003E21B0 __attribute__((section(".data")));
extern struct BootCb D_003E2230 __attribute__((section(".data")));
extern struct Sbuf D_003E2140 __attribute__((section(".data")));
extern struct Sbuf D_003E21C0 __attribute__((section(".data")));
extern struct Sbuf D_003E2240 __attribute__((section(".data")));
extern struct Ctrl *D_003A0788 __attribute__((section(".data")));
extern s32 D_003E1D10 __attribute__((section(".data")));
extern struct Counted D_003E1EB0 __attribute__((section(".data")));
extern struct SubObject D_003E1F20 __attribute__((section(".data")));
extern struct SubObject D_003E1F80 __attribute__((section(".data")));
extern struct SubObject D_003E1FE0 __attribute__((section(".data")));

extern void *func_00105D30(void *, s32);
extern s32 func_00100DB0(s32 arg, void (*fn)(s32, s32), struct BootCb *node);
extern void func_00104110(void *, s32, void *);
extern void func_00104610(void *, s32, void *);
extern void func_00102670(s32, s32, s32);
extern void func_001034A0(s32, s32);

s32 func_001031F0(s32 result) {
    if (D_003E2128 == 0) {
        func_00105D30(&D_003E2140, D_003A0788->f4);
        func_00100DB0((s32)&D_003E2140, func_001034A0, &D_003E2130);
        D_003E2128 = 1;
    }
    if (D_003E21A8 == 0) {
        func_00105D30(&D_003E21C0, D_003A0788->f8);
        func_00100DB0((s32)&D_003E21C0, func_001034A0, &D_003E21B0);
        D_003E21A8 = 1;
    }
    if (D_003E2228 == 0) {
        func_00105D30(&D_003E2240, D_003A0788->fC);
        func_00100DB0((s32)&D_003E2240, func_001034A0, &D_003E2230);
        D_003E2228 = 1;
    }
    if (D_003E1D10++ != 0) {
        return result;
    }
    if (&D_003E1EB0 != 0) {
        func_00104110(&D_003E1EB0, 1, &D_003E2140);
    }
    if (&D_003E1F20 != 0) {
        func_00104610(&D_003E1F20, 1, &D_003E21C0);
    } else {
        func_00102670(0, 0, 0);
    }
    if (&D_003E1FE0 != 0) {
        func_00104610(&D_003E1FE0, 1, &D_003E2240);
    } else {
        func_00102670(0, 0, 0);
    }
    if (&D_003E1F80 != 0) {
        func_00104610(&D_003E1F80, 1, &D_003E2240);
    } else {
        func_00102670(0, 0, 0);
    }
    D_003E1EB0.payload->f40 = &D_003E1F20;
    D_003E1FE0.payload->f38 |= 0x2000;
    D_003E2140.vt->f0C(&D_003E2140, 0, 0);
    D_003E21C0.vt->f0C(&D_003E21C0, 0, 0);
    D_003E2240.vt->f0C(&D_003E2240, 0, 0);
    return result;
}
