#include "gb_agg_lines.h"
#include "gb_agg_lines_scanline.h"

int main(int argc, char **argv)
{
    GBAggLineBenchmark gb_agg_line;
    gb_agg_line.init();
    gb_agg_line.app_state.load_data("../../data/gb_lines.data");
    gb_agg_line.render();

    GBAggLineScanLineBenchmark gb_agg_line_scanline;
    gb_agg_line_scanline.init();
    gb_agg_line_scanline.app_state.load_data("../../data/gb_lines.data");
    gb_agg_line_scanline.render();
}