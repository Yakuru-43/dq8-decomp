// range: 0x100480 0x100500
#include "common.h"

void func_00100480(char *objects, s32 (*destroy)(void *, s32), s32 size,
                  s32 count) {
    char *p;

    p = objects + size * count;
    if (count != 0) {
        do {
            p -= size;
            destroy(p, -1);
            count -= 1;
        } while (count != 0);
    }
}
