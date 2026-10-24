// range: 0x30AD30 0x30AD80
#include "common.h"

void *func_0030AD80(void *);                            /* extern */
char *func_00356910(char *, void *);                    /* extern */

typedef struct {
    char pad0[0x124];
    void *unk124;
} S_arg1;

void func_0030AD30(char *arg0, S_arg1 *arg1) {
    void *v;

    v = arg1->unk124;
    if (v == 0) {
        func_00356910(arg0, 0);
        return;
    }
    func_00356910(arg0, func_0030AD80(v));
}
