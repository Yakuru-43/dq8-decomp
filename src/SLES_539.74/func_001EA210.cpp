// range: 0x1EA210 0x1EA270
#include "common.h"

extern "C" {
s32 func_0014FF20(char *, s32, char *);
s32 func_0015F490(void);

struct Node {
    s32 data[0x6C];
    virtual s32 v_0x08();
    virtual s32 v_0x0C();
    virtual s32 v_0x10();
    virtual s32 v_0x14();
};

s32 func_001EA210(Node *obj) {
    s32 r = obj->v_0x14();
    if (r != 0) {
        s32 id = func_0015F490();
        return func_0014FF20((char *)obj, id, (char *)obj + 0x120);
    }
    return 0;
}
}
