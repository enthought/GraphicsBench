#pragma once

#define GB_CANVAS_WIDTH 1920
#define GB_CANVAS_HEIGHT 1200
#define GB_CANVAS_CAIRO_FORMAT CAIRO_FORMAT_ARGB32
// TODO: figure out why changing this to pixfmt_rgba32 makes the colors funky
#define GB_CANVAS_AGG_FORMAT agg::pixfmt_rgba32
#define GB_CANVAS_BPP 4
#define GB_SAVE_BENCHMARK_IMAGE true
