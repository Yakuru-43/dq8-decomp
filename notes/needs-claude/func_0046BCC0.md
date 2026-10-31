# func_0046BCC0 (SHOP, 224 B, 0x46BCC0..0x46BDA0)

CLASS structural score=53 (46 words differ, 192 vs 220 bytes) — best attempt,
the one in `func_0046BCC0.c.txt` next to this note (natural C, one attempt).

## What it does (my reading)

```c
func_0046DE00();                       // SHOP, void
win = func_0046D0C0();                 // SHOP; returns v0 (its own file says void,
                                       // calls func_0046DD40)
if (func_2B14A0(win, win, 0) > 0) {    // blezl $v0 -> else
    D_003E1A20 = 0;                    // sb $zero, -0x5850($gp)  (u8)
} else {
    func_2D38E0(arg1, 0x1F6D, 0, -1);
    func_3768A0(arg1);
    func_27BBF0(buf_250);              // streambuf-like init?
    fmt = func_2B0CF0(win, win);       // char *
    func_1339E0(win, fmt, fmt);        // (s32, char *, ...) — printf-like,
                                       // seen elsewhere: func_1339E0(win, fmt, args)
    func_0046B9A0(buf_250, buf_50);    // *buf_250 = (s32)buf_50 (matched twin)
    func_379690(buf_250, D_003E015C, 0, 0);
}
return 1;                              // shared stub `b epi; addiu v0,1` at 0x46BD0C
```

Stack: frame 0x3B0; sq s0..s3 at 0x00/0x10/0x20/0x30, sd ra at 0x40;
`buf_50` at sp+0x50 (0x200 B, the sprintf target), `buf_250` at sp+0x250 (0x160 B).
Declare order that lands them right: buf_250 first, buf_50 second (CW stacks
last-declared lowest). With s3 (arg0) genuinely saved, my buffer offsets came
out exactly 0x20 lower — everything tracks the save block, so the layout is
right and only the register/save set is missing.

## Why it is stuck: two dead instructions

1. `addiu $a0, $zero, 0x2712` at 0x46BD30 — the delay slot of `jal func_27BBF0`;
   `daddu $a0, $s1` three words later (0x46BD38, for `func_2B0CF0`) overwrites
   it before any `jal` reads it. Dead.
2. `lw $t0, 0x20($s3)` at 0x46BD60 — `$t0` is not read anywhere in the function
   (checked every word to `jr $ra`). It is the ONLY use of arg0, and it is why
   s3 is saved and the frame is 0x3B0 not 0x390.

Register-traced both against every `jal`: they cannot be argument setups.
At each call: 2D38E0 a0=s2 (blezl delay slot, always runs); 3768A0 a0=s2;
27BBF0 a0=sp+0x250 (delay of jal 3768A0); 2B0CF0 a0=s1 a1=s0; 1339E0 a0=s1
(still from 0x46BD38) a1=s0 a2=v0; 0046B9A0 a0=sp+0x250 a1=sp+0x50;
379690 a0=sp+0x250 a1=lw -0x7114(gp) a2=0 a3=0 (all set after the lw t0, and
a1 is the global load, so t0 is not a stolen arg).

So the original C reads `arg0->field_0x20` (u32) and discards it — only a
volatile-qualified type keeps that load, and `volatile` is lint-forbidden here
(not a hardware register). `0x2712` likewise survives only if written for a
consumer CW could not remove.

## Tried

- Natural C (the draft): score 53, mine lacks `s3`, the `lw t0`, the
  `addiu 0x2712`, frame 0x390, buffers at sp+0x30/0x230.
- Considered and rejected: making `func_27BBF0(void *, s32)` and
  `func_379690(..., arg0->f20, ...)` — argument register trace above shows the
  values land too late / are overwritten; o32 never uses `t0` for args;
  no `sw` into 0(sp) exists so no 5th stack arg.
- mh2 catalogue: not consulted (out of time; likely nothing there on dead
  loads).

## Leads for Claude

- Check the SHOP overlay's .data structs near 0x3E015C: maybe `arg0` is a
  known struct type whose +0x20 member was volatile in the original header
  (thread-shared flag? then `// thread-shared` is the honest spelling).
- If it is not volatile: ask whether CW's -O3 scheduler can really leave a
  dead `lw` + dead `addiu` (a known autodecomp/permute escape hatch?), or
  whether the tail `b .L0046BD0C` hides a peeled second call at the boundary
  with the next function (0x46BDA0).
- `D_003E1A20` has no symbol_addrs alias yet (I put it in the uncommitted
  `config/symbol_addrs_SHOP_local.txt` for try_match).
