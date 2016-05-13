################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Lib/subdir.mk
-include Dave/Generated/src/WEBSERVER001/HTTPServer/subdir.mk
-include Dave/Generated/src/UART001/subdir.mk
-include Dave/Generated/src/SYSTM001/subdir.mk
-include Dave/Generated/src/SLTHA003/subdir.mk
-include Dave/Generated/src/SLTHA001/subdir.mk
-include Dave/Generated/src/SDMMC003/subdir.mk
-include Dave/Generated/src/SDMMC001/subdir.mk
-include Dave/Generated/src/RTC001/subdir.mk
-include Dave/Generated/src/RESET001/subdir.mk
-include Dave/Generated/src/NVIC_SCU001/subdir.mk
-include Dave/Generated/src/NVIC002/subdir.mk
-include Dave/Generated/src/MOTORLIBS/subdir.mk
-include Dave/Generated/src/LMM001/subdir.mk
-include Dave/Generated/src/LIBS/subdir.mk
-include Dave/Generated/src/IO004/subdir.mk
-include Dave/Generated/src/GMM001/subdir.mk
-include Dave/Generated/src/FATFS004/subdir.mk
-include Dave/Generated/src/FATFS002/Src/subdir.mk
-include Dave/Generated/src/FATFS002/subdir.mk
-include Dave/Generated/src/ETH004/01_lwIP_Stack/src/netif/subdir.mk
-include Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/ipv4/subdir.mk
-include Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/subdir.mk
-include Dave/Generated/src/ETH004/01_lwIP_Stack/src/api/subdir.mk
-include Dave/Generated/src/ETH004/01_lwIP_Stack/port/arch/sys/subdir.mk
-include Dave/Generated/src/ETH004/subdir.mk
-include Dave/Generated/src/ETH002/subdir.mk
-include Dave/Generated/src/ETH001/subdir.mk
-include Dave/Generated/src/DAVESupport/subdir.mk
-include Dave/Generated/src/CLK001/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
XMC4500_RK_HTTPserver.hex \

SECONDARY_LIST += \
XMC4500_RK_HTTPserver.lst \

SECONDARY_SIZE += \
XMC4500_RK_HTTPserver.siz \


# All Target
all: XMC4500_RK_HTTPserver.elf secondary-outputs

# Tool invocations
XMC4500_RK_HTTPserver.elf: $(OBJS) ../XMC4500_RK_HTTPserver.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM-GCC C Linker'
	"C:\DAVE-3.1.10\ARM-GCC/bin/arm-none-eabi-gcc" -T"../XMC4500_RK_HTTPserver.ld" -nostartfiles -L"C:\DAVE-3.1.10\eclipse\/../CMSIS/Infineon/Lib" -L"C:\DAVE-3.1.10\eclipse\/../Examples/Lib" -L"C:\DAVE-3.1.10\eclipse\/../emWin/Start/GUI" -Wl,-Map,"XMC4500_RK_HTTPserver.map" -mcpu=cortex-m4 -mthumb -g3 -gdwarf-2 -o "XMC4500_RK_HTTPserver.elf" "@makefile.rsp" $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

XMC4500_RK_HTTPserver.hex: XMC4500_RK_HTTPserver.elf
	@echo 'Invoking: ARM-GCC Create Flash Image'
	"C:\DAVE-3.1.10\ARM-GCC/bin/arm-none-eabi-objcopy" -O ihex "XMC4500_RK_HTTPserver.elf"  "XMC4500_RK_HTTPserver.hex"
	@echo 'Finished building: $@'
	@echo ' '

XMC4500_RK_HTTPserver.lst: XMC4500_RK_HTTPserver.elf
	@echo 'Invoking: ARM-GCC Create Listing'
	"C:\DAVE-3.1.10\ARM-GCC/bin/arm-none-eabi-objdump" -h -S "XMC4500_RK_HTTPserver.elf" > "XMC4500_RK_HTTPserver.lst"
	@echo 'Finished building: $@'
	@echo ' '

