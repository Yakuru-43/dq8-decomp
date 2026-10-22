// range: 0x20FD40 0x20FE20
#include "common.h"

M2C_UNK func_001340C0(char *, char *);                            /* extern */
M2C_UNK func_00210C90(char *, s32, s32);                         /* extern */
M2C_UNK func_001339E0(char *, char *, char *, char *);           /* extern */
M2C_UNK func_00305320(s32, u64 *, u64 *);                        /* extern */
extern char D_003C79E8[];                                         /* " " pad */
extern char D_003C79F0[];                                         /* "  " pad */
extern char D_003C79F8[];                                         /* format */

void func_0020FD40(s32 secs, char *dst) {
    u64 quot;
    u64 rem;
    char buf60[0x40];
    char buf20[0x40];

    func_00305320(secs, &quot, &rem);
    if (quot < 100) {
        if (10 <= quot) {
            func_001340C0(buf20, D_003C79E8);
            func_00210C90(buf20 + 2, (s32)quot, 0);
        } else {
            func_001340C0(buf20, D_003C79F0);
            func_00210C90(buf20 + 4, (s32)quot, 0);
        }
    } else {
        func_00210C90(buf20, (s32)quot, 0);
    }
    func_00210C90(buf60, (s32)rem, 2);
    func_001339E0(dst, D_003C79F8, buf20, buf60);
}
