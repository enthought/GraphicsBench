CXX=g++
CC=g++

GRAPHICS_BENCH_ROOT=../..
COMMON_DIR=$(GRAPHICS_BENCH_ROOT)/implementations/common

UNAME = $(shell uname)
ifeq ($(UNAME), Linux)
	LIBS += $(shell pkg-config --libs cairo) $(shell pkg-config --libs libagg) -lrt -lgbutils
endif

ifeq ($(UNAME), Darwin)
	LIBS += $(shell pkg-config --libs cairo) $(shell pkg-config --libs libagg) -lgbutils
endif

CFLAGS +=-g $(shell pkg-config --cflags cairo) $(shell pkg-config --cflags libagg) -I$(GRAPHICS_BENCH_ROOT) -I$(COMMON_DIR)
LDFLAGS += -L$(GRAPHICS_BENCH_ROOT)/utils
OUTPUT = gb_agg_main

OBJECTS = gb_agg_main.o gb_agg_lines.o
COMMON_OBJECTS = $(COMMON_DIR)/gb_lines.o $(COMMON_DIR)/gb_box.o

all : common $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o gb_agg_main $(OBJECTS) $(COMMON_OBJECTS) $(LIBS)

common :
	make --directory=$(COMMON_DIR)

gb_agg_main.o : gb_agg_main.cpp
	$(CC) -c $(CFLAGS) $(LDFLAGS) gb_agg_main.cpp

gb_agg_lines.o : gb_agg_lines.cpp
	$(CC) -c $(CFLAGS) $(LDFLAGS) gb_agg_lines.cpp

.PHONY : clean
clean :
	rm -f *~ *.o *.a *.png core $(OUTPUT)
