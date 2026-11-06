# needs-claude: func_001A2AA0

CLASS structural score=24 expected — exact **twin of func_001A2990** (see
notes/needs-claude/func_001A2990.md for the analysis and the best C); the asm
at 0x1A2AA0..0x1A2B20 is identical word-for-word except `addiu $v1, $zero,
0x25` instead of `0x27` (item type 37 instead of 39). Same struct: items
0x00/count 0x04, head 0x38, tail 0x3C; item stride 0x50, next 0x4C.

Best attempt not run here (session clock cut off 4 min after claiming; the
draft from the twin applies with `item->type = 37;`). Remaining diffs to
solve: the three branch-likely encodings listed in the twin's note (loop
found test `beql`+store in taken-delay-slot, the `if (item)` guard with the
redundant `daddu` peeled into the delay slot, and `if (!head) head = item`
as `beql`+delay-store while the tail check stays `beqz+nop`).
