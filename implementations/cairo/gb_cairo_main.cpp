#include "gb_cairo_lines.h"
#include "gb_cairo_box_alpha.h"
#include "gb_cairo_box_gradient.h"
#include "gb_cairo_memmove.h"

int main(int argc, char **argv)
{
    GBCairoLineBenchmark gb_cairo_line;
    gb_cairo_line.init();
    gb_cairo_line.app_state.load_data("../../data/gb_lines.data");
    gb_cairo_line.render();

    
    GBCairoBoxBenchmark gb_cairo_box_alpha;
    gb_cairo_box_alpha.init();
    gb_cairo_box_alpha.app_state.load_data("../../data/gb_box_alpha.data");
    gb_cairo_box_alpha.render();
    
    GBCairoBoxGradientBenchmark gb_cairo_box_gradient;
    gb_cairo_box_gradient.init();
    gb_cairo_box_gradient.app_state.load_data("../../data/gb_box_alpha.data");
    gb_cairo_box_gradient.render(); 

    GBCairoMemmoveBenchmark gb_cairo_memmove;
    gb_cairo_memmove.init();
    gb_cairo_memmove.app_state.load_data("../../data/gb_box_alpha.data");
    gb_cairo_memmove.render(); 
    return 0;
}
