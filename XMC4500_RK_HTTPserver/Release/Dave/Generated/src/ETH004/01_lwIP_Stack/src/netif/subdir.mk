################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Dave/Generated/src/ETH004/01_lwIP_Stack/src/netif/etharp.c \
../Dave/Generated/src/ETH004/01_lwIP_Stack/src/netif/ethernetif.c \
../Dave/Generated/src/ETH004/01_lwIP_Stack/src/netif/loopif.c \
../Dave/Generated/src/ETH004/01_lwIP_Stack/src/netif/slipif.c 

OBJS += \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/netif/etharp.o \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/netif/ethernetif.o \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/netif/loopif.o \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/netif/slipif.o 

C_DEPS += \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/netif/etharp.d \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/netif/ethernetif.d \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/netif/loopif.d \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/netif/slipif.d 


# Each subdirectory must supply rules for building sources it contributes
Dave/Generated/src/ETH004/01_lwIP_Stack/src/netif/%.o: ../Dave/Generated/src/ETH004/01_lwIP_Stack/src/netif/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"C:\DAVE-3.1.10\ARM-GCC/bin/arm-none-eabi-gcc" -DUC_ID=4503 -DDAVE_CE -I"C:\DAVE-3.1.10\eclipse\/../CMSIS/Include" -I"C:\DAVE-3.1.10\eclipse\/../CMSIS/Infineon/Include" -I"C:\DAVE-3.1.10\ARM-GCC/arm-none-eabi/include" -I"C:\DAVE-3.1.10\eclipse\/../emWin/Start/GUI/inc" -I"C:\DAVE-3.1.10\eclipse\/../CMSIS/Infineon/XMC4500_series/Include" -I"F:\WORK\SmartHome_checkout1\XMC4500_RK_HTTPserver\Dave\Generated\src\ETH004\01_lwIP_Stack\src\include\lwip" -I"F:\WORK\SmartHome_checkout1\XMC4500_RK_HTTPserver\Dave\Generated\src\ETH004\01_lwIP_Stack\src\include\ipv4" -I"F:\WORK\SmartHome_checkout1\XMC4500_RK_HTTPserver\Dave\Generated\src\ETH004\01_lwIP_Stack\src\include" -I"F:\WORK\SmartHome_checkout1\XMC4500_RK_HTTPserver\Dave\Generated\src\ETH004\01_lwIP_Stack\port" -I"F:\WORK\SmartHome_checkout1\XMC4500_RK_HTTPserver\Dave\Generated\inc\DAVESupport" -I"F:\WORK\SmartHome_checkout1\XMC4500_RK_HTTPserver\Dave\Generated\inc\LIBS" -I"F:\WORK\SmartHome_checkout1\XMC4500_RK_HTTPserver\Dave\Generated\inc\MOTORLIBS" -Os -ffunction-sections -Wall -std=gnu99 -mfloat-abi=softfp -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


