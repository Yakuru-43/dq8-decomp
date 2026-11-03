// CLASS structural score=165 (153 words differ, 616 vs 664 bytes) — best (only) attempt 2026-11-03 factory-2
// Draft analysis, session cut off after 1 attempt (row left todo). See notes/needs-claude/func_0025FBD0.md.
// range: 0x25FBD0 0x25FE70
#include "common.h"

extern char D_003C96F8[];
extern void DebugPrintf(char *);
extern s32 func_00130F38(void *, void *, s32);
extern s32 func_00130FD0(void *, void *, u32);

typedef struct CmdData {
    /* 0x00 */ u8 kind;
    /* 0x01 */ u8 mode;
    /* 0x02 */ u8 flag;
    /* 0x04 */ u32 w04;
    /* 0x08 */ u32 w08;
    /* 0x0C */ u32 w0C;
    /* 0x10 */ union {
        u32 w[2];
        u16 h[3];
    } code;
    /* 0x18 */ u32 w18;
    /* 0x1C */ u32 w1C;
    /* 0x20 */ u32 w20;
    /* 0x24 */ u32 w24;
    /* 0x28 */ u32 w28;
    /* 0x2C */ u8 name[16];
    /* 0x3C */ u32 link;
    /* 0x40 */ f32 f40[6];
    /* 0x58 */ f32 f58[6];
    /* 0x70 */ u32 w70;
    /* 0x74 */ u32 w74;
    /* 0x80 */ u32 tab[16];
    /* 0xC0 */ u32 wC0;
    /* 0xC4 */ u32 wC4;
    /* 0xC8 */ u32 ptrs[2];
    /* 0xD0 */ u32 wD0;
    /* 0xD4 */ u32 wD4;
    /* 0xD8 */ u32 wD8;
    /* 0xDC */ u32 wDC;
    /* 0xE0 */ u32 wE0;
    /* 0xE4 */ u32 wE4;
    /* 0xE8 */ f32 fE8;
    /* 0xEC */ u32 vptr;
} CmdData; /* size 0xF0 */

typedef union Cmd {
    CmdData d;
    u128 q[15];
} Cmd; /* size 0xF0 */

typedef struct CmdSet {
    /* 0x00 */ u32 changed;
    /* 0x04 */ u32 pad04;
    /* 0x08 */ u32 count;
    /* 0x10 */ Cmd items[4];
} CmdSet; /* size 0x3D0 */

s32 func_0025FBD0(CmdSet *set, Cmd *arg1) {
    Cmd in;
    CmdData work;
    u32 i;
    u32 dup;

    in = *arg1;
    if (set->count >= 4) {
        DebugPrintf(D_003C96F8);
        return 1;
    }
    work.kind = in.d.kind;
    work.mode = in.d.mode;
    work.flag = in.d.flag;
    work.w04 = in.d.w04;
    work.w08 = in.d.w08;
    work.w0C = in.d.w0C;
    work.code.h[0] = in.d.code.h[0];
    work.code.h[1] = in.d.code.h[1];
    work.code.h[2] = in.d.code.h[2];
    work.code.w[0] = in.d.code.w[0];
    work.code.w[1] = in.d.code.w[1];
    work.w18 = in.d.w18;
    work.w1C = in.d.w1C;
    work.w20 = in.d.w20;
    work.w24 = in.d.w24;
    work.w28 = in.d.w28;
    for (i = 0; i < 16; i++) {
        work.name[i] = in.d.name[i];
    }
    for (i = 0; i < 6; i++) {
        work.f40[i] = in.d.f40[i];
    }
    for (i = 0; i < 6; i++) {
        work.f58[i] = in.d.f58[i];
    }
    work.w70 = in.d.w70;
    work.w74 = in.d.w74;
    for (i = 0; i < 16; i++) {
        work.tab[i] = in.d.tab[i];
    }
    work.wC0 = in.d.wC0;
    work.wC4 = in.d.wC4;
    work.wD0 = in.d.wD0;
    work.wD4 = in.d.wD4;
    work.wD8 = in.d.wD8;
    work.wDC = in.d.wDC;
    work.wE0 = in.d.wE0;
    work.wE4 = in.d.wE4;
    work.fE8 = in.d.fE8;
    i = 0;
    dup = 0;
    while (i < set->count) {
        if (func_00130F38(&work, &set->items[i], 0xF0) == 0) {
            dup = 1;
            break;
        }
        i++;
    }
    if (dup == 0) {
        func_00130FD0(&set->items[set->count], &in, 0xF0);
        set->count = set->count + 1;
        set->changed = 1;
        return 1;
    }
    return 0;
}
