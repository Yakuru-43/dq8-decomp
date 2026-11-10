// range: 0x15BDE0 0x15BF50
#include "common.h"

typedef struct {
    u8 pad[0x40];
    u16 b0 : 2;
    u16 mode : 3;
    u16 flag : 1;
    u16 state : 3;
    u16 b9 : 7;
} Obj15BDE0;

void func_0015BDE0(Obj15BDE0 *o, s32 arg1) {
    if (o->mode == 0) {
        switch (arg1) {
        case 0:
            o->flag = 0;
            o->state = 0;
            break;
        case 1:
        case 2:
            o->flag = 1;
            o->state = 1;
            break;
        }
    } else {
        switch (arg1) {
        case 0:
            o->flag = 0;
            o->state = 2;
            break;
        case 1:
            o->flag = 1;
            o->state = 4;
        case 2:
            o->flag = 1;
            o->state = 5;
            break;
        }
    }
}
