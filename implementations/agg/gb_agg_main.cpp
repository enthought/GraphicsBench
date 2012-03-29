#include "gb_agg_lines.h"

int main(int argc, char **argv)
{
    GBAggLineBenchmark gb_agg_line;
    gb_agg_line.init();
    gb_agg_line.app_state.load_data("../../data/gb_lines.data");
    gb_agg_line.render();
}