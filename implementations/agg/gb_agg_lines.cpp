#include "gb_agg_lines.h"
#include <utils/gb_utils_timer.h>
#include <utils/gb_utils_save_buffer.h>
#include <gb_settings.h>
#include <iostream>

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
    return;
}

bool write_ppm(const unsigned char* buf, 
               unsigned width, 
               unsigned height,
               unsigned bpp,
               const char* file_name)
{
    FILE* fd = fopen(file_name, "wb");
    if(fd)
    {
        fprintf(fd, "P6 %d %d 255 ", width, height);
        fwrite(buf, 1, width * height * bpp, fd);
        fclose(fd);
        return true;
    }
    return false;
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

    GBTimer timer;
    
    timer.start();
    for (counter=0; counter < app_state.metadata->num_elements; counter++)
    {
        LineSegment segment = app_state.drawdata->segments[counter];
        rasterizer.move_to_d(segment.begin_x, segment.begin_y);
        rasterizer.line_to_d(segment.end_x, segment.end_y);
        rasterizer.render(false);
    }

    timer.stop();

    std::string filename_png("out.png");
    std::string filename_ppm("out.ppm");

    gb_save_buffer(filename_png, data, GB_CANVAS_WIDTH, GB_CANVAS_HEIGHT, GB_CANVAS_BPP, GB_CANVAS_CAIRO_FORMAT );
    write_ppm(data, GB_CANVAS_WIDTH, GB_CANVAS_HEIGHT, GB_CANVAS_BPP, filename_ppm.c_str());
    free(data);
    cout << timer << endl;
    return;
}

