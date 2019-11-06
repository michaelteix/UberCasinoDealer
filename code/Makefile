OSPL_LIBS = -lpthread -lddskernel -ldcpssacpp
LIBS=-L${OSPL_HOME}/lib ${OSPL_LIBS}
CFLAGS = -Wall -O0 -g -I. -I./include -I${OSPL_HOME}/include/dcps/C++/SACPP -I${OSPL_HOME}/include/sys
CXXFLAGS = -Wall -O0 -g -I. -I./include
fltk = -L/usr/local/lib -lfltk -lXext -lX11 -lm -lfltk_images

all: Dealer

SRC = $(wildcard src/*.cpp)
include = $(wildcard include/*.h)

rule:
	source release.bash

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

PitBoss: ${IDL_GENERATED_H} ${IDL_GENERATED_CPP} ./src/PitBoss.cpp
	g++ -o $@ ${CFLAGS} ${CXXFLAGS} $^ ${LIBS}

Dealer: ${IDL_GENERATED_H} ${IDL_GENERATED_CPP} ./src/Dealer.cpp ${COMMON_H} ${COMMON_CPP} ${SRC} ${include}
	g++ -o $@ ${CFLAGS} ${CXXFLAGS} $^ ${LIBS} ${fltk}

Player: ${IDL_GENERATED_H} ${IDL_GENERATED_CPP} ./src/Player.cpp ${COMMON_H} ${COMMON_CPP} ${SRC}
	g++ -o $@ ${CFLAGS} ${CXXFLAGS} $^ ${LIBS}

standalone:
	g++ ./src/coms.cpp -o coms.o -c ${CFLAGS} ${CXXFLAGS} 
	g++ ./src/game.cpp -o game.o -c ${CFLAGS} ${CXXFLAGS}
	g++ ./src/player.cpp -o player.o -c ${CFLAGS} ${CXXFLAGS}
	g++ ./src/uuid.cpp -o uuid.o -c ${CFLAGS} ${CXXFLAGS} 
	g++ ./src/Dealer.cpp -o Dealer.o -pthread -c ${CFLAGS} ${CXXFLAGS} ${fltk}
	g++  Dealer.o coms.o game.o player.o uuid.o -o casino_dealer ${CFLAGS} ${CXXFLAGS} ${fltk}
	-rm -f *.o
	
clean:
	-rm -f PitBoss Player Dealer test_suite
	-rm -f ${IDL_GENERATED_H} ${IDL_GENERATED_CPP}
	-rm -f ospl-error.log ospl-info.log
	-rm -f *.o
	-rm -f casino_dealer
