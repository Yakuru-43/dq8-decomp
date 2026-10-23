// range: 0x304CE0 0x304D30
// auto: hand, verified byte-exact
#include "common.h"

void func_00305060(void *, s32);                                      /* extern */
void func_00305160(void *, void *, s32);                              /* extern */

void func_00304CE0(void *arg0, void *arg1) {
    func_00305060(arg0, 1);
    func_00305160(arg0, arg1, 1);
}
