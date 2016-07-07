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
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/swm8722.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/swm8722.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../swm8722.c ../crc8_fast.c ../xlcd/busyxlcd.c ../xlcd/openxlcd.c ../xlcd/putrxlcd.c ../xlcd/putsxlcd.c ../xlcd/readaddr.c ../xlcd/readdata.c ../xlcd/setcgram.c ../xlcd/setddram.c ../xlcd/wcmdxlcd.c ../xlcd/writdata.c ../crit.c ../sdspi.c ../hwconf.c ../model.c ../power.c ../mbmc_vector.c ../daq.c ../timelib.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1472/swm8722.o ${OBJECTDIR}/_ext/1472/crc8_fast.o ${OBJECTDIR}/_ext/760475324/busyxlcd.o ${OBJECTDIR}/_ext/760475324/openxlcd.o ${OBJECTDIR}/_ext/760475324/putrxlcd.o ${OBJECTDIR}/_ext/760475324/putsxlcd.o ${OBJECTDIR}/_ext/760475324/readaddr.o ${OBJECTDIR}/_ext/760475324/readdata.o ${OBJECTDIR}/_ext/760475324/setcgram.o ${OBJECTDIR}/_ext/760475324/setddram.o ${OBJECTDIR}/_ext/760475324/wcmdxlcd.o ${OBJECTDIR}/_ext/760475324/writdata.o ${OBJECTDIR}/_ext/1472/crit.o ${OBJECTDIR}/_ext/1472/sdspi.o ${OBJECTDIR}/_ext/1472/hwconf.o ${OBJECTDIR}/_ext/1472/model.o ${OBJECTDIR}/_ext/1472/power.o ${OBJECTDIR}/_ext/1472/mbmc_vector.o ${OBJECTDIR}/_ext/1472/daq.o ${OBJECTDIR}/_ext/1472/timelib.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1472/swm8722.o.d ${OBJECTDIR}/_ext/1472/crc8_fast.o.d ${OBJECTDIR}/_ext/760475324/busyxlcd.o.d ${OBJECTDIR}/_ext/760475324/openxlcd.o.d ${OBJECTDIR}/_ext/760475324/putrxlcd.o.d ${OBJECTDIR}/_ext/760475324/putsxlcd.o.d ${OBJECTDIR}/_ext/760475324/readaddr.o.d ${OBJECTDIR}/_ext/760475324/readdata.o.d ${OBJECTDIR}/_ext/760475324/setcgram.o.d ${OBJECTDIR}/_ext/760475324/setddram.o.d ${OBJECTDIR}/_ext/760475324/wcmdxlcd.o.d ${OBJECTDIR}/_ext/760475324/writdata.o.d ${OBJECTDIR}/_ext/1472/crit.o.d ${OBJECTDIR}/_ext/1472/sdspi.o.d ${OBJECTDIR}/_ext/1472/hwconf.o.d ${OBJECTDIR}/_ext/1472/model.o.d ${OBJECTDIR}/_ext/1472/power.o.d ${OBJECTDIR}/_ext/1472/mbmc_vector.o.d ${OBJECTDIR}/_ext/1472/daq.o.d ${OBJECTDIR}/_ext/1472/timelib.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1472/swm8722.o ${OBJECTDIR}/_ext/1472/crc8_fast.o ${OBJECTDIR}/_ext/760475324/busyxlcd.o ${OBJECTDIR}/_ext/760475324/openxlcd.o ${OBJECTDIR}/_ext/760475324/putrxlcd.o ${OBJECTDIR}/_ext/760475324/putsxlcd.o ${OBJECTDIR}/_ext/760475324/readaddr.o ${OBJECTDIR}/_ext/760475324/readdata.o ${OBJECTDIR}/_ext/760475324/setcgram.o ${OBJECTDIR}/_ext/760475324/setddram.o ${OBJECTDIR}/_ext/760475324/wcmdxlcd.o ${OBJECTDIR}/_ext/760475324/writdata.o ${OBJECTDIR}/_ext/1472/crit.o ${OBJECTDIR}/_ext/1472/sdspi.o ${OBJECTDIR}/_ext/1472/hwconf.o ${OBJECTDIR}/_ext/1472/model.o ${OBJECTDIR}/_ext/1472/power.o ${OBJECTDIR}/_ext/1472/mbmc_vector.o ${OBJECTDIR}/_ext/1472/daq.o ${OBJECTDIR}/_ext/1472/timelib.o

