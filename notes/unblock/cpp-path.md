# Unblock: C++ build path (plan step 7) — scoped semaphore lock family

Status: done

## 2026-11-07 (night 3, Opus, branch `unblock`)

### Where this started
The three queue families (jumptable, hilo, entry-inside) were already marked
done. The queue still had 113 `jumptable` rows (212 KB); re-running
`autodecomp --jumptables --why` on all binaries matched nothing new (main:
compile 33, mismatch 20, repaired 14, m2c 13, size 8; the compile errors are
m2c type defects, `illegal implicit conversion` first; 6 drafts pass a stale
`$a1` holding the table address as a call argument). One open sub-family of
night 1 was a tooling cause: func_0025CCF0's C++ scoped lock "emits an
out-of-line destructor that the linker scripts don't place". That is the
plan's step 7 (C++ build path).

### Why C++ objects with an inline destructor failed
mwccps2 emits an inline member that needs an out-of-line copy (here the
deleting destructor `__dt__8SemaLockFv`, which calls `__dl__FPv`) in its own
second `.text` section with symbol binding 13 (multiply defined).
CodeWarrior's linker dead-strips such a function when nothing calls it; GNU ld
placed it (extra code, undefined `__dl__FPv`), and with two objects the
binding-13 symbols clashed (multiple definition). The tools also misread these
objects: try_match took the bytes of the first `.text` (the destructor)
for the function, verify's section-size check overwrote one `.text` with the
other (SIZE), and `autodecomp --why` logged mwcc's caret line, not its message.

### What changed
- fdb19ff7 tools: `tools/set_abi.py` (run on every object by the Makefile,
  verify and now try_match) empties an executable section that holds only
  binding-13 functions no relocation of the object's code/data points at, with
  its relocations and `.mwcats`; the Makefile runs it before the rodata
  `ld -r` merge (which would fuse the sections). `--why` logs mwcc messages.
- 2c88c794 include, tools: `include/sema_lock.h` (SemaLock); autodecomp
  verify() runs set_abi.py before reading sizes and sums same-named sections.
- 82780b12 tools: set_abi.py turns binding 13 into weak (keep one copy).
- c5604ec9 include: `include/stream_channel.h` (Channel, GetChannel,
  PushCommand, PushParams, PopParams).
- 63c90b39 include: `include/sound_voice.h` (Voice, PushVoiceCommand).
Every commit through the full gate, six OK.

### Matches: 16 functions, 5,552 bytes
src commits 79d64907, ae4e1b72, 19838248, 569c7286, 0bc3b419:
func_0025CCF0 (was blocker `jumptable`), func_00250F50, func_0024F440,
func_0025ADC0, func_0025AEF0, func_0025B020, func_0025B270, func_0025D230,
func_0025CE70, func_0025D050, func_0025B3A0, func_0024F4F0, func_00250DD0,
func_002517D0, func_00251600, func_0024FAC0. Nine of them had needs-claude
notes from the factory (removed in the notes commit).

The family: 21 queued functions whose asm has the lock signature
(`lw $X,N($sp); lw $v0,0($X); blez; jal SignalSema; lw $a0,0($X)`), 13 KB.
Left: func_00251290 (496, best C in notes/needs-claude/func_00251290.md:
register rotation and lock-slot order only), func_00250A00 (976),
func_0025C6B0 (1056), func_0024FD70 (1680), func_0025D410 (3216, jump table).
More `SignalSema` callers (65 unmatched in all) are in the same TUs
(game_24F440..2514B0, game_25A750..25BE20, game_15F530..160F40,
game_19F170..1A0D30) and likely use the same headers or explicit
Wait/Signal pairs.

### What the factory can take now
notes/idioms.md "Scoped semaphore lock (sound streams)": the sign, the
`.cpp` + `-Cpp_exceptions off` recipe, the three headers, and the
thread-shared `volatile` rule for fields the original re-loads. The rows are
blocker `none` already; with the tools fixed the factory can take them.
No queue blocker was added or removed by this family.

### Next
- func_00251290 from its note; then the large ones above (by hand, Claude).
- Other C++ objects that failed with `__dl__FPv` / `multiple definition`
  or SIZE should be re-tried now; `autodecomp` still writes C only (m2c),
  so it cannot produce these by itself. A `.cpp` mode for autodecomp
  (drafts that wrap the m2c body around SemaLock when the signature is
  there) is the next tooling step if the factory stalls on them.
- The jumptable leftovers stay needs-claude material (see jumptable.md).
