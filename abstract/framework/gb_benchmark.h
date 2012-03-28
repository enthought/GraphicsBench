#pragma once

#include "gb_app_state.h"
#include <string>

template <typename meta, typename draw_data, typename context>
class GBBenchmark
{
public:
    //context ctx;
    //GBAppState<meta, draw_data> app_state;
    virtual void init() = 0;
    virtual void render() = 0;
};
