#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/TCPIP_Demo_App_-_C32_-_PIC32_ENET_SK_DM320004_INTERNAL_ETHERNET.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/TCPIP_Demo_App_-_C32_-_PIC32_ENET_SK_DM320004_INTERNAL_ETHERNET.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../BerkeleyTCPClientDemo.c ../BerkeleyTCPServerDemo.c ../BerkeleyUDPClientDemo.c ../GenericTCPClient.c ../GenericTCPServer.c ../LegacyHTTPApp.c ../PingDemo.c ../SMTPDemo.c ../UARTConfig.c "../../Microchip/TCPIP Stack/Announce.c" "../../Microchip/TCPIP Stack/ARCFOUR.c" "../../Microchip/TCPIP Stack/ARP.c" "../../Microchip/TCPIP Stack/AutoIP.c" "../../Microchip/TCPIP Stack/BerkeleyAPI.c" "../../Microchip/TCPIP Stack/BigInt.c" "../../Microchip/TCPIP Stack/Delay.c" "../../Microchip/TCPIP Stack/DHCP.c" "../../Microchip/TCPIP Stack/DHCPs.c" "../../Microchip/TCPIP Stack/DNS.c" "../../Microchip/TCPIP Stack/DNSs.c" "../../Microchip/TCPIP Stack/DynDNS.c" "../../Microchip/TCPIP Stack/ENC28J60.c" "../../Microchip/TCPIP Stack/ENCX24J600.c" "../../Microchip/TCPIP Stack/ETHPIC32ExtPhy.c" "../../Microchip/TCPIP Stack/ETHPIC32ExtPhyDP83848.c" "../../Microchip/TCPIP Stack/ETHPIC32IntMac.c" "../../Microchip/TCPIP Stack/FileSystem.c" "../../Microchip/TCPIP Stack/FTP.c" "../../Microchip/TCPIP Stack/Hashes.c" "../../Microchip/TCPIP Stack/Helpers.c" "../../Microchip/TCPIP Stack/HTTP2.c" "../../Microchip/TCPIP Stack/HTTP.c" "../../Microchip/TCPIP Stack/ICMP.c" "../../Microchip/TCPIP Stack/IP.c" "../../Microchip/TCPIP Stack/LCDBlocking.c" "../../Microchip/TCPIP Stack/MPFS2.c" "../../Microchip/TCPIP Stack/MPFS.c" "../../Microchip/TCPIP Stack/NBNS.c" "../../Microchip/TCPIP Stack/Random.c" "../../Microchip/TCPIP Stack/Reboot.c" "../../Microchip/TCPIP Stack/RSA.c" "../../Microchip/TCPIP Stack/SMTP.c" "../../Microchip/TCPIP Stack/SNMP.c" "../../Microchip/TCPIP Stack/SNMPv3.c" "../../Microchip/TCPIP Stack/SNMPv3USM.c" "../../Microchip/TCPIP Stack/SNTP.c" "../../Microchip/TCPIP Stack/SPIEEPROM.c" "../../Microchip/TCPIP Stack/SPIFlash.c" "../../Microchip/TCPIP Stack/SPIRAM.c" "../../Microchip/TCPIP Stack/SSL.c" "../../Microchip/TCPIP Stack/StackTsk.c" "../../Microchip/TCPIP Stack/TCP.c" "../../Microchip/TCPIP Stack/TCPPerformanceTest.c" "../../Microchip/TCPIP Stack/Telnet.c" "../../Microchip/TCPIP Stack/TFTPc.c" "../../Microchip/TCPIP Stack/Tick.c" "../../Microchip/TCPIP Stack/UART2TCPBridge.c" "../../Microchip/TCPIP Stack/UART.c" "../../Microchip/TCPIP Stack/UDP.c" "../../Microchip/TCPIP Stack/UDPPerformanceTest.c" "../../Microchip/TCPIP Stack/ZeroconfHelper.c" "../../Microchip/TCPIP Stack/ZeroconfLinkLocal.c" "../../Microchip/TCPIP Stack/ZeroconfMulticastDNS.c" ../MPFSImg2.c ../MPFSImg.c "../../Microchip/TCPIP Stack/BigInt_helper_C32.S" ../CustomHTTPApp.c ../CustomSNMPApp.c ../CustomSSLCert.c ../MainDemo.c ../mbmc.c ../crc8_fast.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o ${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o ${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o ${OBJECTDIR}/_ext/1472/GenericTCPClient.o ${OBJECTDIR}/_ext/1472/GenericTCPServer.o ${OBJECTDIR}/_ext/1472/LegacyHTTPApp.o ${OBJECTDIR}/_ext/1472/PingDemo.o ${OBJECTDIR}/_ext/1472/SMTPDemo.o ${OBJECTDIR}/_ext/1472/UARTConfig.o ${OBJECTDIR}/_ext/1295770447/Announce.o ${OBJECTDIR}/_ext/1295770447/ARCFOUR.o ${OBJECTDIR}/_ext/1295770447/ARP.o ${OBJECTDIR}/_ext/1295770447/AutoIP.o ${OBJECTDIR}/_ext/1295770447/BerkeleyAPI.o ${OBJECTDIR}/_ext/1295770447/BigInt.o ${OBJECTDIR}/_ext/1295770447/Delay.o ${OBJECTDIR}/_ext/1295770447/DHCP.o ${OBJECTDIR}/_ext/1295770447/DHCPs.o ${OBJECTDIR}/_ext/1295770447/DNS.o ${OBJECTDIR}/_ext/1295770447/DNSs.o ${OBJECTDIR}/_ext/1295770447/DynDNS.o ${OBJECTDIR}/_ext/1295770447/ENC28J60.o ${OBJECTDIR}/_ext/1295770447/ENCX24J600.o ${OBJECTDIR}/_ext/1295770447/ETHPIC32ExtPhy.o ${OBJECTDIR}/_ext/1295770447/ETHPIC32ExtPhyDP83848.o ${OBJECTDIR}/_ext/1295770447/ETHPIC32IntMac.o ${OBJECTDIR}/_ext/1295770447/FileSystem.o ${OBJECTDIR}/_ext/1295770447/FTP.o ${OBJECTDIR}/_ext/1295770447/Hashes.o ${OBJECTDIR}/_ext/1295770447/Helpers.o ${OBJECTDIR}/_ext/1295770447/HTTP2.o ${OBJECTDIR}/_ext/1295770447/HTTP.o ${OBJECTDIR}/_ext/1295770447/ICMP.o ${OBJECTDIR}/_ext/1295770447/IP.o ${OBJECTDIR}/_ext/1295770447/LCDBlocking.o ${OBJECTDIR}/_ext/1295770447/MPFS2.o ${OBJECTDIR}/_ext/1295770447/MPFS.o ${OBJECTDIR}/_ext/1295770447/NBNS.o ${OBJECTDIR}/_ext/1295770447/Random.o ${OBJECTDIR}/_ext/1295770447/Reboot.o ${OBJECTDIR}/_ext/1295770447/RSA.o ${OBJECTDIR}/_ext/1295770447/SMTP.o ${OBJECTDIR}/_ext/1295770447/SNMP.o ${OBJECTDIR}/_ext/1295770447/SNMPv3.o ${OBJECTDIR}/_ext/1295770447/SNMPv3USM.o ${OBJECTDIR}/_ext/1295770447/SNTP.o ${OBJECTDIR}/_ext/1295770447/SPIEEPROM.o ${OBJECTDIR}/_ext/1295770447/SPIFlash.o ${OBJECTDIR}/_ext/1295770447/SPIRAM.o ${OBJECTDIR}/_ext/1295770447/SSL.o ${OBJECTDIR}/_ext/1295770447/StackTsk.o ${OBJECTDIR}/_ext/1295770447/TCP.o ${OBJECTDIR}/_ext/1295770447/TCPPerformanceTest.o ${OBJECTDIR}/_ext/1295770447/Telnet.o ${OBJECTDIR}/_ext/1295770447/TFTPc.o ${OBJECTDIR}/_ext/1295770447/Tick.o ${OBJECTDIR}/_ext/1295770447/UART2TCPBridge.o ${OBJECTDIR}/_ext/1295770447/UART.o ${OBJECTDIR}/_ext/1295770447/UDP.o ${OBJECTDIR}/_ext/1295770447/UDPPerformanceTest.o ${OBJECTDIR}/_ext/1295770447/ZeroconfHelper.o ${OBJECTDIR}/_ext/1295770447/ZeroconfLinkLocal.o ${OBJECTDIR}/_ext/1295770447/ZeroconfMulticastDNS.o ${OBJECTDIR}/_ext/1472/MPFSImg2.o ${OBJECTDIR}/_ext/1472/MPFSImg.o ${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o ${OBJECTDIR}/_ext/1472/CustomHTTPApp.o ${OBJECTDIR}/_ext/1472/CustomSNMPApp.o ${OBJECTDIR}/_ext/1472/CustomSSLCert.o ${OBJECTDIR}/_ext/1472/MainDemo.o ${OBJECTDIR}/_ext/1472/mbmc.o ${OBJECTDIR}/_ext/1472/crc8_fast.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o.d ${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o.d ${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o.d ${OBJECTDIR}/_ext/1472/GenericTCPClient.o.d ${OBJECTDIR}/_ext/1472/GenericTCPServer.o.d ${OBJECTDIR}/_ext/1472/LegacyHTTPApp.o.d ${OBJECTDIR}/_ext/1472/PingDemo.o.d ${OBJECTDIR}/_ext/1472/SMTPDemo.o.d ${OBJECTDIR}/_ext/1472/UARTConfig.o.d ${OBJECTDIR}/_ext/1295770447/Announce.o.d ${OBJECTDIR}/_ext/1295770447/ARCFOUR.o.d ${OBJECTDIR}/_ext/1295770447/ARP.o.d ${OBJECTDIR}/_ext/1295770447/AutoIP.o.d ${OBJECTDIR}/_ext/1295770447/BerkeleyAPI.o.d ${OBJECTDIR}/_ext/1295770447/BigInt.o.d ${OBJECTDIR}/_ext/1295770447/Delay.o.d ${OBJECTDIR}/_ext/1295770447/DHCP.o.d ${OBJECTDIR}/_ext/1295770447/DHCPs.o.d ${OBJECTDIR}/_ext/1295770447/DNS.o.d ${OBJECTDIR}/_ext/1295770447/DNSs.o.d ${OBJECTDIR}/_ext/1295770447/DynDNS.o.d ${OBJECTDIR}/_ext/1295770447/ENC28J60.o.d ${OBJECTDIR}/_ext/1295770447/ENCX24J600.o.d ${OBJECTDIR}/_ext/1295770447/ETHPIC32ExtPhy.o.d ${OBJECTDIR}/_ext/1295770447/ETHPIC32ExtPhyDP83848.o.d ${OBJECTDIR}/_ext/1295770447/ETHPIC32IntMac.o.d ${OBJECTDIR}/_ext/1295770447/FileSystem.o.d ${OBJECTDIR}/_ext/1295770447/FTP.o.d ${OBJECTDIR}/_ext/1295770447/Hashes.o.d ${OBJECTDIR}/_ext/1295770447/Helpers.o.d ${OBJECTDIR}/_ext/1295770447/HTTP2.o.d ${OBJECTDIR}/_ext/1295770447/HTTP.o.d ${OBJECTDIR}/_ext/1295770447/ICMP.o.d ${OBJECTDIR}/_ext/1295770447/IP.o.d ${OBJECTDIR}/_ext/1295770447/LCDBlocking.o.d ${OBJECTDIR}/_ext/1295770447/MPFS2.o.d ${OBJECTDIR}/_ext/1295770447/MPFS.o.d ${OBJECTDIR}/_ext/1295770447/NBNS.o.d ${OBJECTDIR}/_ext/1295770447/Random.o.d ${OBJECTDIR}/_ext/1295770447/Reboot.o.d ${OBJECTDIR}/_ext/1295770447/RSA.o.d ${OBJECTDIR}/_ext/1295770447/SMTP.o.d ${OBJECTDIR}/_ext/1295770447/SNMP.o.d ${OBJECTDIR}/_ext/1295770447/SNMPv3.o.d ${OBJECTDIR}/_ext/1295770447/SNMPv3USM.o.d ${OBJECTDIR}/_ext/1295770447/SNTP.o.d ${OBJECTDIR}/_ext/1295770447/SPIEEPROM.o.d ${OBJECTDIR}/_ext/1295770447/SPIFlash.o.d ${OBJECTDIR}/_ext/1295770447/SPIRAM.o.d ${OBJECTDIR}/_ext/1295770447/SSL.o.d ${OBJECTDIR}/_ext/1295770447/StackTsk.o.d ${OBJECTDIR}/_ext/1295770447/TCP.o.d ${OBJECTDIR}/_ext/1295770447/TCPPerformanceTest.o.d ${OBJECTDIR}/_ext/1295770447/Telnet.o.d ${OBJECTDIR}/_ext/1295770447/TFTPc.o.d ${OBJECTDIR}/_ext/1295770447/Tick.o.d ${OBJECTDIR}/_ext/1295770447/UART2TCPBridge.o.d ${OBJECTDIR}/_ext/1295770447/UART.o.d ${OBJECTDIR}/_ext/1295770447/UDP.o.d ${OBJECTDIR}/_ext/1295770447/UDPPerformanceTest.o.d ${OBJECTDIR}/_ext/1295770447/ZeroconfHelper.o.d ${OBJECTDIR}/_ext/1295770447/ZeroconfLinkLocal.o.d ${OBJECTDIR}/_ext/1295770447/ZeroconfMulticastDNS.o.d ${OBJECTDIR}/_ext/1472/MPFSImg2.o.d ${OBJECTDIR}/_ext/1472/MPFSImg.o.d ${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o.d ${OBJECTDIR}/_ext/1472/CustomHTTPApp.o.d ${OBJECTDIR}/_ext/1472/CustomSNMPApp.o.d ${OBJECTDIR}/_ext/1472/CustomSSLCert.o.d ${OBJECTDIR}/_ext/1472/MainDemo.o.d ${OBJECTDIR}/_ext/1472/mbmc.o.d ${OBJECTDIR}/_ext/1472/crc8_fast.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o ${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o ${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o ${OBJECTDIR}/_ext/1472/GenericTCPClient.o ${OBJECTDIR}/_ext/1472/GenericTCPServer.o ${OBJECTDIR}/_ext/1472/LegacyHTTPApp.o ${OBJECTDIR}/_ext/1472/PingDemo.o ${OBJECTDIR}/_ext/1472/SMTPDemo.o ${OBJECTDIR}/_ext/1472/UARTConfig.o ${OBJECTDIR}/_ext/1295770447/Announce.o ${OBJECTDIR}/_ext/1295770447/ARCFOUR.o ${OBJECTDIR}/_ext/1295770447/ARP.o ${OBJECTDIR}/_ext/1295770447/AutoIP.o ${OBJECTDIR}/_ext/1295770447/BerkeleyAPI.o ${OBJECTDIR}/_ext/1295770447/BigInt.o ${OBJECTDIR}/_ext/1295770447/Delay.o ${OBJECTDIR}/_ext/1295770447/DHCP.o ${OBJECTDIR}/_ext/1295770447/DHCPs.o ${OBJECTDIR}/_ext/1295770447/DNS.o ${OBJECTDIR}/_ext/1295770447/DNSs.o ${OBJECTDIR}/_ext/1295770447/DynDNS.o ${OBJECTDIR}/_ext/1295770447/ENC28J60.o ${OBJECTDIR}/_ext/1295770447/ENCX24J600.o ${OBJECTDIR}/_ext/1295770447/ETHPIC32ExtPhy.o ${OBJECTDIR}/_ext/1295770447/ETHPIC32ExtPhyDP83848.o ${OBJECTDIR}/_ext/1295770447/ETHPIC32IntMac.o ${OBJECTDIR}/_ext/1295770447/FileSystem.o ${OBJECTDIR}/_ext/1295770447/FTP.o ${OBJECTDIR}/_ext/1295770447/Hashes.o ${OBJECTDIR}/_ext/1295770447/Helpers.o ${OBJECTDIR}/_ext/1295770447/HTTP2.o ${OBJECTDIR}/_ext/1295770447/HTTP.o ${OBJECTDIR}/_ext/1295770447/ICMP.o ${OBJECTDIR}/_ext/1295770447/IP.o ${OBJECTDIR}/_ext/1295770447/LCDBlocking.o ${OBJECTDIR}/_ext/1295770447/MPFS2.o ${OBJECTDIR}/_ext/1295770447/MPFS.o ${OBJECTDIR}/_ext/1295770447/NBNS.o ${OBJECTDIR}/_ext/1295770447/Random.o ${OBJECTDIR}/_ext/1295770447/Reboot.o ${OBJECTDIR}/_ext/1295770447/RSA.o ${OBJECTDIR}/_ext/1295770447/SMTP.o ${OBJECTDIR}/_ext/1295770447/SNMP.o ${OBJECTDIR}/_ext/1295770447/SNMPv3.o ${OBJECTDIR}/_ext/1295770447/SNMPv3USM.o ${OBJECTDIR}/_ext/1295770447/SNTP.o ${OBJECTDIR}/_ext/1295770447/SPIEEPROM.o ${OBJECTDIR}/_ext/1295770447/SPIFlash.o ${OBJECTDIR}/_ext/1295770447/SPIRAM.o ${OBJECTDIR}/_ext/1295770447/SSL.o ${OBJECTDIR}/_ext/1295770447/StackTsk.o ${OBJECTDIR}/_ext/1295770447/TCP.o ${OBJECTDIR}/_ext/1295770447/TCPPerformanceTest.o ${OBJECTDIR}/_ext/1295770447/Telnet.o ${OBJECTDIR}/_ext/1295770447/TFTPc.o ${OBJECTDIR}/_ext/1295770447/Tick.o ${OBJECTDIR}/_ext/1295770447/UART2TCPBridge.o ${OBJECTDIR}/_ext/1295770447/UART.o ${OBJECTDIR}/_ext/1295770447/UDP.o ${OBJECTDIR}/_ext/1295770447/UDPPerformanceTest.o ${OBJECTDIR}/_ext/1295770447/ZeroconfHelper.o ${OBJECTDIR}/_ext/1295770447/ZeroconfLinkLocal.o ${OBJECTDIR}/_ext/1295770447/ZeroconfMulticastDNS.o ${OBJECTDIR}/_ext/1472/MPFSImg2.o ${OBJECTDIR}/_ext/1472/MPFSImg.o ${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o ${OBJECTDIR}/_ext/1472/CustomHTTPApp.o ${OBJECTDIR}/_ext/1472/CustomSNMPApp.o ${OBJECTDIR}/_ext/1472/CustomSSLCert.o ${OBJECTDIR}/_ext/1472/MainDemo.o ${OBJECTDIR}/_ext/1472/mbmc.o ${OBJECTDIR}/_ext/1472/crc8_fast.o

