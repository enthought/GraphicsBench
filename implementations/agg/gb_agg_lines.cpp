#include "gb_agg_lines.h"
#include <utils/gb_utils_timer.h>
#include <utils/gb_utils_save_buffer.h>
#include <gb_settings.h>
#include <iostream>

#include "agg_path_storage.h"
#include "agg_basics.h"
#include "agg_pixfmt_rgb.h"
#include "agg_pixfmt_rgba.h"
#include "agg_renderer_outline_aa.h"
#include "agg_rasterizer_outline_aa.h"
#include "agg_rendering_buffer.h"
#include "platform/agg_platform_support.h"


using std::ifstream;
using std::ios_base;
using std::cout;
using std::cin;
using std::endl;

void GBAggLineBenchmark::init()
{
    benchmark_name = "Agg lines";
    benchmark_file_name = "gb_agg_lines.png";
    return;
}



void GBAggLineBenchmark::render()
{
    unsigned char *data;
    long counter;
    agg::rendering_buffer buffer;

    data = (unsigned char*) malloc(GB_CANVAS_WIDTH * GB_CANVAS_HEIGHT * GB_CANVAS_BPP);

    memset(data, 255, GB_CANVAS_WIDTH * GB_CANVAS_HEIGHT * GB_CANVAS_BPP);

    buffer.attach(data, GB_CANVAS_WIDTH, GB_CANVAS_HEIGHT, GB_CANVAS_WIDTH * GB_CANVAS_BPP);

    typedef GB_CANVAS_AGG_FORMAT pixfmt;
    typedef agg::renderer_base<pixfmt> renderer_base;
    typedef agg::renderer_outline_aa<renderer_base> renderer_oaa;
    typedef agg::rasterizer_outline_aa<renderer_oaa> rasterizer_outline_aa;

    pixfmt pixelFormat(buffer);
    renderer_base ren_base(pixelFormat);

    agg::line_profile_aa prof;

    //TODO: parametrise
    prof.width(1.0);

    renderer_oaa renderer(ren_base, prof);
    rasterizer_outline_aa rasterizer(renderer);

    renderer.color(agg::rgba(0, 0, 0, 1));
    rasterizer.round_cap(true);

    agg::path_storage path;

    GBTimer timer;
    
    timer.start();
    for (counter=0; counter < app_state.metadata->num_elements; counter++)
    {
        LineSegment segment = app_state.drawdata->segments[counter];
        path.move_to(segment.begin_x, segment.begin_y);
        path.line_to(segment.end_x, segment.end_y);
        
    }

    rasterizer.add_path(path);
    timer.stop();
    print_timing(timer);

    if (GB_SAVE_BENCHMARK_IMAGE)
    {
        gb_save_buffer(benchmark_file_name, data, GB_CANVAS_WIDTH, GB_CANVAS_HEIGHT, GB_CANVAS_BPP, GB_CANVAS_CAIRO_FORMAT);   
    }

    free(data);
    return;
}

