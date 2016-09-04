################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/CRYPTO_AES/aes_cbc.c" \
"../Sources/CRYPTO_AES/aes_cfb.c" \
"../Sources/CRYPTO_AES/aes_core.c" \
"../Sources/CRYPTO_AES/aes_ctr.c" \
"../Sources/CRYPTO_AES/aes_ecb.c" \
"../Sources/CRYPTO_AES/aes_ofb.c" \
"../Sources/CRYPTO_AES/crypto_aes.c" \
"../Sources/CRYPTO_AES/crypto_aes_conf.c" \

C_SRCS += \
../Sources/CRYPTO_AES/aes_cbc.c \
../Sources/CRYPTO_AES/aes_cfb.c \
../Sources/CRYPTO_AES/aes_core.c \
../Sources/CRYPTO_AES/aes_ctr.c \
../Sources/CRYPTO_AES/aes_ecb.c \
../Sources/CRYPTO_AES/aes_ofb.c \
../Sources/CRYPTO_AES/crypto_aes.c \
../Sources/CRYPTO_AES/crypto_aes_conf.c \

OBJS += \
./Sources/CRYPTO_AES/aes_cbc.o \
./Sources/CRYPTO_AES/aes_cfb.o \
./Sources/CRYPTO_AES/aes_core.o \
./Sources/CRYPTO_AES/aes_ctr.o \
./Sources/CRYPTO_AES/aes_ecb.o \
./Sources/CRYPTO_AES/aes_ofb.o \
./Sources/CRYPTO_AES/crypto_aes.o \
./Sources/CRYPTO_AES/crypto_aes_conf.o \

C_DEPS += \
./Sources/CRYPTO_AES/aes_cbc.d \
./Sources/CRYPTO_AES/aes_cfb.d \
./Sources/CRYPTO_AES/aes_core.d \
./Sources/CRYPTO_AES/aes_ctr.d \
./Sources/CRYPTO_AES/aes_ecb.d \
./Sources/CRYPTO_AES/aes_ofb.d \
./Sources/CRYPTO_AES/crypto_aes.d \
./Sources/CRYPTO_AES/crypto_aes_conf.d \

OBJS_QUOTED += \
"./Sources/CRYPTO_AES/aes_cbc.o" \
"./Sources/CRYPTO_AES/aes_cfb.o" \
"./Sources/CRYPTO_AES/aes_core.o" \
"./Sources/CRYPTO_AES/aes_ctr.o" \
"./Sources/CRYPTO_AES/aes_ecb.o" \
"./Sources/CRYPTO_AES/aes_ofb.o" \
"./Sources/CRYPTO_AES/crypto_aes.o" \
"./Sources/CRYPTO_AES/crypto_aes_conf.o" \

C_DEPS_QUOTED += \
"./Sources/CRYPTO_AES/aes_cbc.d" \
"./Sources/CRYPTO_AES/aes_cfb.d" \
"./Sources/CRYPTO_AES/aes_core.d" \
"./Sources/CRYPTO_AES/aes_ctr.d" \
"./Sources/CRYPTO_AES/aes_ecb.d" \
"./Sources/CRYPTO_AES/aes_ofb.d" \
"./Sources/CRYPTO_AES/crypto_aes.d" \
"./Sources/CRYPTO_AES/crypto_aes_conf.d" \

OBJS_OS_FORMAT += \
./Sources/CRYPTO_AES/aes_cbc.o \
./Sources/CRYPTO_AES/aes_cfb.o \
./Sources/CRYPTO_AES/aes_core.o \
./Sources/CRYPTO_AES/aes_ctr.o \
./Sources/CRYPTO_AES/aes_ecb.o \
./Sources/CRYPTO_AES/aes_ofb.o \
./Sources/CRYPTO_AES/crypto_aes.o \
./Sources/CRYPTO_AES/crypto_aes_conf.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/CRYPTO_AES/aes_cbc.o: ../Sources/CRYPTO_AES/aes_cbc.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/CRYPTO_AES/aes_cbc.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/CRYPTO_AES/aes_cbc.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/CRYPTO_AES/aes_cfb.o: ../Sources/CRYPTO_AES/aes_cfb.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/CRYPTO_AES/aes_cfb.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/CRYPTO_AES/aes_cfb.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/CRYPTO_AES/aes_core.o: ../Sources/CRYPTO_AES/aes_core.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/CRYPTO_AES/aes_core.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/CRYPTO_AES/aes_core.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/CRYPTO_AES/aes_ctr.o: ../Sources/CRYPTO_AES/aes_ctr.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/CRYPTO_AES/aes_ctr.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/CRYPTO_AES/aes_ctr.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/CRYPTO_AES/aes_ecb.o: ../Sources/CRYPTO_AES/aes_ecb.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/CRYPTO_AES/aes_ecb.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/CRYPTO_AES/aes_ecb.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/CRYPTO_AES/aes_ofb.o: ../Sources/CRYPTO_AES/aes_ofb.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/CRYPTO_AES/aes_ofb.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/CRYPTO_AES/aes_ofb.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/CRYPTO_AES/crypto_aes.o: ../Sources/CRYPTO_AES/crypto_aes.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/CRYPTO_AES/crypto_aes.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/CRYPTO_AES/crypto_aes.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/CRYPTO_AES/crypto_aes_conf.o: ../Sources/CRYPTO_AES/crypto_aes_conf.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/CRYPTO_AES/crypto_aes_conf.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/CRYPTO_AES/crypto_aes_conf.o"
	@echo 'Finished building: $<'
	@echo ' '


