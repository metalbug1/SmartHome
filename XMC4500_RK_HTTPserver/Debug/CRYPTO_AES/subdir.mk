################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CRYPTO_AES/aes_cbc.c \
../CRYPTO_AES/aes_cfb.c \
../CRYPTO_AES/aes_core.c \
../CRYPTO_AES/aes_ctr.c \
../CRYPTO_AES/aes_ecb.c \
../CRYPTO_AES/aes_ofb.c \
../CRYPTO_AES/crypto_aes.c \
../CRYPTO_AES/crypto_aes_conf.c 

OBJS += \
./CRYPTO_AES/aes_cbc.o \
./CRYPTO_AES/aes_cfb.o \
./CRYPTO_AES/aes_core.o \
./CRYPTO_AES/aes_ctr.o \
./CRYPTO_AES/aes_ecb.o \
./CRYPTO_AES/aes_ofb.o \
./CRYPTO_AES/crypto_aes.o \
./CRYPTO_AES/crypto_aes_conf.o 

C_DEPS += \
./CRYPTO_AES/aes_cbc.d \
./CRYPTO_AES/aes_cfb.d \
./CRYPTO_AES/aes_core.d \
./CRYPTO_AES/aes_ctr.d \
./CRYPTO_AES/aes_ecb.d \
./CRYPTO_AES/aes_ofb.d \
./CRYPTO_AES/crypto_aes.d \
./CRYPTO_AES/crypto_aes_conf.d 


# Each subdirectory must supply rules for building sources it contributes
CRYPTO_AES/%.o: ../CRYPTO_AES/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"C:\DAVE-3.1.10\ARM-GCC/bin/arm-none-eabi-gcc" -DUC_ID=4503 -DDAVE_CE -I"C:\DAVE-3.1.10\eclipse\/../CMSIS/Include" -I"C:\DAVE-3.1.10\eclipse\/../CMSIS/Infineon/Include" -I"C:\DAVE-3.1.10\ARM-GCC/arm-none-eabi/include" -I"C:\DAVE-3.1.10\eclipse\/../emWin/Start/GUI/inc" -I"C:\DAVE-3.1.10\eclipse\/../CMSIS/Infineon/XMC4500_series/Include" -I"F:\WORK\SmartHome_checkout1\XMC4500_RK_HTTPserver\Dave\Generated\src\ETH004\01_lwIP_Stack\src\include\lwip" -I"F:\WORK\SmartHome_checkout1\XMC4500_RK_HTTPserver\Dave\Generated\src\ETH004\01_lwIP_Stack\src\include\ipv4" -I"F:\WORK\SmartHome_checkout1\XMC4500_RK_HTTPserver\Dave\Generated\src\ETH004\01_lwIP_Stack\src\include" -I"F:\WORK\SmartHome_checkout1\XMC4500_RK_HTTPserver\Dave\Generated\src\ETH004\01_lwIP_Stack\port" -I"F:\WORK\SmartHome_checkout1\XMC4500_RK_HTTPserver\Dave\Generated\inc\DAVESupport" -I"F:\WORK\SmartHome_checkout1\XMC4500_RK_HTTPserver\Dave\Generated\inc\LIBS" -I"F:\WORK\SmartHome_checkout1\XMC4500_RK_HTTPserver\Dave\Generated\inc\MOTORLIBS" -O0 -ffunction-sections -Wall -std=gnu99 -mfloat-abi=softfp -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -g3 -gdwarf-2 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


