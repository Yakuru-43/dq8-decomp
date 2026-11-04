// range: 0x462B90 0x462CA0
#include "common.h"

extern s32 D_003E1C64;
extern void *D_003E1C68;
extern void *D_003E1C54;
extern u8 D_004644E0[];
extern u8 D_3FAFB0[];

void func_1419A0(s32, s32, f32);
void func_14DF80(void *);
void func_15F230(void);
s32 func_15F490(void);
void func_15FF10(s32);
void func_162BC0(void);
void *func_162CA0(void);
void func_164040(void *);
void func_164060(void *);
void func_164460(void *, s32);
void *func_167A80(void);
void func_175B20(s32);
void func_176480(s32);
void func_19FE80(void);
void func_1A0CC0(void *, s32);
void func_1A0F90(void *);
void func_1A12E0(void *);
void func_20C2D0(void *, s32);
void func_20D0A0(void *);
void func_305F60(void);
void func_372330(void *);

void func_00462B90(void) {
    void *item;
    s32 handle;

    if (D_003E1C64 != 0) {
        handle = func_15F490();
        func_1419A0(handle, 0x126, 1.0f);
        func_1A12E0(D_003E1C68);
        func_19FE80();
        func_15F230();
        func_1A0CC0(D_003E1C68, 0);
        func_1A0F90(D_003E1C68);
        func_1A0CC0(D_003E1C68, 0);
        func_14DF80(&D_004644E0);
        func_15FF10(1);
    }
    D_003E1C64 = 0;
    item = func_162CA0();
    if (item != 0) {
        func_162BC0();
    }
    item = func_167A80();
    if (item != 0) {
        func_372330(item);
    }
    func_305F60();
    func_176480(1);
    func_175B20(-1);
    func_20C2D0(D_003E1C54, 0);
    func_20D0A0(D_003E1C54);
    func_164060(&D_3FAFB0);
    func_164040(&D_3FAFB0);
    func_164460(&D_3FAFB0, 0);
}
