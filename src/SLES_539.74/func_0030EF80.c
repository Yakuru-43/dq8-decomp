// range: 0x30EF80 0x30EFB0
#include "common.h"

typedef struct {
    u8 pad1[0x2C];
    s32 dataOff;
    s32 table[1];
} EntryTable;

char *func_0030EF80(char *arg0, s32 arg1) {
    EntryTable *t = (EntryTable *)arg0;
    s32 entry = t->table[arg1];
    if (entry != 0) {
        return arg0 + t->dataOff + entry * 32;
    }
    return 0;
}
