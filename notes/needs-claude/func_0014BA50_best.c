CLASS structural score=22 (22 words differ, 148 vs 148 bytes)  [best attempt 2026-11-05;
previous best (2026-10-30): CLASS structural score=41, 164 vs 148]

Best attempt: q hoisted before a ternary whose POS arm is written first.

void func_0014BA50(f32 *arg0, u16 *arg1, f32 *arg2) {
    s32 raw;
    s32 q;
    f32 f;

    raw = arg1[0];
    q = ((u32)raw >> 1) | (raw & 1);
    f = (raw >= 0) ? (f32)raw : (f32)q + (f32)q;
    arg0[0] = 3.0517578125e-05f * f * arg2[0];

    raw = arg1[1];
    q = ((u32)raw >> 1) | (raw & 1);
    f = (raw >= 0) ? (f32)raw : (f32)q + (f32)q;
    arg0[1] = 3.0517578125e-05f * f * arg2[1];
}

Layout this form achieves (mine, per half): [test][NEG inline][b join with
add.s in delay][POS inline][join] — the MIRROR of the original
([test][POS][b join with cvt in delay][NEG falls into join]). The register
leftovers may all be downstream of that mirror plus the q hoist: lhu $t0
(mine) vs $v1, `bltz` vs `bltzl`, `or $v1,$a3,$v1` vs in-place
`or $a3,$a3,$v1`, cvt to $f0 vs $f2, add.s $f2,$f0,$f0 vs $f2,$f2,$f2, and
srl+andi above the test vs srl in the delay slot + andi inside the block.
