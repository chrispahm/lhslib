#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=RTools-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/TestClass.o \
	${OBJECTDIR}/improvedLHS_RTest.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/maximinLHS_RTest.o \
	${OBJECTDIR}/optSeededLHS_RTest.o \
	${OBJECTDIR}/optimumLHS_RTest.o \
	${OBJECTDIR}/simpleMatrixTest.o \
	${OBJECTDIR}/utilityLHS_RTest.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-m64
CXXFLAGS=-m64

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lhstest.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lhstest.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lhstest ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/TestClass.o: TestClass.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/C/Users/carnellr/Documents/Repositories/lhsgit/lhs_nb/lhslib -I/C/Users/carnellr/Documents/Repositories/Rdevel/Rdevel/src/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/TestClass.o TestClass.cpp

${OBJECTDIR}/improvedLHS_RTest.o: improvedLHS_RTest.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/C/Users/carnellr/Documents/Repositories/lhsgit/lhs_nb/lhslib -I/C/Users/carnellr/Documents/Repositories/Rdevel/Rdevel/src/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/improvedLHS_RTest.o improvedLHS_RTest.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/C/Users/carnellr/Documents/Repositories/lhsgit/lhs_nb/lhslib -I/C/Users/carnellr/Documents/Repositories/Rdevel/Rdevel/src/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/maximinLHS_RTest.o: maximinLHS_RTest.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/C/Users/carnellr/Documents/Repositories/lhsgit/lhs_nb/lhslib -I/C/Users/carnellr/Documents/Repositories/Rdevel/Rdevel/src/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/maximinLHS_RTest.o maximinLHS_RTest.cpp

${OBJECTDIR}/optSeededLHS_RTest.o: optSeededLHS_RTest.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/C/Users/carnellr/Documents/Repositories/lhsgit/lhs_nb/lhslib -I/C/Users/carnellr/Documents/Repositories/Rdevel/Rdevel/src/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/optSeededLHS_RTest.o optSeededLHS_RTest.cpp

${OBJECTDIR}/optimumLHS_RTest.o: optimumLHS_RTest.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/C/Users/carnellr/Documents/Repositories/lhsgit/lhs_nb/lhslib -I/C/Users/carnellr/Documents/Repositories/Rdevel/Rdevel/src/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/optimumLHS_RTest.o optimumLHS_RTest.cpp

${OBJECTDIR}/simpleMatrixTest.o: simpleMatrixTest.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/C/Users/carnellr/Documents/Repositories/lhsgit/lhs_nb/lhslib -I/C/Users/carnellr/Documents/Repositories/Rdevel/Rdevel/src/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/simpleMatrixTest.o simpleMatrixTest.cpp

${OBJECTDIR}/utilityLHS_RTest.o: utilityLHS_RTest.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -I/C/Users/carnellr/Documents/Repositories/lhsgit/lhs_nb/lhslib -I/C/Users/carnellr/Documents/Repositories/Rdevel/Rdevel/src/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/utilityLHS_RTest.o utilityLHS_RTest.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lhstest.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc