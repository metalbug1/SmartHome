################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Dave/Generated/src/ETH001/DMA_Descriptors.c \
../Dave/Generated/src/ETH001/synopGMAC_Dev.c \
../Dave/Generated/src/ETH001/synopGMAC_network_interface.c \
../Dave/Generated/src/ETH001/synopGMAC_plat.c \
../Dave/Generated/src/ETH001/synopGMAC_stack_interface.c 

OBJS += \
./Dave/Generated/src/ETH001/DMA_Descriptors.o \
./Dave/Generated/src/ETH001/synopGMAC_Dev.o \
./Dave/Generated/src/ETH001/synopGMAC_network_interface.o \
./Dave/Generated/src/ETH001/synopGMAC_plat.o \
./Dave/Generated/src/ETH001/synopGMAC_stack_interface.o 

C_DEPS += \
./Dave/Generated/src/ETH001/DMA_Descriptors.d \
./Dave/Generated/src/ETH001/synopGMAC_Dev.d \
./Dave/Generated/src/ETH001/synopGMAC_network_interface.d \
./Dave/Generated/src/ETH001/synopGMAC_plat.d \
./Dave/Generated/src/ETH001/synopGMAC_stack_interface.d 


# Each subdirectory must supply rules for building sources it contributes
Dave/Generated/src/ETH001/%.o: ../Dave/Generated/src/ETH001/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"C:\DAVE-3.1.10\ARM-GCC/bin/arm-none-eabi-gcc" -DUC_ID=4503 -DDAVE_CE -I"C:\DAVE-3.1.10\eclipse\/../CMSIS/Include" -I"C:\DAVE-3.1.10\eclipse\/../CMSIS/Infineon/Include" -I"C:\DAVE-3.1.10\ARM-GCC/arm-none-eabi/include" -I"C:\DAVE-3.1.10\eclipse\/../emWin/Start/GUI/inc" -I"C:\DAVE-3.1.10\eclipse\/../CMSIS/Infineon/XMC4500_series/Include" -I"F:\WORK\SmartHome_checkout1\XMC4500_RK_HTTPserver\Dave\Generated\src\ETH004\01_lwIP_Stack\src\include\lwip" -I"F:\WORK\SmartHome_checkout1\XMC4500_RK_HTTPserver\Dave\Generated\src\ETH004\01_lwIP_Stack\src\include\ipv4" -I"F:\WORK\SmartHome_checkout1\XMC4500_RK_HTTPserver\Dave\Generated\src\ETH004\01_lwIP_Stack\src\include" -I"F:\WORK\SmartHome_checkout1\XMC4500_RK_HTTPserver\Dave\Generated\src\ETH004\01_lwIP_Stack\port" -I"F:\WORK\SmartHome_checkout1\XMC4500_RK_HTTPserver\Dave\Generated\inc\DAVESupport" -I"F:\WORK\SmartHome_checkout1\XMC4500_RK_HTTPserver\Dave\Generated\inc\LIBS" -I"F:\WORK\SmartHome_checkout1\XMC4500_RK_HTTPserver\Dave\Generated\inc\MOTORLIBS" -O0 -ffunction-sections -Wall -std=gnu99 -mfloat-abi=softfp -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -g3 -gdwarf-2 -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


