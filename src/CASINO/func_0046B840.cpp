// range: 0x46B840 0x46B8A0
#include "common.h"

extern "C" {

extern void *D_3DD8A0[];
extern void *D_3DD8C0[];
extern void *D_3DEE60[];

void func_1E7EB0(void *);

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

char *func_0046B840(char *self) {
    *(void **)(self + 0x1B0) = D_3DD8C0;
    ((HandlerHead *)(self + 0x10))->vtbl = D_3DD8A0;
    ((Handler *)(self + 0x10))->reset();
    *(void **)(self + 0x1B0) = D_3DEE60;
    func_1E7EB0(self + 0x1F0);
    return self;
}

}
