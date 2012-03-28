CXX=clang++
CC=clang++

UNAME = $(shell uname)

ifeq ($(UNAME), Linux)
LIBS += -lrt -lgbutils -lfreetype -lpthread -lGL -lX11 -lpng -lGLU -lz
LDFLAGS += -g -L$(GRAPHICS_BENCH_ROOT)/lib/skia -L$(GRAPHICS_BENCH_ROOT)/utils
endif

ifeq ($(UNAME), Darwin)
LIBS += -lgbutils -lpthread -lz
LDFLAGS += -g -m32 -L$(GRAPHICS_BENCH_ROOT)/lib/skia -L$(GRAPHICS_BENCH_ROOT)/utils
endif


GRAPHICS_BENCH_ROOT=../..
COMMON_DIR=$(GRAPHICS_BENCH_ROOT)/implementations/common

SKIA_INCLUDE=$(GRAPHICS_BENCH_ROOT)/include/skia
CFLAGS +=-g -I$(GRAPHICS_BENCH_ROOT) -I$(GRAPHICS_BENCH_ROOT) -I$(COMMON_DIR) -I$(SKIA_INCLUDE)/animator -I$(SKIA_INCLUDE)/config -I$(SKIA_INCLUDE)/core \
 -I$(SKIA_INCLUDE)/device -I$(SKIA_INCLUDE)/effects -I$(SKIA_INCLUDE)/gpu -I$(SKIA_INCLUDE)/images -I$(SKIA_INCLUDE)/pdf -I$(SKIA_INCLUDE)/pipe\
 -I$(SKIA_INCLUDE)/ports -I$(SKIA_INCLUDE)/svg -I$(SKIA_INCLUDE)/text -I$(SKIA_INCLUDE)/utils -I$(SKIA_INCLUDE)/views -I$(SKIA_INCLUDE)/xml





SKIA_LIB_ROOT = $(GRAPHICS_BENCH_ROOT)/..//trunk/out/Debug

SKIA_STATIC_LIBS = $(SKIA_LIB_ROOT)/libcore.a $(SKIA_LIB_ROOT)/libeffects.a $(SKIA_LIB_ROOT)/libexperimental.a $(SKIA_LIB_ROOT)/libgr.a \
$(SKIA_LIB_ROOT)/libskgr.a $(SKIA_LIB_ROOT)/libimages.a $(SKIA_LIB_ROOT)/libports.a $(SKIA_LIB_ROOT)/libpdf.a $(SKIA_LIB_ROOT)/libutils.a $(SKIA_LIB_ROOT)/libopts.a \
$(SKIA_LIB_ROOT)/libopts_ssse3.a $(SKIA_LIB_ROOT)/libtess.a $(SKIA_LIB_ROOT)/libzlib.a $(SKIA_LIB_ROOT)/libanimator.a $(SKIA_LIB_ROOT)/libxml.a $(SKIA_LIB_ROOT)/libviews.a $(SKIA_LIB_ROOT)/libcore.a

OUTPUT = gb_skia_main

OBJECTS = gb_skia_main.o gb_skia_lines.o
COMMON_OBJECTS = $(COMMON_DIR)/gb_lines.o $(COMMON_DIR)/gb_box.o


all : common $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o gb_skia_main $(OBJECTS) $(COMMON_OBJECTS) $(SKIA_STATIC_LIBS) $(LIBS) 
common :
	make --directory=$(COMMON_DIR)

gb_skia_main.o : gb_skia_main.cpp
	$(CC) -c $(CFLAGS) $(LDFLAGS) gb_skia_main.cpp

gb_skia_lines.o : gb_skia_lines.cpp
	$(CC) -c $(CFLAGS) $(LDFLAGS) gb_skia_lines.cpp

.PHONY : clean
clean :
	rm -f *~ *.o *.png core $(OUTPUT)

