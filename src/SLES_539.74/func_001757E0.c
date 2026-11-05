// range: 0x001757E0 0x001758B0
#include "common.h"

extern s32 func_00133F78(char *, char *);
extern char D_003C2A28[];
extern char D_003C2A48[];
extern char D_003C2A50[];
extern char D_003C2A58[];
extern char D_003C2A60[];

s32 func_001757E0(char *name) {
    s32 ret;

    if (func_00133F78(name, D_003C2A28) == 0) {
        ret = 9;
    } else if (func_00133F78(name, D_003C2A48) == 0) {
        ret = 3;
    } else if (func_00133F78(name, D_003C2A50) == 0) {
        ret = 4;
    } else if (func_00133F78(name, D_003C2A58) == 0) {
        ret = 6;
    } else if (func_00133F78(name, D_003C2A60) == 0) {
        ret = 8;
    } else {
        ret = -1;
    }
    if (ret < 0) {
        return -1;
    }
    return (u8)ret << 24;
}
