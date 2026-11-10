// range: 0x15FB90 0x15FE40
// best attempt for main (func_0015FB90): 680 vs 676, CLASS structural score=84
// (attempt 2 without the `region` local: 676 vs 676, CLASS structural score=92,
//  first real diff +0x2C: CW constant-folded 0x2000000-0x2010 into `lui 0x1FF`)
#include "common.h"

extern s32 GetThreadId(void);
extern void ChangeThreadPriority(s32, s32);
extern s32 D_003DFB8C;
extern u8 D_A0000 __attribute__((section(".data")));
extern u8 D_486C80 __attribute__((section(".data")));
extern char D_003C2380[];
extern char D_003C23A0[];
extern char D_003C23A8[];
extern char D_003F2490[];
extern s32 func_00130400(s32);
extern s32 func_00130458(s32);
extern char *func_00135950(char *, char *);
extern void func_001340C0(char *, char *);
extern void func_00163ED0(char *);
extern void func_00100440(void);
extern void func_00100450(void);
extern void func_003899E0(void);
extern void func_003899F0(s32, char **);
extern void func_00119DE0(s32);
extern void func_0011EAD0(void);
extern void func_0012AE98(s32);
extern void func_0012BA88(s32);
extern u32 func_0011FF50(char *);
extern u32 func_0011FF00(void);
extern void func_0011B940(void);
extern void func_00109FC0(s32);
extern void func_00108538(void);
extern void func_00108398(s32, s32, s32, s32);
extern void func_00108F28(void *, s32, s32, s32, s32, s32, s32);
extern void func_00109220(s32);
extern void FlushCache(s32);
extern void sceGsPutDrawEnv(void *);
extern void sceGsSyncPath(s32, s32);
extern void func_0015F840(void);
extern void func_00163720(void);
extern void func_00161840(void);
extern void func_00163430(s32);
extern void func_001684A0(void);
extern void func_00163380(void);
extern void func_001617E0(void);

s32 main(s32 argc, char **argv) {
    char *romName;
    u8 env_3B0[0xF0];
    u8 env_2C0[0xF0];
    u8 init_270[0x50];
    u8 env_180[0xF0];
    u8 env_90[0xF0];
    u8 init_40[0x50];
    u64 gifCtl;
    s32 tid;
    s32 region;

    tid = GetThreadId();
    ChangeThreadPriority(tid, D_003DFB8C);
    region = -0x2010 - (s32)&D_A0000;
    region = region - (s32)&D_486C80;
    func_00130458(func_00130400(region + 0x2000000));
    func_00130458(func_00130400(0x1900000));
    romName = func_00135950(argv[0], D_003C23A0);
    func_00163ED0(romName);
    if (romName != 0) {
        func_001340C0(D_003F2490, romName);
    } else {
        func_001340C0(D_003F2490, D_003C23A8);
    }
    func_00100450();
    func_003899F0(argc, argv);
    func_00119DE0(0);
    func_0012AE98(0);
    func_0012BA88(2);
    while (((0 < func_0011FF50(D_003C2380)) ^ 1) != 0) {
    }
    while (((0 < func_0011FF00()) ^ 1) != 0) {
    }
    func_00119DE0(0);
    func_0011EAD0();
    func_0012AE98(0);
    func_0012BA88(2);
    func_0011B940();
    func_00109FC0(1);
    func_00108538();
    func_00108398(0, 1, 2, 1);
    gifCtl = *(u64 *)0x12000000 & ~(u64)3; // hw-register
    func_00108F28(init_40, 0, 0x280, 0x1C0, 2, 0x31, 1);
    *(u64 *)0x12000000 = gifCtl; // hw-register
    FlushCache(0);
    func_00109220(0);
    sceGsPutDrawEnv(env_90);
    sceGsSyncPath((s32)env_90, 0);
    sceGsPutDrawEnv(env_180);
    sceGsSyncPath((s32)env_180, 0);
    func_0015F840();
    func_00163720();
    func_00161840();
    func_00163430(D_003DFB8C - 1);
    func_001684A0();
    func_00108F28(init_270, 0, 0x280, 0x1C0, 2, 0x31, 1);
    FlushCache(0);
    func_00109220(0);
    sceGsPutDrawEnv(env_2C0);
    sceGsSyncPath((s32)env_2C0, 0);
    sceGsPutDrawEnv(env_3B0);
    sceGsSyncPath((s32)env_3B0, 0);
    func_00163380();
    func_001617E0();
    func_003899E0();
    func_00100440();
    return 0;
}
