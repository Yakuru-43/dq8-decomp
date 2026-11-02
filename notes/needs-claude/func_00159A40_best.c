// best attempt for func_00159A40 (CLASS structural score=51, 320 vs 324 bytes)
// range: 0x159A40 0x159B90
#include "common.h"

extern s32 func_00130F38(void *a, void *b, s32 n);
extern char *func_00130FD0(char *dest, const char *src, u32 n);
extern char D_003C20A8[];

typedef struct {
    /* 00 */ u8 tag;
    /* 01 */ u8 pad[0x2B];
    /* 2C */ s32 key;
    /* 30 */ u8 rest[0x10];
} Entry;

typedef struct {
    /* 00 */ u8 name[4];
    /* 04 */ u32 dataOff;
    /* 08 */ u32 count;
} List;

/* Insertion pass over the entry array: an entry with a smaller key that is
 * not a spare (tag 0x23) is swapped toward the front; negative keys are
 * clamped to zero on the way. */
void func_00159A40(List *list) {
    Entry *base;
    u32 i;
    u32 j;
    Entry *cur;
    s32 spare;
    Entry tmp;

    if (func_00130F38(list, D_003C20A8, 3) != 0) {
        return;
    }
    base = (Entry *)((char *)list + list->dataOff);
    for (i = 0; i < list->count - 1; i++) {
        cur = &base[i];
        for (j = i + 1; j < list->count; j++) {
            if (cur->key < 0) {
                cur->key = 0;
            }
            if (base[j].key < 0) {
                base[j].key = 0;
            }
            if (cur->key > base[j].key) {
                spare = base[j].tag == 0x23;
                if (spare == 0) {
                    func_00130FD0((char *)&tmp, (char *)cur, 0x40);
                    func_00130FD0((char *)cur, (char *)&base[j], 0x40);
                    func_00130FD0((char *)&base[j], (char *)&tmp, 0x40);
                }
            }
        }
    }
}
