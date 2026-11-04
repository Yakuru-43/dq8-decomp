// range: 0x18FE80 0x190050
#include "common.h"

extern s32 func_0018E680(s32);
extern void func_001F2F80(void *);
extern char *func_001F2F90(void *);
extern void func_001F2FB0(void *, s32);
extern char **func_001F7AB0(char *, s32 *);

void func_0018FE80(char *arg0, s32 arg1) {
    char *obj;
    s32 flag;
    char *grp;
    s32 count;
    char **arr;
    s32 i;
    char *el;
    char *sub;
    char *node;

    obj = arg0;
    if (obj == 0) {
        return;
    }
    flag = 0;
    if (func_0018E680(arg1) != 0) {
        flag = 1;
    }
    grp = obj + 0x1624;
    func_001F2FB0(grp, 2);
    while (1) {
        node = func_001F2F90(grp);
        if (node == 0) {
            break;
        }
        *(u32 *)(node + 0x74) = ((*(u32 *)(node + 0x74) > 0) ^ 1) & 0xFF;
        if (flag != 0) {
            *(s32 *)(node + 0x7C) = -1;
        }
    }
    func_001F2F80(grp);
    func_001F2FB0(grp, 8);
    while (1) {
        node = func_001F2F90(grp);
        if (node == 0) {
            break;
        }
        if (flag != 0) {
            if (*(s32 *)(node + 0x60) == 2) {
                *(s32 *)(node + 0x60) = -1;
            }
        }
    }
    func_001F2F80(grp);
    arr = func_001F7AB0(obj, &count);
    for (i = 0; i < count; i++) {
        el = arr[i];
        if (el == 0) {
            return;
        }
        sub = el + 0x114;
        func_001F2FB0(sub, 2);
        while (1) {
            node = func_001F2F90(sub);
            if (node == 0) {
                break;
            }
            *(u32 *)(node + 0x74) = ((*(u32 *)(node + 0x74) > 0) ^ 1) & 0xFF;
            if (flag != 0) {
                *(s32 *)(node + 0x7C) = -1;
            }
        }
        func_001F2F80(sub);
        func_001F2FB0(sub, 8);
        while (1) {
            node = func_001F2F90(sub);
            if (node == 0) {
                break;
            }
            if (flag != 0) {
                if (*(s32 *)(node + 0x60) == 2) {
                    *(s32 *)(node + 0x60) = -1;
                }
            }
        }
        func_001F2F80(sub);
    }
}
