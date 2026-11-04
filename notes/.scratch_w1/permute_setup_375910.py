"""One-off: set up build/permute/func_00375910 without an m2c draft (m2c fails here)."""
import subprocess
import sys
from pathlib import Path

ROOT = Path("/home/user/Code/DQ8_w3")
sys.path.insert(0, str(ROOT / "tools"))
import autodecomp as a  # noqa: E402

f = next(x for x in a.functions("SLES_539.74") if x[0] == "func_00375910")
d = ROOT / "build/permute/func_00375910"
d.mkdir(parents=True, exist_ok=True)
(d / "base.c").write_text((ROOT / "src/SLES_539.74/func_00375910.c").read_text())
(d / "target.s").write_text('.include "macro.inc"\n.set noat\n.set noreorder\n.section .text\n' + f[3])
subprocess.run([a.BIN / "mips64-linux-gnu-as", "-EL", "-march=r5900", "-mabi=o64", "-G0",
                "-no-pad-sections", "-I", ROOT / "include", d / "target.s", "-o", d / "target.o"], check=True)
(d / "compile.sh").write_text(
    f'#!/bin/sh\nexec "{a.TC / "wibo"}" "{a.MWCC}" -c {" ".join(a.CFLAGS)} "$1" -o "$3"\n')
(d / "compile.sh").chmod(0o755)
(d / "settings.toml").write_text(
    f'func_name = "func_00375910"\ncompiler_type = "mwcc"\n'
    f'objdump_command = "{a.BIN / "mips64-linux-gnu-objdump"} -drz -m mips:5900"\n')
print("setup ok", d)
