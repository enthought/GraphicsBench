#include "gb_agg_lines_scanline.h"
#include <utils/gb_utils_timer.h>
#include <utils/gb_utils_save_buffer.h>
#include <gb_settings.h>
#include <iostream>

#include "agg_path_storage.h"
#include "agg_basics.h"
#include "agg_conv_stroke.h"
#include "agg_pixfmt_rgb.h"
#include "agg_pixfmt_rgba.h"
#include "agg_scanline_u.h"
#include "agg_rasterizer_scanline_aa.h"
#include "agg_renderer_scanline.h"
#include "agg_rendering_buffer.h"
#include "platform/agg_platform_support.h"


using std::ifstream;
using std::ios_base;
using std::cout;
using std::cin;
using std::endl;

void GBAggLineScanLineBenchmark::init()
{
    benchmark_name = "Agg lines scanline";
    benchmark_file_name = "gb_agg_lines_scanline.png";
    return;
}



void GBAggLineScanLineBenchmark::render()
{
    unsigned char *data;
    long counter;
    agg::rendering_buffer buffer;

    data = (unsigned char*) malloc(GB_CANVAS_WIDTH * GB_CANVAS_HEIGHT * GB_CANVAS_BPP);
    memset(data, 0, GB_CANVAS_WIDTH * GB_CANVAS_HEIGHT * GB_CANVAS_BPP);

    buffer.attach(data, GB_CANVAS_WIDTH, GB_CANVAS_HEIGHT, GB_CANVAS_WIDTH * GB_CANVAS_BPP);

    typedef GB_CANVAS_AGG_FORMAT pixfmt;
    typedef agg::renderer_base<pixfmt> renderer_base;
    typedef agg::renderer_scanline_aa_solid<renderer_base> renderer_aa;
    typedef agg::rasterizer_scanline_aa<> rasterizer_scanline;

    pixfmt pixelFormat(buffer);
    renderer_base ren_base(pixelFormat);
    agg::scanline_u8 scanline;
    renderer_aa renderer(ren_base);
    rasterizer_scanline rasterizer;
    rasterizer.reset();

    agg::path_storage path;
    agg::conv_stroke<agg::path_storage> stroke(path);

    GBTimer timer;
    
    timer.start();
    for (counter=0; counter < app_state.metadata->num_elements; counter++)
    {
        LineSegment segment = app_state.drawdata->segments[counter];
        path.move_to(segment.begin_x, segment.begin_y);
        path.line_to(segment.end_x, segment.end_y);
    }

    rasterizer.add_path(stroke);
    renderer.color(agg::rgba(0, 0, 0, 1));
    agg::render_scanlines(rasterizer, scanline, renderer);

    timer.stop();
    print_timing(timer);

    if (GB_SAVE_BENCHMARK_IMAGE)
    {
        gb_save_buffer(benchmark_file_name, data, GB_CANVAS_WIDTH, GB_CANVAS_HEIGHT, GB_CANVAS_BPP, GB_CANVAS_CAIRO_FORMAT);   
    }

    free(data);
    return;
}

