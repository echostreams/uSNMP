cmake_minimum_required(VERSION 3.7)

project(uSNMP)

include_directories(src)
set(uSNMP_src
	src/endian.c
	src/misc.c
	src/timer.c
	src/list.c
	src/oid.c 
	src/octet.c
	src/mib.c
	src/miblist.c
	src/varbind.c
	src/mibutil.c 
	src/SnmpAgent.c
	src/SnmpMgr.c
)
if(WIN32)
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
	list(APPEND uSNMP_src src/wingetopt.c)
	set(LIBSOCKET ws2_32)
endif()

add_library(usnmp ${uSNMP_src})
add_library(libsnmp 
	libSNMP/auth.cpp
	libSNMP/dataBlock.cpp
	libSNMP/des.cpp
	libSNMP/libSNMP.cpp
	libSNMP/snmpObject.cpp
	libSNMP/snmpUser.cpp
)

add_definitions(-DHAVE_STDINT_H)
include_directories(libSNMP)
add_executable(usnmptrap "examples/usnmptrap.cpp")
target_link_libraries(usnmptrap usnmp ${LIBSOCKET} libsnmp)

add_executable(usnmptrapd examples/usnmptrapd.c)
target_link_libraries(usnmptrapd usnmp ${LIBSOCKET})



	