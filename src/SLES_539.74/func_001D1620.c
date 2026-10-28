// range: 0x1D1620 0x1D1700
#include "common.h"

extern s32 D_003E06E8;
extern s32 D_003E06EC;
extern s32 D_003E06F0;
extern s32 D_003E06F4;
extern s32 D_003E06F8;
extern s32 D_003E06FC;

s32 func_0014E030(s32);
s32 func_0014EA80(s32, s32);
s32 func_0014EB30(s32, s32);
s32 func_001A87F0(s32);
s32 func_00100630(s32, s32, s32, s32, s32);
s32 func_001A49E0(s32);

void func_001D1620(s32 arg0) {
    s32 var_v0;

    func_0014E030(arg0);
    D_003E06E8 = func_0014EA80(0x8010, arg0);
    func_0014E030(arg0);
    D_003E06EC = func_0014EA80(0x1410, arg0);
    func_0014E030(arg0);
    D_003E06F0 = func_0014EA80(0xC00, arg0);
    func_0014E030(arg0);
    var_v0 = func_0014EB30(0xB70, arg0);
    if (var_v0 != 0) {
        var_v0 = func_001A87F0(var_v0);
    }
    D_003E06F4 = var_v0;
    func_0014E030(arg0);
    D_003E06F8 = func_0014EA80(0x1400, arg0);
    func_0014E030(arg0);
    D_003E06FC = func_00100630(func_0014EA80(0xBE10, arg0), (s32)func_001A49E0, 0, 0x5F0, 0x20);
}
