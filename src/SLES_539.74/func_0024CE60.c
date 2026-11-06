// range: 0x24CE60 0x24CEF0
#include "common.h"

extern char *func_001340C0(char *, char *);

void func_0024CE60(char *arg0) {
    char buf[0x200];
    char *in;
    char *out;
    s32 c;

    func_001340C0(buf, arg0);
    in = buf;
    out = arg0;
    while ((c = *in) != 0) {
        if (c == 0x5C && in[1] == 0x6E) {
            *out = 0x81;
            in += 2;
            out[1] = 0x40;
            out += 2;
        } else {
            *out = c;
            in++;
            out++;
        }
    }
}
