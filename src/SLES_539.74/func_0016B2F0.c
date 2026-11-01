// range: 0x16B2F0 0x16B3E0
#include "common.h"

static inline char *get_554(char *obj, s32 idx) {
    if ((idx >= 0) && (idx < M2C_FIELD(obj, s32 *, 0x550))) {
        return obj + (idx << 6) + 0x554;
    }
    return NULL;
}

static inline char *get_3a48(char *obj, s32 idx) {
    if ((idx >= 0) && (idx < M2C_FIELD(obj, s32 *, 0x3A44))) {
        return obj + (idx * 0x3C) + 0x3A48;
    }
    return NULL;
}

static inline char *get_3864(char *obj, s32 idx) {
    if ((idx >= 0) && (idx < M2C_FIELD(obj, s32 *, 0x3860))) {
        return obj + (idx * 0x3C) + 0x3864;
    }
    return NULL;
}

s32 func_0016B2F0(char *arg0, s32 arg1, s32 arg2) {
    char *p;
    s32 value;

    switch (arg1) {
    case 1:
        p = get_554(arg0, arg2);
        break;
    case 2:
        p = get_3a48(arg0, arg2);
        break;
    case 3:
        p = get_3864(arg0, arg2);
        break;
    default:
        p = NULL;
        break;
    }
    if (p != NULL) {
        value = *(s32 *)p;
    } else {
        value = 0;
    }
    return value;
}
