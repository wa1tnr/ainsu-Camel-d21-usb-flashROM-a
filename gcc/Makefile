################################################################################
# Automatically-generated file. Do not edit!
################################################################################

ifdef SystemRoot
	SHELL = cmd.exe
	MK_DIR = mkdir
else
	ifeq ($(shell uname), Linux)
		MK_DIR = mkdir -p
	endif

	ifeq ($(shell uname | cut -d _ -f 1), CYGWIN)
		MK_DIR = mkdir -p
	endif

	ifeq ($(shell uname | cut -d _ -f 1), MINGW32)
		MK_DIR = mkdir -p
	endif

	ifeq ($(shell uname | cut -d _ -f 1), MINGW64)
		MK_DIR = mkdir -p
	endif
endif

CFLAGS = -Wall -Werror -fmax-errors=3

# List the subdirectories for creating object files
SUB_DIRS +=  \
samd21a/gcc/gcc \
samd21a/gcc \
hpl/usb \
hpl/dmac \
usb/class/cdc/device \
usb/device \
hal/src \
hpl/pm \
hpl/sysctrl \
hal/utils/src \
hpl/sercom \
examples \
hpl/gclk \
src \
src/cf \
src/cf/atsamdx1 \
hpl/core \
usb


# List the object files
OBJS +=  \
hal/src/hal_io.o \
at25df081a.o \
samd21a/gcc/gcc/startup_samd21.o \
usb/class/cdc/device/cdcdf_acm.o \
hal/utils/src/utils_syscalls.o \
hpl/usb/hpl_usb.o \
hal/src/hal_spi_m_sync.o \
hal/src/hal_delay.o \
hpl/pm/hpl_pm.o \
hpl/core/hpl_init.o \
hal/utils/src/utils_list.o \
hpl/core/hpl_core_m0plus_base.o \
hal/utils/src/utils_assert.o \
usb_support.o \
hpl/dmac/hpl_dmac.o \
hpl/sysctrl/hpl_sysctrl.o \
hpl/gclk/hpl_gclk.o \
usb/usb_protocol.o \
hal/src/hal_init.o \
hal/src/hal_usb_device.o \
samd21a/gcc/system_samd21.o \
examples/driver_examples.o \
driver_init.o \
hpl/sercom/hpl_sercom.o \
hal/src/hal_gpio.o \
hal/utils/src/utils_event.o \
hal/src/hal_sleep.o \
atmel_start.o \
usb_cdc_echo_main.o \
usb/device/usbdc.o \
hal/src/hal_atomic.o \
src/cf/forth.o \
main.o

# usb_start.o \
# src/cf/atsamdx1/usb_gateway.o \

OBJS_AS_ARGS +=  \
"hal/src/hal_io.o" \
"at25df081a.o" \
"samd21a/gcc/gcc/startup_samd21.o" \
"usb/class/cdc/device/cdcdf_acm.o" \
"hal/utils/src/utils_syscalls.o" \
"hpl/usb/hpl_usb.o" \
"hal/src/hal_spi_m_sync.o" \
"hal/src/hal_delay.o" \
"hpl/pm/hpl_pm.o" \
"hpl/core/hpl_init.o" \
"hal/utils/src/utils_list.o" \
"hpl/core/hpl_core_m0plus_base.o" \
"hal/utils/src/utils_assert.o" \
"usb_support.o" \
"hpl/dmac/hpl_dmac.o" \
"hpl/sysctrl/hpl_sysctrl.o" \
"hpl/gclk/hpl_gclk.o" \
"usb/usb_protocol.o" \
"hal/src/hal_init.o" \
"hal/src/hal_usb_device.o" \
"samd21a/gcc/system_samd21.o" \
"examples/driver_examples.o" \
"driver_init.o" \
"hpl/sercom/hpl_sercom.o" \
"hal/src/hal_gpio.o" \
"hal/utils/src/utils_event.o" \
"hal/src/hal_sleep.o" \
"atmel_start.o" \
"usb_cdc_echo_main.o" \
"usb/device/usbdc.o" \
"hal/src/hal_atomic.o" \
"src/cf/forth.o" \
"main.o"

# "usb_start.o" \
# "src/cf/atsamdx1/usb_gateway.o" \