# Source Files
SOURCEFILES=../swm8722.c ../crc8_fast.c ../xlcd/busyxlcd.c ../xlcd/openxlcd.c ../xlcd/putrxlcd.c ../xlcd/putsxlcd.c ../xlcd/readaddr.c ../xlcd/readdata.c ../xlcd/setcgram.c ../xlcd/setddram.c ../xlcd/wcmdxlcd.c ../xlcd/writdata.c ../crit.c ../sdspi.c ../hwconf.c ../model.c ../power.c ../mbmc_vector.c ../daq.c ../timelib.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/swm8722.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F8722
MP_PROCESSOR_OPTION_LD=18f8722
MP_LINKER_DEBUG_OPTION= -u_DEBUGCODESTART=0x1fd30 -u_DEBUGCODELEN=0x2d0 -u_DEBUGDATASTART=0xef4 -u_DEBUGDATALEN=0xb
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1472/swm8722.o: ../swm8722.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/swm8722.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/swm8722.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/swm8722.o   ../swm8722.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/swm8722.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/swm8722.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/crc8_fast.o: ../crc8_fast.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/crc8_fast.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/crc8_fast.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/crc8_fast.o   ../crc8_fast.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/crc8_fast.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/crc8_fast.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/760475324/busyxlcd.o: ../xlcd/busyxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/760475324" 
	@${RM} ${OBJECTDIR}/_ext/760475324/busyxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/760475324/busyxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/760475324/busyxlcd.o   ../xlcd/busyxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/760475324/busyxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/760475324/busyxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/760475324/openxlcd.o: ../xlcd/openxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/760475324" 
	@${RM} ${OBJECTDIR}/_ext/760475324/openxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/760475324/openxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/760475324/openxlcd.o   ../xlcd/openxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/760475324/openxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/760475324/openxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/760475324/putrxlcd.o: ../xlcd/putrxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/760475324" 
	@${RM} ${OBJECTDIR}/_ext/760475324/putrxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/760475324/putrxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/760475324/putrxlcd.o   ../xlcd/putrxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/760475324/putrxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/760475324/putrxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/760475324/putsxlcd.o: ../xlcd/putsxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/760475324" 
	@${RM} ${OBJECTDIR}/_ext/760475324/putsxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/760475324/putsxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/760475324/putsxlcd.o   ../xlcd/putsxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/760475324/putsxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/760475324/putsxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/760475324/readaddr.o: ../xlcd/readaddr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/760475324" 
	@${RM} ${OBJECTDIR}/_ext/760475324/readaddr.o.d 
	@${RM} ${OBJECTDIR}/_ext/760475324/readaddr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/760475324/readaddr.o   ../xlcd/readaddr.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/760475324/readaddr.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/760475324/readaddr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/760475324/readdata.o: ../xlcd/readdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/760475324" 
	@${RM} ${OBJECTDIR}/_ext/760475324/readdata.o.d 
	@${RM} ${OBJECTDIR}/_ext/760475324/readdata.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/760475324/readdata.o   ../xlcd/readdata.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/760475324/readdata.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/760475324/readdata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/760475324/setcgram.o: ../xlcd/setcgram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/760475324" 
	@${RM} ${OBJECTDIR}/_ext/760475324/setcgram.o.d 
	@${RM} ${OBJECTDIR}/_ext/760475324/setcgram.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/760475324/setcgram.o   ../xlcd/setcgram.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/760475324/setcgram.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/760475324/setcgram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/760475324/setddram.o: ../xlcd/setddram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/760475324" 
	@${RM} ${OBJECTDIR}/_ext/760475324/setddram.o.d 
	@${RM} ${OBJECTDIR}/_ext/760475324/setddram.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/760475324/setddram.o   ../xlcd/setddram.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/760475324/setddram.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/760475324/setddram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/760475324/wcmdxlcd.o: ../xlcd/wcmdxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/760475324" 
	@${RM} ${OBJECTDIR}/_ext/760475324/wcmdxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/760475324/wcmdxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/760475324/wcmdxlcd.o   ../xlcd/wcmdxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/760475324/wcmdxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/760475324/wcmdxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/760475324/writdata.o: ../xlcd/writdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/760475324" 
	@${RM} ${OBJECTDIR}/_ext/760475324/writdata.o.d 
	@${RM} ${OBJECTDIR}/_ext/760475324/writdata.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/760475324/writdata.o   ../xlcd/writdata.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/760475324/writdata.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/760475324/writdata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/crit.o: ../crit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/crit.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/crit.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/crit.o   ../crit.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/crit.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/crit.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/sdspi.o: ../sdspi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/sdspi.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/sdspi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/sdspi.o   ../sdspi.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/sdspi.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/sdspi.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/hwconf.o: ../hwconf.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/hwconf.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/hwconf.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/hwconf.o   ../hwconf.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/hwconf.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/hwconf.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/model.o: ../model.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/model.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/model.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/model.o   ../model.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/model.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/model.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/power.o: ../power.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/power.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/power.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/power.o   ../power.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/power.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/power.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/mbmc_vector.o: ../mbmc_vector.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/mbmc_vector.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/mbmc_vector.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/mbmc_vector.o   ../mbmc_vector.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/mbmc_vector.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/mbmc_vector.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/daq.o: ../daq.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/daq.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/daq.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/daq.o   ../daq.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/daq.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/daq.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/timelib.o: ../timelib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/timelib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/timelib.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/timelib.o   ../timelib.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/timelib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/timelib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
