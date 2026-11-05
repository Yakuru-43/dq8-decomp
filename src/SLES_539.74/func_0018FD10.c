// range: 0x18FD10 0x18FE50
#include "common.h"

extern char *func_0018CCF0(char *, s32);
extern void func_0018DD40(void *);
extern void func_0018DD70(void *);
extern s32 func_0018FE50(char *);
extern s32 func_0018FE60(void *);
extern char *func_0018FE70(void *);
extern void *func_001EBDC0(char *, s32);
extern s32 func_00133F78(char *, char *);
extern char D_003C3430[];
extern char D_003C3440[];
extern char D_003C3450[];

void func_0018FD10(char *arg0, char *arg1) {
    char *node;
    char *list;
    s32 i;
    void *item;
    char *name;

    if (arg0 == 0) {
        return;
    }
    if (arg1 == 0) {
        return;
    }
    node = func_0018CCF0(arg0, -1);
    if (node == 0) {
        return;
    }
    func_0018DD40(node);
    list = arg1 + 0x70;
    for (i = 0; i < func_0018FE50(list); i++) {
        item = func_001EBDC0(list, i);
        if (item != 0) {
            name = func_0018FE70(item);
            func_0018FE60(item);
            if (func_00133F78(name, D_003C3430) == 0) {
                func_0018DD70(node);
            } else if (func_00133F78(name, D_003C3440) == 0) {
                node[0x15] = 1;
            } else if (func_00133F78(name, D_003C3450) == 0) {
                node[0x14] = 1;
            }
        }
    }
}
