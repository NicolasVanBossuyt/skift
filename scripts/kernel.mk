KERNEL_OBJS =  $(patsubst %.c,%.c.o,$(shell find $(SOURCE_FOLDER)/kernel -name '*.c'))
KERNEL_OBJS += $(patsubst %.S, %.S.o,$(shell find $(SOURCE_FOLDER)/kernel -name '*.S'))

kernel.bin: $(KERNEL_OBJS) libc.a
	@echo -n "\n\033[1;37m 🔧 Linking the kernel.\033[0m"
	@$(LD) $(LDFLAGS) -T $(SOURCE_FOLDER)/kernel.ld -o $@ $^
	@$(OBJDUMP) -S $@ > kernel.asm
	@echo "\r\033[0m ✅ "