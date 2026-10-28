// best attempt (no range line on purpose: gen_configs must ignore this): CLASS
// structural score=84 (80 words differ, 332 vs 348 bytes), -O3 plain C
#include "common.h"

extern char D_003C9EF0[];
extern char D_003C9F50[];

extern void func_0012D4D8(char *file, s32 line, char *expr);
extern u32 func_001341D8(char *s);
extern void func_001080E0(void *buf, u32 len);
extern void func_00107100(void *buf, u32 pos, u32 count, char *s);
extern s32 func_002739E0(void *out18, void *list24, void *buf, u32 word);
extern void func_001007A0(u32);
extern void *func_00274230(void *list);
extern void func_00107040(void *node4, char *s);

typedef struct Rec {
    u32 field_00[3];
    u32 field_0C;
    u32 field_10;
    u32 field_14;
    u8 *field_18;
    u8 field_1C;
    u32 field_20;
    u8 field_24;
    f32 field_28;
} Rec;

void func_002723C0(u32 *out, void *list, char *s, u32 *src)
{
    Rec rec;
    u32 len;
    u32 i;
    void *node;

    if ((s == 0) || (s[0] == 0)) {
        func_0012D4D8(D_003C9EF0, 286, D_003C9F50);
        *out = 0;
        return;
    }
    rec.field_28 = 0.0f;
    for (i = 0; i < 3; i++) {
        rec.field_00[i] = 0;
    }
    len = func_001341D8(s);
    func_001080E0(&rec, len);
    func_00107100(&rec, 0, 0, s);
    rec.field_0C = func_002739E0(&rec.field_18, (u8 *)list + 0x24, &rec,
                                 *(u32 *)&rec.field_28);
    if (rec.field_00[0] & 1) {
        func_001007A0(rec.field_00[2]);
    }
    if (rec.field_1C != 0) {
        node = func_00274230(list);
        func_00107040((u8 *)node + 4, s);
        *(u32 *)node = *src;
        *out = *(u32 *)(rec.field_18 + 0x18);
    } else {
        *out = 0;
    }
}
