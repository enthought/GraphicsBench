CXX=clang++
CC=clang++

GRAPHICS_BENCH_ROOT=../..
COMMON_DIR=$(GRAPHICS_BENCH_ROOT)/implementations/common

CFLAGS +=-g $(shell pkg-config --cflags cairo) -I$(GRAPHICS_BENCH_ROOT) -I$(COMMON_DIR)
LDFLAGS += -g
LIBS += $(shell pkg-config --libs cairo) -lrt -lgbutils -L$(GRAPHICS_BENCH_ROOT)/utils
OUTPUT = gb_cairo_main

OBJECTS = gb_cairo_main.o gb_cairo_lines.o gb_cairo_box_alpha.o gb_cairo_box_gradient.o
COMMON_OBJECTS = $(COMMON_DIR)/gb_lines.o $(COMMON_DIR)/gb_box.o

all : common $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o gb_cairo_main $(OBJECTS) $(COMMON_OBJECTS) $(LIBS)

common :
	make --directory=$(COMMON_DIR)

gb_cairo_main.o : gb_cairo_main.cpp
	$(CC) -c $(CFLAGS) $(LDFLAGS) gb_cairo_main.cpp

gb_cairo_lines.o : gb_cairo_lines.cpp
	$(CC) -c $(CFLAGS) $(LDFLAGS) gb_cairo_lines.cpp

gb_cairo_box_alpha.o : gb_cairo_box_alpha.cpp
	$(CC) -c $(CFLAGS) $(LDFLAGS) gb_cairo_box_alpha.cpp

gb_cairo_box_gradient.o : gb_cairo_box_gradient.cpp
	$(CC) -c $(CFLAGS) $(LDFLAGS) gb_cairo_box_gradient.cpp

.PHONY : clean
clean :
	rm -f *~ *.o *.a *.png core $(OUTPUT)