# List the dependency files
DEPS := $(OBJS:%.o=%.d)

DEPS_AS_ARGS +=  \
"hal/src/hal_io.d" \
"at25df081a.d" \
"samd21a/gcc/gcc/startup_samd21.d" \
"usb/class/cdc/device/cdcdf_acm.d" \
"hal/utils/src/utils_syscalls.d" \
"hpl/usb/hpl_usb.d" \
"hal/src/hal_spi_m_sync.d" \
"hal/src/hal_delay.d" \
"hpl/pm/hpl_pm.d" \
"hpl/core/hpl_init.d" \
"hal/utils/src/utils_list.d" \
"hpl/core/hpl_core_m0plus_base.d" \
"hal/utils/src/utils_assert.d" \
"usb_support.d" \
"hpl/dmac/hpl_dmac.d" \
"hpl/sysctrl/hpl_sysctrl.d" \
"hpl/gclk/hpl_gclk.d" \
"usb/usb_protocol.d" \
"hal/src/hal_init.d" \
"hal/src/hal_usb_device.d" \
"samd21a/gcc/system_samd21.d" \
"examples/driver_examples.d" \
"driver_init.d" \
"hpl/sercom/hpl_sercom.d" \
"hal/src/hal_gpio.d" \
"hal/utils/src/utils_event.d" \
"hal/src/hal_sleep.d" \
"atmel_start.d" \
"usb_cdc_echo_main.d" \
"usb/device/usbdc.d" \
"hal/src/hal_atomic.d" \
"src/cf/forth.d" \
"main.d"

# "usb_start.d" \
# "src/cf/atsamdx1/usb_gateway.d" \

OUTPUT_FILE_NAME :=AtmelStart
QUOTE := "
OUTPUT_FILE_PATH +=$(OUTPUT_FILE_NAME).elf
OUTPUT_FILE_PATH_AS_ARGS +=$(OUTPUT_FILE_NAME).elf

vpath %.c ../
vpath %.s ../
vpath %.S ../

# All Target
all: $(SUB_DIRS) $(OUTPUT_FILE_PATH)

# Linker target
# -T"../samd21a/gcc/gcc/samd21j18a_flash.ld" \

$(OUTPUT_FILE_PATH): $(OBJS)
	@echo Building target: $@
	@echo Invoking: ARM/GNU Linker
	$(QUOTE)arm-none-eabi-gcc$(QUOTE) -o $(OUTPUT_FILE_NAME).elf $(OBJS_AS_ARGS) -Wl,--start-group -lm -Wl,--end-group -mthumb \
-Wl,-Map="$(OUTPUT_FILE_NAME).map" --specs=nano.specs -Wl,--gc-sections -mcpu=cortex-m0plus \
 \
-T"../samd21a/gcc/gcc/samd21g18a_flash_with_bootloader.ld" \
-L"../samd21a/gcc/gcc"
	@echo Finished building target: $@

	"arm-none-eabi-objcopy" -O binary "$(OUTPUT_FILE_NAME).elf" "$(OUTPUT_FILE_NAME).bin"
	"arm-none-eabi-objcopy" -O ihex -R .eeprom -R .fuse -R .lock -R .signature  \
        "$(OUTPUT_FILE_NAME).elf" "$(OUTPUT_FILE_NAME).hex"
	"arm-none-eabi-objcopy" -j .eeprom --set-section-flags=.eeprom=alloc,load --change-section-lma \
        .eeprom=0 --no-change-warnings -O binary "$(OUTPUT_FILE_NAME).elf" \
        "$(OUTPUT_FILE_NAME).eep" || exit 0
	"arm-none-eabi-objdump" -h -S "$(OUTPUT_FILE_NAME).elf" > "$(OUTPUT_FILE_NAME).lss"
	"arm-none-eabi-size" "$(OUTPUT_FILE_NAME).elf"

	

# Compiler targets



%.o: %.c
	@echo Building file: $<
	@echo ARM/GNU C Compiler
	$(QUOTE)arm-none-eabi-gcc$(QUOTE) -x c -mthumb -DDEBUG -Os -ffunction-sections -mlong-calls -g3 $(CFLAGS)       -c -std=gnu99 \
