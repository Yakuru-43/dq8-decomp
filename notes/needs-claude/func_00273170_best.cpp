// range: 0x273170 0x273230
// BEST ATTEMPT 2026-10-27 factory-2 — one word off (see func_00273170.md)
#include "common.h"

extern "C" {

/* assert file/expr strings */
extern char D_003C9EF0[];
extern char D_003C9F58[];
extern char D_003C9F70[];
extern volatile s32 D_003E0D78; // thread-shared
extern void func_0012D4D8(char *file, s32 line, char *expr);

typedef struct StampPair {
    u16 value;   /* 0x0 */
    u16 stamp;   /* 0x2 */
} StampPair;

typedef struct Slot273170 {
    union {
        u32 count;
        StampPair pair;
    } u;
} Slot273170;

void func_00273170(Slot273170 *slot, s32 value)
{
    s32 next;

    if ((0 < slot->u.count) != false) {
        func_0012D4D8(D_003C9EF0, 54, D_003C9F58);
    }
    if (!((u32)value < 0x10000)) {
        func_0012D4D8(D_003C9EF0, 55, D_003C9F70);
    }
    next = D_003E0D78 + 1;
    D_003E0D78 = next;
    if ((u32)next >= 0x10000) {
        D_003E0D78 = 1;
    }
    slot->u.pair.value = (u16)value;
    slot->u.pair.stamp = (u16)D_003E0D78;
}

}
