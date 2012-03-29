GRAPHICS_BENCH_ROOT = .
COMMON_DIR = $(GRAPHICS_BENCH_ROOT)/implementations/common
UTILS_DIR = $(GRAPHICS_BENCH_ROOT)/utils
IMPLEMENTATIONS_BASE_DIR = $(GRAPHICS_BENCH_ROOT)/implementations
IMPLEMENTATIONS_AGG_DIR = $(IMPLEMENTATIONS_BASE_DIR)/agg
IMPLEMENTATIONS_CAIRO_DIR = $(IMPLEMENTATIONS_BASE_DIR)/cairo
IMPLEMENTATIONS = agg cairo

all : data utils common $(IMPLEMENTATIONS)

data :
	make --directory=$(DATA_DIR)

utils : common
	make --directory=$(UTILS_DIR)

common :
	make --directory=$(COMMON_DIR)

agg : utils
	make --directory=$(IMPLEMENTATIONS_AGG_DIR)

cairo : utils
	make --directory=$(IMPLEMENTATIONS_CAIRO_DIR)

clean :
	make --directory=$(UTILS_DIR) clean
	make --directory=$(COMMON_DIR) clean
	make --directory=$(IMPLEMENTATIONS_AGG_DIR) clean
	make --directory=$(IMPLEMENTATIONS_CAIRO_DIR) clean




