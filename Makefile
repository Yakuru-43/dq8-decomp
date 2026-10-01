# Dragon Quest VIII (PAL, SLES-53974) decompilation
#   make setup   extract code from DQ8.iso and split it with splat
#   make         rebuild every binary and verify it matches the original

CROSS   ?= $(if $(wildcard .toolchain/usr/bin),.toolchain/usr/bin/)mips64-linux-gnu-
AS      := $(CROSS)as
LD      := $(CROSS)ld
OBJCOPY := $(CROSS)objcopy
PYTHON  ?= .venv/bin/python
WIBO    ?= .toolchain/wibo
MWCC    ?= .toolchain/mwcps2/3.0.1b151-050317/mwccps2.exe

ASFLAGS := -EL -march=r5900 -mabi=o64 -G0 -no-pad-sections -I include
# Pinned by matching code: only builds 145/151 reproduce the game's output.
CFLAGS  := -O3 -nostdinc -stderr -Iinclude -Isrc
LDFLAGS := -EL -m elf32ltsmip --no-check-sections -nostdlib

BUILD    := build
MAIN     := SLES_539.74
OVERLAYS := TITLE SHOP MENU CASINO BATTLE
TARGETS  := $(MAIN) $(OVERLAYS)

# Every asm/*.s file (and later src/*.c) a binary's linker script pulls in.
objs = $(shell grep -o '$(BUILD)/[^ ]*\.o' linker/$(1).ld | sort -u)

OUTPUTS := $(BUILD)/$(MAIN) $(addprefix $(BUILD)/BIN/,$(addsuffix .BIN,$(OVERLAYS)))

.SECONDEXPANSION:

all: $(OUTPUTS)
	@sha1sum -c checksum.sha1

setup: extract split

extract:
	$(PYTHON) tools/extract.py

split:
	$(PYTHON) tools/gen_configs.py
	$(foreach t,$(TARGETS),$(PYTHON) -m splat split config/$(t).yaml &&) true
	# second pass: name functions from the disassembly, then re-split with the names
	$(PYTHON) tools/symbolize.py
	$(foreach t,$(TARGETS),$(PYTHON) -m splat split config/$(t).yaml &&) true
	$(PYTHON) tools/postsplit.py

clean:
	rm -rf $(BUILD)

distclean: clean
	rm -rf asm linker extract iso include/macro.inc

$(BUILD)/%.s.o: %.s
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) -o $@ $<

# splat leaves out bss files when it finds no symbols in them (bss is NOLOAD).
$(BUILD)/%.bss.s.o: $$(wildcard %.bss.s)
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) -o $@ $(or $<,/dev/null)

$(BUILD)/%.cpp.o: %.cpp
	@mkdir -p $(dir $@)
	$(WIBO) $(MWCC) -c $(CFLAGS) $< -o $@
	$(PYTHON) tools/set_abi.py $@

# a `// flags: ...` line near the top of a source file adds per-file flags
$(BUILD)/%.c.o: %.c
	@mkdir -p $(dir $@)
	$(WIBO) $(MWCC) -c $(CFLAGS) $(shell sed -n '1,5s|^// flags: ||p' $<) $< -o $@
	$(PYTHON) tools/set_abi.py $@

$(BUILD)/%.bin.o: %.bin
	@mkdir -p $(dir $@)
	printf '.section .data\n.incbin "%s"\n' $< | $(AS) $(ASFLAGS) -o $@

# Main executable
$(BUILD)/$(MAIN).elf: $(call objs,$(MAIN)) linker/$(MAIN).ld
	$(LD) $(LDFLAGS) -Map $(BUILD)/$(MAIN).map -T linker/$(MAIN).ld \
	    -T linker/$(MAIN)_undefined_funcs_auto.txt -T linker/$(MAIN)_undefined_syms_auto.txt -o $@

$(BUILD)/$(MAIN): $(BUILD)/$(MAIN).elf
	$(OBJCOPY) -O binary $< $@.payload
	$(PYTHON) tools/stitch.py $@.payload extract/$(MAIN).head extract/$(MAIN).tail $@

# Overlays: symbols in the main executable come from undefined_*_auto.txt
$(BUILD)/%.elf: $$(call objs,%) linker/%.ld
	$(LD) $(LDFLAGS) -Map $(BUILD)/$*.map -T linker/$*.ld \
	    -T linker/$*_undefined_funcs_auto.txt -T linker/$*_undefined_syms_auto.txt -o $@

$(BUILD)/BIN/%.BIN: $(BUILD)/%.elf
	@mkdir -p $(dir $@)
	$(OBJCOPY) -O binary -j .$(shell echo $* | tr A-Z a-z) $< $(BUILD)/$*.payload
	$(PYTHON) tools/stitch.py $(BUILD)/$*.payload extract/$*.head - $@

.PHONY: all setup extract split clean distclean
.SECONDARY:
