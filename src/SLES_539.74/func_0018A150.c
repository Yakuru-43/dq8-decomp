// range: 0x18A150 0x18A180
#include "common.h"

char *func_00130FD0(char *, const char *, u32);

void func_0018A150(char *arg0, char *arg1) {
    if (arg1 != 0) {
        func_00130FD0(arg1, arg0 + 0x6934, 0x30);
    }
}
