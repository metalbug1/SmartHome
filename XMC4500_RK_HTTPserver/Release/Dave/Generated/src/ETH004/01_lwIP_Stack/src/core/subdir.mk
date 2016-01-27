################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/dhcp.c \
../Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/dns.c \
../Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/init.c \
../Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/mem.c \
../Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/memp.c \
../Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/netconf.c \
../Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/netif.c \
../Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/pbuf.c \
../Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/raw.c \
../Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/stats.c \
../Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/sys.c \
../Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/tcp.c \
../Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/tcp_in.c \
../Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/tcp_out.c \
../Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/udp.c 

OBJS += \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/dhcp.o \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/dns.o \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/init.o \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/mem.o \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/memp.o \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/netconf.o \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/netif.o \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/pbuf.o \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/raw.o \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/stats.o \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/sys.o \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/tcp.o \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/tcp_in.o \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/tcp_out.o \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/udp.o 

C_DEPS += \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/dhcp.d \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/dns.d \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/init.d \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/mem.d \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/memp.d \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/netconf.d \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/netif.d \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/pbuf.d \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/raw.d \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/stats.d \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/sys.d \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/tcp.d \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/tcp_in.d \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/tcp_out.d \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/udp.d 


# Each subdirectory must supply rules for building sources it contributes
Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/%.o: ../Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"C:\DAVE-3.1.10\ARM-GCC/bin/arm-none-eabi-gcc" -DUC_ID=4502 -DDAVE_CE -I"C:\DAVE-3.1.10\eclipse\/../CMSIS/Include" -I"C:\DAVE-3.1.10\eclipse\/../CMSIS/Infineon/Include" -I"C:\DAVE-3.1.10\ARM-GCC/arm-none-eabi/include" -I"C:\DAVE-3.1.10\eclipse\/../emWin/Start/GUI/inc" -I"C:\DAVE-3.1.10\eclipse\/../CMSIS/Infineon/XMC4500_series/Include" -I"C:\DAVE3_workspace\ws3.1.10\XMC4500_RK_HTTPserver\XMC4500_RK_HTTPserver\Dave\Generated\src\ETH004\01_lwIP_Stack\src\include\lwip" -I"C:\DAVE3_workspace\ws3.1.10\XMC4500_RK_HTTPserver\XMC4500_RK_HTTPserver\Dave\Generated\src\ETH004\01_lwIP_Stack\src\include\ipv4" -I"C:\DAVE3_workspace\ws3.1.10\XMC4500_RK_HTTPserver\XMC4500_RK_HTTPserver\Dave\Generated\src\ETH004\01_lwIP_Stack\src\include" -I"C:\DAVE3_workspace\ws3.1.10\XMC4500_RK_HTTPserver\XMC4500_RK_HTTPserver\Dave\Generated\src\ETH004\01_lwIP_Stack\port" -I"C:\DAVE3_workspace\ws3.1.10\XMC4500_RK_HTTPserver\XMC4500_RK_HTTPserver\Dave\Generated\inc\DAVESupport" -I"C:\DAVE3_workspace\ws3.1.10\XMC4500_RK_HTTPserver\XMC4500_RK_HTTPserver\Dave\Generated\inc\LIBS" -Os -ffunction-sections -Wall -std=gnu99 -mfloat-abi=softfp -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


