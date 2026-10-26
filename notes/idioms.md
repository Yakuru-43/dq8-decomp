# Idioms

Techniques that matched functions the Qwen factory had given up on. The nightly Opus
batch adds one entry per technique (newest last), and every factory session reads this
file before its first attempt and checks the function's asm against the signs.

Entry format:

    ## <short name>
    Sign: what the asm, or Qwen's try_match diff, shows.
    Fix: what to write (C, a type, a compiler flag) and how to try it.
    Example: src/<bin>/<file>.c
    Solved: func_... (date, who)

## divbyzerocheck: a divide guarded by bnez + break 0, 7
Sign: `bnez <divisor>` before `div $zero, a, b` and `break 0, 7` after it, around a `/` or
`%`, and no C rewrite produces the guard (Qwen's notes call it the "div-guard family").
Fix: write the plain `/` or `%`; the guard comes from a compiler flag. Try it with
`tools/try_match.py <file> <func> <vram> --show -- -O3 -flag divbyzerocheck`; on a match
put `// flags: -flag divbyzerocheck` on line 2, under `// range:` (verify.py and the
build read it there).
Example: src/SLES_539.74/func_002FF0D0.c
Solved: func_002FF0D0 func_00301200 func_003012F0 func_00301350 func_00302140
func_0020C5C0 func_00210C90 func_00210F80 func_00212BA0 (2026-10-24, Opus)

## throw(): an unreachable jal func_00101510 + nop spin loop after the body
Sign: `sq $fp` / `addu $fp,$sp` frame, the body, then `b <epilogue>` over a dead block
`jal func_00101510; addiu $a0,$fp,0x20; 5x nop; b -6; nop`, epilogue `addu $sp,$fp`.
Notes call it a "dead C++-EH handler" or "terminate island"; try/catch gets close but adds
`sw $sp,..($fp)` and a bigger frame.
Fix: a C++ file (`.cpp`) whose function has an empty exception specification:
`void f(void) throw() { ...body... }`. CW emits the `__unexpected` handler as that dead
block; `func_00101510` is `__unexpected`. Try `-O4,p` if the `addu $fp,$sp` is not in the
first jal's delay slot (`// flags: -O4,p`). verify.py says `LINK` until
`__unexpected = 0x101510;` is in config/symbol_addrs_SLES_539.74.txt (integration adds it).
Example: notes/needs-claude/func_001007A0.md (Opus attempt section)
Solved: func_001007A0 (byte match, waiting for the alias; 2026-10-26, Opus)
