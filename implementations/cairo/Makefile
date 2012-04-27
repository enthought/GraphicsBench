CXX=g++
CC=g++

GRAPHICS_BENCH_ROOT=../..
COMMON_DIR=$(GRAPHICS_BENCH_ROOT)/implementations/common

UNAME = $(shell uname)
ifeq ($(UNAME), Linux)
	LIBS += $(shell pkg-config --libs cairo QtGui) -lgbutils -lrt -L$(GRAPHICS_BENCH_ROOT)/utils
endif

ifeq ($(UNAME), Darwin)
	LIBS += $(shell pkg-config --libs cairo QtGui) -lgbutils -L$(GRAPHICS_BENCH_ROOT)/utils
endif

CFLAGS += $(shell pkg-config --cflags cairo QtGui) -I$(GRAPHICS_BENCH_ROOT) -I$(COMMON_DIR)
LDFLAGS += -g
OUTPUT = gb_cairo_main

OBJECTS = gb_cairo_main.o gb_cairo_lines.o gb_cairo_box_alpha.o gb_cairo_box_gradient.o gb_cairo_memmove.o moc_gb_cairo_memmove.o
COMMON_OBJECTS = $(COMMON_DIR)/gb_lines.o $(COMMON_DIR)/gb_box.o $(COMMON_DIR)/gb_benchmark.o

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

gb_cairo_memmove.o : gb_cairo_memmove.cpp
	$(CC) -c $(CFLAGS) $(LDFLAGS) gb_cairo_memmove.cpp

moc_gb_cairo_memmove.o : gb_cairo_memmove.h gb_cairo_memmove.cpp
	moc -o moc_gb_cairo_memmove.cpp gb_cairo_memmove.h
	$(CC) -c $(CFLAGS) $(LDFLAGS) moc_gb_cairo_memmove.cpp
	



.PHONY : clean
clean :
	rm -f *~ *.o *.a *.png core $(OUTPUT)

