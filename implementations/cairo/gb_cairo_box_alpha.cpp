#include "gb_cairo_box_alpha.h"
#include <utils/gb_utils_timer.h>

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


void GBCairoBoxBenchmark::init()
{
    return;
}

void GBCairoBoxBenchmark::render()
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
    timer.start();
    for (counter=0; counter < app_state.metadata->num_elements; counter++)
    {
        Box box = app_state.drawdata->boxes[counter];
        cairo_rectangle(cr, box.x, box.y, box.width, box.height);
        cairo_fill (cr);
    }
    timer.stop();
    cout << "Cairo lines: " << timer << endl;
    cairo_destroy (cr);
    cairo_surface_write_to_png (surface, "box.png");
    cairo_surface_destroy (surface);
    return;
}

