# needs-claude: build — `// flags:` is ignored for .cpp files, main checksum fails at HEAD

Not a function note: a build-system bug. `make split && make -j` ends with
five OK and `build/SLES_539.74: FAILED` on a clean factory-2 tree (independent
of this session's matches; the payload diff is 171 bytes at file
0x201418..0x2014EB, inside `src/SLES_539.74/func_00301350.cpp`).

## Root cause
The Makefile's `%.c.o` rule reads a `// flags:` line (`$(shell sed -n
'1,5s|^// flags: ||p' $<)`) but the `%.cpp.o` rule does not.
`func_00301350.cpp` (bfad935, factory-4) carries `// flags: -flag
divbyzerocheck` — dead in the build, honoured by `verify.py`/`try_match.py`
(autodecomp reads it for every suffix). So the committed function verifies
byte-exact but the real build omits the div guards: a false MATCH that only
the checksum sees. It is the only `.cpp` with a `// flags:` line.

## Verified facts (2026-10-25, factory-2 session)
- try_match with the Makefile's exact flags (`-O3 -nostdinc -stderr -Iinclude
  -Isrc -flag divbyzerocheck`) MATCHes all 412 bytes.
- `#pragma divbyzerocheck on` after `#include "common.h"` MATCHes under plain
  `-O3` — but `tools/lint_contrived.py` refuses any `#pragma` (line 24), so
  the lint would have to grow an exemption like `// hw-register` has.
- Editing the Makefile from this session is not permitted; both fixes are
  one-liners for a privileged session.

## Fix (pick one)
1. Mirror the sed into the cpp rule:
   `$(WIBO) $(MWCC) -c $(CFLAGS) $(shell sed -n '1,5s|^// flags: ||p' $<) $< -o $@`
2. Allow `#pragma divbyzerocheck` in the lint (source comment in
   `func_00301350.cpp` already names it) and switch the file to the pragma.

After either, force a rebuild of the stale `build/src/.../func_00301350.cpp.o`
(touch the source) and `make -j` must end with six OK.
