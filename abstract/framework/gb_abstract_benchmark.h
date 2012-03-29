#pragma once
#include "gb_app_state.h"
#include <string>

template <typename meta, typename draw_data, typename context>
class GBAbstractBenchmark
{
public:
    virtual void init() = 0;
    virtual void render() = 0;
};
