#include "gb_cairo_box_gradient.h"
#include <utils/gb_utils_save_buffer.h>
#include <utils/gb_utils_timer.h>
#include <gb_settings.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#include <fstream>
#include <iostream>

using std::ifstream;
using std::ios_base;
using std::cout;
using std::cin;
using std::endl;


void GBCairoBoxGradientBenchmark::init()
{
    benchmark_name = "Cairo box gradient";
    benchmark_file_name = "gb_cairo_box_gradient.png";
    return;
}

void GBCairoBoxGradientBenchmark::render()
{
    // todo: parametrise
    cairo_surface_t *surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, 1920, 1200);
    cairo_t *cr = cairo_create (surface);
    int counter;
    
    GBTimer timer;

    // TODO: parametrise
    cairo_set_line_width (cr, 1);
    cairo_set_antialias(cr, CAIRO_ANTIALIAS_SUBPIXEL);
    cairo_set_source_rgba(cr, 0.5, 0.5, 1, 0.5);

    cairo_pattern_t *gradient = cairo_pattern_create_linear(0, 0, 100, 100);
    cairo_pattern_add_color_stop_rgba(gradient, 0, 0, 0, 1, 0.5);
    cairo_pattern_add_color_stop_rgba(gradient, 0, 0, 1, 0, 0.5);
    cairo_set_source(cr, gradient);

    timer.start();
    for (counter=0; counter < app_state.metadata->num_elements; counter++)
    {
        Box box = app_state.drawdata->boxes[counter];
        cairo_rectangle(cr, box.x, box.y, box.width, box.height);
        cairo_fill (cr);
    }
    timer.stop();

    print_timing(timer);

    if (GB_SAVE_BENCHMARK_IMAGE)
    {
        gb_save_buffer(benchmark_file_name, cairo_image_surface_get_data(surface), GB_CANVAS_WIDTH, GB_CANVAS_HEIGHT, GB_CANVAS_BPP, GB_CANVAS_CAIRO_FORMAT);   
    }

    cairo_pattern_destroy(gradient);
    cairo_destroy (cr);
    cairo_surface_destroy (surface);
    return;
}