XMC4500_RK_HTTPserver.siz: XMC4500_RK_HTTPserver.elf
	@echo 'Invoking: ARM-GCC Print Size'
	"C:\DAVE-3.1.10\ARM-GCC/bin/arm-none-eabi-size"  --format=berkeley XMC4500_RK_HTTPserver.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(SECONDARY_SIZE)$(C_DEPS)$(SECONDARY_FLASH)$(S_DEPS)$(ARM_GCC_FOR_XMC_LINKER_OUTPUT_TYPE_OUTPUTS)$(SECONDARY_LIST)
	-$(RM) DataProcessing.o DataQueue.o SmartHome.o WebServerFunctions.o Startup/startup_XMC4500.o Startup/system_XMC4500.o Lib/System_LibcStubs.o Dave/Generated/src/WEBSERVER001/HTTPServer/fs.o Dave/Generated/src/WEBSERVER001/HTTPServer/fsdata.o Dave/Generated/src/WEBSERVER001/HTTPServer/httpd.o Dave/Generated/src/UART001/UART001.o Dave/Generated/src/UART001/UART001_Conf.o Dave/Generated/src/SYSTM001/SYSTM001.o Dave/Generated/src/SLTHA003/SLTHA003.o Dave/Generated/src/SLTHA003/SLTHA003_Conf.o Dave/Generated/src/SLTHA001/SLTHA001.o Dave/Generated/src/SLTHA001/SLTHA001_Conf.o Dave/Generated/src/SDMMC003/SDMMC003.o Dave/Generated/src/SDMMC003/SDMMC003_Conf.o Dave/Generated/src/SDMMC003/SDMMC003_Private.o Dave/Generated/src/SDMMC001/SDMMC001.o Dave/Generated/src/SDMMC001/SDMMC001_Conf.o Dave/Generated/src/RTC001/RTC001.o Dave/Generated/src/RTC001/RTC001_Conf.o Dave/Generated/src/RESET001/RESET001.o Dave/Generated/src/NVIC_SCU001/NVIC_SCU001.o Dave/Generated/src/NVIC002/NVIC002.o Dave/Generated/src/NVIC002/NVIC002_Conf.o Dave/Generated/src/MOTORLIBS/MOTORLIBS.o Dave/Generated/src/LMM001/LMM001.o Dave/Generated/src/LMM001/LMM001_Conf.o Dave/Generated/src/LIBS/CCU8PWMLIB.o Dave/Generated/src/IO004/IO004.o Dave/Generated/src/IO004/IO004_Conf.o Dave/Generated/src/GMM001/GMM001.o Dave/Generated/src/GMM001/GMM001_Conf.o Dave/Generated/src/FATFS004/FATFS004.o Dave/Generated/src/FATFS004/FATFS004_Conf.o Dave/Generated/src/FATFS002/FATFS002_Conf.o Dave/Generated/src/FATFS002/syscall.o Dave/Generated/src/FATFS002/Src/ff.o Dave/Generated/src/ETH004/ETH004_Conf.o Dave/Generated/src/ETH004/01_lwIP_Stack/src/netif/etharp.o Dave/Generated/src/ETH004/01_lwIP_Stack/src/netif/ethernetif.o Dave/Generated/src/ETH004/01_lwIP_Stack/src/netif/loopif.o Dave/Generated/src/ETH004/01_lwIP_Stack/src/netif/slipif.o Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/dhcp.o Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/dns.o 
	-$(RM) Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/init.o Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/mem.o Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/memp.o Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/netconf.o Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/netif.o Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/pbuf.o Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/raw.o Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/stats.o Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/sys.o Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/tcp.o Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/tcp_in.o Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/tcp_out.o Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/udp.o Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/ipv4/autoip.o Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/ipv4/icmp.o Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/ipv4/igmp.o Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/ipv4/inet.o Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/ipv4/inet_chksum.o Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/ipv4/ip.o Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/ipv4/ip_addr.o Dave/Generated/src/ETH004/01_lwIP_Stack/src/core/ipv4/ip_frag.o Dave/Generated/src/ETH004/01_lwIP_Stack/src/api/api_lib.o Dave/Generated/src/ETH004/01_lwIP_Stack/src/api/api_msg.o Dave/Generated/src/ETH004/01_lwIP_Stack/src/api/err.o Dave/Generated/src/ETH004/01_lwIP_Stack/src/api/netbuf.o Dave/Generated/src/ETH004/01_lwIP_Stack/src/api/netdb.o Dave/Generated/src/ETH004/01_lwIP_Stack/src/api/netifapi.o Dave/Generated/src/ETH004/01_lwIP_Stack/src/api/sockets.o Dave/Generated/src/ETH004/01_lwIP_Stack/src/api/tcpip.o Dave/Generated/src/ETH004/01_lwIP_Stack/port/arch/sys/sys_arch.o Dave/Generated/src/ETH002/EthernetPHY.o Dave/Generated/src/ETH001/DMA_Descriptors.o Dave/Generated/src/ETH001/synopGMAC_Dev.o Dave/Generated/src/ETH001/synopGMAC_network_interface.o 
	-$(RM) Dave/Generated/src/ETH001/synopGMAC_plat.o Dave/Generated/src/ETH001/synopGMAC_stack_interface.o Dave/Generated/src/DAVESupport/DAVE3.o Dave/Generated/src/DAVESupport/MULTIPLEXER.o Dave/Generated/src/CLK001/CLK001.o  XMC4500_RK_HTTPserver.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
