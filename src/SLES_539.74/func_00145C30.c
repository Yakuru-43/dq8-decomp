// range: 0x145C30 0x145D70
#include "common.h"

/* "mg_draw.cpp", "texman", "denv" */
extern char D_003C1FC0[];
extern char D_003C1FD0[];
extern char D_003C1FD8[];

typedef struct Denv {
    char pad0[0x38];
    s32 mode;           /* 0x38 */
    char pad3C[0x17C - 0x3C];
    s32 x;              /* 0x17C */
    s32 w;              /* 0x180 */
    s32 kind;           /* 0x184 */
    s32 h;              /* 0x188 */
} Denv;

typedef struct MgDraw {
    char pad0[0x270];
    Denv *denv;         /* 0x270 */
    char pad274[0x3B90 - 0x274];
    void *texman;       /* 0x3B90 */
} MgDraw;

extern void func_0012D4D8(char *file, s32 line, char *expr);
extern void func_0015B370(void *texman, s32 x, s32 y, s32 arg);

void func_00145C30(MgDraw *self, s32 useX, s32 useY, s32 arg)
{
    void *texman = self->texman;
    Denv *denv;
    s32 x;
    s32 y;

    if (texman == NULL) {
        func_0012D4D8(D_003C1FC0, 104, D_003C1FD0);
    }
    denv = self->denv;
    if (denv == NULL) {
        func_0012D4D8(D_003C1FC0, 106, D_003C1FD8);
    }
    if (denv->kind != 1) {
        useX = 0;
    }
    if (denv->mode != 0x31) {
        useY = 0;
    }
    x = 0;
    y = 0;
    if (useX && useY) {
        x = denv->x;
        y = denv->h + (denv->x + denv->w);
    } else if (useX) {
        x = denv->x;
        y = denv->x + denv->w;
    } else if (useY) {
        x = denv->x + denv->w;
        y = x + denv->h;
    }
    func_0015B370(texman, x << 5, y << 5, arg);
}
