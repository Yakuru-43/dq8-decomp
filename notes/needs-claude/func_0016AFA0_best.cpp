// range: 0x0016AFA0 0x0016B100
// best draft, NOT matched — do not build with this in src/
#include "common.h"

extern "C" {

extern char *func_001340C0(char *, char *);
extern char D_003DFBD0[];

struct EntryBase {
    s32 state;         /* 0x00 */
    s32 pad_04;        /* 0x04 */
    char name[0x2C];   /* 0x08 */
    virtual s32 v0();  /* vptr 0x34 */
};

struct Entry : EntryBase {
    void *data;        /* 0x38 */
};

static inline char *get_3864(char *obj, s32 idx) {
    if ((idx >= 0) && (idx < M2C_FIELD(obj, s32 *, 0x3860))) {
        return obj + (idx * 0x3C) + 0x3864;
    }
    return NULL;
}

static inline s32 entry_state(Entry *e) {
    return e->state;
}

s32 func_0016AFA0(char *obj, s32 idx, void *data, char *name) {
    Entry *e;
    s32 i;
    s32 flag;

    if (idx < 0) {
        for (i = 0; i < M2C_FIELD(obj, s32 *, 0x3860); i++) {
            e = (Entry *)get_3864(obj, i);
            if ((e != NULL) && (entry_state(e) == 0)) {
                return -1;
            }
        }
        return -1;
    }
    e = (Entry *)get_3864(obj, idx);
    if (e == NULL) {
        return -1;
    }
    if (name == NULL) {
        name = D_003DFBD0;
    }
    if (M2C_FIELD(obj, s32 *, 0x44B4) < 0) {
        M2C_FIELD(obj, s32 *, 0x44B4) = idx;
    }
    if (data != NULL) {
        e->v0();
        e->state = 0;
        e->data = data;
        if (name != NULL) {
            func_001340C0(e->name, name);
        } else {
            e->name[0] = 0;
        }
        e->state = e->state | 4;
        flag = 0;
    } else {
        flag = -1;
    }
    if (flag == 0) {
        return -1;
    }
    return idx;
}
}
