// best attempt for func_0015AFF0 (NOT matched — kept for the note; do not commit as src)
// range: 0x15AFF0 0x15B190
#include "common.h"

typedef struct FuncNode {
    struct FuncNode *self;
    struct FuncNode *next;
    char name[1];
} FuncNode;

typedef struct FuncMgr {
    u8 pad_0[0x30];
    FuncNode *buckets[101];
    u8 pad_1C4[4];
    FuncNode **entries;
    s32 capacity;
    s32 count;
    u8 pad_1D4[0x10];
    char prefix[1];
} FuncMgr;

s32 func_00133F78(char *, char *);                   /* extern */
void func_001340C0(char *, char *);                   /* extern */
void func_00133CB8(char *, char *);                   /* extern */
void func_00134750(char *, char *, s32);              /* extern */
void DebugPrintf(const char *, ...);                  /* extern */
extern u8 D_003E0294 __attribute__((section(".data")));
extern u8 D_003EDE98 __attribute__((section(".data")));
extern char D_003EDE99 __attribute__((section(".data")));
extern char D_003C2098[] __attribute__((section(".data")));
extern char D_003C2110[] __attribute__((section(".data")));
extern char D_003C2130[] __attribute__((section(".data")));

FuncNode *func_0015AFF0(FuncMgr *mgr, char *name) {
    char *str;
    FuncNode *node;
    FuncNode *cur;
    FuncNode *found;
    char *p;
    char buf[0x80];
    u8 hash;

    node = NULL;
    if (mgr->count < mgr->capacity) {
        node = mgr->entries[mgr->count];
        mgr->count++;
    }
    if (node == NULL) {
        DebugPrintf(D_003C2130, name);
    }
    if (D_003E0294 != 0) {
        DebugPrintf(D_003C2098, mgr->count, mgr->capacity);
    }
    if (name == NULL) {
        return node;
    }
    str = name;
    if (mgr->prefix[0] != 0) {
        func_001340C0(buf, name);
        func_00133CB8(buf, mgr->prefix);
        str = buf;
    }
    hash = 0;
    for (p = str; *p != 0; p++) {
        hash = ((hash << 8) + *p) % 101;
    }
    found = NULL;
    cur = mgr->buckets[hash];
    while (cur != NULL) {
        if (func_00133F78(str, cur->self->name) == 0) {
            found = cur->self;
            break;
        }
        cur = cur->next;
    }
    if (found == NULL) {
        return node;
    }
    D_003EDE98 = 1;
    func_00134750(&D_003EDE99, found->name, 0x20);
    DebugPrintf(D_003C2110, name);
    return node;
}
