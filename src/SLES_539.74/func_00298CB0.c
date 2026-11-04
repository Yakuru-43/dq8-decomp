// range: 0x298CB0 0x298FE0
#include "common.h"

extern s64 func_00296F60(char *);
extern s32 func_002991E0(char *, char *, s32, s32);

s64 func_00298CB0(char *arg0) {
    char *temp_v0;
    char *temp_a0;
    s64 temp_v0_2;
    char *temp_a1;
    char *temp_s1;
    s64 temp_s0;
    s32 var_a3;

    temp_v0 = *(char **)(arg0 + 0x488);
    if (temp_v0 == NULL) {
        return 0;
    }
    temp_a0 = *(char **)(temp_v0 + 0x1C);
    if (temp_a0 == NULL) {
        return 0;
    }
    temp_v0_2 = func_00296F60(temp_a0);
    var_a3 = 0;
    temp_a1 = *(char **)(*(char **)(arg0 + 0x488) + 0x1C);
    temp_s1 = temp_a1 + 0xE0;
    temp_s0 = *(s64 *)(temp_a1 + 0x158);
    if (temp_v0_2 & 0x80000) {
        return 0;
    }
    if (temp_v0_2 & 0x40) {
        var_a3 = func_002991E0(arg0, temp_a1, 6, var_a3) & 0xFF;
    }
    if (temp_v0_2 & 0x80) {
        var_a3 = func_002991E0(arg0, *(char **)(*(char **)(arg0 + 0x488) + 0x1C), 7, var_a3) & 0xFF;
    }
    if (temp_v0_2 & 0x200) {
        var_a3 = func_002991E0(arg0, *(char **)(*(char **)(arg0 + 0x488) + 0x1C), 9, var_a3) & 0xFF;
    }
    if (temp_v0_2 & 0x400) {
        var_a3 = func_002991E0(arg0, *(char **)(*(char **)(arg0 + 0x488) + 0x1C), 0xA, var_a3) & 0xFF;
    }
    if (temp_v0_2 & 0x800) {
        var_a3 = func_002991E0(arg0, *(char **)(*(char **)(arg0 + 0x488) + 0x1C), 0xB, var_a3) & 0xFF;
    }
    if (temp_v0_2 & 0x20000) {
        var_a3 = func_002991E0(arg0, *(char **)(*(char **)(arg0 + 0x488) + 0x1C), 0x11, var_a3) & 0xFF;
    }
    if (temp_v0_2 & 0x4000) {
        var_a3 = func_002991E0(arg0, *(char **)(*(char **)(arg0 + 0x488) + 0x1C), 0xE, var_a3) & 0xFF;
    }
    if (temp_v0_2 & (8LL << 32)) {
        var_a3 = func_002991E0(arg0, *(char **)(*(char **)(arg0 + 0x488) + 0x1C), 0x23, var_a3) & 0xFF;
    }
    if (temp_v0_2 & 0x8000) {
        var_a3 = func_002991E0(arg0, *(char **)(*(char **)(arg0 + 0x488) + 0x1C), 0xF, var_a3) & 0xFF;
    }
    if (temp_v0_2 & 0x10000) {
        var_a3 = func_002991E0(arg0, *(char **)(*(char **)(arg0 + 0x488) + 0x1C), 0x10, var_a3) & 0xFF;
    }
    if (temp_v0_2 & 0x100000) {
        var_a3 = func_002991E0(arg0, *(char **)(*(char **)(arg0 + 0x488) + 0x1C), 0x14, var_a3) & 0xFF;
    }
    if (temp_v0_2 & 0x10000000) {
        var_a3 = func_002991E0(arg0, *(char **)(*(char **)(arg0 + 0x488) + 0x1C), 0x1C, var_a3) & 0xFF;
    }
    if (temp_v0_2 & (0x10LL << 32)) {
        var_a3 = func_002991E0(arg0, *(char **)(*(char **)(arg0 + 0x488) + 0x1C), 0x24, var_a3) & 0xFF;
    }
    if (temp_v0_2 & 0x800000) {
        var_a3 = func_002991E0(arg0, *(char **)(*(char **)(arg0 + 0x488) + 0x1C), 0x17, var_a3) & 0xFF;
    }
    if (temp_v0_2 & 0x01000000) {
        var_a3 = func_002991E0(arg0, *(char **)(*(char **)(arg0 + 0x488) + 0x1C), 0x18, var_a3) & 0xFF;
    }
    if (temp_v0_2 & 0x04000000) {
        var_a3 = func_002991E0(arg0, *(char **)(*(char **)(arg0 + 0x488) + 0x1C), 0x1A, var_a3) & 0xFF;
    }
    if (temp_v0_2 & 0x08000000) {
        func_002991E0(arg0, *(char **)(*(char **)(arg0 + 0x488) + 0x1C), 0x1B, var_a3);
    }
    return temp_s0 & (temp_s0 ^ *(s64 *)(temp_s1 + 0x78));
}
