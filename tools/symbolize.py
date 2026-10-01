#!/usr/bin/env python3
"""Name functions automatically from evidence in the disassembly.

Writes config/symbol_addrs_<binary>_auto.txt (regenerated each run; put manual
names in config/symbol_addrs_<binary>.txt, which take precedence).

Rules, both conservative:
  syscall  4-instruction EE kernel stubs `addiu $v1,$zero,N; syscall; jr $ra; nop`.
           Negative N is the interrupt-context variant (i-prefixed).
  string   A string starting with "<name>:" or "<name>()" names the function using
           it, e.g. "sceDbcInitSocket: rpc error". Applied only when the function
           uses exactly one such name and no other function uses that name.
           "error: <name>" strings are ignored: they are printed by the caller
           of the function that failed.
"""
import re
import sys
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
BINARIES = ["SLES_539.74", "TITLE", "SHOP", "MENU", "CASINO", "BATTLE"]

# EE kernel syscalls (Sony libkernl names)
SYSCALLS = {
    0x01: "ResetEE", 0x02: "SetGsCrt", 0x04: "Exit", 0x06: "LoadExecPS2",
    0x07: "ExecPS2", 0x10: "AddIntcHandler", 0x11: "RemoveIntcHandler",
    0x12: "AddDmacHandler", 0x13: "RemoveDmacHandler", 0x14: "EnableIntc",
    0x15: "DisableIntc", 0x16: "EnableDmac", 0x17: "DisableDmac",
    0x20: "CreateThread",
    0x21: "DeleteThread", 0x22: "StartThread", 0x23: "ExitThread",
    0x24: "ExitDeleteThread", 0x25: "TerminateThread",
    0x27: "DisableDispatchThread", 0x28: "EnableDispatchThread",
    0x29: "ChangeThreadPriority", 0x2B: "RotateThreadReadyQueue",
    0x2D: "ReleaseWaitThread", 0x2F: "GetThreadId", 0x30: "ReferThreadStatus",
    0x32: "SleepThread", 0x33: "WakeupThread", 0x35: "CancelWakeupThread",
    0x37: "SuspendThread", 0x39: "ResumeThread", 0x3C: "SetupThread",
    0x3D: "SetupHeap", 0x3E: "EndOfHeap", 0x40: "CreateSema",
    0x41: "DeleteSema", 0x42: "SignalSema", 0x44: "WaitSema", 0x45: "PollSema",
    0x47: "ReferSemaStatus", 0x4A: "SetOsdConfigParam", 0x4B: "GetOsdConfigParam", 0x4C: "GetGsHParam",
    0x4D: "GetGsVParam", 0x4E: "SetGsHParam", 0x4F: "SetGsVParam",
    0x64: "FlushCache", 0x70: "GsGetIMR", 0x71: "GsPutIMR",
    0x73: "SetVSyncFlag", 0x74: "SetSyscall", 0x76: "sceSifDmaStat",
    0x77: "sceSifSetDma", 0x78: "sceSifSetDChain", 0x79: "sceSifSetReg",
    0x7A: "sceSifGetReg", 0x7B: "ExecOSD", 0x7C: "Deci2Call",
    0x7D: "PSMode", 0x7E: "MachineType", 0x7F: "GetMemorySize",
    0xFC: "_SetAlarm", 0xFD: "_ReleaseAlarm",
}
# Negative numbers: interrupt-context variants
SYSCALLS_NEG = {
    0x1A: "iEnableIntc", 0x1B: "iDisableIntc", 0x1C: "iEnableDmac",
    0x1D: "iDisableDmac", 0x26: "iTerminateThread", 0x2A: "iChangeThreadPriority",
    0x2C: "iRotateThreadReadyQueue", 0x2E: "iReleaseWaitThread",
    0x31: "iReferThreadStatus", 0x34: "iWakeupThread", 0x36: "iCancelWakeupThread",
    0x38: "iSuspendThread", 0x3A: "iResumeThread", 0x43: "iSignalSema",
    0x46: "iPollSema", 0x48: "iReferSemaStatus", 0x70: "iGsGetIMR",
    0x71: "iGsPutIMR", 0x76: "isceSifDmaStat", 0x77: "isceSifSetDma",
    0x78: "isceSifSetDChain", 0xFE: "_iSetAlarm", 0xFF: "_iReleaseAlarm",
}
# Sony libkernl has a second stub for these syscalls
SECOND_STUB = {"AddIntcHandler": "AddIntcHandler2", "AddDmacHandler": "AddDmacHandler2"}

