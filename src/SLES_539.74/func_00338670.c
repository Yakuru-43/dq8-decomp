// range: 0x338670 0x3386A0
#include "common.h"

s32 func_00166760(char *);
extern void *D_003E1260;

s32 func_00338670(char *arg0) {
    if (D_003E1260 == NULL) {
        return 0;
    }
    func_00166760(arg0);
    return 1;
}
