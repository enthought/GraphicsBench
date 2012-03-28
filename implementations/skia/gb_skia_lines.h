#pragma once
#include "gb_skia_benchmark.h"
#include <gb_lines.h>

class GBSkiaLineBenchmark : public GBBenchmark<GBLineMeta, GBLineData, GBSkiaContext>
{
public:
    GBLineAppState app_state;
    virtual void init();
    virtual void render();
};
