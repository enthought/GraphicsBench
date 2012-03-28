#pragma once

#include "gb_cairo_benchmark.h"
#include <gb_box.h>

class GBCairoBoxGradientBenchmark : public GBBenchmark<GBBoxMeta, GBBoxData, CairoContext>
{
public:
	GBBoxAppState app_state;
	virtual void init();
    virtual void render();
};
