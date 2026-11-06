// range: 0x19DFF0 0x19E0F0
#include "common.h"

extern char *func_001340C0(char *, char *);
extern s32 func_00133BE0(char *, char *);

struct Dq8FileEntry {
    char *name;
    s32 id;
};

extern struct Dq8FileEntry D_003A1B20[];

s32 func_0019DFF0(char *path) {
    char buf[0x40];
    char *name;
    char *p;
    s8 c;
    struct Dq8FileEntry *found;
    s32 i;
    struct Dq8FileEntry *e;

    if (path == 0 || *path == 0) {
        return 0;
    }
    name = path;
    p = path;
    while ((c = *p) != 0) {
        if (c == '/' || c == '\\') {
            name = p + 1;
        }
        p++;
    }
    func_001340C0(buf, name);
    p = buf;
    while ((c = *p) != 0) {
        if (c == '.') {
            *p = 0;
            break;
        }
        p++;
    }
    found = 0;
    for (i = 0;; i++) {
        e = &D_003A1B20[i];
        if (e->name == 0) {
            break;
        }
        if (func_00133BE0(e->name, buf) == 0) {
            found = e;
            break;
        }
    }
    if (found == 0) {
        return 3;
    }
    return found->id;
}
