#include "gb_cairo_memmove.h"
#include <utils/gb_utils_save_buffer.h>
#include <utils/gb_utils_timer.h>
#include <gb_settings.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>

using std::ifstream;
using std::ios_base;
using std::cout;
using std::cin;
using std::endl;


void GBCairoMemmoveBenchmark::init()
{
    benchmark_name = "Cairo box memmove";
    benchmark_file_name = "gb_cairo_memmove.png";
    return;
}

void GBCairoMemmoveBenchmark::render()
{
    // todo: parametrise
    cairo_surface_t *surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, 1920, 1200);
    cairo_t *cr = cairo_create (surface);
    int counter;
    
    GBTimer timer;

    GBTimer draw_timer;

    // TODO: parametrise
    cairo_set_line_width (cr, 1);
    cairo_set_antialias(cr, CAIRO_ANTIALIAS_SUBPIXEL);
    cairo_set_source_rgba(cr, 0.5, 0.5, 1, 0.5);
    

    Box box = {0, 0, GB_CANVAS_WIDTH, GB_CANVAS_HEIGHT};

    draw_timer.start();
    cairo_pattern_t *gradient = cairo_pattern_create_linear(box.x, box.y, box.x + box.width, box.y + box.height);
    cairo_pattern_add_color_stop_rgba(gradient, 0, 0, 0, 1, 0.5);
    cairo_pattern_add_color_stop_rgba(gradient, 0.5, 1, 1, 0, 0.5);
    cairo_pattern_add_color_stop_rgba(gradient, 1, 1, 0, 0, 0.5);
    cairo_set_source(cr, gradient);
    cairo_rectangle(cr, box.x, box.y, box.width, box.height);
    cairo_fill (cr);
    cairo_pattern_destroy(gradient);

    int tile_width = 75;
    int rows = ceil(GB_CANVAS_WIDTH / tile_width);
    int cols = ceil(GB_CANVAS_HEIGHT / tile_width); 

    cairo_set_source_rgba(cr, 0.5, 0.5, 1, 1.0);
    cairo_set_font_size (cr, 14);

    for (int rcount = 0; rcount < rows; ++rcount)
    {
        for (int ccount = 0; ccount < cols; ++ccount)
        {
            if ((rcount + ccount) % 2 == 0)
            {
                cairo_set_source_rgba(cr, 0, 0, 0, 0.3);
            }
            else
            {
                cairo_set_source_rgba(cr, 1, 1, 1, 0.3);
            }
            cairo_rectangle(cr, rcount * tile_width, ccount * tile_width, tile_width, tile_width);
            cairo_fill (cr);

            cairo_set_source_rgba(cr, 1, 1, 1, 1);


            cairo_move_to(cr, tile_width * (0.5 + rcount), tile_width * (0.5 + ccount));
            std::stringstream tile_number;
            tile_number << (rcount * cols) + ccount;
            //cout << tile_number.str() << " " << rcount << " " << ccount << endl;
            cairo_show_text (cr, tile_number.str().c_str());
        }
    }

    draw_timer.stop();

    cout << benchmark_name << "draw time: " << draw_timer << endl;

    unsigned char* data = cairo_image_surface_get_data(surface);
    int stride = cairo_format_stride_for_width (GB_CANVAS_CAIRO_FORMAT, GB_CANVAS_WIDTH);

    timer.start();
    memmove(data , data, stride * GB_CANVAS_HEIGHT);
    timer.stop();

    print_timing(timer);

    if (GB_SAVE_BENCHMARK_IMAGE)
    {
        gb_save_buffer( benchmark_file_name, cairo_image_surface_get_data(surface), 
                        GB_CANVAS_WIDTH, GB_CANVAS_HEIGHT, GB_CANVAS_BPP, GB_CANVAS_CAIRO_FORMAT);   
    }

    
    cairo_destroy (cr);
    cairo_surface_destroy (surface);
    return;
}

