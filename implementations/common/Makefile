CXX=clang++
CC=clang++

GRAPHICS_BENCH_ROOT=../..
COMMON_DIR=$(GRAPHICS_BENCH_ROOT)/implementations/common

CFLAGS +=-g -I$(GRAPHICS_BENCH_ROOT)
LDFLAGS += -g
LIBS += -L$(GRAPHICS_BENCH_ROOT)/utils

objects = gb_lines.o gb_box.o

all : $(objects)

gb_lines.o : gb_lines.cpp
	$(CC) -c $(CFLAGS) $(LDFLAGS) gb_lines.cpp

gb_box.o : gb_box.cpp
	$(CC) -c $(CFLAGS) $(LDFLAGS) gb_box.cpp

.PHONY : clean
clean :
	rm -f *~ *.o *.a *.png core
