CLASS structural score=54 (52 words differ, 300 vs 292 bytes)  [best attempt; DIFF at +0xC]

# func_0025AEF0

Size 304 (0x25AEF0..0x25B020), SLES_539.74, no blocker, 2 attempts (~30 min).

Byte-8 twin of the stuck **func_0025ADC0** (see notes/needs-claude/func_0025ADC0.md,
which has the same guard chain, the same sema spill problem, and a `*volatile`
experiment log). Same family as the matched twins src/SLES_539.74/func_0025B760.c
(GetChannel/IsEmpty/IsBusy, volatile sema) and func_0025AB80.c (guard). Pushes a
byte `8` (not 4) into the channel ring queue: validates id 0..5 against
D_0041CBC0[6] (Channel, 0x128 stride) and D_0041D2B0[6], returns -1 if NULL; else
`if (ch->sema > 0) WaitSema(...)` (bgtz + cold block, arg `lw $a0,0($v1)` in the
jal delay slot), then `if (ch->closing || ch->readPos != ch->writePos)` stores 8 at
queue[writePos], `writePos = (writePos + 1) % 24` (plain divu+mfhi, no div guard),
done = 1, closing = 0 (sb in the `b` delay slot), else done stays 0; then the
shared tail `if (*sema > 0) SignalSema(*sema); return done;` (tail `b epi; andi
$v0,$s1,0xFF`).

## The blocker (same as func_0025ADC0): sema-pointer spill shape
Original: first test is a direct `lw $v0,0xC($s0)`, then `addiu $v1,$s0,0xC` and
`sw $v1,0x3C($sp)` in the **plain bgtz delay slot**; $v1 stays live through the
WaitSema cold block (`lw $a0,0($v1)`), and the tail reloads it **once**
(`lw $v1,0x3C($sp)`, then test and jal arg both from $v1); tail test is
`blez $v0,<skip>; nop; jal SignalSema; lw $a0,0($v1)` (call inline, not bgtzl to
a cold block). ch=$s0, done=$s1, saves `sd $ra,0x20`/`sq $s1,0x10`/`sq $s0,0` in
the bltz delay slot.

Attempt log:
1. Plain `volatile s32 *sema` local, `u8 ret` last, test `ch->sema > 0`, else-arm
   `ret = 0`: CLASS structural score=74 — CW kept sema in $s0 (ch→$s1, ret→$s2),
   3 saved registers, and the tail became `lw $v0,0($s0); bgtzl; lw $a0,0($s0)`
   (arg hoisted into the delay slot, signal block out of line).
2. `u8 done; Channel *ch; volatile s32 *volatile sema;` + `done = 0;` before the
   if, no else (the ADC0 note's best, with the test written `ch->sema > 0` not
   `*sema > 0`): **score 54**. Frame now byte-identical through +0x68 (saves,
   guard chain, `beql` -1 stub all match). Divergence from +0x6C:
   mine `addiu $v0,$s0,0xC; sw $v0,0x3C($sp); lw $v0,0xC($s0); bgtzl;
   lw $v0,0x3C($sp)` vs orig `lw $v0,0xC($s0); addiu $v1,$s0,0xC; bgtz;
   sw $v1,0x3C($sp)`, and the tail mine has an extra pointer reload + `bgtzl` +
   cold signal block vs orig's inline `blez/jal/lw a0,0($v1)` — 8 bytes long.
   The `*volatile` reloads the pointer before **every** use (test, WaitSema arg,
   tail); the original computes it once, spills once, reloads once.

## Best C (also notes/needs-claude/func_0025AEF0_best.c)
```c
// range: 0x0025AEF0 0x0025B020
#include "common.h"

typedef struct Channel {
    u8 pad0[0xC];
    volatile s32 sema; // thread-shared: the stream thread signals it
    u8 pad10[0x40];
    u8 closing;
    u8 pad51[3];
    s32 readPos;
    u32 writePos;
    u8 queue[0x18];
    u8 pad74[0x128 - 0x74];
} Channel;

extern Channel D_0041CBC0[6];
extern s32 D_0041D2B0[6];

s32 WaitSema(s32);
s32 SignalSema(s32);

s32 func_0025AEF0(s32 id) {
    u8 done;
    Channel *ch;
    volatile s32 *volatile sema;

    if (id >= 0 && id < 6) {
        ch = &D_0041CBC0[id];
    } else {
        ch = NULL;
    }
    if (ch == NULL || D_0041D2B0[id] == 0) {
        ch = NULL;
    }
    if (ch == NULL) {
        return -1;
    }
    sema = &ch->sema;
    if (ch->sema > 0) {
        WaitSema(*sema);
    }
    done = 0;
    if (ch->closing || ch->readPos != ch->writePos) {
        ch->queue[ch->writePos] = 8;
        ch->writePos = (ch->writePos + 1) % 24;
        done = 1;
        ch->closing = 0;
    }
    if (*sema > 0) {
        SignalSema(*sema);
    }
    return done;
}
```

## Left todo (shared with func_0025ADC0)
Get CW to spill `&ch->sema` exactly once with the store in the plain `bgtz` delay
slot, keep $v1 live to the WaitSema arg, and reload once for the tail, with the
tail signal call inline (`blez` skip, not `bgtzl` to cold). Ideas from both
notes, untried: non-volatile `s32 *` local with the volatile **field**
(`volatile s32 sema;` in the struct, no volatile on the pointer local); or an
inline helper taking the pointer so the "local" is a call-boundary value. mh2
catalogue index was not consulted (time limit; the ADC0 note says no entry
matches this spill shape).
