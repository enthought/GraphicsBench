#pragma once
#include "gb_agg_benchmark.h"
#include <gb_lines.h>

class GBAggBoxBenchmark : public GBBenchmark<GBBoxMeta, GBBoxData, AggContext>
{
public:
    GBBoxAppState app_state;
    virtual void init();
    virtual void render();
};
