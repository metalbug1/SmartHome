################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Dave/Generated/src/WEBSERVER001/HTTPServer/fs.c \
../Dave/Generated/src/WEBSERVER001/HTTPServer/fsdata.c \
../Dave/Generated/src/WEBSERVER001/HTTPServer/httpd.c 

OBJS += \
./Dave/Generated/src/WEBSERVER001/HTTPServer/fs.o \
./Dave/Generated/src/WEBSERVER001/HTTPServer/fsdata.o \
./Dave/Generated/src/WEBSERVER001/HTTPServer/httpd.o 

C_DEPS += \
./Dave/Generated/src/WEBSERVER001/HTTPServer/fs.d \
./Dave/Generated/src/WEBSERVER001/HTTPServer/fsdata.d \
./Dave/Generated/src/WEBSERVER001/HTTPServer/httpd.d 


# Each subdirectory must supply rules for building sources it contributes
Dave/Generated/src/WEBSERVER001/HTTPServer/%.o: ../Dave/Generated/src/WEBSERVER001/HTTPServer/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"C:\DAVE-3.1.10\ARM-GCC/bin/arm-none-eabi-gcc" -DUC_ID=4503 -DDAVE_CE -I"C:\DAVE-3.1.10\eclipse\/../CMSIS/Include" -I"C:\DAVE-3.1.10\eclipse\/../CMSIS/Infineon/Include" -I"C:\DAVE-3.1.10\ARM-GCC/arm-none-eabi/include" -I"C:\DAVE-3.1.10\eclipse\/../emWin/Start/GUI/inc" -I"C:\DAVE-3.1.10\eclipse\/../CMSIS/Infineon/XMC4500_series/Include" -I"F:\WORK\SmartHome_checkout1\XMC4500_RK_HTTPserver\Dave\Generated\src\ETH004\01_lwIP_Stack\src\include\lwip" -I"F:\WORK\SmartHome_checkout1\XMC4500_RK_HTTPserver\Dave\Generated\src\ETH004\01_lwIP_Stack\src\include\ipv4" -I"F:\WORK\SmartHome_checkout1\XMC4500_RK_HTTPserver\Dave\Generated\src\ETH004\01_lwIP_Stack\src\include" -I"F:\WORK\SmartHome_checkout1\XMC4500_RK_HTTPserver\Dave\Generated\src\ETH004\01_lwIP_Stack\port" -I"F:\WORK\SmartHome_checkout1\XMC4500_RK_HTTPserver\Dave\Generated\inc\DAVESupport" -I"F:\WORK\SmartHome_checkout1\XMC4500_RK_HTTPserver\Dave\Generated\inc\LIBS" -I"F:\WORK\SmartHome_checkout1\XMC4500_RK_HTTPserver\Dave\Generated\inc\MOTORLIBS" -Os -ffunction-sections -Wall -std=gnu99 -mfloat-abi=softfp -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


