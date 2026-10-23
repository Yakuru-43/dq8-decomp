// range: 0x210810 0x210910
#include "common.h"

extern int func_00131188();                          /* extern */
void func_00210730(void *);                           /* extern */
void func_002107B0(void *);                           /* extern */
void func_00210380(void *);                           /* extern */
void func_00308D80(void *);                           /* extern */

void func_00210810(void *arg0) {
    char *base = (char *)arg0;

    func_00131188(arg0, 0, 0x7800);
    *(s32 *)(base + 0x9C0) = 0;
    *(s32 *)(base + 0x9C4) = 0;
    *(s32 *)(base + 0x10) = -1;
    func_00131188(base + 0xA00, 0, 0x5CE0);
    *(void **)(base + 0x9E8) = base + 0xA00;
    *(s32 *)(base + 0x66E0) = 0;
    *(s32 *)(base + 0x66E4) = 0;
    *(s32 *)(base + 0x66E8) = 0;
    *(s32 *)(base + 0x9E4) = 0;
    func_00210730(arg0);
    func_002107B0(arg0);
    *(s32 *)(base + 0x0) = 0x10;
    *(s32 *)(base + 0x4) = 1;
    *(s32 *)(base + 0x9DC) = 0x3D;
    *(s32 *)(base + 0xC) = 0;
    *(s32 *)(base + 0x66F4) = 0;
    *(s32 *)(base + 0x66EC) = 0;
    *(s32 *)(base + 0x66F0) = 0;
    *(s32 *)(base + 0x66F8) = 0;
    func_00131188(base + 0x6774, 0, 0x3C4);
    func_00131188(base + 0x6B38, 0, 0x20);
    func_00131188(base + 0x6BB8, 0, 0x38);
    func_00131188(base + 0x66FC, 0, 0x78);
    func_00210380(arg0);
    func_00308D80(base + 0x77C0);
    *(u128 *)(base + 0x77F0) = 0;
}
