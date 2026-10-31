// range: 0x460C60 0x460D60
// Initialises the shop window: installs the handlers at +0x10 and +0x280
// (vptr after 0xE0 bytes of data), resets both, fills the entry tables with
// -1 pairs and zeroes the tail fields. Returns the object.
#include "common.h"

extern "C" {

extern void *D_3DD8A0[];
extern void *D_3DD8C0[];
extern void *D_3DEF40[];
extern void *D_3DEA10[];

void func_1E7EB0(void *);

struct Entry {
    s32 key;
    s32 value;
};

struct Handler {
    s32 data[0x38]; /* must precede the first virtual: vptr at +0xE0 */
    virtual s32 draw();
    virtual s32 update();
    virtual s32 reset();
};

struct HandlerHead {
    s32 data[0x38];
    void **vtbl;
};

char *func_00460C60(char *self) {
    *(void **)(self + 0x1B0) = D_3DD8C0;
    ((HandlerHead *)(self + 0x10))->vtbl = D_3DD8A0;
    ((Handler *)(self + 0x10))->reset();
    *(void **)(self + 0x1B0) = D_3DEF40;
    func_1E7EB0(self + 0x1F0);
    *(void **)(self + 0x1B0) = D_3DEA10;
    Entry *entry = (Entry *)(self + 0x228);
    s32 empty = -1;
    do {
        entry->value = empty;
        entry->key = empty;
        entry++;
    } while (entry < (Entry *)(self + 0x248));
    Entry *cursor = (Entry *)(self + 0x248);
    s32 gone = -1;
    do {
        cursor->value = gone;
        cursor->key = gone;
        cursor++;
    } while (cursor < (Entry *)(self + 0x268));
    *(void **)(self + 0x420) = D_3DD8C0;
    ((HandlerHead *)(self + 0x280))->vtbl = D_3DD8A0;
    ((Handler *)(self + 0x280))->reset();
    *(s32 *)(self + 0x430) = 0;
    *(s32 *)(self + 0x438) = 0;
    *(s32 *)(self + 0x434) = 0;
    *(s32 *)(self + 0x440) = 0;
    *(s32 *)(self + 0x43C) = 0;
    return self;
}

}
