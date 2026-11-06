## Returning a bool flag: `daddu $v0,$sN,$zero` — declare the function `bool`, not `s32`
Sign: a 0/1 flag in an `$s` register, stored with 64-bit ops (`daddiu $sN,$zero,1`,
`daddu $sN,$zero,$zero`) and copied at the return with a bare `daddu $v0,$sN,$zero`,
where `u8 ret` gives `andi $v0,$sN,0xFF` (score 1, one word) and `s32 ret` gives
32-bit `addiu`/`addu` stores.
Fix: a `.cpp` inside `extern "C" { }` with the flag `bool` **and the function's own
return type `bool`**: a `bool` local returned from an `s32` function still emits the
returning `andi 0xFF` (bool→int promotion); `bool`→`bool` copies raw. The lint and
verify only care about bytes, so widening the C return type is free. Related in the
same file: a `u8`-returning getter (a flag reader like `func_0035E570`) tested against
0 at the call site needs its extern declared `s32` **in this file**: a `u8` prototype
adds `andi $v0,$v0,0xFF` before the test, and the original tests `$v0` bare.
Example: src/SLES_539.74/func_0035DBB0.cpp
Solved: func_0035DBB0 2026-11-05 Qwen factory-3
