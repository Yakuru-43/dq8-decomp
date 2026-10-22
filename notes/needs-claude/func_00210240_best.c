// best attempt for func_00210240 (factory-2, 2026-10-22) — NOT matched, kept out of src/
// range: 0x210240 0x21036C
#include "common.h"

s32 func_00202520(s32 arg0);
void func_002033A0(s32 arg0, s32 arg1);
s32 func_002061F0(s32 arg0, s32 arg1);
s16 func_00201BD0(s32 arg0);   // NOT void * — int->void* implicit conv is illegal to CW
s64 func_0020F5E0(s64 *arg0);
s32 func_00210370(s32 arg0);
M2C_UNK func_00130FD0(s32, s32, s32);   // memcpy(dst, src, len), returns dst

void func_00210240(char *arg0, char *arg1, char *arg2) {
    s32 id;
    s64 stamp;

    if (arg1 == 0) {
        return;
    }
    if (arg2 == 0) {
        return;
    }
    func_002033A0(func_00202520((s32)(arg2 + 0x40)), (s32)(arg1 + 0x18));
    *(u16 *)(arg1 + 0xE) = (u16)(func_00201BD0(func_002061F0(func_00202520((s32)(arg2 + 0x40)), 0)) + 1);
    *(s8 *)(arg1 + 1) = *(s8 *)(arg2 + 4);
    *(s32 *)(arg1 + 4) = *(s32 *)arg2;
    if (*(s32 *)(arg1 + 4) != 0x10) {
        *(s8 *)(arg1 + 1) = 2;
    }
    if (*(s8 *)(arg2 + 4) != 0) {
        *(s8 *)(arg1 + 1) = 1;
    }
    id = *(s32 *)(arg2 + 0xC);
    stamp = func_0020F5E0((s64 *)(arg2 + 0x40));
    *(u16 *)(arg1 + 0xC) = (u16)id;
    *(s64 *)(arg1 + 0x38) = stamp;
    *(u32 *)(arg1 + 0x14) = *(u16 *)(arg2 + 0x14);
    *(s64 *)(arg1 + 0x40) = *(s64 *)(arg2 + 0x18);
    if (*(s8 *)(arg1 + 1) != 0) {
        return;
    }
    if (*(s64 *)(arg1 + 0x40) < (s64)*(u128 *)(arg0 + 0x77F0)) {
        return;
    }
    func_00130FD0((s32)(arg0 + 0x77C0), func_00210370((s32)(arg2 + 0x40)), 0x30);
    *(s64 *)(arg0 + 0x77F0) = *(s64 *)(arg1 + 0x40);
    *(s64 *)(arg0 + 0x77F8) = (s64)(arg0 + 0x77C0);
}
