
# Single user cpp file containing game code to build into firmware
PROJECT = Src/32blitgame.cpp
# Set the output filename to match the user code filename
TARGET = $(basename $(notdir $(PROJECT)))
DEBUG = 0
OPT = -Os
BUILD_DIR = build

# C sources
C_SOURCES =  \
Src/main.c \
Src/stm32h7xx_it.c \
Src/stm32h7xx_hal_msp.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_adc.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_adc_ex.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_cortex.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dac.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dac_ex.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_hrtim.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_smbus.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_ltdc.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_ltdc_ex.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dsi.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_qspi.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_spi.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_spi_ex.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim_ex.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc_ex.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash_ex.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_gpio.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_hsem.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma_ex.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_mdma.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr_ex.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c_ex.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_exti.c \
Src/system_stm32h7xx.c \
Src/user_diskio.c \
Src/fatfs.c \
Middlewares/Third_Party/FatFs/src/diskio.c \
Middlewares/Third_Party/FatFs/src/ff.c \
Middlewares/Third_Party/FatFs/src/ff_gen_drv.c \
Middlewares/Third_Party/FatFs/src/option/syscall.c \
Src/gpio.c \
Src/adc.c \
Src/dac.c \
Src/debug.c \
Src/dma.c \
Src/hrtim.c \
Src/i2c.c \
Src/ltdc.c \
Src/quadspi.c \
Src/spi.c \
Src/sys.c \
Src/tim.c \
Src/usb_otg.c \
Src/32blit.c

# ASM sources
ASM_SOURCES =  \
startup_stm32h750xx.s


PREFIX := arm-none-eabi-
# The gcc compiler bin path can be either defined in make command via GCC_PATH variable (> make GCC_PATH=xxx)
# either it can be added to the PATH environment variable.
ifdef GCC_PATH
CC = $(GCC_PATH)/$(PREFIX)g++
AS = $(GCC_PATH)/$(PREFIX)g++ -x assembler-with-cpp
CP = $(GCC_PATH)/$(PREFIX)objcopy
SZ = $(GCC_PATH)/$(PREFIX)size
else
CC = $(PREFIX)g++
AS = $(PREFIX)g++ -x assembler-with-cpp
CP = $(PREFIX)objcopy
SZ = $(PREFIX)size
endif
HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S


CPU = -mcpu=cortex-m7
FPU = -mfpu=fpv5-d16
FLOAT-ABI = -mfloat-abi=hard
MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI) -specs=nosys.specs -fpermissive

# macros for gcc
AS_DEFS =

# C defines
C_DEFS =  \
-DUSE_HAL_DRIVER \
-DSTM32H750xx \
-DUSE_USB_HS

# AS includes
AS_INCLUDES =

# C includes
C_INCLUDES =  \
-IInc \
-IDrivers/STM32H7xx_HAL_Driver/Inc \
-IDrivers/STM32H7xx_HAL_Driver/Inc/Legacy \
-IDrivers/CMSIS/Device/ST/STM32H7xx/Include \
-IDrivers/CMSIS/Include \
-IDrivers/CMSIS/Include \
-IMiddlewares/Third_Party/FatFs/src \
-I../32blit \
-I$(dir $(PROJECT))

# compile gcc flags
ASFLAGS = $(MCU) $(AS_DEFS) $(AS_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

# TODO: fix warnings that we're suppressing with -Wno-write-strings
CFLAGS = $(MCU) $(C_DEFS) $(C_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections -Wattributes -Wdouble-promotion -Wno-unused-variable -Wno-write-strings -std=c++14

ifeq ($(DEBUG), 1)
CFLAGS += -g -gdwarf-2
endif

# Generate dependency information
CFLAGS += -MMD -MP -MF"$(@:%.o=%.d)"

# link script
LDSCRIPT = STM32H750VBTx_FLASH.ld

# libraries
LIBS =  -l32blit -lc -lm -lnosys #-llua
LIBDIR = -L../32blit/build.32blit-stm32 #-L../lua
LDFLAGS = $(MCU) -specs=nano.specs -T$(LDSCRIPT) -static $(LIBDIR) -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--cref -Wl,--gc-sections

# default action: build all
all: lib32blit-stm32 $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex $(BUILD_DIR)/$(TARGET).bin

# list of objects
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))

OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(PROJECT:.cpp=.o)))
vpath %.cpp $(sort $(dir $(PROJECT)))

# list of ASM program objects
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(ASM_SOURCES:.s=.o)))
vpath %.s $(sort $(dir $(ASM_SOURCES)))

lib32blit-stm32:
	make -C ../32blit

$(BUILD_DIR)/%.o: %.cpp Makefile | $(BUILD_DIR)
	$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.cpp=.lst)) $< -o $@

$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR)
	$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@

$(BUILD_DIR)/%.o: %.s Makefile | $(BUILD_DIR)
	$(AS) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS) Makefile
	$(CC) $(LDFLAGS) $(OBJECTS) $(LIBS) -o $@
	$(SZ) $@

$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(HEX) $< $@

$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(BIN) $< $@

$(BUILD_DIR):
	mkdir $@

clean:
	-rm -fR $(BUILD_DIR)

flash:
	openocd -f flash.cfg

winflash:
	../openocd/bin/openocd.exe -f flash.cfg

-include $(wildcard $(BUILD_DIR)/*.d)