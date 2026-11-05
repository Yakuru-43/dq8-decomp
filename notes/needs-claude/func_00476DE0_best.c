/* func_00476DE0 (BATTLE, 224 B) — best draft, NOT matched (factory-6 session cut off
 * at 45 min, 2026-11-05). Row released to todo.
 *
 * CLASS structural score=60 (54 words differ, 248 vs 224 bytes)
 *
 * What it does: arg1 is an object with s32 state at 0xB8 and counter at 0xBC.
 *   state==1: counter -= 1 (store unconditional); if (counter <= 0) log
 *             func_00476EC0(D_00421A14, D_00484918, 4), set D_00421A0C=1 if
 *             nonzero, then func_0046EBA0(arg1).
 *   state==0: log ... D_00484908, 6; D_00421A0C=2 if nonzero; state += 1.
 *   else: nothing. Always returns 0 (single shared return-0 tail at EB0;
 *   E0C tail jumps into EAC = `ld ra` shared epilogue).
 *
 * Diffs left after 2 attempts:
 * 1. The counter decrement: original is `lw v0,0xBC(s0); addiu v0,-1;
 *    bgtz v0,skip; sw v0,0xBC(s0)` — single load, test on the register, store
 *    in the bgtz delay slot (runs on both paths). Mine (`arg1->unkBC -= 1;
 *    if (arg1->unkBC <= 0) {...}`) stored then RELOADED for the test. Try
 *    `if (--arg1->unkBC <= 0)` or a permuter run on this region.
 * 2. Block layout: original top = `li v0,1` hoisted to +4, `lw v1,0xB8(a1)`,
 *    `beq v1,v0` to the ==1 body placed LAST (falls through into the shared
 *    epilogue), then `beqz v1` to the ==0 body placed second, then else
 *    `b EB0` with `ld ra` in its delay slot. Mine laid the ==0 body first and
 *    ran 24 B long. Source order must be ==1 first (the constant 1 is loaded
 *    before the state load). Also try the whole thing as a switch (cases 1 then
 *    0, default falls to the shared tail).
 *
 * Note: func_00476EC0 is called with THREE args here (value, string, 6/4) —
 * the matched src/BATTLE/func_00476EC0.c only names arg0; declare the caller
 * extern with all three. extern scalar globals need
 * __attribute__((section(".data"))) or CW uses $gp (see notes/idioms-new).
 */
// range: 0x476DE0 0x476EC0
#include "common.h"

typedef struct {
    char pad0[0xB8];
    s32 unkB8;
    s32 unkBC;
} S_476DE0;

extern void func_00476EC0(M2C_UNK, char *, s32);
extern void func_0046EBA0(S_476DE0 *);
extern M2C_UNK D_00421A0C __attribute__((section(".data")));
extern M2C_UNK D_00421A14 __attribute__((section(".data")));
extern char D_00484908[];
extern char D_00484918[];

s32 func_00476DE0(M2C_UNK arg0, S_476DE0 *arg1) {
    if (arg1->unkB8 == 1) {
        arg1->unkBC -= 1;
        if (arg1->unkBC <= 0) {
            if (D_00421A14 != 0) {
                func_00476EC0(D_00421A14, D_00484918, 4);
            }
            if (D_00421A0C != 0) {
                D_00421A0C = 1;
            }
            func_0046EBA0(arg1);
        }
    } else if (arg1->unkB8 == 0) {
        if (D_00421A14 != 0) {
            func_00476EC0(D_00421A14, D_00484908, 6);
        }
        if (D_00421A0C != 0) {
            D_00421A0C = 2;
        }
        arg1->unkB8 += 1;
    }
    return 0;
}
