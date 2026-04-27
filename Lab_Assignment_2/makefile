#First makefile

# gcc -c main.c -o main.o

# gcc -c register.c -o register.o

# gcc -c stats.c -o stats.o

# gcc main.o register.o stats.o -o app

include sources.mk

BUILD_DIR = build
EXEC = $(BUILD_DIR)/app.elf

LINKER_FILE = stm32f4.ld
CPU = cortex-m4
ARCH = armv7e-m
SPECS = nosys.specs
FPU = fpv4-sp-d16

ARCHFLAGS = -mcpu=$(CPU) -mthumb -march=$(ARCH) -mfloat-abi=hard -mfpu=$(FPU) --specs=$(SPECS)

OBJS := $(addprefix $(BUILD_DIR)/, $(notdir $(SRCS:.c=.o))) #Creating Objects Lists from Sources List

CC = arm-none-eabi-gcc

#Compiler Flags
CFLAGS = -g -O0 -std=c99 -Werror -Wall $(ARCHFLAGS)

#Linker flags
LDFLAGS = -nostdlib -T $(LINKER_FILE)

$(BUILD_DIR)/%.o : src/%.c | $(BUILD_DIR)
	$(CC) -c $< $(CFLAGS) $(INCLUDES) -o $@

$(BUILD_DIR)/%.o : CMSIS/%.c | $(BUILD_DIR)
	$(CC) -c $< $(CFLAGS) $(INCLUDES) -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

.PHONY: build
build : $(EXEC)

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -o $@

.PHONY: flash
flash : 
	openocd -f board/st_nucleo_f4.cfg -c "program $(EXEC) verify reset" -c shutdown

.PHONY: clean
clean :
	rm -rf $(BUILD_DIR)