#pragma once

#include <abstract/framework/gb_benchmark.h>
#include <string>
#include <stdint.h>
#include <stdlib.h>

struct _box {
    int16_t x;
    int16_t y;
    int16_t width;
    int16_t height;
};

typedef struct _box Box;

class GBBoxMeta 
{
public:
    GBBoxMeta()
    {
    }
    long num_elements;
    long dimensions;
    long bytes_per_axis;
    GBBoxMeta( long num_elements, long dimensions, 
                    long bytes_per_axis) :  num_elements(num_elements), 
                                            dimensions(dimensions), 
                                            bytes_per_axis(bytes_per_axis)
    {
    }
};


class GBBoxData
{
public:
    GBBoxData()
    {
    }
    ~GBBoxData()
    {
        if (NULL != boxes)
        {
            free(boxes);    
        }
    }

    Box *boxes;
};


class GBBoxAppState : public GBAppState<GBBoxMeta, GBBoxData>
{
public:
    virtual void load_data(std::string filename);
};
