// range: 0x474C30 0x474CF0
// best attempt: try_match CLASS structural score=32 (27 words differ, 168 vs 188 B)
#include "common.h"

M2C_UNK func_131188();         /* extern */

void func_00474C30(char *arg0, s32 arg1, s32 arg2, char *arg3) {
    char *next;
    char *prev;

    if (arg2 == 1) {
        arg1 += 0x20;
    }
    next = *(char **)(arg3 + 0x90);
    prev = *(char **)(arg3 + 0x94);
    if (next != NULL) {
        *(char **)(next + 0x94) = prev;
    }
    if (prev != NULL) {
        *(char **)(prev + 0x90) = next;
    }
    if (next == NULL) {
        if (prev != NULL) {
            *(s32 *)((arg1 * 4) + (s32)arg0 + 0x1F00) = (s32)prev;
        } else {
            *(s32 *)((arg1 * 4) + (s32)arg0 + 0x1E00) = 0;
            *(s32 *)((arg1 * 4) + (s32)arg0 + 0x1F00) = 0;
        }
    }
    if (next != NULL && prev == NULL) {
        *(s32 *)((arg1 * 4) + (s32)arg0 + 0x1E00) = (s32)next;
    }
    *(s32 *)arg3 = 0;
    *(s32 *)(arg3 + 0x90) = 0;
    *(s32 *)(arg3 + 0x94) = 0;
    func_131188(arg3 + 0x30, 0, 0x20);
}
