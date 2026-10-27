// range: 0x30C640 0x30C910
// auto: m2c draft, verified byte-exact
// rodata: 0x3D0790 0x3D0868
#include "common.h"

char * func_00356910(char *, s32);
typedef struct {
    char pad0[0x15C];
    s32 unk15C;
} S_arg1;

void func_0030C640(char *arg0, S_arg1 *arg1) {
    s32 temp_v0;

    temp_v0 = arg1->unk15C;
    switch (temp_v0) {
    case 0x65:
        func_00356910(arg0, 2);
        return;
    case 0x66:
        func_00356910(arg0, 4);
        return;
    case 0x67:
        func_00356910(arg0, 8);
        return;
    case 0x68:
        func_00356910(arg0, 0x10);
        return;
    case 0x69:
        func_00356910(arg0, 0x20);
        return;
    case 0x6A:
        func_00356910(arg0, 0x40);
        return;
    case 0x6B:
        func_00356910(arg0, 0x80);
        return;
    case 0x6C:
        func_00356910(arg0, 0x100);
        return;
    case 0x6D:
        func_00356910(arg0, 0x200);
        return;
    case 0x6E:
        func_00356910(arg0, 0x400);
        return;
    case 0x6F:
        func_00356910(arg0, 0x800);
        return;
    case 0x70:
        func_00356910(arg0, 0x1000);
        return;
    case 0x71:
        func_00356910(arg0, 0x2000);
        return;
    case 0x72:
        func_00356910(arg0, 0x4000);
        return;
    case 0x73:
        func_00356910(arg0, 0x8000);
        return;
    case 0x74:
        func_00356910(arg0, 0x10000);
        return;
    case 0x75:
        func_00356910(arg0, 0x20000);
        return;
    case 0x76:
        func_00356910(arg0, 0x40000);
        return;
    case 0x77:
        func_00356910(arg0, 0x80000);
        return;
    case 0x78:
        func_00356910(arg0, 0x100000);
        return;
    case 0x79:
        func_00356910(arg0, 0x200000);
        return;
    case 0x7A:
        func_00356910(arg0, 0x400000);
        return;
    case 0x7B:
        func_00356910(arg0, 0x800000);
        return;
    case 0x7C:
        func_00356910(arg0, 0x01000000);
        return;
    case 0x7D:
        func_00356910(arg0, 0x02000000);
        return;
    case 0x7E:
        func_00356910(arg0, 0x04000000);
        return;
    case 0x7F:
        func_00356910(arg0, 0x08000000);
        return;
    case 0x80:
        func_00356910(arg0, 0x10000000);
        return;
    case 0x81:
        func_00356910(arg0, 0x20000000);
        return;
    case 0x82:
        func_00356910(arg0, 0x40000000);
        return;
    case 0x83:
        func_00356910(arg0, 0x80000000);
        return;
    case 0x84:
        func_00356910(arg0, 1);
        return;
    case 0x85:
        func_00356910(arg0, 4);
        return;
    case 0x86:
        func_00356910(arg0, 4);
        return;
    case 0x87:
        func_00356910(arg0, 8);
        return;
    case 0x88:
        func_00356910(arg0, 0x10);
        return;
    case 0x97:
        func_00356910(arg0, 2);
        return;
    case 0x98:
        func_00356910(arg0, 2);
        return;
    case 0x99:
        func_00356910(arg0, 2);
        return;
    case 0x9A:
        func_00356910(arg0, 2);
        return;
    default:
        func_00356910(arg0, 0);
        return;
    }
}
