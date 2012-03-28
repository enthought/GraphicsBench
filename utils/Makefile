UNAME = $(shell uname)

ifeq ($(UNAME), Linux)
LDFLAGS +=-lrt -L.
endif

ifeq ($(UNAME), Darwin)
LDFLAGS +=
endif

CXX=clang++
CC=clang++

CFLAGS +=-g $(shell pkg-config --cflags cairo)
AR=ar
LIBNAME=libgbutils.a
LIB_LINK_NAME=-lgbutils

objects = gb_utils_timer.o gb_utils_save_buffer.o


all : $(objects)
	$(AR) rcs $(LIBNAME) $(objects)

test : all gb_test_utils_timer.o 
	$(CC) $(CFLAGS) $(LDFLAGS) -o gb_test_timer gb_test_utils_timer.o $(LIB_LINK_NAME)

gb_utils_timer.o : gb_utils_timer.h
gb_test_utils_timer.o : gb_utils_timer.h
gb_utils_save_buffer.o : gb_utils_save_buffer.h gb_utils_save_buffer.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) -c gb_utils_save_buffer.cpp
	

.PHONY : clean
clean :
		rm -f gb_test_timer *.o *.a

