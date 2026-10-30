// range: 0x3514E0 0x351560
#include "common.h"

extern s32 func_0014E8A0(char *);
extern s32 func_00169260(char *);
extern char *func_003501B0(char *);
extern s32 func_00350890(char *);
extern s32 func_00351560(u32);

u32 func_003514E0(u32 arg0) {
    u32 cursor;

    func_00169260((char *)arg0 + 0x44);
    func_00350890((char *)arg0 + 0x250);
    func_003501B0((char *)arg0 + 0x18B4);
    func_0014E8A0((char *)arg0 + 0x18F4);
    func_0014E8A0((char *)arg0 + 0x194C);
    cursor = arg0 + 0x19A4;
    do {
        func_00351560(cursor);
        cursor += 0xA4;
    } while (cursor < arg0 + 0x1AEC);
    return arg0;
}
