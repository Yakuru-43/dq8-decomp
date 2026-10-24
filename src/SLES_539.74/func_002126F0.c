// range: 0x2126F0 0x212740
#include "common.h"

typedef struct {
    s32 type;
    s32 val;
} Item;

extern char *D_003E0944;

s32 func_00212790(void);
void func_002127B0(char *, Item *);

s32 func_002126F0(Item *arg0) {
    if (func_00212790() != 0) {
        func_002127B0(D_003E0944 + 0x10, arg0);
        return 1;
    }
    return 1;
}
