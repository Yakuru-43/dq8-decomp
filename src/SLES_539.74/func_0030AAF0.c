// range: 0x30AAF0 0x30AB30
#include "common.h"

s32 func_0030AAE0(s32);                                /* extern */
char *func_00356910(char *, s64);                       /* extern */

typedef struct {
    char pad0[0x138];
    s32 unk138;
} S_arg1;

void func_0030AAF0(char *arg0, S_arg1 *arg1) {
    func_00356910(arg0, func_0030AAE0(arg1->unk138));
}