-D__SAMD21G18A__ -mcpu=cortex-m0plus  \
-I"../" -I"../config" -I"../examples" -I"../src" -I"../src/cf" -I"../src/cf/atsamdx1" -I"../hal/include" -I"../hal/utils/include" -I"../hpl/core" -I"../hpl/dmac" -I"../hpl/gclk" -I"../hpl/pm" -I"../hpl/port" -I"../hpl/sercom" -I"../hpl/sysctrl" -I"../hpl/usb" -I"../hri" -I"../config" -I"../usb" -I"../usb/class/cdc" -I"../usb/class/cdc/device" -I"../usb/device" -I"../CMSIS/Include" -I"../samd21a/include"  \
-MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"  -o "$@" "$<"
	@echo Finished building: $<


%.o: %.s
	@echo Building file: $<
	@echo ARM/GNU Assembler
	$(QUOTE)arm-none-eabi-as$(QUOTE) -x c -mthumb -DDEBUG -Os -ffunction-sections -mlong-calls -g3 $(CFLAGS)       -c -std=gnu99 \
-D__SAMD21G18A__ -mcpu=cortex-m0plus  \
-I"../" -I"../config" -I"../examples" -I"../src" -I"../src/cf" -I"../src/cf/atsamdx1" -I"../hal/include" -I"../hal/utils/include" -I"../hpl/core" -I"../hpl/dmac" -I"../hpl/gclk" -I"../hpl/pm" -I"../hpl/port" -I"../hpl/sercom" -I"../hpl/sysctrl" -I"../hpl/usb" -I"../hri" -I"../config" -I"../usb" -I"../usb/class/cdc" -I"../usb/class/cdc/device" -I"../usb/device" -I"../CMSIS/Include" -I"../samd21a/include"  \
-MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"  -o "$@" "$<"
	@echo Finished building: $<

%.o: %.S
	@echo Building file: $<
	@echo ARM/GNU Preprocessing Assembler
	$(QUOTE)arm-none-eabi-gcc$(QUOTE) -x c -mthumb -DDEBUG -Os -ffunction-sections -mlong-calls -g3 $(CFLAGS)       -c -std=gnu99 \
-D__SAMD21G18A__ -mcpu=cortex-m0plus  \
-I"../" -I"../config" -I"../examples" -I"../src" -I"../src/cf" -I"../src/cf/atsamdx1" -I"../hal/include" -I"../hal/utils/include" -I"../hpl/core" -I"../hpl/dmac" -I"../hpl/gclk" -I"../hpl/pm" -I"../hpl/port" -I"../hpl/sercom" -I"../hpl/sysctrl" -I"../hpl/usb" -I"../hri" -I"../config" -I"../usb" -I"../usb/class/cdc" -I"../usb/class/cdc/device" -I"../usb/device" -I"../CMSIS/Include" -I"../samd21a/include"  \
-MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"  -o "$@" "$<"
	@echo Finished building: $<

###bookmark 
# Detect changes in the dependent files and recompile the respective object files.
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(DEPS)),)
-include $(DEPS)
endif
endif

$(SUB_DIRS):
	$(MK_DIR) "$@"

install:
	@echo -n "[0;1;33;40msleeping 5 seconds.."
	@sleep 5
	@echo    ".  Done.[0m"
	@sleep 1
	# running target '[0;1;34mmake install[0m' now
	@sleep 1
	@echo "[0;1;32;40m./scripts/_bossac_local.sh [0;1;36;40m./AtmelStart.bin[0m"
	@sleep 1
	@./scripts/_bossac_local.sh ./AtmelStart.bin

cleanup:
	@./scripts/cleanup.sh

clean:
	rm -f $(OBJS_AS_ARGS)
	rm -f $(OUTPUT_FILE_PATH)
	rm -f $(DEPS_AS_ARGS)
	rm -f $(OUTPUT_FILE_NAME).a $(OUTPUT_FILE_NAME).hex $(OUTPUT_FILE_NAME).bin \
        $(OUTPUT_FILE_NAME).lss $(OUTPUT_FILE_NAME).eep $(OUTPUT_FILE_NAME).map \
        $(OUTPUT_FILE_NAME).srec
