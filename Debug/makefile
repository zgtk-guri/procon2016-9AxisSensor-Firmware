################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include mbed/TARGET_LPC1114/TOOLCHAIN_GCC_CR/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: procon2016-9axisSensor.axf

# Tool invocations
procon2016-9axisSensor.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU C++ Linker'
	arm-none-eabi-c++ -nostdlib -L"C:\Users\takah_000\Documents\GitHub\procon2016-9AxisSensor-Firmware" -L"C:\Users\takah_000\Documents\GitHub\procon2016-9AxisSensor-Firmware\mbed" -L"C:\Users\takah_000\Documents\GitHub\procon2016-9AxisSensor-Firmware\mbed\TARGET_LPC1114" -L"C:\Users\takah_000\Documents\GitHub\procon2016-9AxisSensor-Firmware\mbed\TARGET_LPC1114\TARGET_NXP" -L"C:\Users\takah_000\Documents\GitHub\procon2016-9AxisSensor-Firmware\mbed\TARGET_LPC1114\TARGET_NXP\TARGET_LPC11XX_11CXX" -L"C:\Users\takah_000\Documents\GitHub\procon2016-9AxisSensor-Firmware\mbed\TARGET_LPC1114\TARGET_NXP\TARGET_LPC11XX_11CXX\TARGET_LPC11XX" -L"C:\Users\takah_000\Documents\GitHub\procon2016-9AxisSensor-Firmware\mbed\TARGET_LPC1114\TOOLCHAIN_GCC_CR" -Xlinker -Map="procon2016-9axisSensor.map" -Xlinker --gc-sections -mcpu=cortex-m0 -mthumb -T "C:\Users\takah_000\Documents\GitHub\procon2016-9AxisSensor-Firmware\mbed\TARGET_LPC1114\TOOLCHAIN_GCC_CR\LPC1114.ld" -o "procon2016-9axisSensor.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(EXECUTABLES)$(C_UPPER_DEPS)$(CXX_DEPS)$(OBJS)$(CPP_DEPS)$(C_DEPS) procon2016-9axisSensor.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "procon2016-9axisSensor.axf"; arm-none-eabi-objcopy -O binary "procon2016-9axisSensor.axf" "procon2016-9axisSensor.bin" ; # checksum -p LPC1114FN_102 -d "procon2016-9axisSensor.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
