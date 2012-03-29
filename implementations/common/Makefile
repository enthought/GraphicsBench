CXX=clang++
CC=clang++

GRAPHICS_BENCH_ROOT=../..
COMMON_DIR=$(GRAPHICS_BENCH_ROOT)/implementations/common

CFLAGS +=-g -I$(GRAPHICS_BENCH_ROOT) $(shell pkg-config --cflags cairo)
LDFLAGS += -g
LIBS += -L$(GRAPHICS_BENCH_ROOT)/utils $(shell pkg-config --libs cairo)

objects = gb_lines.o gb_box.o gb_benchmark.o

all : $(objects)

gb_lines.o : gb_lines.cpp
	$(CC) -c $(CFLAGS) $(LDFLAGS) gb_lines.cpp

gb_box.o : gb_box.cpp
	$(CC) -c $(CFLAGS) $(LDFLAGS) gb_box.cpp

gb_benchmark.o : gb_benchmark.cpp
	$(CC) -c $(CFLAGS) $(LDFLAGS) gb_benchmark.cpp


.PHONY : clean
clean :
	rm -f *~ *.o *.a *.png core
