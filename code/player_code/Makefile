OSPL_LIBS = -lpthread -lddskernel -ldcpssacpp
LIBS=-L${OSPL_HOME}/lib ${OSPL_LIBS}
CFLAGS = -Wall -std=c++11 -O0 -g -I. -I./include -I${OSPL_HOME}/include/dcps/C++/SACPP -I${OSPL_HOME}/include/sys
CXXFLAGS = -Wall -O0 -g -I. -I./include
fltk = -L/usr/local/lib -lfltk -lXext -lX11 -lm -lfltk_images

all: Player

SRC = $(wildcard src/*.cpp)
include = $(wildcard include/*.h)


IDL_GENERATED_H= \
		 ccpp_UberCasino.h \
                 UberCasinoDcps.h \
                 UberCasinoDcps_impl.h \
                 UberCasino.h \
                 UberCasinoSplDcps.h 

IDL_GENERATED_CPP=\
                 UberCasino.cpp \
                 UberCasinoDcps.cpp \
                 UberCasinoDcps_impl.cpp \
                 UberCasinoSplDcps.cpp

IDL_GENERATED=${IDL_GENERATED_H} ${IDL_GENERATED_CPP}

${IDL_GENERATED}: ./idl/UberCasino.idl
	${OSPL_HOME}/bin/idlpp -l cpp ./idl/UberCasino.idl

COMMON_CPP=./common/CheckStatus.cpp ./common/DDSEntityManager.cpp \
	   		$(wildcard $common/*.cpp)

COMMON_H= $(wildcard $common/*.h)

Player: ${IDL_GENERATED_H} ${IDL_GENERATED_CPP} ./src/Player.cpp ${COMMON_H} ${COMMON_CPP} ${SRC} ${include}
	g++ -o $@ ${CFLAGS} ${CXXFLAGS} $^ ${LIBS}
	
clean:
	-rm -f PitBoss Player Dealer
	-rm -f ${IDL_GENERATED_H} ${IDL_GENERATED_CPP}
	-rm -f ospl-error.log ospl-info.log
	-rm -f *.o
	-rm -f casino_dealer
