#pragma once
#include <abstract/framework/gb_abstract_benchmark.h>
#include <abstract/framework/gb_app_state.h>
#include <utils/gb_utils_timer.h>
#include "gb_settings.h"
#include <string>
#include <iostream>

template <typename meta, typename draw_data, typename context>
class GBBenchmark : GBAbstractBenchmark<meta, draw_data, context>
{
public:
    std::string benchmark_name;
    std::string benchmark_file_name;
    
    virtual void print_timing(const GBTimer &timer)
    {
        std::cout << benchmark_name << ": " << timer << std::endl;
    }
};
