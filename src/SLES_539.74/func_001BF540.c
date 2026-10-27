// range: 0x1BF540 0x1BF590
#include "common.h"

char *func_001814D0(void);
void func_003077A0(char *, s32);

s32 func_001BF540(char *arg0) {
    s32 result;
    s32 flag;

    flag = (*(s32 *)arg0 == 1);
    if (flag) {
        result = (s32)*(f32 *)(arg0 + 4);
    } else {
        result = *(s32 *)(arg0 + 4);
    }
    func_003077A0(func_001814D0(), result);
    return 1;
}
