// range: 0x1F8A50 0x1F8AB0
#include "common.h"

void func_001E9A30(void *, void *);
void func_0013C490(void *, void *, void *, void *, void *);

s32 func_001F8A50(void *arg0, void *arg1) {
    u8 buf[0x40];
    void *s1 = arg0;
    void *s0 = arg1;

    if (*(s32 *)((char *)arg0 + 0xA8) == 0) {
        return 0;
    }

    func_001E9A30(arg0, buf);
    func_0013C490(s0, (char *)s0 + 0x10, buf, (char *)s1 + 0xB0, (char *)s1 + 0xC0);

    return 1;
}
