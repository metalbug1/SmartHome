################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Generated_Code/BlueLed.c" \
"../Generated_Code/Cpu.c" \
"../Generated_Code/DHT22Pin.c" \
"../Generated_Code/DHT22Timer.c" \
"../Generated_Code/HmTrpUart.c" \
"../Generated_Code/PE_LDD.c" \
"../Generated_Code/RedLed.c" \
"../Generated_Code/TSL2561Timer.c" \
"../Generated_Code/TU1.c" \
"../Generated_Code/TU2.c" \
"../Generated_Code/TU3.c" \
"../Generated_Code/TimerIntLdd1.c" \
"../Generated_Code/TimerIntLdd2.c" \
"../Generated_Code/TimerIntLdd3.c" \
"../Generated_Code/Vectors.c" \
"../Generated_Code/WakeUpTimer.c" \

C_SRCS += \
../Generated_Code/BlueLed.c \
../Generated_Code/Cpu.c \
../Generated_Code/DHT22Pin.c \
../Generated_Code/DHT22Timer.c \
../Generated_Code/HmTrpUart.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/RedLed.c \
../Generated_Code/TSL2561Timer.c \
../Generated_Code/TU1.c \
../Generated_Code/TU2.c \
../Generated_Code/TU3.c \
../Generated_Code/TimerIntLdd1.c \
../Generated_Code/TimerIntLdd2.c \
../Generated_Code/TimerIntLdd3.c \
../Generated_Code/Vectors.c \
../Generated_Code/WakeUpTimer.c \

OBJS += \
./Generated_Code/BlueLed.o \
./Generated_Code/Cpu.o \
./Generated_Code/DHT22Pin.o \
./Generated_Code/DHT22Timer.o \
./Generated_Code/HmTrpUart.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/RedLed.o \
./Generated_Code/TSL2561Timer.o \
./Generated_Code/TU1.o \
./Generated_Code/TU2.o \
./Generated_Code/TU3.o \
./Generated_Code/TimerIntLdd1.o \
./Generated_Code/TimerIntLdd2.o \
./Generated_Code/TimerIntLdd3.o \
./Generated_Code/Vectors.o \
./Generated_Code/WakeUpTimer.o \

C_DEPS += \
./Generated_Code/BlueLed.d \
./Generated_Code/Cpu.d \
./Generated_Code/DHT22Pin.d \
./Generated_Code/DHT22Timer.d \
./Generated_Code/HmTrpUart.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/RedLed.d \
./Generated_Code/TSL2561Timer.d \
./Generated_Code/TU1.d \
./Generated_Code/TU2.d \
./Generated_Code/TU3.d \
./Generated_Code/TimerIntLdd1.d \
./Generated_Code/TimerIntLdd2.d \
./Generated_Code/TimerIntLdd3.d \
./Generated_Code/Vectors.d \
./Generated_Code/WakeUpTimer.d \

OBJS_QUOTED += \
"./Generated_Code/BlueLed.o" \
"./Generated_Code/Cpu.o" \
"./Generated_Code/DHT22Pin.o" \
"./Generated_Code/DHT22Timer.o" \
"./Generated_Code/HmTrpUart.o" \
"./Generated_Code/PE_LDD.o" \
"./Generated_Code/RedLed.o" \
"./Generated_Code/TSL2561Timer.o" \
"./Generated_Code/TU1.o" \
"./Generated_Code/TU2.o" \
"./Generated_Code/TU3.o" \
"./Generated_Code/TimerIntLdd1.o" \
"./Generated_Code/TimerIntLdd2.o" \
"./Generated_Code/TimerIntLdd3.o" \
"./Generated_Code/Vectors.o" \
"./Generated_Code/WakeUpTimer.o" \

C_DEPS_QUOTED += \
"./Generated_Code/BlueLed.d" \
"./Generated_Code/Cpu.d" \
"./Generated_Code/DHT22Pin.d" \
"./Generated_Code/DHT22Timer.d" \
"./Generated_Code/HmTrpUart.d" \
"./Generated_Code/PE_LDD.d" \
"./Generated_Code/RedLed.d" \
"./Generated_Code/TSL2561Timer.d" \
"./Generated_Code/TU1.d" \
"./Generated_Code/TU2.d" \
"./Generated_Code/TU3.d" \
"./Generated_Code/TimerIntLdd1.d" \
"./Generated_Code/TimerIntLdd2.d" \
"./Generated_Code/TimerIntLdd3.d" \
"./Generated_Code/Vectors.d" \
"./Generated_Code/WakeUpTimer.d" \

