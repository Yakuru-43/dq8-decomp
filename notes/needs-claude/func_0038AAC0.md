# func_0038AAC0 — CLASS structural score=4 (4 words differ, 368 vs 368)

Best attempt's CLASS line (top of every attempt after the layout aligned):

```
CLASS structural score=4 (4 words differ, 368 vs 368 bytes)
```

Size: 0x170 (368 B) at 0x0038AAC0 (`asm/SLES_539.74/game_38AA20.s`,
endlabel 0x0038AC30). Called by `func_0038AA20` (which masks the result with
`andi 0xFFFF` — consistent with a `u16` return).

## What it does
`c = arg0 & 0xFF`, then an if/else-if chain of signed range tests
(`slti` + `bnez`/`beqz` pairs — matched byte-exact):

| range        | arm           |
|--------------|---------------|
| [0x20,0x30)  | `v1 = 1`      |
| [0x30,0x3A)  | `pair = 0`    |
| [0x3A,0x41)  | `v1 = 0xB`    |
| [0x41,0x5B)  | `pair = 1`    |
| [0x5B,0x61)  | `v1 = 0x25`   |
| [0x61,0x7B)  | `pair = 2`    |
| [0x7B,0x7F)  | `v1 = 0x3F`   |
| else         | `DebugPrintf(D_003D5C90); return 0;` |

Tail (`v1` in `$v1`, `pair` in `$a0`): `if (v1 != 0)` (raw-register `beql`,
`andi $v0,$a0,0xFF` for the pair in its delay slot) → table1 path
`lhu` from `D_003BE6B0` at word index `(c-0x20) - (((u8)v1) - 1)`;
else table2 path `lhu` from `D_003BE738` / `D_003BE73A` at `4*pair`,
result `c + t1 - t2` truncated by the `b <stub>; andi $v0,$v0,0xFFFF` into a
second `ld $ra` stub. All of this — including the two `ld $ra` return
stubs and the block layout — matched word-for-word in the best attempt.

## The one remaining problem
The four `v1 = K` assignments (K = 1, 0xB, 0x25, 0x3F) must be **`daddiu`**
(64-bit register store), but every type that makes them `daddiu` also breaks
the raw `beql $v1,$zero` test:

| v1 type | stores | `if (v1 != 0)` test |
|---------|--------|--------------------|
| `u32`   | `addiu` ✗ | raw `beql $v1` ✓ |
| `u64`   | `addiu` ✗ | raw `beql $v1` ✓ |
| `u8`    | `daddiu` ✓ | `andi 0xFF` + `beql $v0` ✗ |
| `u16`   | `daddiu` ✓ | `andi 0xFFFF` + `beql $v0` ✗ |
| `s8`    | `daddiu` ✓ | `dsll32 24`/`dsra32 24` sign-extend + `beql $v0` ✗ |

The table2 halfword truncation needed a `u16 result;` local assigned in both
arms and a single trailing `return result;` (this is what produced the
`b stub; andi 0xFFFF` tail and the second `ld $ra` — both present in the
original, both missing with direct `return (u16)(...)`).

## Best C (this is attempt 6; only the 4 addiu/daddiu words differ)
```c
// range: 0x38AAC0 0x38AC30
#include "common.h"

extern void DebugPrintf(char *);
extern char D_003D5C90[];
extern u32 D_003BE6B0[];
extern u32 D_003BE738[];
extern u32 D_003BE73A[];

u16 func_0038AAC0(u32 arg0) {
    s32 c = arg0 & 0xFF;
    u8 pair;
    u64 v1 = 0;
    u16 result;

    if (c >= 0x20 && c < 0x30) {
        v1 = 1;
    } else if (c >= 0x30 && c < 0x3A) {
        pair = 0;
    } else if (c >= 0x3A && c < 0x41) {
        v1 = 0xB;
    } else if (c >= 0x41 && c < 0x5B) {
        pair = 1;
    } else if (c >= 0x5B && c < 0x61) {
        v1 = 0x25;
    } else if (c >= 0x61 && c < 0x7B) {
        pair = 2;
    } else if (c >= 0x7B && c < 0x7F) {
        v1 = 0x3F;
    } else {
        DebugPrintf(D_003D5C90);
        return 0;
    }
    if (v1 != 0) {
        result = *(u16 *)&D_003BE6B0[(c - 0x20) - ((u8)v1 - 1)];
    } else {
        result = (u16)(c + *(u16 *)&D_003BE738[pair] - *(u16 *)&D_003BE73A[pair]);
    }
    return result;
}
```

The four differing words, all the same shape:

```
* +0E4  addiu  $v1, $zero, 0x3F    daddiu  $v1, $zero, 0x3F
```
(same at +0x28 with 0x1, +0x68 with 0xB, +0xA8 with 0x25 — `pair`'s
`daddiu $a0,$zero,K` already match; the init `daddu $v1,$zero,$zero` in the
first `bnez` delay slot already matches.)

## Things tried
1. `u32 c` — wrong: chain needs **signed** compares (`slti`, not `sltiu`).
2. Direct `return` expressions — lost the `andi 0xFFFF` tail and the second
   `ld $ra`; fixed by the `u16 result;` local + single trailing return.
3. `u32`/`u64` v1 — raw test ✓ but `addiu` stores (CW proves the upper
   32 bits zero from the phi of small constants and shrinks to `addiu`).
4. `u8`/`u16`/`s8` v1 — `daddiu` stores ✓ but the test gains
   `andi`/`dsll32+dsra32`.
5. Registers: declaring `pair` before `v1` puts `pair` in `$a0` and `v1` in
   `$v1` as the original; the other order swaps them.
6. Near-miss ref consulted: none of the mwcc-matching-mh2 Index entries fit
   "daddiu store + unmasked 64-bit zero test on a small-int value".
7. Not tried (time box): `tools/permute.py` finisher.

Untouched idea: a type CW does not constant-propagate through (pointer?
`volatile`-free 64-bit enum?) that forces `daddiu` yet tests raw, or an
assignment form like `v1 = (char *)1` that keeps the 64-bit store.
