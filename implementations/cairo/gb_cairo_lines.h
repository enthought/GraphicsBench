#pragma once
#include "gb_cairo_benchmark.h"
#include <gb_lines.h>

class GBCairoLineBenchmark : public GBBenchmark<GBLineMeta, GBLineData, CairoContext>
{
public:
    GBLineAppState app_state;
    virtual void init();
    virtual void render();
};
