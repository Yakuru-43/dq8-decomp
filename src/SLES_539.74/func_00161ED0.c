// range: 0x161ED0 0x161F70
#include "common.h"

extern s32 func_00133BE0(char *a0, char *a1);

char *func_00161ED0(char *arg0, char *arg1) {
    s8 c;
    char *sep;
    char *p;
    char *rec;

    if (arg0 == NULL) {
        return NULL;
    }
    if (arg1 == NULL) {
        return NULL;
    }
    if (*arg1 == 0) {
        return NULL;
    }
    sep = arg1;
    p = arg1;
    while ((c = *p) != 0) {
        if (c == '/') {
            sep = p + 1;
        }
        p++;
    }
    rec = arg0;
    while (*rec != 0) {
        if (func_00133BE0(rec, sep) == 0) {
            return rec;
        }
        rec = rec + *(s32 *)(rec + 0x48);
    }
    return NULL;
}
