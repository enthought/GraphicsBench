#include "gb_box.h"
#include <utils/gb_utils_timer.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#include <fstream>
#include <iostream>

using std::ifstream;
using std::ios_base;
using std::cout;
using std::cin;
using std::endl;

void GBBoxAppState::load_data(std::string filename)
{
    GBBoxMeta *meta = new GBBoxMeta();
    GBBoxData *data = new GBBoxData();

    long num_elements, dimensions, bytes_per_axis;
    long bytes_per_box;

    ifstream datafile(filename.c_str(), ios_base::in | ios_base::binary);

    datafile.read((char*) &num_elements, sizeof(num_elements));
    datafile.read((char*) &dimensions, sizeof(dimensions));
    datafile.read((char*) &bytes_per_axis, sizeof(bytes_per_axis));

    meta->num_elements = num_elements;
    meta->dimensions = dimensions;
    meta->bytes_per_axis = bytes_per_axis;
    
    /* bytesize * 4 because (x,y,width, height) */
    bytes_per_box  = dimensions * 2 * bytes_per_axis;
    assert(sizeof(Box) == bytes_per_box);
    
    Box *boxes = (Box *)malloc(num_elements * bytes_per_box);
    datafile.read((char *) boxes, num_elements * bytes_per_box);

    data->boxes = boxes;

    metadata = meta;
    drawdata = data;
}