# Source Files
SOURCEFILES=../BerkeleyTCPClientDemo.c ../BerkeleyTCPServerDemo.c ../BerkeleyUDPClientDemo.c ../GenericTCPClient.c ../GenericTCPServer.c ../LegacyHTTPApp.c ../PingDemo.c ../SMTPDemo.c ../UARTConfig.c ../../Microchip/TCPIP Stack/Announce.c ../../Microchip/TCPIP Stack/ARCFOUR.c ../../Microchip/TCPIP Stack/ARP.c ../../Microchip/TCPIP Stack/AutoIP.c ../../Microchip/TCPIP Stack/BerkeleyAPI.c ../../Microchip/TCPIP Stack/BigInt.c ../../Microchip/TCPIP Stack/Delay.c ../../Microchip/TCPIP Stack/DHCP.c ../../Microchip/TCPIP Stack/DHCPs.c ../../Microchip/TCPIP Stack/DNS.c ../../Microchip/TCPIP Stack/DNSs.c ../../Microchip/TCPIP Stack/DynDNS.c ../../Microchip/TCPIP Stack/ENC28J60.c ../../Microchip/TCPIP Stack/ENCX24J600.c ../../Microchip/TCPIP Stack/ETHPIC32ExtPhy.c ../../Microchip/TCPIP Stack/ETHPIC32ExtPhyDP83848.c ../../Microchip/TCPIP Stack/ETHPIC32IntMac.c ../../Microchip/TCPIP Stack/FileSystem.c ../../Microchip/TCPIP Stack/FTP.c ../../Microchip/TCPIP Stack/Hashes.c ../../Microchip/TCPIP Stack/Helpers.c ../../Microchip/TCPIP Stack/HTTP2.c ../../Microchip/TCPIP Stack/HTTP.c ../../Microchip/TCPIP Stack/ICMP.c ../../Microchip/TCPIP Stack/IP.c ../../Microchip/TCPIP Stack/LCDBlocking.c ../../Microchip/TCPIP Stack/MPFS2.c ../../Microchip/TCPIP Stack/MPFS.c ../../Microchip/TCPIP Stack/NBNS.c ../../Microchip/TCPIP Stack/Random.c ../../Microchip/TCPIP Stack/Reboot.c ../../Microchip/TCPIP Stack/RSA.c ../../Microchip/TCPIP Stack/SMTP.c ../../Microchip/TCPIP Stack/SNMP.c ../../Microchip/TCPIP Stack/SNMPv3.c ../../Microchip/TCPIP Stack/SNMPv3USM.c ../../Microchip/TCPIP Stack/SNTP.c ../../Microchip/TCPIP Stack/SPIEEPROM.c ../../Microchip/TCPIP Stack/SPIFlash.c ../../Microchip/TCPIP Stack/SPIRAM.c ../../Microchip/TCPIP Stack/SSL.c ../../Microchip/TCPIP Stack/StackTsk.c ../../Microchip/TCPIP Stack/TCP.c ../../Microchip/TCPIP Stack/TCPPerformanceTest.c ../../Microchip/TCPIP Stack/Telnet.c ../../Microchip/TCPIP Stack/TFTPc.c ../../Microchip/TCPIP Stack/Tick.c ../../Microchip/TCPIP Stack/UART2TCPBridge.c ../../Microchip/TCPIP Stack/UART.c ../../Microchip/TCPIP Stack/UDP.c ../../Microchip/TCPIP Stack/UDPPerformanceTest.c ../../Microchip/TCPIP Stack/ZeroconfHelper.c ../../Microchip/TCPIP Stack/ZeroconfLinkLocal.c ../../Microchip/TCPIP Stack/ZeroconfMulticastDNS.c ../MPFSImg2.c ../MPFSImg.c ../../Microchip/TCPIP Stack/BigInt_helper_C32.S ../CustomHTTPApp.c ../CustomSNMPApp.c ../CustomSSLCert.c ../MainDemo.c ../mbmc.c ../crc8_fast.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/TCPIP_Demo_App_-_C32_-_PIC32_ENET_SK_DM320004_INTERNAL_ETHERNET.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX795F512L
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o: ../../Microchip/TCPIP\ Stack/BigInt_helper_C32.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o.ok ${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o.err 
	@${RM} ${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o.d" "${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o.asm.d" -t $(SILENT)  -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1 -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -MMD -MF "${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o.d"  -o ${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o "../../Microchip/TCPIP Stack/BigInt_helper_C32.S" -legacy-libc -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o.asm.d",--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--gdwarf-2,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PIC32MXSK=1,-I"..",-as
	
else
${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o: ../../Microchip/TCPIP\ Stack/BigInt_helper_C32.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o.ok ${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o.err 
	@${RM} ${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o.d" "${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o.asm.d" -t $(SILENT)  -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -MMD -MF "${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o.d"  -o ${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o "../../Microchip/TCPIP Stack/BigInt_helper_C32.S" -legacy-libc -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/1295770447/BigInt_helper_C32.o.asm.d",--gdwarf-2,-I"..",-as
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o: ../BerkeleyTCPClientDemo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o.d" -o ${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o ../BerkeleyTCPClientDemo.c  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o: ../BerkeleyTCPServerDemo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o.d" -o ${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o ../BerkeleyTCPServerDemo.c  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o: ../BerkeleyUDPClientDemo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o.d" -o ${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o ../BerkeleyUDPClientDemo.c  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1472/GenericTCPClient.o: ../GenericTCPClient.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/GenericTCPClient.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/GenericTCPClient.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/GenericTCPClient.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/GenericTCPClient.o.d" -o ${OBJECTDIR}/_ext/1472/GenericTCPClient.o ../GenericTCPClient.c  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1472/GenericTCPServer.o: ../GenericTCPServer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/GenericTCPServer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/GenericTCPServer.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/GenericTCPServer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/GenericTCPServer.o.d" -o ${OBJECTDIR}/_ext/1472/GenericTCPServer.o ../GenericTCPServer.c  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1472/LegacyHTTPApp.o: ../LegacyHTTPApp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/LegacyHTTPApp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/LegacyHTTPApp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/LegacyHTTPApp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/LegacyHTTPApp.o.d" -o ${OBJECTDIR}/_ext/1472/LegacyHTTPApp.o ../LegacyHTTPApp.c  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1472/PingDemo.o: ../PingDemo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/PingDemo.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/PingDemo.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/PingDemo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/PingDemo.o.d" -o ${OBJECTDIR}/_ext/1472/PingDemo.o ../PingDemo.c  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1472/SMTPDemo.o: ../SMTPDemo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/SMTPDemo.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/SMTPDemo.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/SMTPDemo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/SMTPDemo.o.d" -o ${OBJECTDIR}/_ext/1472/SMTPDemo.o ../SMTPDemo.c  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1472/UARTConfig.o: ../UARTConfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/UARTConfig.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/UARTConfig.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/UARTConfig.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/UARTConfig.o.d" -o ${OBJECTDIR}/_ext/1472/UARTConfig.o ../UARTConfig.c  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/Announce.o: ../../Microchip/TCPIP\ Stack/Announce.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Announce.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Announce.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/Announce.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/Announce.o.d" -o ${OBJECTDIR}/_ext/1295770447/Announce.o "../../Microchip/TCPIP Stack/Announce.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/ARCFOUR.o: ../../Microchip/TCPIP\ Stack/ARCFOUR.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ARCFOUR.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ARCFOUR.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/ARCFOUR.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/ARCFOUR.o.d" -o ${OBJECTDIR}/_ext/1295770447/ARCFOUR.o "../../Microchip/TCPIP Stack/ARCFOUR.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/ARP.o: ../../Microchip/TCPIP\ Stack/ARP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ARP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ARP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/ARP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/ARP.o.d" -o ${OBJECTDIR}/_ext/1295770447/ARP.o "../../Microchip/TCPIP Stack/ARP.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/AutoIP.o: ../../Microchip/TCPIP\ Stack/AutoIP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/AutoIP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/AutoIP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/AutoIP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/AutoIP.o.d" -o ${OBJECTDIR}/_ext/1295770447/AutoIP.o "../../Microchip/TCPIP Stack/AutoIP.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/BerkeleyAPI.o: ../../Microchip/TCPIP\ Stack/BerkeleyAPI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/BerkeleyAPI.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/BerkeleyAPI.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/BerkeleyAPI.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/BerkeleyAPI.o.d" -o ${OBJECTDIR}/_ext/1295770447/BerkeleyAPI.o "../../Microchip/TCPIP Stack/BerkeleyAPI.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/BigInt.o: ../../Microchip/TCPIP\ Stack/BigInt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/BigInt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/BigInt.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/BigInt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/BigInt.o.d" -o ${OBJECTDIR}/_ext/1295770447/BigInt.o "../../Microchip/TCPIP Stack/BigInt.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/Delay.o: ../../Microchip/TCPIP\ Stack/Delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Delay.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Delay.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/Delay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/Delay.o.d" -o ${OBJECTDIR}/_ext/1295770447/Delay.o "../../Microchip/TCPIP Stack/Delay.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/DHCP.o: ../../Microchip/TCPIP\ Stack/DHCP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/DHCP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/DHCP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/DHCP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/DHCP.o.d" -o ${OBJECTDIR}/_ext/1295770447/DHCP.o "../../Microchip/TCPIP Stack/DHCP.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/DHCPs.o: ../../Microchip/TCPIP\ Stack/DHCPs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/DHCPs.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/DHCPs.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/DHCPs.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/DHCPs.o.d" -o ${OBJECTDIR}/_ext/1295770447/DHCPs.o "../../Microchip/TCPIP Stack/DHCPs.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/DNS.o: ../../Microchip/TCPIP\ Stack/DNS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/DNS.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/DNS.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/DNS.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/DNS.o.d" -o ${OBJECTDIR}/_ext/1295770447/DNS.o "../../Microchip/TCPIP Stack/DNS.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/DNSs.o: ../../Microchip/TCPIP\ Stack/DNSs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/DNSs.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/DNSs.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/DNSs.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/DNSs.o.d" -o ${OBJECTDIR}/_ext/1295770447/DNSs.o "../../Microchip/TCPIP Stack/DNSs.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/DynDNS.o: ../../Microchip/TCPIP\ Stack/DynDNS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/DynDNS.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/DynDNS.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/DynDNS.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/DynDNS.o.d" -o ${OBJECTDIR}/_ext/1295770447/DynDNS.o "../../Microchip/TCPIP Stack/DynDNS.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/ENC28J60.o: ../../Microchip/TCPIP\ Stack/ENC28J60.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ENC28J60.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ENC28J60.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/ENC28J60.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/ENC28J60.o.d" -o ${OBJECTDIR}/_ext/1295770447/ENC28J60.o "../../Microchip/TCPIP Stack/ENC28J60.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/ENCX24J600.o: ../../Microchip/TCPIP\ Stack/ENCX24J600.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ENCX24J600.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ENCX24J600.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/ENCX24J600.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/ENCX24J600.o.d" -o ${OBJECTDIR}/_ext/1295770447/ENCX24J600.o "../../Microchip/TCPIP Stack/ENCX24J600.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/ETHPIC32ExtPhy.o: ../../Microchip/TCPIP\ Stack/ETHPIC32ExtPhy.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ETHPIC32ExtPhy.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ETHPIC32ExtPhy.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/ETHPIC32ExtPhy.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/ETHPIC32ExtPhy.o.d" -o ${OBJECTDIR}/_ext/1295770447/ETHPIC32ExtPhy.o "../../Microchip/TCPIP Stack/ETHPIC32ExtPhy.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/ETHPIC32ExtPhyDP83848.o: ../../Microchip/TCPIP\ Stack/ETHPIC32ExtPhyDP83848.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ETHPIC32ExtPhyDP83848.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ETHPIC32ExtPhyDP83848.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/ETHPIC32ExtPhyDP83848.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/ETHPIC32ExtPhyDP83848.o.d" -o ${OBJECTDIR}/_ext/1295770447/ETHPIC32ExtPhyDP83848.o "../../Microchip/TCPIP Stack/ETHPIC32ExtPhyDP83848.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/ETHPIC32IntMac.o: ../../Microchip/TCPIP\ Stack/ETHPIC32IntMac.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ETHPIC32IntMac.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ETHPIC32IntMac.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/ETHPIC32IntMac.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/ETHPIC32IntMac.o.d" -o ${OBJECTDIR}/_ext/1295770447/ETHPIC32IntMac.o "../../Microchip/TCPIP Stack/ETHPIC32IntMac.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/FileSystem.o: ../../Microchip/TCPIP\ Stack/FileSystem.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/FileSystem.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/FileSystem.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/FileSystem.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/FileSystem.o.d" -o ${OBJECTDIR}/_ext/1295770447/FileSystem.o "../../Microchip/TCPIP Stack/FileSystem.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/FTP.o: ../../Microchip/TCPIP\ Stack/FTP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/FTP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/FTP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/FTP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/FTP.o.d" -o ${OBJECTDIR}/_ext/1295770447/FTP.o "../../Microchip/TCPIP Stack/FTP.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/Hashes.o: ../../Microchip/TCPIP\ Stack/Hashes.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Hashes.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Hashes.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/Hashes.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/Hashes.o.d" -o ${OBJECTDIR}/_ext/1295770447/Hashes.o "../../Microchip/TCPIP Stack/Hashes.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/Helpers.o: ../../Microchip/TCPIP\ Stack/Helpers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Helpers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Helpers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/Helpers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/Helpers.o.d" -o ${OBJECTDIR}/_ext/1295770447/Helpers.o "../../Microchip/TCPIP Stack/Helpers.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/HTTP2.o: ../../Microchip/TCPIP\ Stack/HTTP2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/HTTP2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/HTTP2.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/HTTP2.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/HTTP2.o.d" -o ${OBJECTDIR}/_ext/1295770447/HTTP2.o "../../Microchip/TCPIP Stack/HTTP2.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/HTTP.o: ../../Microchip/TCPIP\ Stack/HTTP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/HTTP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/HTTP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/HTTP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/HTTP.o.d" -o ${OBJECTDIR}/_ext/1295770447/HTTP.o "../../Microchip/TCPIP Stack/HTTP.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/ICMP.o: ../../Microchip/TCPIP\ Stack/ICMP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ICMP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ICMP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/ICMP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/ICMP.o.d" -o ${OBJECTDIR}/_ext/1295770447/ICMP.o "../../Microchip/TCPIP Stack/ICMP.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/IP.o: ../../Microchip/TCPIP\ Stack/IP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/IP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/IP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/IP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/IP.o.d" -o ${OBJECTDIR}/_ext/1295770447/IP.o "../../Microchip/TCPIP Stack/IP.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/LCDBlocking.o: ../../Microchip/TCPIP\ Stack/LCDBlocking.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/LCDBlocking.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/LCDBlocking.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/LCDBlocking.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/LCDBlocking.o.d" -o ${OBJECTDIR}/_ext/1295770447/LCDBlocking.o "../../Microchip/TCPIP Stack/LCDBlocking.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/MPFS2.o: ../../Microchip/TCPIP\ Stack/MPFS2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/MPFS2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/MPFS2.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/MPFS2.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/MPFS2.o.d" -o ${OBJECTDIR}/_ext/1295770447/MPFS2.o "../../Microchip/TCPIP Stack/MPFS2.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/MPFS.o: ../../Microchip/TCPIP\ Stack/MPFS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/MPFS.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/MPFS.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/MPFS.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/MPFS.o.d" -o ${OBJECTDIR}/_ext/1295770447/MPFS.o "../../Microchip/TCPIP Stack/MPFS.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/NBNS.o: ../../Microchip/TCPIP\ Stack/NBNS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/NBNS.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/NBNS.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/NBNS.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/NBNS.o.d" -o ${OBJECTDIR}/_ext/1295770447/NBNS.o "../../Microchip/TCPIP Stack/NBNS.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/Random.o: ../../Microchip/TCPIP\ Stack/Random.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Random.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Random.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/Random.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/Random.o.d" -o ${OBJECTDIR}/_ext/1295770447/Random.o "../../Microchip/TCPIP Stack/Random.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/Reboot.o: ../../Microchip/TCPIP\ Stack/Reboot.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Reboot.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Reboot.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/Reboot.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/Reboot.o.d" -o ${OBJECTDIR}/_ext/1295770447/Reboot.o "../../Microchip/TCPIP Stack/Reboot.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/RSA.o: ../../Microchip/TCPIP\ Stack/RSA.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/RSA.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/RSA.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/RSA.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/RSA.o.d" -o ${OBJECTDIR}/_ext/1295770447/RSA.o "../../Microchip/TCPIP Stack/RSA.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/SMTP.o: ../../Microchip/TCPIP\ Stack/SMTP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SMTP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SMTP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/SMTP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/SMTP.o.d" -o ${OBJECTDIR}/_ext/1295770447/SMTP.o "../../Microchip/TCPIP Stack/SMTP.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/SNMP.o: ../../Microchip/TCPIP\ Stack/SNMP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SNMP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SNMP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/SNMP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/SNMP.o.d" -o ${OBJECTDIR}/_ext/1295770447/SNMP.o "../../Microchip/TCPIP Stack/SNMP.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/SNMPv3.o: ../../Microchip/TCPIP\ Stack/SNMPv3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SNMPv3.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SNMPv3.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/SNMPv3.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/SNMPv3.o.d" -o ${OBJECTDIR}/_ext/1295770447/SNMPv3.o "../../Microchip/TCPIP Stack/SNMPv3.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/SNMPv3USM.o: ../../Microchip/TCPIP\ Stack/SNMPv3USM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SNMPv3USM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SNMPv3USM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/SNMPv3USM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/SNMPv3USM.o.d" -o ${OBJECTDIR}/_ext/1295770447/SNMPv3USM.o "../../Microchip/TCPIP Stack/SNMPv3USM.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/SNTP.o: ../../Microchip/TCPIP\ Stack/SNTP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SNTP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SNTP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/SNTP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/SNTP.o.d" -o ${OBJECTDIR}/_ext/1295770447/SNTP.o "../../Microchip/TCPIP Stack/SNTP.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/SPIEEPROM.o: ../../Microchip/TCPIP\ Stack/SPIEEPROM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SPIEEPROM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SPIEEPROM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/SPIEEPROM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/SPIEEPROM.o.d" -o ${OBJECTDIR}/_ext/1295770447/SPIEEPROM.o "../../Microchip/TCPIP Stack/SPIEEPROM.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/SPIFlash.o: ../../Microchip/TCPIP\ Stack/SPIFlash.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SPIFlash.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SPIFlash.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/SPIFlash.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/SPIFlash.o.d" -o ${OBJECTDIR}/_ext/1295770447/SPIFlash.o "../../Microchip/TCPIP Stack/SPIFlash.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/SPIRAM.o: ../../Microchip/TCPIP\ Stack/SPIRAM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SPIRAM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SPIRAM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/SPIRAM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/SPIRAM.o.d" -o ${OBJECTDIR}/_ext/1295770447/SPIRAM.o "../../Microchip/TCPIP Stack/SPIRAM.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/SSL.o: ../../Microchip/TCPIP\ Stack/SSL.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SSL.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SSL.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/SSL.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/SSL.o.d" -o ${OBJECTDIR}/_ext/1295770447/SSL.o "../../Microchip/TCPIP Stack/SSL.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/StackTsk.o: ../../Microchip/TCPIP\ Stack/StackTsk.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/StackTsk.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/StackTsk.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/StackTsk.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/StackTsk.o.d" -o ${OBJECTDIR}/_ext/1295770447/StackTsk.o "../../Microchip/TCPIP Stack/StackTsk.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/TCP.o: ../../Microchip/TCPIP\ Stack/TCP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/TCP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/TCP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/TCP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/TCP.o.d" -o ${OBJECTDIR}/_ext/1295770447/TCP.o "../../Microchip/TCPIP Stack/TCP.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/TCPPerformanceTest.o: ../../Microchip/TCPIP\ Stack/TCPPerformanceTest.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/TCPPerformanceTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/TCPPerformanceTest.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/TCPPerformanceTest.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/TCPPerformanceTest.o.d" -o ${OBJECTDIR}/_ext/1295770447/TCPPerformanceTest.o "../../Microchip/TCPIP Stack/TCPPerformanceTest.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/Telnet.o: ../../Microchip/TCPIP\ Stack/Telnet.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Telnet.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Telnet.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/Telnet.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/Telnet.o.d" -o ${OBJECTDIR}/_ext/1295770447/Telnet.o "../../Microchip/TCPIP Stack/Telnet.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/TFTPc.o: ../../Microchip/TCPIP\ Stack/TFTPc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/TFTPc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/TFTPc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/TFTPc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/TFTPc.o.d" -o ${OBJECTDIR}/_ext/1295770447/TFTPc.o "../../Microchip/TCPIP Stack/TFTPc.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/Tick.o: ../../Microchip/TCPIP\ Stack/Tick.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Tick.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Tick.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/Tick.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/Tick.o.d" -o ${OBJECTDIR}/_ext/1295770447/Tick.o "../../Microchip/TCPIP Stack/Tick.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/UART2TCPBridge.o: ../../Microchip/TCPIP\ Stack/UART2TCPBridge.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/UART2TCPBridge.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/UART2TCPBridge.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/UART2TCPBridge.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/UART2TCPBridge.o.d" -o ${OBJECTDIR}/_ext/1295770447/UART2TCPBridge.o "../../Microchip/TCPIP Stack/UART2TCPBridge.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/UART.o: ../../Microchip/TCPIP\ Stack/UART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/UART.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/UART.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/UART.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/UART.o.d" -o ${OBJECTDIR}/_ext/1295770447/UART.o "../../Microchip/TCPIP Stack/UART.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/UDP.o: ../../Microchip/TCPIP\ Stack/UDP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/UDP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/UDP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/UDP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/UDP.o.d" -o ${OBJECTDIR}/_ext/1295770447/UDP.o "../../Microchip/TCPIP Stack/UDP.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/UDPPerformanceTest.o: ../../Microchip/TCPIP\ Stack/UDPPerformanceTest.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/UDPPerformanceTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/UDPPerformanceTest.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/UDPPerformanceTest.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/UDPPerformanceTest.o.d" -o ${OBJECTDIR}/_ext/1295770447/UDPPerformanceTest.o "../../Microchip/TCPIP Stack/UDPPerformanceTest.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/ZeroconfHelper.o: ../../Microchip/TCPIP\ Stack/ZeroconfHelper.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ZeroconfHelper.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ZeroconfHelper.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/ZeroconfHelper.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/ZeroconfHelper.o.d" -o ${OBJECTDIR}/_ext/1295770447/ZeroconfHelper.o "../../Microchip/TCPIP Stack/ZeroconfHelper.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/ZeroconfLinkLocal.o: ../../Microchip/TCPIP\ Stack/ZeroconfLinkLocal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ZeroconfLinkLocal.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ZeroconfLinkLocal.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/ZeroconfLinkLocal.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/ZeroconfLinkLocal.o.d" -o ${OBJECTDIR}/_ext/1295770447/ZeroconfLinkLocal.o "../../Microchip/TCPIP Stack/ZeroconfLinkLocal.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/ZeroconfMulticastDNS.o: ../../Microchip/TCPIP\ Stack/ZeroconfMulticastDNS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ZeroconfMulticastDNS.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ZeroconfMulticastDNS.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/ZeroconfMulticastDNS.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/ZeroconfMulticastDNS.o.d" -o ${OBJECTDIR}/_ext/1295770447/ZeroconfMulticastDNS.o "../../Microchip/TCPIP Stack/ZeroconfMulticastDNS.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1472/MPFSImg2.o: ../MPFSImg2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/MPFSImg2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/MPFSImg2.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/MPFSImg2.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/MPFSImg2.o.d" -o ${OBJECTDIR}/_ext/1472/MPFSImg2.o ../MPFSImg2.c  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1472/MPFSImg.o: ../MPFSImg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/MPFSImg.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/MPFSImg.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/MPFSImg.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/MPFSImg.o.d" -o ${OBJECTDIR}/_ext/1472/MPFSImg.o ../MPFSImg.c  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1472/CustomHTTPApp.o: ../CustomHTTPApp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/CustomHTTPApp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/CustomHTTPApp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/CustomHTTPApp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/CustomHTTPApp.o.d" -o ${OBJECTDIR}/_ext/1472/CustomHTTPApp.o ../CustomHTTPApp.c  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1472/CustomSNMPApp.o: ../CustomSNMPApp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/CustomSNMPApp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/CustomSNMPApp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/CustomSNMPApp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/CustomSNMPApp.o.d" -o ${OBJECTDIR}/_ext/1472/CustomSNMPApp.o ../CustomSNMPApp.c  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1472/CustomSSLCert.o: ../CustomSSLCert.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/CustomSSLCert.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/CustomSSLCert.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/CustomSSLCert.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/CustomSSLCert.o.d" -o ${OBJECTDIR}/_ext/1472/CustomSSLCert.o ../CustomSSLCert.c  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1472/MainDemo.o: ../MainDemo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/MainDemo.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/MainDemo.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/MainDemo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/MainDemo.o.d" -o ${OBJECTDIR}/_ext/1472/MainDemo.o ../MainDemo.c  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1472/mbmc.o: ../mbmc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/mbmc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/mbmc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/mbmc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/mbmc.o.d" -o ${OBJECTDIR}/_ext/1472/mbmc.o ../mbmc.c  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1472/crc8_fast.o: ../crc8_fast.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/crc8_fast.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/crc8_fast.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/crc8_fast.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PIC32MXSK=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/crc8_fast.o.d" -o ${OBJECTDIR}/_ext/1472/crc8_fast.o ../crc8_fast.c  -legacy-libc -membedded-data 
	
else
${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o: ../BerkeleyTCPClientDemo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o.d" -o ${OBJECTDIR}/_ext/1472/BerkeleyTCPClientDemo.o ../BerkeleyTCPClientDemo.c  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o: ../BerkeleyTCPServerDemo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o.d" -o ${OBJECTDIR}/_ext/1472/BerkeleyTCPServerDemo.o ../BerkeleyTCPServerDemo.c  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o: ../BerkeleyUDPClientDemo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o.d" -o ${OBJECTDIR}/_ext/1472/BerkeleyUDPClientDemo.o ../BerkeleyUDPClientDemo.c  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1472/GenericTCPClient.o: ../GenericTCPClient.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/GenericTCPClient.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/GenericTCPClient.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/GenericTCPClient.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/GenericTCPClient.o.d" -o ${OBJECTDIR}/_ext/1472/GenericTCPClient.o ../GenericTCPClient.c  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1472/GenericTCPServer.o: ../GenericTCPServer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/GenericTCPServer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/GenericTCPServer.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/GenericTCPServer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/GenericTCPServer.o.d" -o ${OBJECTDIR}/_ext/1472/GenericTCPServer.o ../GenericTCPServer.c  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1472/LegacyHTTPApp.o: ../LegacyHTTPApp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/LegacyHTTPApp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/LegacyHTTPApp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/LegacyHTTPApp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/LegacyHTTPApp.o.d" -o ${OBJECTDIR}/_ext/1472/LegacyHTTPApp.o ../LegacyHTTPApp.c  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1472/PingDemo.o: ../PingDemo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/PingDemo.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/PingDemo.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/PingDemo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/PingDemo.o.d" -o ${OBJECTDIR}/_ext/1472/PingDemo.o ../PingDemo.c  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1472/SMTPDemo.o: ../SMTPDemo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/SMTPDemo.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/SMTPDemo.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/SMTPDemo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/SMTPDemo.o.d" -o ${OBJECTDIR}/_ext/1472/SMTPDemo.o ../SMTPDemo.c  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1472/UARTConfig.o: ../UARTConfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/UARTConfig.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/UARTConfig.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/UARTConfig.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/UARTConfig.o.d" -o ${OBJECTDIR}/_ext/1472/UARTConfig.o ../UARTConfig.c  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/Announce.o: ../../Microchip/TCPIP\ Stack/Announce.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Announce.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Announce.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/Announce.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/Announce.o.d" -o ${OBJECTDIR}/_ext/1295770447/Announce.o "../../Microchip/TCPIP Stack/Announce.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/ARCFOUR.o: ../../Microchip/TCPIP\ Stack/ARCFOUR.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ARCFOUR.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ARCFOUR.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/ARCFOUR.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/ARCFOUR.o.d" -o ${OBJECTDIR}/_ext/1295770447/ARCFOUR.o "../../Microchip/TCPIP Stack/ARCFOUR.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/ARP.o: ../../Microchip/TCPIP\ Stack/ARP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ARP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ARP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/ARP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/ARP.o.d" -o ${OBJECTDIR}/_ext/1295770447/ARP.o "../../Microchip/TCPIP Stack/ARP.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/AutoIP.o: ../../Microchip/TCPIP\ Stack/AutoIP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/AutoIP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/AutoIP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/AutoIP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/AutoIP.o.d" -o ${OBJECTDIR}/_ext/1295770447/AutoIP.o "../../Microchip/TCPIP Stack/AutoIP.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/BerkeleyAPI.o: ../../Microchip/TCPIP\ Stack/BerkeleyAPI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/BerkeleyAPI.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/BerkeleyAPI.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/BerkeleyAPI.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/BerkeleyAPI.o.d" -o ${OBJECTDIR}/_ext/1295770447/BerkeleyAPI.o "../../Microchip/TCPIP Stack/BerkeleyAPI.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/BigInt.o: ../../Microchip/TCPIP\ Stack/BigInt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/BigInt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/BigInt.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/BigInt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/BigInt.o.d" -o ${OBJECTDIR}/_ext/1295770447/BigInt.o "../../Microchip/TCPIP Stack/BigInt.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/Delay.o: ../../Microchip/TCPIP\ Stack/Delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Delay.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Delay.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/Delay.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/Delay.o.d" -o ${OBJECTDIR}/_ext/1295770447/Delay.o "../../Microchip/TCPIP Stack/Delay.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/DHCP.o: ../../Microchip/TCPIP\ Stack/DHCP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/DHCP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/DHCP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/DHCP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/DHCP.o.d" -o ${OBJECTDIR}/_ext/1295770447/DHCP.o "../../Microchip/TCPIP Stack/DHCP.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/DHCPs.o: ../../Microchip/TCPIP\ Stack/DHCPs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/DHCPs.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/DHCPs.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/DHCPs.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/DHCPs.o.d" -o ${OBJECTDIR}/_ext/1295770447/DHCPs.o "../../Microchip/TCPIP Stack/DHCPs.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/DNS.o: ../../Microchip/TCPIP\ Stack/DNS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/DNS.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/DNS.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/DNS.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/DNS.o.d" -o ${OBJECTDIR}/_ext/1295770447/DNS.o "../../Microchip/TCPIP Stack/DNS.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/DNSs.o: ../../Microchip/TCPIP\ Stack/DNSs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/DNSs.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/DNSs.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/DNSs.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/DNSs.o.d" -o ${OBJECTDIR}/_ext/1295770447/DNSs.o "../../Microchip/TCPIP Stack/DNSs.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/DynDNS.o: ../../Microchip/TCPIP\ Stack/DynDNS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/DynDNS.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/DynDNS.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/DynDNS.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/DynDNS.o.d" -o ${OBJECTDIR}/_ext/1295770447/DynDNS.o "../../Microchip/TCPIP Stack/DynDNS.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/ENC28J60.o: ../../Microchip/TCPIP\ Stack/ENC28J60.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ENC28J60.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ENC28J60.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/ENC28J60.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/ENC28J60.o.d" -o ${OBJECTDIR}/_ext/1295770447/ENC28J60.o "../../Microchip/TCPIP Stack/ENC28J60.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/ENCX24J600.o: ../../Microchip/TCPIP\ Stack/ENCX24J600.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ENCX24J600.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ENCX24J600.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/ENCX24J600.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/ENCX24J600.o.d" -o ${OBJECTDIR}/_ext/1295770447/ENCX24J600.o "../../Microchip/TCPIP Stack/ENCX24J600.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/ETHPIC32ExtPhy.o: ../../Microchip/TCPIP\ Stack/ETHPIC32ExtPhy.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ETHPIC32ExtPhy.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ETHPIC32ExtPhy.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/ETHPIC32ExtPhy.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/ETHPIC32ExtPhy.o.d" -o ${OBJECTDIR}/_ext/1295770447/ETHPIC32ExtPhy.o "../../Microchip/TCPIP Stack/ETHPIC32ExtPhy.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/ETHPIC32ExtPhyDP83848.o: ../../Microchip/TCPIP\ Stack/ETHPIC32ExtPhyDP83848.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ETHPIC32ExtPhyDP83848.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ETHPIC32ExtPhyDP83848.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/ETHPIC32ExtPhyDP83848.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/ETHPIC32ExtPhyDP83848.o.d" -o ${OBJECTDIR}/_ext/1295770447/ETHPIC32ExtPhyDP83848.o "../../Microchip/TCPIP Stack/ETHPIC32ExtPhyDP83848.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/ETHPIC32IntMac.o: ../../Microchip/TCPIP\ Stack/ETHPIC32IntMac.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ETHPIC32IntMac.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ETHPIC32IntMac.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/ETHPIC32IntMac.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/ETHPIC32IntMac.o.d" -o ${OBJECTDIR}/_ext/1295770447/ETHPIC32IntMac.o "../../Microchip/TCPIP Stack/ETHPIC32IntMac.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/FileSystem.o: ../../Microchip/TCPIP\ Stack/FileSystem.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/FileSystem.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/FileSystem.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/FileSystem.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/FileSystem.o.d" -o ${OBJECTDIR}/_ext/1295770447/FileSystem.o "../../Microchip/TCPIP Stack/FileSystem.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/FTP.o: ../../Microchip/TCPIP\ Stack/FTP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/FTP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/FTP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/FTP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/FTP.o.d" -o ${OBJECTDIR}/_ext/1295770447/FTP.o "../../Microchip/TCPIP Stack/FTP.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/Hashes.o: ../../Microchip/TCPIP\ Stack/Hashes.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Hashes.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Hashes.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/Hashes.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/Hashes.o.d" -o ${OBJECTDIR}/_ext/1295770447/Hashes.o "../../Microchip/TCPIP Stack/Hashes.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/Helpers.o: ../../Microchip/TCPIP\ Stack/Helpers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Helpers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Helpers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/Helpers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/Helpers.o.d" -o ${OBJECTDIR}/_ext/1295770447/Helpers.o "../../Microchip/TCPIP Stack/Helpers.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/HTTP2.o: ../../Microchip/TCPIP\ Stack/HTTP2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/HTTP2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/HTTP2.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/HTTP2.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/HTTP2.o.d" -o ${OBJECTDIR}/_ext/1295770447/HTTP2.o "../../Microchip/TCPIP Stack/HTTP2.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/HTTP.o: ../../Microchip/TCPIP\ Stack/HTTP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/HTTP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/HTTP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/HTTP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/HTTP.o.d" -o ${OBJECTDIR}/_ext/1295770447/HTTP.o "../../Microchip/TCPIP Stack/HTTP.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/ICMP.o: ../../Microchip/TCPIP\ Stack/ICMP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ICMP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ICMP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/ICMP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/ICMP.o.d" -o ${OBJECTDIR}/_ext/1295770447/ICMP.o "../../Microchip/TCPIP Stack/ICMP.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/IP.o: ../../Microchip/TCPIP\ Stack/IP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/IP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/IP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/IP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/IP.o.d" -o ${OBJECTDIR}/_ext/1295770447/IP.o "../../Microchip/TCPIP Stack/IP.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/LCDBlocking.o: ../../Microchip/TCPIP\ Stack/LCDBlocking.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/LCDBlocking.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/LCDBlocking.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/LCDBlocking.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/LCDBlocking.o.d" -o ${OBJECTDIR}/_ext/1295770447/LCDBlocking.o "../../Microchip/TCPIP Stack/LCDBlocking.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/MPFS2.o: ../../Microchip/TCPIP\ Stack/MPFS2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/MPFS2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/MPFS2.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/MPFS2.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/MPFS2.o.d" -o ${OBJECTDIR}/_ext/1295770447/MPFS2.o "../../Microchip/TCPIP Stack/MPFS2.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/MPFS.o: ../../Microchip/TCPIP\ Stack/MPFS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/MPFS.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/MPFS.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/MPFS.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/MPFS.o.d" -o ${OBJECTDIR}/_ext/1295770447/MPFS.o "../../Microchip/TCPIP Stack/MPFS.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/NBNS.o: ../../Microchip/TCPIP\ Stack/NBNS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/NBNS.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/NBNS.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/NBNS.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/NBNS.o.d" -o ${OBJECTDIR}/_ext/1295770447/NBNS.o "../../Microchip/TCPIP Stack/NBNS.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/Random.o: ../../Microchip/TCPIP\ Stack/Random.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Random.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Random.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/Random.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/Random.o.d" -o ${OBJECTDIR}/_ext/1295770447/Random.o "../../Microchip/TCPIP Stack/Random.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/Reboot.o: ../../Microchip/TCPIP\ Stack/Reboot.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Reboot.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Reboot.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/Reboot.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/Reboot.o.d" -o ${OBJECTDIR}/_ext/1295770447/Reboot.o "../../Microchip/TCPIP Stack/Reboot.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/RSA.o: ../../Microchip/TCPIP\ Stack/RSA.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/RSA.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/RSA.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/RSA.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/RSA.o.d" -o ${OBJECTDIR}/_ext/1295770447/RSA.o "../../Microchip/TCPIP Stack/RSA.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/SMTP.o: ../../Microchip/TCPIP\ Stack/SMTP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SMTP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SMTP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/SMTP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/SMTP.o.d" -o ${OBJECTDIR}/_ext/1295770447/SMTP.o "../../Microchip/TCPIP Stack/SMTP.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/SNMP.o: ../../Microchip/TCPIP\ Stack/SNMP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SNMP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SNMP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/SNMP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/SNMP.o.d" -o ${OBJECTDIR}/_ext/1295770447/SNMP.o "../../Microchip/TCPIP Stack/SNMP.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/SNMPv3.o: ../../Microchip/TCPIP\ Stack/SNMPv3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SNMPv3.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SNMPv3.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/SNMPv3.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/SNMPv3.o.d" -o ${OBJECTDIR}/_ext/1295770447/SNMPv3.o "../../Microchip/TCPIP Stack/SNMPv3.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/SNMPv3USM.o: ../../Microchip/TCPIP\ Stack/SNMPv3USM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SNMPv3USM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SNMPv3USM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/SNMPv3USM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/SNMPv3USM.o.d" -o ${OBJECTDIR}/_ext/1295770447/SNMPv3USM.o "../../Microchip/TCPIP Stack/SNMPv3USM.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/SNTP.o: ../../Microchip/TCPIP\ Stack/SNTP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SNTP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SNTP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/SNTP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/SNTP.o.d" -o ${OBJECTDIR}/_ext/1295770447/SNTP.o "../../Microchip/TCPIP Stack/SNTP.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/SPIEEPROM.o: ../../Microchip/TCPIP\ Stack/SPIEEPROM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SPIEEPROM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SPIEEPROM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/SPIEEPROM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/SPIEEPROM.o.d" -o ${OBJECTDIR}/_ext/1295770447/SPIEEPROM.o "../../Microchip/TCPIP Stack/SPIEEPROM.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/SPIFlash.o: ../../Microchip/TCPIP\ Stack/SPIFlash.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SPIFlash.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SPIFlash.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/SPIFlash.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/SPIFlash.o.d" -o ${OBJECTDIR}/_ext/1295770447/SPIFlash.o "../../Microchip/TCPIP Stack/SPIFlash.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/SPIRAM.o: ../../Microchip/TCPIP\ Stack/SPIRAM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SPIRAM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SPIRAM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/SPIRAM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/SPIRAM.o.d" -o ${OBJECTDIR}/_ext/1295770447/SPIRAM.o "../../Microchip/TCPIP Stack/SPIRAM.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/SSL.o: ../../Microchip/TCPIP\ Stack/SSL.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SSL.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/SSL.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/SSL.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/SSL.o.d" -o ${OBJECTDIR}/_ext/1295770447/SSL.o "../../Microchip/TCPIP Stack/SSL.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/StackTsk.o: ../../Microchip/TCPIP\ Stack/StackTsk.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/StackTsk.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/StackTsk.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/StackTsk.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/StackTsk.o.d" -o ${OBJECTDIR}/_ext/1295770447/StackTsk.o "../../Microchip/TCPIP Stack/StackTsk.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/TCP.o: ../../Microchip/TCPIP\ Stack/TCP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/TCP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/TCP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/TCP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/TCP.o.d" -o ${OBJECTDIR}/_ext/1295770447/TCP.o "../../Microchip/TCPIP Stack/TCP.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/TCPPerformanceTest.o: ../../Microchip/TCPIP\ Stack/TCPPerformanceTest.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/TCPPerformanceTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/TCPPerformanceTest.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/TCPPerformanceTest.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/TCPPerformanceTest.o.d" -o ${OBJECTDIR}/_ext/1295770447/TCPPerformanceTest.o "../../Microchip/TCPIP Stack/TCPPerformanceTest.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/Telnet.o: ../../Microchip/TCPIP\ Stack/Telnet.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Telnet.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Telnet.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/Telnet.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/Telnet.o.d" -o ${OBJECTDIR}/_ext/1295770447/Telnet.o "../../Microchip/TCPIP Stack/Telnet.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/TFTPc.o: ../../Microchip/TCPIP\ Stack/TFTPc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/TFTPc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/TFTPc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/TFTPc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/TFTPc.o.d" -o ${OBJECTDIR}/_ext/1295770447/TFTPc.o "../../Microchip/TCPIP Stack/TFTPc.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/Tick.o: ../../Microchip/TCPIP\ Stack/Tick.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Tick.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/Tick.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/Tick.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/Tick.o.d" -o ${OBJECTDIR}/_ext/1295770447/Tick.o "../../Microchip/TCPIP Stack/Tick.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/UART2TCPBridge.o: ../../Microchip/TCPIP\ Stack/UART2TCPBridge.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/UART2TCPBridge.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/UART2TCPBridge.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/UART2TCPBridge.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/UART2TCPBridge.o.d" -o ${OBJECTDIR}/_ext/1295770447/UART2TCPBridge.o "../../Microchip/TCPIP Stack/UART2TCPBridge.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/UART.o: ../../Microchip/TCPIP\ Stack/UART.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/UART.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/UART.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/UART.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/UART.o.d" -o ${OBJECTDIR}/_ext/1295770447/UART.o "../../Microchip/TCPIP Stack/UART.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/UDP.o: ../../Microchip/TCPIP\ Stack/UDP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/UDP.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/UDP.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/UDP.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/UDP.o.d" -o ${OBJECTDIR}/_ext/1295770447/UDP.o "../../Microchip/TCPIP Stack/UDP.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/UDPPerformanceTest.o: ../../Microchip/TCPIP\ Stack/UDPPerformanceTest.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/UDPPerformanceTest.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/UDPPerformanceTest.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/UDPPerformanceTest.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/UDPPerformanceTest.o.d" -o ${OBJECTDIR}/_ext/1295770447/UDPPerformanceTest.o "../../Microchip/TCPIP Stack/UDPPerformanceTest.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/ZeroconfHelper.o: ../../Microchip/TCPIP\ Stack/ZeroconfHelper.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ZeroconfHelper.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ZeroconfHelper.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/ZeroconfHelper.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/ZeroconfHelper.o.d" -o ${OBJECTDIR}/_ext/1295770447/ZeroconfHelper.o "../../Microchip/TCPIP Stack/ZeroconfHelper.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/ZeroconfLinkLocal.o: ../../Microchip/TCPIP\ Stack/ZeroconfLinkLocal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ZeroconfLinkLocal.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ZeroconfLinkLocal.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/ZeroconfLinkLocal.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/ZeroconfLinkLocal.o.d" -o ${OBJECTDIR}/_ext/1295770447/ZeroconfLinkLocal.o "../../Microchip/TCPIP Stack/ZeroconfLinkLocal.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1295770447/ZeroconfMulticastDNS.o: ../../Microchip/TCPIP\ Stack/ZeroconfMulticastDNS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295770447" 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ZeroconfMulticastDNS.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295770447/ZeroconfMulticastDNS.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295770447/ZeroconfMulticastDNS.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1295770447/ZeroconfMulticastDNS.o.d" -o ${OBJECTDIR}/_ext/1295770447/ZeroconfMulticastDNS.o "../../Microchip/TCPIP Stack/ZeroconfMulticastDNS.c"  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1472/MPFSImg2.o: ../MPFSImg2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/MPFSImg2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/MPFSImg2.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/MPFSImg2.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/MPFSImg2.o.d" -o ${OBJECTDIR}/_ext/1472/MPFSImg2.o ../MPFSImg2.c  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1472/MPFSImg.o: ../MPFSImg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/MPFSImg.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/MPFSImg.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/MPFSImg.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/MPFSImg.o.d" -o ${OBJECTDIR}/_ext/1472/MPFSImg.o ../MPFSImg.c  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1472/CustomHTTPApp.o: ../CustomHTTPApp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/CustomHTTPApp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/CustomHTTPApp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/CustomHTTPApp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/CustomHTTPApp.o.d" -o ${OBJECTDIR}/_ext/1472/CustomHTTPApp.o ../CustomHTTPApp.c  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1472/CustomSNMPApp.o: ../CustomSNMPApp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/CustomSNMPApp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/CustomSNMPApp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/CustomSNMPApp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/CustomSNMPApp.o.d" -o ${OBJECTDIR}/_ext/1472/CustomSNMPApp.o ../CustomSNMPApp.c  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1472/CustomSSLCert.o: ../CustomSSLCert.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/CustomSSLCert.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/CustomSSLCert.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/CustomSSLCert.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/CustomSSLCert.o.d" -o ${OBJECTDIR}/_ext/1472/CustomSSLCert.o ../CustomSSLCert.c  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1472/MainDemo.o: ../MainDemo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/MainDemo.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/MainDemo.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/MainDemo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/MainDemo.o.d" -o ${OBJECTDIR}/_ext/1472/MainDemo.o ../MainDemo.c  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1472/mbmc.o: ../mbmc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/mbmc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/mbmc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/mbmc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/mbmc.o.d" -o ${OBJECTDIR}/_ext/1472/mbmc.o ../mbmc.c  -legacy-libc -membedded-data 
	
${OBJECTDIR}/_ext/1472/crc8_fast.o: ../crc8_fast.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/crc8_fast.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/crc8_fast.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/crc8_fast.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DPIC32_ENET_SK_DM320004_INTERNAL_ETHERNET -I".." -I"../../Microchip/Include" -I"../../Microchip/Include/TCPIP Stack" -I"../Alternative Configurations" -I"../../Microchip/Include/Crypto" -O2 -fomit-frame-pointer -fschedule-insns -fschedule-insns2 -Wall -MMD -MF "${OBJECTDIR}/_ext/1472/crc8_fast.o.d" -o ${OBJECTDIR}/_ext/1472/crc8_fast.o ../crc8_fast.c  -legacy-libc -membedded-data 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/TCPIP_Demo_App_-_C32_-_PIC32_ENET_SK_DM320004_INTERNAL_ETHERNET.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../Microchip/Crypto/AES_PIC32MX.a  
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mdebugger -D__MPLAB_DEBUGGER_PIC32MXSK=1 -mprocessor=$(MP_PROCESSOR_OPTION) -O3 -o dist/${CND_CONF}/${IMAGE_TYPE}/TCPIP_Demo_App_-_C32_-_PIC32_ENET_SK_DM320004_INTERNAL_ETHERNET.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}   ../../Microchip/Crypto/AES_PIC32MX.a   -legacy-libc -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PIC32MXSK=1,--defsym=_min_heap_size=16000,--defsym=_min_stack_size=2048,-L"..",-Map="${DISTDIR}/TCPIP_Demo_App_-_C32_-_PIC32_ENET_SK_DM320004_INTERNAL_ETHERNET.X.${IMAGE_TYPE}.map",-Os  
else
dist/${CND_CONF}/${IMAGE_TYPE}/TCPIP_Demo_App_-_C32_-_PIC32_ENET_SK_DM320004_INTERNAL_ETHERNET.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../Microchip/Crypto/AES_PIC32MX.a 
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION) -O3 -o dist/${CND_CONF}/${IMAGE_TYPE}/TCPIP_Demo_App_-_C32_-_PIC32_ENET_SK_DM320004_INTERNAL_ETHERNET.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}   ../../Microchip/Crypto/AES_PIC32MX.a   -legacy-libc -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=16000,--defsym=_min_stack_size=2048,-L"..",-Map="${DISTDIR}/TCPIP_Demo_App_-_C32_-_PIC32_ENET_SK_DM320004_INTERNAL_ETHERNET.X.${IMAGE_TYPE}.map",-Os 
	${MP_CC_DIR}/pic32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/TCPIP_Demo_App_-_C32_-_PIC32_ENET_SK_DM320004_INTERNAL_ETHERNET.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
