CLASS structural score=11 — best attempts (next_arg / K&R forms), see also twin notes/needs-claude/func_0045F190.md

# func_0045FEF0 (MENU, 48 B) — needs-claude

## The asm (asm/MENU/text_45F930.s, `nonmatching func_0045FEF0, 0x2C`)

```
glabel func_0045FEF0
    addiu  $sp, $sp, -0x40
    sd     $a0, 0x0($sp)
    sd     $a1, 0x8($sp)
    sd     $a2, 0x10($sp)
    sd     $a3, 0x18($sp)
    sd     $t0, 0x20($sp)
    sd     $t1, 0x28($sp)
    sd     $t2, 0x30($sp)
    sd     $t3, 0x38($sp)
    jr     $ra
    addiu  $sp, $sp, 0x40
```

Byte-identical shape to func_0045F190 (SHOP, already needs-claude with
score 11): a save-all-args stub that loads nothing and returns. Callers
are debug/log style — one arg, a format-string global, e.g. text_45F930.s:
`lui a0,%hi(D_00478F70); jal func_0045FEF0; addiu a0,a0,%lo(D_00478F70)`;
text_460DE0.s passes only `%hi/%lo(D_00479000)`.

## What it seems to be

A stripped `void Report(const char *fmt, ...)`-style stub whose argument
spills survive but whose body is gone. Read before this file's attempts:
notes/needs-claude/func_0045F190.md (6 attempts logged there: named+`...`
empty body, next_arg(t3), __builtin_saveregs as first guess, stdarg.h
missing, optimization_level 0).

## This session's attempts (all CLASS structural)

Best score 11 (K&R / next_arg forms, 8 vs 44 B). New results, mostly
`__builtin_va_start` behaviour in this compiler (b151, -O3):

1. `char *fmt, ...` + `ap = (char *)__builtin_next_arg(fmt) -
   (__builtin_args_info(2) >= 8 ? 0 : (8-__builtin_args_info(2))*8)` +
   `if (ap == 0) return;` → score 31. args_info(2) is a **runtime** value
   with only 1 named param: CW emits the `8 - n` arithmetic and a save
   **loop** (`slti; bnez; sd; b; …`), frame 0x50.
2. 8 named `s32` + `...` + `ap = (char *)__builtin_next_arg(t3)` +
   `if (ap == 0) return;` → score 11 (20 B): args_info folds, but only
   `addiu $v1,$sp,0x80; sw $t3,0x70($sp)` — the *home slot* of the
   next_arg argument, 16-byte slots, frame 0x80. No save area. Same with
   `next_arg(a0)` (sw a0 at 0(sp)).
3. **`__builtin_va_start(ap, fmt)` EXISTS** (no header needed): emits the
   correct eight 8-byte `sd` save-area stores at 0x8..0x40 — but also
   `daddu $a1,$a0,$zero`, `sd $ra,0($sp)`, frame 0x60 and
   `jal func_000000` (unresolved helper, save in its delay slot).
   Score 17. `char ap[8]` array form: same (score 19, frame 0x70).
4. `__builtin_va_end(ap)` adds a SECOND `jal func_000000` (score 27).
5. `void f() { __builtin_saveregs(); }` (K&R) → `j func_000000; nop`
   (tail call, score 11) — matches the twin's finding: saveregs = call.
6. `void f() { if (__builtin_args_info(2)==0) return; }` → bare `jr $ra`
   (args_info folds to a constant 8 for a K&R definition? nothing emitted).
7. 8 `s64` params all address-taken via `if (&a0==0 || …)` → score 52:
   CW does NOT fold `&local == 0`; it emits addiu+beqz per param.
8. 8 `s64` params, `p=&t3` used in one `if (p==0)` → only t3's home slot
   is stored (score 11, 32 B): confirms home-slot store is per-param,
   16-byte slots, and only for address-taken ones.

## What would match

Exactly the attempt-3 store set **without** the ra save and **without**
the helper call. Ideas for the next pass:

- Find what `func_000000` under `__builtin_va_start` is (run verify.py →
  LINK name). If the game contains that runtime routine, the sibling
  stubs may be `#define`-wrapped differently; if it lives in MSL, check
  whether a CW `#pragma` or library build option inlines it.
- The MH2 catalogue ("Prototypes" → Varargs) says variadic definitions
  need its `ee_stdarg.h` `va_start` define (this file's attempt 1);
  with **8 named params + `...`** the args_info term folds — untried is
  that define combined with `#pragma optimization_level` 1/2 so the
  save-area stores survive DCE (they are prologue-level stores).
- The whole 45Fxxx/46xxxx stub family (func_0045F190, func_0045FEF0,
  maybe more in other overlay bins) is one translation-unit question;
  answer it once, match them all.

## MH2 catalogue entries consulted

Index lines: "Variadic functions: variadic prototypes and MWCC's
`va_start` (Prototypes)" (line 252, section Prototypes, entry
"Varargs", file line ~2941); "A parameter stored to its home slot: its
address is taken (Stack)" (line 316).
