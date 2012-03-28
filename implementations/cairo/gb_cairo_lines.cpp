#include "gb_cairo_lines.h"
#include <utils/gb_utils_timer.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>

using std::ifstream;
using std::ios_base;
using std::cout;
using std::cin;
using std::endl;


void GBCairoLineBenchmark::init()
{
    return;
}

void GBCairoLineBenchmark::render()
{
    // todo: parametrise
    cairo_surface_t *surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, 1920, 1200);
    cairo_t *cr = cairo_create (surface);
    int counter;
    
    GBTimer timer;

    // TODO: parametrise
    cairo_set_line_width (cr, 1);
    cairo_set_antialias(cr, CAIRO_ANTIALIAS_SUBPIXEL);
    
    timer.start();
    for (counter=0; counter < app_state.metadata->num_elements; counter++)
    {
        LineSegment segment = app_state.drawdata->segments[counter];
        cairo_move_to (cr, segment.begin_x, segment.begin_y);
        cairo_line_to (cr, segment.end_x, segment.end_y);
        cairo_stroke (cr);
    }
    timer.stop();
    cout << "Cairo lines: " << timer << endl;
    cairo_destroy (cr);
    cairo_surface_destroy (surface);
    return;
}

