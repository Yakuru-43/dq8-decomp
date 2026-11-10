// range: 0x46C980 0x46CA20
#include "common.h"

s32 func_0027BBF0();                                   /* extern */
void func_004696D0();                                   /* extern */
void func_004697B0(s32 arg0, s32 arg1);
extern char *func_0046DDF0(void);
M2C_UNK func_3710B0(char *, M2C_UNK, M2C_UNK);          /* extern */
void func_2D38E0(void *arg0, s32 arg1, s32 arg2, s32 arg3);
typedef struct { u8 a, b, c, d; } S_bytes;

extern S_bytes D_003E0180 __attribute__((section(".sdata")));

typedef struct {
    char pad[0x18];
    char *unk18;
} S_win;

void func_0046C980(s32 arg0, S_win *arg1) {
    u32 idx;
    s8 bytes[4];

    idx = arg0 * 2;
    *(S_bytes *)bytes = D_003E0180;
    func_004696D0(func_0027BBF0(bytes[idx]));
    func_3710B0((char *)arg1, 1, bytes[idx + 1]);
    func_004697B0(M2C_FIELD(M2C_FIELD(arg1, char **, 0x18), s16 *, 0x12), 1);
    func_2D38E0(func_0046DDF0(), 0x1F6D, 1, -1);
}
