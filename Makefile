CC=g++
CFLAGS=-std=c++11 -Wall
#BUILD=-L. -lunvlist
HDR_OPT=-c
ACV=ar
ACV_OPT=rvs
LIB_SRC=unvlist.cpp
LIB_OBJ=unvlist.o
LIB=libunvlist.a
SRCS=main.cpp #unvlist.hpp#${LIB}
OBJ=main

	#${CC} ${CFLAGS} ${HDR_OPT} ${LIB_SRC}
	#${ACV} ${ACV_OPT} ${LIB} ${LIB_OBJ}
all:
	${CC} ${CFLAGS} ${BUILD} ${SRCS} -o ${OBJ}

header:
	${CC} ${CFLAGS} ${HDR_OPT} ${LIB_SRC}
	${ACV} ${ACV_OPT} ${LIB} ${LIB_OBJ}

clean:
	rm -rf ${LIB_OBJ} ${LIB} ${OBJ}
