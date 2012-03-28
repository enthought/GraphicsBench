#include "gb_skia_lines.h"


int main(int argc, char **argv)
{
    GBSkiaLineBenchmark gb_skia_lines;
    gb_skia_lines.app_state.load_data("../../data/gb_lines.data");
    gb_skia_lines.render();

    return 0;
}
