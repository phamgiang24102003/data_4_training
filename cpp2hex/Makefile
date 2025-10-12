# Toolchain settings
RISCV_TOOLCHAIN_DIR = /opt/riscv/bin
GCC         = $(RISCV_TOOLCHAIN_DIR)/riscv32-unknown-elf-gcc
OBJDUMP     = $(RISCV_TOOLCHAIN_DIR)/riscv32-unknown-elf-objdump
OBJCOPY     = $(RISCV_TOOLCHAIN_DIR)/riscv32-unknown-elf-objcopy

# Project structure
SRC_DIR     = .
BUILD_DIR   = .
INCLUDE_DIR = inc
MEM_SIZE    = 1024

# Source files
C_SRC       = $(SRC_DIR)/main.c

# Object and output files
C_OBJ       = $(BUILD_DIR)/main.o
ELF_FILE    = $(BUILD_DIR)/firmware.elf
BIN_FILE    = $(BUILD_DIR)/firmware.bin
HEX_FILE    = $(BUILD_DIR)/firmware.hex
MAP_FILE    = $(BUILD_DIR)/firmware.map

# Build rules
all: $(HEX_FILE) $(DUMP_FILE)

$(HEX_FILE): $(BIN_FILE) makehex.py
	python3 makehex.py $< $(MEM_SIZE) > $@

$(BIN_FILE): $(ELF_FILE)
	$(OBJCOPY) -O binary $< $@

$(ELF_FILE): $(C_OBJ) $(ASM_OBJ)
	$(GCC) -Og -mabi=ilp32 -march=rv32i -ffreestanding -nostdlib -o $@ \
		-Wl,--build-id=none -Wl,-Bstatic -Wl,-Map=$(MAP_FILE) -Wl,--strip-debug \
		$(ASM_OBJ) $(C_OBJ) -lgcc

$(C_OBJ): $(C_SRC)
	$(GCC) -c -I$(INCLUDE_DIR)/ -mabi=ilp32 -march=rv32i -Og --std=c99 -ffreestanding -nostdlib -o $@ $<

clean:
	rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/*.elf $(BUILD_DIR)/*.bin \
	      $(BUILD_DIR)/*.hex $(BUILD_DIR)/*.map
