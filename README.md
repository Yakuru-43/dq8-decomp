# Dragon Quest VIII decompilation (PAL, SLES-53974)

> **This project is made with an LLM.** The decompilation is driven by an AI
> coding agent (Anthropic's Claude, via Claude Code) working at my direction.
> See [How this is made](#how-this-is-made) for exactly what the LLM did and
> how every result is verified.

Disassembly that rebuilds byte-identical game binaries, with functions being
moved into matching C one at a time. Porting that code to PC is the long-term goal.

| Binary | Role | vram |
|---|---|---|
| `SLES_539.74` | main executable | `0x100000` |
| `BIN/TITLE.BIN`, `SHOP.BIN`, `MENU.BIN`, `CASINO.BIN`, `BATTLE.BIN` | overlays (`MWo3` header) | `0x45EC80` |

## Progress

<!-- progress:start -->
```
                 code bytes                                     functions
SLES_539.74      [█░░░░░░░░░░░░░░░░░░░]  5.9%    141/ 2397 KB   [███████░░░░░░░░░░░░░]  32.9%  3159/9595 
TITLE (overlay)  [█░░░░░░░░░░░░░░░░░░░]  1.0%      0/   19 KB   [███████░░░░░░░░░░░░░]  33.3%    12/36   
SHOP (overlay)   [█░░░░░░░░░░░░░░░░░░░]  7.3%      4/   60 KB   [██████░░░░░░░░░░░░░░]  32.2%   109/339  
MENU (overlay)   [█░░░░░░░░░░░░░░░░░░░]  4.5%      5/  103 KB   [██████░░░░░░░░░░░░░░]  29.5%    98/332  
CASINO (overlay) [█░░░░░░░░░░░░░░░░░░░]  1.3%      1/  106 KB   [█████░░░░░░░░░░░░░░░]  27.0%    53/196  
BATTLE (overlay) [█░░░░░░░░░░░░░░░░░░░]  3.5%      5/  143 KB   [█████░░░░░░░░░░░░░░░]  25.9%   159/613  
ALL game code    [█░░░░░░░░░░░░░░░░░░░]  5.5%    157/ 2828 KB   [██████░░░░░░░░░░░░░░]  32.3%  3590/11111
```
_(refreshed 2026-10-21 by `tools/readme_progress.py`; only files in the repo count -- `src/*/asmfunc/` is generated asm and uncommitted work is not progress; run `tools/progress.py` for the per-region table)_
<!-- progress:end -->

The SDK regions of the main executable (`sdk_*`, `lib*`, GCC-built) are
tracked separately by `tools/progress.py` and not shown above.

## How this is made

I use an LLM agent to do the decompilation work. Concretely:

- **Written by the LLM:** the binary analysis (memory map, compiler identification,
  SDK/game boundaries), every script in `tools/`, the `Makefile`, the configs,
  `include/common.h`, the hand-matched function in `src/SLES_539.74/game_359C90.cpp`,
  and this README.
- **Function bodies in `src/*/*.c`** (files marked `// auto:`) are drafted by
  [m2c](https://github.com/matt-kempster/m2c), a conventional rule-based MIPS
  decompiler (not an LLM), then rewritten by LLM-written scripts (struct synthesis,
  signature fixes, operand swaps). Some are refined by
  [decomp-permuter](https://github.com/simonlindholm/decomp-permuter), a random search.
- **Nothing is trusted on the LLM's word.** A function is only kept if it compiles,
  with the original compiler (CodeWarrior PS2 3.0.1), to exactly the original bytes
  when linked at its real address. The full build is also checked against the SHA-1
  of the original executables. So the code is *behaviourally* exact, but names,
  types and struct layouts are machine-generated guesses (`func_XXXXXXXX`, `arg0`,
  `unk10`) and may be misleading.

## Legal

This repository contains **no game data**: no disc image, executables, assets,
audio, video, text, or disassembly. Dragon Quest VIII is © Square Enix / Level-5;
the PS2 SDK is © Sony; the CodeWarrior compiler is © Metrowerks/NXP and is
downloaded separately by `tools/setup_toolchain.sh`, never committed.
You need your own legally obtained copy of the PAL disc (SLES-53974).
`src/` contains functions written in C that compile to the original machine code;
`src/*/asmfunc/` (original VU0 instructions) is generated locally and not published.

## License

My own contributions (tools, build system, configs, docs, and the decompiled
source to the extent I hold any rights in it) are dedicated to the public domain
under [CC0 1.0](LICENSE). Much of it is AI-generated, which may not be
copyrightable at all; CC0 waives whatever rights exist. **CC0 does not cover the
game itself**: material derived from Dragon Quest VIII remains subject to Square
Enix / Level-5's rights, and the PS2 SDK to Sony's.

Third-party tools used (not included in this repository): splat, spimdisasm,
rabbitizer, wibo and decomp-permuter (MIT), m2c (GPL-3.0, used as a program; its
output is not covered), GNU binutils (GPL-3.0), Metrowerks CodeWarrior for PS2
(proprietary).

## Building

Put your own dump at `DQ8.iso`, then:

```sh
python3 -m venv .venv && .venv/bin/pip install splat64[mips] spimdisasm \
    "git+https://github.com/matt-kempster/m2c.git"
tools/setup_toolchain.sh   # MIPS binutils, wibo, CodeWarrior PS2 -> .toolchain/
make setup   # extract code from the ISO, generate configs, disassemble, auto-name
tools/autodecomp.py        # optional: regenerate src/*/asmfunc (not in the repo)
make -j      # assemble, link, verify against checksum.sha1
tools/progress.py          # how much is built from src/
tools/watch.py             # the same count as a live bar, plus the permuter's queue
```

## Source files

`src/<binary>/*.c|cpp` replace the assembly for the range in their first line:

```c
// range: 0x13E390 0x13E3D0
// flags: -O4                     (optional, extra compiler flags for this file)
```

`make split` regenerates configs and asm around them; `make` must still print OK
for every binary. A short object is padded to the next 16-byte boundary by
`tools/postsplit.py`.

### Automatic decompilation

`tools/autodecomp.py [--bin X]` tries every function that is still asm and keeps
only byte-exact results (linked at the real address against every known symbol,
compared including padding; objects that emit their own data are rejected).
Per function it tries, in order:

1. m2c drafts (`mips-gcc-c` and `mipsee-mwcc-c` targets), with
   - pointer fields turned into synthesized structs (`M2C_FIELD` pointer
     arithmetic makes CodeWarrior hold addresses in registers),
   - callees left unprototyped (m2c disagrees with itself on argument counts),
   - `==`/`!=` operands swapped (CodeWarrior keeps source order);
2. the same at `-O4` and `-O2`;
3. the draft repaired by `tools/repair.py` (see below), plus its swapped-compare
   variant and `-O4`/`-O2`;
4. for functions using VU0 instructions, a CodeWarrior `asm` function with the
   original instructions (this vector code was hand-written; m2c can't express it);
   the `asm` body declares its `j`/`jal`/branch targets as `extern` — mwccps2
   otherwise reports them as undefined labels (most VU0 code calls back into C).

### Repairing m2c's types (`tools/repair.py`)

CodeWarrior is strict where GCC is lenient, so most drafts that fail to compile
are otherwise correct: a pointer used where an `int` is wanted, an `int`
dereferenced as a pointer, a callee whose parameter list m2c guessed wrong.
`repair()` compiles the draft, reads CodeWarrior's first error — it echoes the
line with a caret one past the offending expression — and rewrites that spot,
keeping whichever candidate compiles and moving on to the next error. The rules
are casts, so they cannot change the generated code: `temp_t0 - M2C_FIELD(…)`
becomes `(s32) ((char *) temp_t0 - (char *) M2C_FIELD(…))`, `*var_a3` becomes
`*( s32 *) var_a3`. About a third of the `compile` failures turn into compiling
C this way; when the bytes still differ the source is saved to
`build/repair/<bin>/` and `permute_batch.py` permutes that instead of a raw draft.

Files it writes say `// auto:` and use m2c names (`arg0`, `unk10`, `func_XXXXXXXX`).
They are correct but not yet readable: naming types and fields is manual work.

### Tail-call thunks

`tools/thunkify.py [--bin X]` handles the other shape m2c gets wrong: tail
calls. The original source is `return target(...)`, which CodeWarrior compiles
to a jump; m2c drafts `jal` + `return v0` instead, which never matches. CodeWarrior
schedules argument setup *before* the jump and fills the delay slot, so the body
is a run of argument shuffles ending in `j target`.

The tool walks that run instruction by instruction, keeping a register map of
C expressions: moves (`daddu $a1, $a0, $zero`), constants, null pointers,
`addiu`/`ori`/`andi` offsets and masks, loads through an argument, loads of
`%gp_rel` globals, and stores (including `swc1`/`sq`). Anything it cannot
express — a real sum of two live values, an absolute `%hi/%lo` reference, a
branch — rejects the function. The map is then inlined into
`return target(arg0, ...)`, so no temporaries appear, and only what
`autodecomp.verify()` calls byte-exact is kept. 134 of the 226 recognised
shapes matched first try.

Not handled yet: functions with jump tables or their own constants (switches,
float literals), which need their `.rodata` placed with them; functions whose
m2c draft compiles but differs (control-flow shape, register allocation), which
need manual matching (`tools/try_match.py --show`) or a permuter; and functions
that address data absolutely (`lui $at, %hi(sym)` + `%lo(sym)($at)`), which the
`asm` form cannot express — CodeWarrior's inline assembler has no relocation
syntax at all:

| operand | result |
|---|---|
| `lui v0, %hi(D_x)`, `%lo(D_x)(v1)`, `hi()`, `@hi()`, `D_x@ha` | rejected |
| `li v0, D_x`, `addiu v0, zero, D_x` | "illegal constant expression" |
| `lw v0, D_x` | `lw v0, 0(gp)` — `R_MIPS_GPREL16`, silently small-data |
| `lw v0, D_x(v1)` | `lw v0, 0(gp)` — the register is silently dropped |
| `lw v0, 0x2F50(v1)` | correct, but the address is a literal |

So an `asm` body can only reach data through `$gp` or a hardcoded number; the
`%hi`/`%lo` functions need real C (`&sym` compiles to exactly that pair) or a
draft that m2c refused to produce.

### What a range may cover

`// range:` claims those bytes belong to one translation unit, and splat
re-disassembles the *neighbours* with its own heuristics every time the split
runs. Two ways that bites:

- **A label the callers still need.** Truncating an asm chunk can merge two of
  its functions into one and drop the glabel between them; the decompiled
  files calling it then fail to link, although no byte changed.
  `tools/keep_funcs.py` asks the linker script which objects make up each
  binary, takes the function symbols the compiled objects want and nothing
  provides, and pins them in `config/symbol_addrs_<bin>.txt` so the label
  survives every re-split.
- **An entry point inside the body.** splat writes `alabel` for an address
  other code calls, and that is global. A C file cannot name a point in the
  middle of one of its own functions, so autodecomp refuses the range
  (`entry inside` in the tsv) instead of matching it and deleting a label its
  callers jump to. 137 functions are in that class; they have to be cut apart
  by hand before any of them can become C.

## Layout notes

- **Compiler**: Metrowerks CodeWarrior for PS2 **3.0.1 build 145 or 151** (Feb/Mar 2005), `-O3`, C++.
  Pinned by matching `FindEntry` (0x359C90): every other 2.4/3.0.1 build differs.
  The ELF `.comment` says `2.4.1.01`, which matches no 3.0.1 compiler; it likely comes from the linker.
  `-O3` vs `-O4` is still tentative (a near-match favours `-O3`).
- **SDK libraries** were built with GCC: they pack functions on 8-byte boundaries, while
  CodeWarrior pads every function to 16. That splits the code into regions
  (see `MAIN_TEXT_REGIONS` in `tools/gen_configs.py`): `sdk_*` (0x108398–0x13B510),
  `game_*`, `lib_*` (0x252348, unidentified) and `libdbc_*` (0x38AE98–0x38DA10).
- **No symbols**: `.symtab` is empty. Known names live in `config/symbol_addrs*.txt`.
- **crt0**: `_start` at `0x100008`, `$gp = 0x3E7270`, `main = 0x15FB90`, bss `0x3E0280–0x486C80`.
- Main executable memory map:

  | Range | Contents |
  |---|---|
  | `0x100000–0x38DA10` | code (split into ~64 KB chunks at function starts) |
  | `0x38DA10–0x39D248` | VU microcode (`assets/vu_microcode.bin`) |
  | `0x39D248–0x39E780` | code, with VIF packet data at `0x39D548–0x39D8B8` |
  | `0x39E780–0x3D6100` | rodata/data |
  | `0x3D6100–0x3DD3F0` | C++ static initializers |
  | `0x3DD3F0–0x3E0280` | ctor table + data |

- `tools/gen_configs.py` generates `config/*.yaml`. Edit the generator, not the yaml.
- `tools/symbolize.py` names functions automatically into `config/symbol_addrs_*_auto.txt`:
  EE kernel syscall stubs (162) and SDK functions named by their own error strings
  (`sceDbcInitSocket: rpc error`, …). Manual names go in `config/symbol_addrs_<bin>.txt`.
- Overlays reference main-executable symbols through `linker/*_undefined_*_auto.txt`.

## Decompiling a function by hand

1. Write it in a scratch file and iterate until it matches:
   `tools/try_match.py --show scratch/f.cpp <symbol> <vram> -- -O3`
2. Put it in `src/SLES_539.74/` with a `// range:` first line; for C++, add the
   mangled name to `config/symbol_addrs_SLES_539.74.txt`.
3. `make split && make -j` — the build must still print OK for every binary. If
   one fails with `undefined reference to func_XXXXXXXX` that no src file
   defines, run `tools/keep_funcs.py` and split again.

## Known source files

Assert/`__FILE__` strings place functions in these translation units (`.h` hits are inlines):

| File | Functions referencing it |
|---|---|
| `mg_draw.cpp` | 0x145C30 |
| `dq_2nd_chk.cpp` | 0x2912C0 … 0x296BD0 (3) |
| `dq_monster_ai.cpp` | 0x29AC20 … 0x29DEC0 (5) |
| `btl_playdata.cpp` | 0x2B8390 |
| `dq_player_ai.cpp` | 0x30D600 … 0x310580 (10) |
| `btl_actana.cpp` | 0x3181F0 |
| `btl_viscom.cpp` | 0x32AB30 … 0x337BD0 (38) |
| `playerai_data.cpp` | 0x356E50 |
| `btl_chrinfo_logic.cpp` | 0x358140 |

## Next steps

1. **Match the remaining game functions by hand.** `tools/try_match.py --show` diffs a
   candidate against the original; `tools/permute.py <func> --run 600` sets up and runs
   decomp-permuter from the best m2c draft (useful for register allocation and
   statement-order noise, not for control-flow shape).
   `tools/permute_batch.py --hours 10` runs it unattended over every mismatching
   function (smallest first, resumable via `build/permute_batch.done`, stop with
   `touch build/permute_batch.stop`); score-0 results are re-verified before they
   are written to `src/`. Follow with `make split && make -j`. `tools/watch.py`
   follows along: one bar per binary, this run's queue and match count, and how
   much is still waiting to be folded in.
2. **Jump tables and constants**: place a function's `.rodata` with it so switches can match.
   `build/autodecomp_*.tsv` marks these `jumptable` (~130 functions).
3. **Absolute data references (`lui %hi` + `ori %lo`)**: the CodeWarrior `asm` form
   cannot express them at all (table above), so the ~1800 `m2c`/`compile` failures
   that are VU0 wrappers need C that computes the address with `&sym` — which means
   teaching m2c, or a hand-written generator, to emit those. Hardcoding the two
   16-bit halves would match bytes but loses the symbol and breaks if data moves.
4. **Readability**: auto files use m2c names. Recovering real types (structs shared across
   functions, C++ classes) is what makes the code portable later.
5. Identify the remaining SDK functions (most have no strings): call-graph from the named
   ones, or byte signatures from a matching Sony SDK release.
6. Share symbols between the main executable and overlays (overlays still see `func_*`).
7. **Porting** needs the whole game in C plus replacements for the PS2 hardware it drives
   (GS, VU0/VU1 microcode, IOP sound modules, CD/DVD streaming, memory card, pads).
