// range: 0x461100 0x4611C0
#include "common.h"

extern "C" {

struct MsgTarget {
    u8 pad0[0x1B0];
    virtual s32 f0();
    virtual s32 f1();
    virtual s32 f2();
    virtual s32 f3();
    virtual s32 f4(f32); /* slot 0x18 */
    virtual s32 f5();
    virtual s32 f6();
    virtual s32 f7(); /* slot 0x24 */
    u8 pad1B4[0x4DC - 0x1B4];
    s32 m4DC;
};

extern MsgTarget *D_003E1B70;
extern s32 D_003E1B74;
extern s32 D_003E1B78;

extern s32 func_15F490(void);
extern void func_1419A0(s32, s32, f32);
extern void func_151E10(void *);
extern int func_00461200(void *);
extern int func_00461210(void *);
extern void func_004611C0(void *, f32, f32, f32);

void func_00461100(void) {
    MsgTarget *target;
    s32 buf;

    target = D_003E1B70;
    if (target != 0) {
        if (!(D_003E1B74 > 0)) {
            if (D_003E1B78 != 0) {
                buf = func_15F490();
                func_1419A0(buf, target->m4DC, 1.0f);
                target->f4(1.0f);
                target->f7();
                if (func_00461210(target) != 0) {
                    func_151E10(target);
                    func_00461200(target);
                    func_004611C0(target, 0.0f, -1000.0f, 0.0f);
                    D_003E1B78 = 0;
                }
            }
        }
    }
}

}
