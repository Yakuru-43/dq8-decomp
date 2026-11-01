// range: 0x45F5D0 0x45F770
#include "common.h"

extern "C" {

struct DrawTarget {
    u8 pad0[0x548];
    char *handler; /* 0x548 */
    u8 fill_54c[0x3F94]; /* up to the vptr at 0x44E0 */
    virtual s32 f0(void);
    virtual s32 show(void); /* slot 0xC */
    void set_handler(char *h) { handler = h; }
    char *get_handler(void) { return handler; }
};

struct Text {
    u8 pad0[0x2C];
    s32 begin; /* 0x2C */
    u8 pad30[4];
    s32 end; /* 0x34 */
};

struct Screen {
    u8 pad0[0x54C];
    char *handler; /* 0x54C */
};

extern DrawTarget *func_168160(void);
extern Text *func_168170(void);
extern char *func_15F490(void);
extern void func_20D300(void *, s32);
extern void func_15F250(void *, s32, void *, s32, s32);
extern char *func_14E130(void *, s32);
extern void func_14E750(void *, void *, s32);
extern void func_15DC80(f32, f32, f32, f32);
extern void func_15F450(void);
extern void func_145D70(void *, s32, s32, void *);
extern void func_13FC60(void *);
extern void func_140410(void *);
extern void func_16BF30(void *, void *, s32);
extern void func_164470(void *, s32, s32, s32);
extern void func_164050(void *, s32);
extern Screen *D_003E1BF0;
extern char *D_003E1BF8;
extern u8 D_004641A0[];
extern u8 D_00464200[];
extern u8 D_3FAFB0[];

void func_0045F5D0(void) {
    DrawTarget *target;
    Text *text;
    char *buf;
    s32 n;
    char *p;

    target = func_168160();
    target->show();
    func_20D300(target, 0);
    text = func_168170();
    buf = func_15F490();
    func_15F250(text, 0x2710, text, 0x7530, 0x11170);
    func_14E750(buf + 0xD0, func_14E130(text, 0x7530), 0x7530);
    func_15DC80(0.0f, 0.0f, 0.0f, 128.0f);
    func_15F450();
    func_145D70(buf, 0x182, 0xC0, text);
    func_13FC60(buf);
    func_140410(buf);
    func_14E750(D_00464200, func_14E130(text, 0x4B00), 0x4B00);
    D_003E1BF0->handler = (char *)D_00464200;
    n = text->end - text->begin;
    p = func_14E130(text, n);
    func_16BF30(target, p, n);
    func_14E750(D_004641A0, p + (n << 4) - 0x30D400, 0x30D40);
    target->set_handler((char *)D_004641A0);
    D_003E1BF8 = target->get_handler();
    func_164470(&D_3FAFB0, 0xF000, 0xF, 4);
    func_164050(&D_3FAFB0, 0x78);
}

}
