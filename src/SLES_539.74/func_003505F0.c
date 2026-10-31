// range: 0x3505F0 0x350630
#include "common.h"

void func_001340C0(char *, char *);

typedef struct {
    char *field0;
    char *field4;
} S_arg1;

void func_003505F0(char *arg0, S_arg1 *arg1) {
    char *p = arg0;
    func_001340C0(p, arg1->field4);
    func_001340C0(p + 0x20, arg1->field0);
}