OBJS_OS_FORMAT += \
./Generated_Code/BlueLed.o \
./Generated_Code/Cpu.o \
./Generated_Code/DHT22Pin.o \
./Generated_Code/DHT22Timer.o \
./Generated_Code/HmTrpUart.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/RedLed.o \
./Generated_Code/TSL2561Timer.o \
./Generated_Code/TU1.o \
./Generated_Code/TU2.o \
./Generated_Code/TU3.o \
./Generated_Code/TimerIntLdd1.o \
./Generated_Code/TimerIntLdd2.o \
./Generated_Code/TimerIntLdd3.o \
./Generated_Code/Vectors.o \
./Generated_Code/WakeUpTimer.o \


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/BlueLed.o: ../Generated_Code/BlueLed.c
	@echo 'Building file: $<'
	@echo 'Executing target #18 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/BlueLed.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/BlueLed.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Cpu.o: ../Generated_Code/Cpu.c
	@echo 'Building file: $<'
	@echo 'Executing target #19 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/Cpu.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/Cpu.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/DHT22Pin.o: ../Generated_Code/DHT22Pin.c
	@echo 'Building file: $<'
	@echo 'Executing target #20 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/DHT22Pin.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/DHT22Pin.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/DHT22Timer.o: ../Generated_Code/DHT22Timer.c
	@echo 'Building file: $<'
	@echo 'Executing target #21 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/DHT22Timer.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/DHT22Timer.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/HmTrpUart.o: ../Generated_Code/HmTrpUart.c
	@echo 'Building file: $<'
	@echo 'Executing target #22 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/HmTrpUart.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/HmTrpUart.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PE_LDD.o: ../Generated_Code/PE_LDD.c
	@echo 'Building file: $<'
	@echo 'Executing target #23 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/PE_LDD.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/PE_LDD.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/RedLed.o: ../Generated_Code/RedLed.c
	@echo 'Building file: $<'
	@echo 'Executing target #24 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/RedLed.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/RedLed.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/TSL2561Timer.o: ../Generated_Code/TSL2561Timer.c
	@echo 'Building file: $<'
	@echo 'Executing target #25 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/TSL2561Timer.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/TSL2561Timer.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/TU1.o: ../Generated_Code/TU1.c
	@echo 'Building file: $<'
	@echo 'Executing target #26 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/TU1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/TU1.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/TU2.o: ../Generated_Code/TU2.c
	@echo 'Building file: $<'
	@echo 'Executing target #27 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/TU2.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/TU2.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/TU3.o: ../Generated_Code/TU3.c
	@echo 'Building file: $<'
	@echo 'Executing target #28 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/TU3.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/TU3.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/TimerIntLdd1.o: ../Generated_Code/TimerIntLdd1.c
	@echo 'Building file: $<'
	@echo 'Executing target #29 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/TimerIntLdd1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/TimerIntLdd1.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/TimerIntLdd2.o: ../Generated_Code/TimerIntLdd2.c
	@echo 'Building file: $<'
	@echo 'Executing target #30 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/TimerIntLdd2.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/TimerIntLdd2.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/TimerIntLdd3.o: ../Generated_Code/TimerIntLdd3.c
	@echo 'Building file: $<'
	@echo 'Executing target #31 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/TimerIntLdd3.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/TimerIntLdd3.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Vectors.o: ../Generated_Code/Vectors.c
	@echo 'Building file: $<'
	@echo 'Executing target #32 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/Vectors.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/Vectors.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/WakeUpTimer.o: ../Generated_Code/WakeUpTimer.c
	@echo 'Building file: $<'
	@echo 'Executing target #33 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/WakeUpTimer.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/WakeUpTimer.o"
	@echo 'Finished building: $<'
	@echo ' '


