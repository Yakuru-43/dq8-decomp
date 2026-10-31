// range: 0x15AEF0 0x15AFF0
#include "common.h"

extern void func_001340C0(void);
extern void func_00133CB8(char *, char *);
extern s32 func_00133F78(char *, char *);

/* Walks the hash chain in obj for the record whose name matches key (or
 * obj's own name at +0x1E4 when that is set), id < 0 accepting any id. */
u32 func_0015AEF0(char *obj, char *key, s32 id) {
    char buf[0x80];
    char *s;
    char *p;
    s32 c;
    s32 h;
    u32 node;

    s = key;
    if (key == 0) {
        return 0;
    }
    if (obj[0x1E4] != 0) {
        func_001340C0();
        func_00133CB8(buf, obj + 0x1E4);
        s = buf;
    }
    h = 0;
    p = s;
    while ((c = *p) != 0) {
        h = ((h & 0xFF) << 8) + c;
        h %= 101;
        p++;
        h &= 0xFF;
    }
    h &= 0xFF;
    node = *(u32 *)((h << 2) + obj + 0x30);
    while (node != 0) {
        if (func_00133F78(s, (char *)(*(u32 *)node + 8)) == 0) {
            if (id < 0 || *(s16 *)(*(u32 *)node) == id) {
                return *(u32 *)node;
            }
        }
        node = *(u32 *)(node + 4);
    }
    return 0;
}
