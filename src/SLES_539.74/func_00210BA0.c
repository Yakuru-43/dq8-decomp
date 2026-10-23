// range: 0x210BA0 0x210C90
#include "common.h"

extern int func_00131188();                           /* extern */
void func_001340C0(void *, void *);                     /* extern */
void func_00130FD0(void *, void *, s32);               /* extern */

extern M2C_UNK D_003C7A68 __attribute__((section(".data")));

void func_00210BA0(char *obj, char *src, char *extra) {
    if (obj == 0) {
        return;
    }
    if (src == 0) {
        return;
    }
    if (extra == 0) {
        return;
    }
    func_00131188(obj, 0, 0x3C4);
    func_001340C0(obj, &D_003C7A68);
    func_001340C0(obj + 0xC0, *(void **)src);
    *(u16 *)(obj + 6) = *(u16 *)(src + 4);
    *(s32 *)(obj + 0xC) = *(s32 *)(src + 8);
    func_00130FD0(obj + 0x10, src + 0x10, 0x40);
    func_00130FD0(obj + 0x50, src + 0x50, 0x30);
    func_00130FD0(obj + 0x80, src + 0x80, 0x30);
    func_00130FD0(obj + 0xB0, src + 0xB0, 0x10);
    func_001340C0(obj + 0x104, extra);
    func_001340C0(obj + 0x144, extra + 0x20);
    func_001340C0(obj + 0x184, extra + 0x40);
}
