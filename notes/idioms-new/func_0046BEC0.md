# New idioms from factory matches

## Record-tail stores spelled `out[n].f = ...` with `n++` last, not `rec = &out[n]; n++;`
Sign: a loop tail stores several fields of `out[n]` (stride 12 or any
non-power-of-2) through a temp pointer local; try_match is `CLASS
reorder+register` only in that tail: the original computes the scaled index
`((n<<1)+n)<<2` early but adds the **base** late (`addu $v1,$s7,$v1` after
the first `lw`), and keeps the array slot address in `$a0` while the record
address sits in `$v1`; yours folds base into the address early and reuses
one register for both addresses (score ~13).
Fix: write each store as `out[n].f = ...;` (array subscript, no record temp)
and the increment as a separate statement **after** the stores; CW then
splits index/addr like the original. `rec = &out[n]; n++;` folds the base
early and gets the schedule wrong.
Example: src/MENU/func_0046BEC0.c (also needs the entry slots re-read as
`entries[j]->f` per line, no hoisted pointer local — CW CSEs it otherwise).
Solved: func_0046BEC0 2026-11-04 Qwen factory-6
