CC=arm-none-eabi-
project_name=PROJECT
SOC_NAME=-mcpu=cortex-m3
SRC1=$(wildcard *.c)
OPJFILS=$(SRC1:.c=.o)
SRC2=$(wildcard *.s)
ASFILS=$(SRC2:.s=.o)
ALL:$(project_name).pin
	@ echo "=========done========="

%.o:%.s
	$(CC)as.exe $(SOC_NAME) $< -o $@
	
%.o:%.c
	$(CC)gcc.exe -c -g -gdwarf-2 $(SOC_NAME) $< -o $@

$(project_name).elf:$(OPJFILS) $(ASFILS)
	$(CC)ld.exe -T linker_script.ld $(OPJFILS) $(ASFILS) -o $(project_name).elf -Map=map.map
	cp $(project_name).elf $(project_name).axf
	
$(project_name).pin:$(project_name).elf
	$(CC)objcopy.exe -O binary $< $@

CLEAN_ALL:
	rm *.o *.pin *.elf