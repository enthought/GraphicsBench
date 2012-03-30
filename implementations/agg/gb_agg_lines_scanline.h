#pragma once
#include "gb_agg_benchmark.h"
#include <gb_lines.h>

class GBAggLineScanLineBenchmark : public GBBenchmark<GBLineMeta, GBLineData, AggContext>
{
public:
    GBLineAppState app_state;
    virtual void init();
    virtual void render();
};
