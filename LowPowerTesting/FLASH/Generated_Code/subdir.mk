################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Generated_Code/AS1.c" \
"../Generated_Code/Bit1.c" \
"../Generated_Code/Cpu.c" \
"../Generated_Code/DHT22Pin.c" \
"../Generated_Code/DHT22Timer.c" \
"../Generated_Code/PE_LDD.c" \
"../Generated_Code/TSL2561Timer.c" \
"../Generated_Code/TU1.c" \
"../Generated_Code/TU2.c" \
"../Generated_Code/TimerIntLdd1.c" \
"../Generated_Code/TimerIntLdd2.c" \
"../Generated_Code/Vectors.c" \

C_SRCS += \
../Generated_Code/AS1.c \
../Generated_Code/Bit1.c \
../Generated_Code/Cpu.c \
../Generated_Code/DHT22Pin.c \
../Generated_Code/DHT22Timer.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/TSL2561Timer.c \
../Generated_Code/TU1.c \
../Generated_Code/TU2.c \
../Generated_Code/TimerIntLdd1.c \
../Generated_Code/TimerIntLdd2.c \
../Generated_Code/Vectors.c \

OBJS += \
./Generated_Code/AS1.o \
./Generated_Code/Bit1.o \
./Generated_Code/Cpu.o \
./Generated_Code/DHT22Pin.o \
./Generated_Code/DHT22Timer.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/TSL2561Timer.o \
./Generated_Code/TU1.o \
./Generated_Code/TU2.o \
./Generated_Code/TimerIntLdd1.o \
./Generated_Code/TimerIntLdd2.o \
./Generated_Code/Vectors.o \

C_DEPS += \
./Generated_Code/AS1.d \
./Generated_Code/Bit1.d \
./Generated_Code/Cpu.d \
./Generated_Code/DHT22Pin.d \
./Generated_Code/DHT22Timer.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/TSL2561Timer.d \
./Generated_Code/TU1.d \
./Generated_Code/TU2.d \
./Generated_Code/TimerIntLdd1.d \
./Generated_Code/TimerIntLdd2.d \
./Generated_Code/Vectors.d \

OBJS_QUOTED += \
"./Generated_Code/AS1.o" \
"./Generated_Code/Bit1.o" \
"./Generated_Code/Cpu.o" \
"./Generated_Code/DHT22Pin.o" \
"./Generated_Code/DHT22Timer.o" \
"./Generated_Code/PE_LDD.o" \
"./Generated_Code/TSL2561Timer.o" \
"./Generated_Code/TU1.o" \
"./Generated_Code/TU2.o" \
"./Generated_Code/TimerIntLdd1.o" \
"./Generated_Code/TimerIntLdd2.o" \
"./Generated_Code/Vectors.o" \

C_DEPS_QUOTED += \
"./Generated_Code/AS1.d" \
"./Generated_Code/Bit1.d" \
"./Generated_Code/Cpu.d" \
"./Generated_Code/DHT22Pin.d" \
"./Generated_Code/DHT22Timer.d" \
"./Generated_Code/PE_LDD.d" \
"./Generated_Code/TSL2561Timer.d" \
"./Generated_Code/TU1.d" \
"./Generated_Code/TU2.d" \
"./Generated_Code/TimerIntLdd1.d" \
"./Generated_Code/TimerIntLdd2.d" \
"./Generated_Code/Vectors.d" \

OBJS_OS_FORMAT += \
./Generated_Code/AS1.o \
./Generated_Code/Bit1.o \
./Generated_Code/Cpu.o \
./Generated_Code/DHT22Pin.o \
./Generated_Code/DHT22Timer.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/TSL2561Timer.o \
./Generated_Code/TU1.o \
./Generated_Code/TU2.o \
./Generated_Code/TimerIntLdd1.o \
./Generated_Code/TimerIntLdd2.o \
./Generated_Code/Vectors.o \


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/AS1.o: ../Generated_Code/AS1.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/AS1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/AS1.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Bit1.o: ../Generated_Code/Bit1.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/Bit1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/Bit1.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Cpu.o: ../Generated_Code/Cpu.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/Cpu.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/Cpu.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/DHT22Pin.o: ../Generated_Code/DHT22Pin.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/DHT22Pin.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/DHT22Pin.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/DHT22Timer.o: ../Generated_Code/DHT22Timer.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/DHT22Timer.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/DHT22Timer.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PE_LDD.o: ../Generated_Code/PE_LDD.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/PE_LDD.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/PE_LDD.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/TSL2561Timer.o: ../Generated_Code/TSL2561Timer.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/TSL2561Timer.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/TSL2561Timer.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/TU1.o: ../Generated_Code/TU1.c
	@echo 'Building file: $<'
	@echo 'Executing target #16 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/TU1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/TU1.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/TU2.o: ../Generated_Code/TU2.c
	@echo 'Building file: $<'
	@echo 'Executing target #17 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/TU2.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/TU2.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/TimerIntLdd1.o: ../Generated_Code/TimerIntLdd1.c
	@echo 'Building file: $<'
	@echo 'Executing target #18 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/TimerIntLdd1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/TimerIntLdd1.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/TimerIntLdd2.o: ../Generated_Code/TimerIntLdd2.c
	@echo 'Building file: $<'
	@echo 'Executing target #19 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/TimerIntLdd2.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/TimerIntLdd2.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Vectors.o: ../Generated_Code/Vectors.c
	@echo 'Building file: $<'
	@echo 'Executing target #20 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/Vectors.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/Vectors.o"
	@echo 'Finished building: $<'
	@echo ' '


