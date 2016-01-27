################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Dave/Generated/src/ETH004/01_lwIP_Stack/src/api/api_lib.c \
../Dave/Generated/src/ETH004/01_lwIP_Stack/src/api/api_msg.c \
../Dave/Generated/src/ETH004/01_lwIP_Stack/src/api/err.c \
../Dave/Generated/src/ETH004/01_lwIP_Stack/src/api/netbuf.c \
../Dave/Generated/src/ETH004/01_lwIP_Stack/src/api/netdb.c \
../Dave/Generated/src/ETH004/01_lwIP_Stack/src/api/netifapi.c \
../Dave/Generated/src/ETH004/01_lwIP_Stack/src/api/sockets.c \
../Dave/Generated/src/ETH004/01_lwIP_Stack/src/api/tcpip.c 

OBJS += \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/api/api_lib.o \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/api/api_msg.o \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/api/err.o \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/api/netbuf.o \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/api/netdb.o \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/api/netifapi.o \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/api/sockets.o \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/api/tcpip.o 

C_DEPS += \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/api/api_lib.d \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/api/api_msg.d \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/api/err.d \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/api/netbuf.d \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/api/netdb.d \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/api/netifapi.d \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/api/sockets.d \
./Dave/Generated/src/ETH004/01_lwIP_Stack/src/api/tcpip.d 


# Each subdirectory must supply rules for building sources it contributes
Dave/Generated/src/ETH004/01_lwIP_Stack/src/api/%.o: ../Dave/Generated/src/ETH004/01_lwIP_Stack/src/api/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"C:\DAVE-3.1.10\ARM-GCC/bin/arm-none-eabi-gcc" -DUC_ID=4502 -DDAVE_CE -I"C:\DAVE-3.1.10\eclipse\/../CMSIS/Include" -I"C:\DAVE-3.1.10\eclipse\/../CMSIS/Infineon/Include" -I"C:\DAVE-3.1.10\ARM-GCC/arm-none-eabi/include" -I"C:\DAVE-3.1.10\eclipse\/../emWin/Start/GUI/inc" -I"C:\DAVE-3.1.10\eclipse\/../CMSIS/Infineon/XMC4500_series/Include" -I"C:\DAVE3_workspace\ws3.1.10\XMC4500_RK_HTTPserver\XMC4500_RK_HTTPserver\Dave\Generated\src\ETH004\01_lwIP_Stack\src\include\lwip" -I"C:\DAVE3_workspace\ws3.1.10\XMC4500_RK_HTTPserver\XMC4500_RK_HTTPserver\Dave\Generated\src\ETH004\01_lwIP_Stack\src\include\ipv4" -I"C:\DAVE3_workspace\ws3.1.10\XMC4500_RK_HTTPserver\XMC4500_RK_HTTPserver\Dave\Generated\src\ETH004\01_lwIP_Stack\src\include" -I"C:\DAVE3_workspace\ws3.1.10\XMC4500_RK_HTTPserver\XMC4500_RK_HTTPserver\Dave\Generated\src\ETH004\01_lwIP_Stack\port" -I"C:\DAVE3_workspace\ws3.1.10\XMC4500_RK_HTTPserver\XMC4500_RK_HTTPserver\Dave\Generated\inc\DAVESupport" -I"C:\DAVE3_workspace\ws3.1.10\XMC4500_RK_HTTPserver\XMC4500_RK_HTTPserver\Dave\Generated\inc\LIBS" -Os -ffunction-sections -Wall -std=gnu99 -mfloat-abi=softfp -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