GLABEL = re.compile(r"^glabel (\w+)")
INSN = re.compile(r"^\s+/\* \w+ ([0-9A-F]{8}) [0-9A-F]{8} \*/\s+(.*)$")
SYMREF = re.compile(r"%(?:hi|lo|gp_rel)\((D_[0-9A-F]{8})\)")
DLABEL = re.compile(r"^dlabel (D_[0-9A-F]{8})")
ASCIZ = re.compile(r'^\s+/\*.*\*/ \.asciz "(.*)"')
# "<name>:" / "<name>()" / "error : <Class::Method>()" at the start of a string
SELF_NAME = re.compile(r"^\s*([A-Za-z_]\w*(?:::~?\w+)?)\s*(?:\(\))?\s*:\s")
CLASS_NAME = re.compile(r"^\s*error\s*:\s*([A-Za-z_]\w*::~?\w+)\s*\(")
NOT_NAMES = {"error", "ERROR", "Error", "warning", "WARNING", "Warning", "n", "Note"}


def strings_of(binary):
    out = {}
    for f in (ROOT / "asm" / binary / "data").glob("*.s"):
        label = None
        for line in f.read_text(errors="replace").splitlines():
            m = DLABEL.match(line)
            if m:
                label = m.group(1)
                continue
            m = ASCIZ.match(line)
            if m and label and label not in out:
                out[label] = m.group(1)
    return out


def functions_of(binary):
    """Yield (name, vram, [instruction text])."""
    for f in sorted((ROOT / "asm" / binary).glob("*.s")):
        name = None
        for line in f.read_text(errors="replace").splitlines():
            m = GLABEL.match(line)
            if m:
                if name:
                    yield name, vram, insns
                name, vram, insns = m.group(1), None, []
                continue
            m = INSN.match(line)
            if m and name:
                if vram is None:
                    vram = int(m.group(1), 16)
                insns.append(m.group(2).split("#")[0].strip())
        if name:
            yield name, vram, insns


def syscall_name(insns):
    if len(insns) != 4:
        return None
    m = re.fullmatch(r"addiu\s+\$v1, \$zero, (-?0x[0-9A-F]+)", insns[0])
    if not m or not insns[1].startswith("syscall") or not re.fullmatch(r"jr\s+\$ra", insns[2]):
        return None
    n = int(m.group(1), 16)
    name = (SYSCALLS_NEG if n < 0 else SYSCALLS).get(abs(n))
    return name or f"syscall_{'m' if n < 0 else ''}{abs(n):02X}"


def string_name(s):
    m = CLASS_NAME.match(s) or SELF_NAME.match(s)
    if not m or m.group(1) in NOT_NAMES:
        return None
    name = m.group(1)
    if "::" not in name and not name.startswith(("sce", "_sce", "isce")):
        return None  # only trust SDK-style or Class::Method names
    return name.replace("::~", "::dtor_").replace("::", "_")


def manual_addrs(binary):
    path = ROOT / "config" / f"symbol_addrs_{binary}.txt"
    text = path.read_text() if path.exists() else ""
    return {int(a, 16) for a in re.findall(r"=\s*(0x[0-9A-Fa-f]+)\s*;", text)}


def symbolize(binary):
    strings = strings_of(binary)
    manual = manual_addrs(binary)
    named = {}
    users = defaultdict(set)      # candidate name -> functions using it
    cands = {}                    # function -> set of candidate names
    vrams = {}
    for func, vram, insns in functions_of(binary):
        if vram is None or vram in manual:
            continue
        vrams[func] = vram
        sc = syscall_name(insns)
        if sc:
            named[func] = (sc, "syscall")
            continue
        names = set()
        for ins in insns:
            for ref in SYMREF.findall(ins):
                n = string_name(strings.get(ref, ""))
                if n:
                    names.add(n)
        if names:
            cands[func] = names
            for n in names:
                users[n].add(func)
    taken = {n for n, _ in named.values()}
    for func, names in cands.items():
        if len(names) == 1:
            (n,) = names
            if len(users[n]) == 1 and n not in taken:
                named[func] = (n, "string")
                taken.add(n)
    # syscall stubs repeat outside libkernl's table: suffix those with their address
    seen = defaultdict(int)
    lines = [f"// Generated by tools/symbolize.py - do not edit, put manual names in symbol_addrs_{binary}.txt"]
    for kind in ("syscall", "string"):
        funcs = sorted((f for f in named if named[f][1] == kind), key=vrams.get)
        if funcs:
            lines.append(f"\n// --- named via {kind} rule ---")
        for func in funcs:
            n = named[func][0]
            seen[n] += 1
            if seen[n] == 2 and n in SECOND_STUB:
                n = SECOND_STUB[n]
            elif seen[n] > 1:
                n = f"{n}_{vrams[func]:X}"
            lines.append(f"{n} = 0x{vrams[func]:X}; // type:func")
    (ROOT / "config" / f"symbol_addrs_{binary}_auto.txt").write_text("\n".join(lines) + "\n")
    return named


if __name__ == "__main__":
    for b in sys.argv[1:] or BINARIES:
        named = symbolize(b)
        kinds = defaultdict(int)
        for _, why in named.values():
            kinds[why] += 1
        print(f"{b:12} {len(named):4} named  " + "  ".join(f"{k}={v}" for k, v in sorted(kinds.items())))
