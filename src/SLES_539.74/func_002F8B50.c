// range: 0x2F8B50 0x2F8D30
// rodata: 0x3CFAE0 0x3CFB00
#include "common.h"

typedef struct {
    char *name;
    u8 len;
    u8 kind[11];
} Tag;

extern Tag D_003AC200[];
extern char D_003CFAC8[];
extern char D_003CFAD0[];
extern void func_00134750(char *, char *, s32);
extern s32 func_002E3380(char *, char *);

/* copies src to dst, replacing `[tag]` markers by text chosen per tag; returns
   the length written, terminator included */
s32 func_002F8B50(char *src, char *dst, s32 arg2, s32 arg3) {
    s32 i;
    s32 n;
    char *p;
    Tag *tag;
    u8 kind;
    s8 c;

    if (src == NULL || dst == NULL) {
        return 0;
    }
    i = 0;
    n = 0;
    while ((c = *(p = &src[i])) != 0) {
        if (c == '[') {
            kind = 0;
            for (tag = D_003AC200; tag->len > 0; tag++) {
                if (p[2] == tag->name[2] && func_002E3380(p, tag->name) == 0) {
                    i += tag->len;
                    kind = tag->kind[arg2 * 2 + arg3];
                    break;
                }
            }
            switch (kind) {
            case 1:
                break;
            case 2:
                dst[n++] = '\'';
                break;
            case 3:
                func_00134750(&dst[n], D_003CFAC8, 2);
                n += 2;
                break;
            case 4:
                func_00134750(&dst[n], D_003CFAD0, 2);
                n += 2;
                break;
            case 5:
                dst[n++] = 's';
                break;
            case 6:
                dst[n++] = 'n';
                break;
            case 7:
                dst[n++] = 'r';
                break;
            default:
                dst[n] = '[';
                i++;
                n++;
                break;
            }
        } else {
            i++;
            dst[n++] = c;
        }
    }
    dst[n] = 0;
    return n + 1;
}