else
${OBJECTDIR}/_ext/1472/swm8722.o: ../swm8722.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/swm8722.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/swm8722.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/swm8722.o   ../swm8722.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/swm8722.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/swm8722.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/crc8_fast.o: ../crc8_fast.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/crc8_fast.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/crc8_fast.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/crc8_fast.o   ../crc8_fast.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/crc8_fast.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/crc8_fast.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/760475324/busyxlcd.o: ../xlcd/busyxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/760475324" 
	@${RM} ${OBJECTDIR}/_ext/760475324/busyxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/760475324/busyxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/760475324/busyxlcd.o   ../xlcd/busyxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/760475324/busyxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/760475324/busyxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/760475324/openxlcd.o: ../xlcd/openxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/760475324" 
	@${RM} ${OBJECTDIR}/_ext/760475324/openxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/760475324/openxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/760475324/openxlcd.o   ../xlcd/openxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/760475324/openxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/760475324/openxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/760475324/putrxlcd.o: ../xlcd/putrxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/760475324" 
	@${RM} ${OBJECTDIR}/_ext/760475324/putrxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/760475324/putrxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/760475324/putrxlcd.o   ../xlcd/putrxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/760475324/putrxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/760475324/putrxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/760475324/putsxlcd.o: ../xlcd/putsxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/760475324" 
	@${RM} ${OBJECTDIR}/_ext/760475324/putsxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/760475324/putsxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/760475324/putsxlcd.o   ../xlcd/putsxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/760475324/putsxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/760475324/putsxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/760475324/readaddr.o: ../xlcd/readaddr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/760475324" 
	@${RM} ${OBJECTDIR}/_ext/760475324/readaddr.o.d 
	@${RM} ${OBJECTDIR}/_ext/760475324/readaddr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/760475324/readaddr.o   ../xlcd/readaddr.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/760475324/readaddr.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/760475324/readaddr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/760475324/readdata.o: ../xlcd/readdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/760475324" 
	@${RM} ${OBJECTDIR}/_ext/760475324/readdata.o.d 
	@${RM} ${OBJECTDIR}/_ext/760475324/readdata.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/760475324/readdata.o   ../xlcd/readdata.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/760475324/readdata.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/760475324/readdata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/760475324/setcgram.o: ../xlcd/setcgram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/760475324" 
	@${RM} ${OBJECTDIR}/_ext/760475324/setcgram.o.d 
	@${RM} ${OBJECTDIR}/_ext/760475324/setcgram.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/760475324/setcgram.o   ../xlcd/setcgram.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/760475324/setcgram.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/760475324/setcgram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/760475324/setddram.o: ../xlcd/setddram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/760475324" 
	@${RM} ${OBJECTDIR}/_ext/760475324/setddram.o.d 
	@${RM} ${OBJECTDIR}/_ext/760475324/setddram.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/760475324/setddram.o   ../xlcd/setddram.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/760475324/setddram.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/760475324/setddram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/760475324/wcmdxlcd.o: ../xlcd/wcmdxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/760475324" 
	@${RM} ${OBJECTDIR}/_ext/760475324/wcmdxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/760475324/wcmdxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/760475324/wcmdxlcd.o   ../xlcd/wcmdxlcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/760475324/wcmdxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/760475324/wcmdxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/760475324/writdata.o: ../xlcd/writdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/760475324" 
	@${RM} ${OBJECTDIR}/_ext/760475324/writdata.o.d 
	@${RM} ${OBJECTDIR}/_ext/760475324/writdata.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/760475324/writdata.o   ../xlcd/writdata.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/760475324/writdata.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/760475324/writdata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/crit.o: ../crit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/crit.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/crit.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/crit.o   ../crit.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/crit.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/crit.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/sdspi.o: ../sdspi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/sdspi.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/sdspi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/sdspi.o   ../sdspi.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/sdspi.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/sdspi.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/hwconf.o: ../hwconf.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/hwconf.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/hwconf.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/hwconf.o   ../hwconf.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/hwconf.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/hwconf.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/model.o: ../model.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/model.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/model.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/model.o   ../model.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/model.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/model.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/power.o: ../power.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/power.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/power.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/power.o   ../power.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/power.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/power.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/mbmc_vector.o: ../mbmc_vector.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/mbmc_vector.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/mbmc_vector.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/mbmc_vector.o   ../mbmc_vector.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/mbmc_vector.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/mbmc_vector.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/daq.o: ../daq.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/daq.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/daq.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/daq.o   ../daq.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/daq.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/daq.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1472/timelib.o: ../timelib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/timelib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/timelib.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) --verbose -I".." -I"." -ml --extended -sa -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/_ext/1472/timelib.o   ../timelib.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1472/timelib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/timelib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/swm8722.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../18f8722_g.lkr
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) "../18f8722_g.lkr"  -p$(MP_PROCESSOR_OPTION_LD)  -w -x -u_DEBUG -m"$(BINDIR_)$(TARGETBASE).map" -w -l"../C:/Program Files (x86)/Microchip/mplabc18/v3.40/lib" -l"." -u_EXTENDEDMODE -g -z__MPLAB_BUILD=1  -u_CRUNTIME -z__MPLAB_DEBUG=1 -z__MPLAB_DEBUGGER_ICD3=1 $(MP_LINKER_DEBUG_OPTION) -l ${MP_CC_DIR}/../lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/swm8722.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
else
dist/${CND_CONF}/${IMAGE_TYPE}/swm8722.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../18f8722_g.lkr
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) "../18f8722_g.lkr"  -p$(MP_PROCESSOR_OPTION_LD)  -w  -m"$(BINDIR_)$(TARGETBASE).map" -w -l"../C:/Program Files (x86)/Microchip/mplabc18/v3.40/lib" -l"." -u_EXTENDEDMODE -g -z__MPLAB_BUILD=1  -u_CRUNTIME -l ${MP_CC_DIR}/../lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/swm8722.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
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
