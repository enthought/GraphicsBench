CXX=g++
CC=g++

GRAPHICS_BENCH_ROOT=../..
COMMON_DIR=$(GRAPHICS_BENCH_ROOT)/implementations/common

UNAME = $(shell uname)
ifeq ($(UNAME), Linux)
	LIBS += -lgbutils -lrt $(shell pkg-config --libs cairo) $(shell pkg-config --libs libagg) 
endif

ifeq ($(UNAME), Darwin)
	LIBS += -lgbutils $(shell pkg-config --libs cairo) $(shell pkg-config --libs libagg)
endif

CFLAGS +=-g $(shell pkg-config --cflags cairo) $(shell pkg-config --cflags libagg) -I$(GRAPHICS_BENCH_ROOT) -I$(COMMON_DIR)
LDFLAGS += -L$(GRAPHICS_BENCH_ROOT)/utils
OUTPUT = gb_agg_main

OBJECTS = gb_agg_main.o gb_agg_lines.o gb_agg_lines_scanline.o
COMMON_OBJECTS = $(COMMON_DIR)/gb_lines.o $(COMMON_DIR)/gb_box.o $(COMMON_DIR)/gb_benchmark.o

all : common $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o gb_agg_main $(OBJECTS) $(COMMON_OBJECTS) $(LIBS)

common :
	make --directory=$(COMMON_DIR)

gb_agg_main.o : gb_agg_main.cpp
	$(CC) -c $(CFLAGS) $(LDFLAGS) gb_agg_main.cpp

gb_agg_lines.o : gb_agg_lines.cpp
	$(CC) -c $(CFLAGS) $(LDFLAGS) gb_agg_lines.cpp

gb_agg_lines_scanline.o : gb_agg_lines_scanline.cpp
	$(CC) -c $(CFLAGS) $(LDFLAGS) gb_agg_lines_scanline.cpp

.PHONY : clean
clean :
	rm -f *~ *.o *.a *.png *.ppm core $(OUTPUT)

