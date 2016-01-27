################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/ipv4/autoip.c \
../Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/ipv4/icmp.c \
../Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/ipv4/igmp.c \
../Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/ipv4/inet.c \
../Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/ipv4/inet_chksum.c \
../Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/ipv4/ip.c \
../Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/ipv4/ip_addr.c \
../Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/ipv4/ip_frag.c 

OBJS += \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/ipv4/autoip.o \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/ipv4/icmp.o \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/ipv4/igmp.o \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/ipv4/inet.o \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/ipv4/inet_chksum.o \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/ipv4/ip.o \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/ipv4/ip_addr.o \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/ipv4/ip_frag.o 

C_DEPS += \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/ipv4/autoip.d \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/ipv4/icmp.d \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/ipv4/igmp.d \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/ipv4/inet.d \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/ipv4/inet_chksum.d \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/ipv4/ip.d \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/ipv4/ip_addr.d \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/ipv4/ip_frag.d 


# Each subdirectory must supply rules for building sources it contributes
Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/ipv4/%.o: ../Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/ipv4/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"C:\DAVE-3.1.10\ARM-GCC/bin/arm-none-eabi-gcc" -DUC_ID=4503 -DDAVE_CE -I"C:\DAVE-3.1.10\eclipse\/../CMSIS/Include" -I"C:\DAVE-3.1.10\eclipse\/../CMSIS/Infineon/Include" -I"C:\DAVE-3.1.10\ARM-GCC/arm-none-eabi/include" -I"C:\DAVE-3.1.10\eclipse\/../emWin/Start/GUI/inc" -I"C:\DAVE-3.1.10\eclipse\/../CMSIS/Infineon/XMC4500_series/Include" -I"F:\WORK\SmartHome_checkout1\XMC4500_RK_HTTPserver\Dave\Generated\src\ETH004\01_lwIP_Stack\src\include\lwip" -I"F:\WORK\SmartHome_checkout1\XMC4500_RK_HTTPserver\Dave\Generated\src\ETH004\01_lwIP_Stack\src\include\ipv4" -I"F:\WORK\SmartHome_checkout1\XMC4500_RK_HTTPserver\Dave\Generated\src\ETH004\01_lwIP_Stack\src\include" -I"F:\WORK\SmartHome_checkout1\XMC4500_RK_HTTPserver\Dave\Generated\src\ETH004\01_lwIP_Stack\port" -I"F:\WORK\SmartHome_checkout1\XMC4500_RK_HTTPserver\Dave\Generated\inc\DAVESupport" -I"F:\WORK\SmartHome_checkout1\XMC4500_RK_HTTPserver\Dave\Generated\inc\LIBS" -I"F:\WORK\SmartHome_checkout1\XMC4500_RK_HTTPserver\Dave\Generated\inc\MOTORLIBS" -Os -ffunction-sections -Wall -std=gnu99 -mfloat-abi=softfp -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


