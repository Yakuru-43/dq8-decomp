// range: 0x1BEBC0 0x1BEC10
#include "common.h"

s32 func_001A2160(void);
void func_0010AE70(void *);

s32 func_001BEBC0(void) {
    char buf[64];
    char *obj;

    obj = (char *)func_001A2160();
    func_0010AE70(buf);
    *(s128 *)(obj + 0x80) = *(s128 *)(buf + 0x00);
    *(s128 *)(obj + 0x90) = *(s128 *)(buf + 0x10);
    *(s128 *)(obj + 0xA0) = *(s128 *)(buf + 0x20);
    *(s128 *)(obj + 0xB0) = *(s128 *)(buf + 0x30);
    return 1;
}
