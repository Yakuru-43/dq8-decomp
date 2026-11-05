CLASS structural score=57 (54 words differ, 304 vs 292 bytes)
Diff at +0xC: mine 0480002A orig 0480002B (mine 12 B long, register-only
elsewhere); best was `volatile s32 *volatile sema` — plain `volatile s32 *sema`
gave CLASS structural score=73 (kept sema in $s0, ch fell to $s2).

# func_0025ADC0

Size 304 (0x25ADC0..0x25AEF0), SLES_539.74, no blocker, 4+3 attempts (25 min).

Pushes a byte `4` into a channel's ring queue: validates `id` 0..5 against
`D_0041CBC0[6]` (Channel, element 0x128) and `D_0041D2B0[6]`, returns -1 if the
channel is NULL or its enable word is 0; otherwise WaitSema if `sema > 0`, then
if `closing || readPos != writePos` stores 4 at `queue[writePos]` (byte array at
0x5C, 24 entries), advances `writePos = (writePos + 1) % 24` (`divu` + `mfhi`,
plain, no div-guard), clears `closing`, sets `done = 1`; finally SignalSema if
`*sema > 0` and returns `(u8)done` (`andi $v0,$s1,0xFF` in the tail `b`).
Matches the style of the matched twins `src/SLES_539.74/func_0025B760.c`
(GetChannel/IsEmpty/IsBusy, volatile sema) and `func_0025AB80.c` (guard).

## The problem: register allocation of the sema pointer local
Original saves only `ra@0x20`, `sq $s1@0x10`, `sq $s0@0x0` (ch=$s0, done=$s1);
the `&ch->sema` pointer is a value CW spilled itself:
`addiu $v1,$s0,0xC` then `sw $v1,0x3C($sp)` **in the `bgtz` delay slot** (so the
bgtz is plain, not `bgtzl`, and the first sema test is a direct
`lw $v0,0xC($s0)`), reloaded once at the shared tail
`lw $v1,0x3C($sp); lw $v0,0($v1); blez ...; jal SignalSema; lw $a0,0($v1)`.
Each `*sema` deref is its own load (arg load `lw $a0,0($v1)` even where the
value is already in a reg) -> the field is `volatile s32` (as in func_0025B760.c)
or the loads straddle calls.

- Plain `volatile s32 *sema;` local: CW gives sema $s0, ch drops to $s2 (frame
  saves s0,s1,s2; `addiu $s0,$s2,0xC`), score 73. Declaration order does not
  fix it (tried `ch;sema;done`, `sema;done;ch`): $s numbering followed the
  first-assignment order, not declaration order, so ch never reached $s0.
- `volatile s32 *volatile sema;` (with `done` declared before `ch` -> ch=$s0,
  done=$s1, frame saves now byte-identical through +0x68): CW reloads the
  pointer with `lw $v0,0x3C($sp)` **before every use** (extra lw before the
  test, before lbu closing, before the tail) and turns `bgtz`+delay-slot-store
  into `bgtzl` after the reload pair — 3 extra words, score 57, CLASS structural.
- What it wants: a local whose address CW spills exactly once and keeps in $v1
  until the first call — looks like a *non-volatile* `s32 *` (or `volatile s32 *`)
  that CW decided to spill, not a volatile local. `done` must be `u8` (daddiu
  store + `andi 0xFF` return, no test of `done`).

## Best C (notes/needs-claude/func_0025ADC0_best.c)
```c
// range: 0x25ADC0 0x25AEF0
#include "common.h"

typedef struct Channel {
    u8 pad0[0xC];
    volatile s32 sema; // thread-shared: the stream thread signals it
    u8 pad10[0x40];
    u8 closing;
    u8 pad51[3];
    s32 readPos;
    u32 writePos;
    u8 queue[24];
    u8 pad74[0x128 - 0x74];
} Channel;

extern Channel D_0041CBC0[6];
extern s32 D_0041D2B0[6];

s32 WaitSema(s32);
s32 SignalSema(s32);

s32 func_0025ADC0(s32 id) {
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
    if (*sema > 0) {
        WaitSema(*sema);
    }
    done = 0;
    if (ch->closing || ch->readPos != ch->writePos) {
        ch->queue[ch->writePos] = 4;
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
With this, +0x00..+0x68 is byte-identical (saves, guard chain, `beql` -1 stub,
all `lui` relos are masked). Divergence starts at +0x6C: mine
`addiu $v0,$s0,0xC; sw $v0,0x3C($sp); lw $v0,0x3C($sp); lw $v0,0($v0);
bgtzl ...` vs orig `lw $v0,0xC($s0); addiu $v1,$s0,0xC; bgtz $v0,<wait>;
sw $v1,0x3C($sp)`.

## Tried
1. Guard copied verbatim from matched twins (func_0025AB80/func_0025B760).
2. `volatile s32 *sema` local, decl orders `ch,sema,done` and `sema,done,ch`.
3. `volatile s32 *volatile sema` with `done` first (best, 57).
4. Plain `/ % 24` on `u32 writePos` gives the `divu`+`mfhi` exactly (no
   `-flag divbyzerocheck` needed; original has no div guard).
5. mh2 catalogue: checked Index entries on register allocation/spills — nothing
   matches "single spill of a pointer local with delay-slot store"; closest is
   the field-load-CSE entry (wrong direction: here mine reloads, orig keeps $v1).

Left todo: get CW to spill `&ch->sema` once into a temp + delay-slot `sw` while
the test loads `0xC($s0)` directly — try a non-volatile `s32 *` local with a
volatile **field** (`volatile s32 sema;` in the struct, `s32 *sema = (s32 *)&ch->sema`
would drop the per-use reloads; needs the arg loads to stay separate), or
recompute `&ch->sema` at the two call sites and let CW CSE+spill it, or make
`ch` a `const Channel *`, or pass the queue store through a pointer local.
