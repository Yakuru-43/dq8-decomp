# func_0046CFF0 (BATTLE)

CLASS structural score=19 (19 words differ, 256 vs 256 bytes) — best attempt, `-- -O3`.

## Session 2 (2026-10-31 late, factory-6): best now `notes/needs-claude/func_0046CFF0.c.txt`
(try_match `--bin BATTLE -- -O4`, CLASS structural score=45; the session-1 `.c.txt` was not
in this worktree, rebuilt C from asm). Solved / learned:

- **Note item 1 SOLVED**: `sel = func_370500() > 0 ? D_003E01D4 : D_003E01D0;` emits the
  orig's exact `blezl $v0, join` + `lw a0,-0x70A0($gp)` delay / fall-through `lw
  a0,-0x709C($gp)`. The unflipped ternary/if-else gives `bgtzl`.
- Sibling `src/BATTLE/func_0046D9A0.c` (flags: **-O4**) shares the object: entries at
  `arg0 + i * 0x58`, field 0xBC4 (data ptr), mirror at `arg0 + i*4` field 0xCFC, 0xB68→0xB98.
  Use its M2C_FIELD + `char *arg0` + `temp_s1/temp_v1` spelling (kept byte-exact there).
- Still wrong (all three trace to one word at +0x40, everything after is shifted):
  1. ctx lands in `$s1` (+0x40 `addiu $s1,$v0,0x10C`, loop `lw a0,0($s1)`, counter in
     `$s2`) vs orig `$s2` (`daddu $s2,$v0`, `lw a0,0x10C($s2)`). Swapping `i`/`ctx`
     declaration order and struct-typing `ctx->unk10C` (BattleCtx pad[0x10C];s32 unk10C)
     did NOT change it. Try: keep ctx as integer/`u32`, or permuter.
  2. block-1 hit: mine `lw a0,0xB68(s3); daddu a1,v0; lw a2; jal; [addiu s0,s3,0xB68;
     lw v0,0(s0); sw v0,0xB98(s3)]` (260 B — the s0 materialize is +4); orig `lw a2;
     lw a0; jal + daddu a1 delay; lw v0,0xB68(s3); sw v0,0xB98(s3)` — arg order a2,a0,a1,
     mirror read direct from s3, temp_v0 local did not remove the fold.
  3. loop hit: mine duplicates the guard (`beqz v0` + delay `daddu a1,v0` **and** a second
     `beqz a1` + nop); orig single `beqz v0`. Mine keeps temp_s1 in s4 (`addu s4,s3,v0`,
     `lw a0,0xBC4(s4)`); orig keeps it in v0 and materializes `addiu s4,v0,0xBC4` in the
     memcpy delay slot, reload `lw a0,0(s4)` — func_001DE300 family, untried spellings:
     pass `temp_s4` to memcpy too, or read via `M2C_FIELD(temp_s4, s32 *, 0)`.
- -O4 tried because sibling 0046D9A0 uses it; -O3 gave the same allocation.

- Size: 256 B (0x46CFF0..0x46D0F0), queue row 27, claimed 2026-10-31 factory-6.
- What it does: picks one of two `.sdata` dwords by `func_370500() <= 0`, calls
  `func_162E80` (context, field 0x10C), then `func_161E80(ctx->0x10C, key, &size)`
  twice — once with `&D_004841C0`, then in a 4-iteration loop over `D_00482ED0[i]` —
  copying hits with `func_130FD0` (memcpy) into `arg0->0xB68` / `arg0+i*88+0xBC4`,
  and mirroring `arg0->0xB68` to `arg0->0xB98` and the entry word to `arg0+4i+0xCFC`.
- My best C is `notes/needs-claude/func_0046CFF0.c.txt`: structs `Ctx{pad[0x10C]; s32 unk10C}`,
  `Buf{pad[0xB68]; void *unkB68; pad[0x2C]; void *unkB98}`, `M2C_UNK *func_161E80(...)`
  (pointer return — with `s32` the `if (r != 0)` blocks went cold, the func_001419A0 sign),
  `do { temp_s0 = var_s1 * 4; ... } while (var_s1 < 4);`.

Remaining diffs vs orig (mine left):
1. +0x24 select: mine `bgtzl $v0` + loads; orig `blezl $v0, join; lw a0, D_003E01D0`
   (delay), fall-through `lw a0, D_003E01D4`. Tried if/else `<= 0`, default-assign +
   `if (f() > 0)` (hoisted the default load into `$s0` before the `jal`, +1 word), and
   ternary `f() <= 0 ? D0 : D4` (still `bgtzl`). Try flipping the ternary arms
   (`f() > 0 ? D_003E01D4 : D_003E01D0`), mh2 "select" entries.
2. Registers: loop counter in `$s2` + ctx in `$s1` where orig has loop `$s1`, ctx `$s2`
   (temp_s0=`$s0` and s4 ok). Swapping declaration order untried at this shape.
3. memcpy arg schedule: orig loads `a2 = 0x6C(sp)` BEFORE the dest address math in both
   blocks (mine after / in the jal delay slot); block 1 orig order `lw a2; lw a0`.
4. Loop hit block: orig `beqz $v0, skip` with `daddu $a1,$v0` in the delay slot, entry
   base kept in `$v0` (`lw a0, 0xBC4(v0)`), `addiu $s4,$v0,0xBC4` in the memcpy `jal`
   delay slot, reload `lw a0, 0(s4)`. Mine copies `a1` before the `beqz`, keeps the base
   in `$s4` and loads `0xBC4($s4)` — the func_001DE300 "materialized pointer local" family.

Tried idioms: func_001C57D0 ternary select, func_001419A0/func_0026BD00 pointer-typed
test (fixed the cold block), func_001DE1A0 per-arm duplication (n/a). Attempted 4 tries
in 25 min of the forced session stop. MH2 index not consulted (clock).
