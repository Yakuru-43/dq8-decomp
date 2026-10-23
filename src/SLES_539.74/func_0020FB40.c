// range: 0x20FB40 0x20FC60
#include "common.h"

M2C_UNK func_001340C0(char *, s32);                       /* extern */
void func_00131188(char *, s32, s32);                     /* extern */
M2C_UNK func_001339E0(char *, M2C_UNK, char *, char *, char *, char *); /* extern */
char *func_00181420(void);                                 /* extern */
M2C_UNK func_00204AB0(char *, s32, s32);                  /* extern */
M2C_UNK func_00205250(char *, s32);                       /* extern */
void func_0020FC60(char *, M2C_UNK);                       /* extern */
M2C_UNK func_0020FD40(s32, char *);                        /* extern */
M2C_UNK func_00210C90(char *, s32, s32);                  /* extern */
s32 func_00370500();                                       /* extern */
M2C_UNK func_0038AA20(char *, char *);                     /* extern */
M2C_UNK func_00223150(s32, char *);                        /* extern */
M2C_UNK DebugPrintf(char *, char *);                       /* extern */
extern s32 D_003E08BC;
extern char D_003C79D0[];                                  /* format string */

void func_0020FB40(char *obj, s64 id, char *text) {
    char buf100[0x40];
    char bufC0[0x40];
    char bufA0[0x20];
    char buf60[0x40];
    char buf40[0x20];
    char *ptr;
    M2C_UNK entry;
    s32 idx;

    ptr = *(char **)(obj + 0x66E8);
    func_001340C0(obj + 0x6834, *(s32 *)ptr);
    entry = func_00205250(func_00181420(), 0);
    func_0020FC60(buf100, entry);
    func_00131188(bufC0, 0, 0x40);
    func_0038AA20(buf100, bufC0);
    M2C_FIELD(obj, u16 *, 0x677A) = 0x1C;
    ptr = func_00181420();
    entry = func_00204AB0(ptr, 0, 1);
    func_00210C90(bufA0, entry, 2);
    func_0020FD40((s32)id, buf60);
    idx = *(s32 *)(obj + 0x9C4);
    func_00210C90(buf40, idx + 1, 2);
    idx = func_00370500();
    entry = func_00223150(D_003E08BC, text + idx * 10);
    func_001339E0(obj + 0x6834, entry, buf40, buf60, bufC0, bufA0);
    DebugPrintf(D_003C79D0, obj + 0x6834);
}
