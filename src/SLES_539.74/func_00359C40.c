// range: 0x359C40 0x359C90
#include "common.h"

struct Entry {
    s32 id;
    char pad[0x590 - 4];
};

struct Entry *func_00359C40(struct Entry *list, s32 arg1)
{
    s32 i;
    struct Entry *e;

    for (i = 0; i < 32; i++) {
        e = &list[i];
        if (e->id >= 0 && arg1 == e->id)
            return e;
    }
    return 0;
}
