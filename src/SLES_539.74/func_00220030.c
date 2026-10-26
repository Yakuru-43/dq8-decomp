// range: 0x220030 0x220040
#include "common.h"

extern void func_0021FED0(void *arg0);

void func_00220030(char *arg0, s16 arg1) {
    *(s16 *)(arg0 + 0x44) = arg1;
    *(s16 *)(arg0 + 0x46) = arg1;
    func_0021FED0(arg0);
}
