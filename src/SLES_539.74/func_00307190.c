// range: 0x307190 0x3071E0
#include "common.h"

void func_0020B4B0(char *);                          /* extern */
void func_001339E0(char *, char *, char *);          /* extern */
extern char D_003D0160[];

void func_00307190(char *arg0) {
    char buf20[0x80];

    if (arg0 == 0) {
        return;
    }
    func_0020B4B0(buf20);
    func_001339E0(arg0, D_003D0160, buf20);
}
