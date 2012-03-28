#pragma once

#include <abstract/framework/gb_benchmark.h>
#include <stdint.h>
#include <stdlib.h>
#include <string>

struct _line_segment {
    int16_t begin_x;
    int16_t begin_y;
    int16_t end_x;
    int16_t end_y;
};

typedef struct _line_segment LineSegment;

class GBLineMeta 
{
public:
    GBLineMeta()
    {
    }
    long num_elements;
    long dimensions;
    long bytes_per_axis;
    GBLineMeta(long num_elements, 
                    long dimensions, 
                    long bytes_per_axis) :  num_elements(num_elements), dimensions(dimensions), bytes_per_axis(bytes_per_axis)
    {
    }
};


class GBLineData
{
public:
    GBLineData()
    {
    }
    ~GBLineData()
    {
        if (NULL != segments)
        {
            free(segments);    
        }
    }
    LineSegment *segments;
};


class GBLineAppState : public GBAppState<GBLineMeta, GBLineData>
{
public:
    virtual void load_data(std::string filename);
};