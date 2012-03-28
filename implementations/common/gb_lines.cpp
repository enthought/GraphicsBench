#include "gb_lines.h"
#include <fstream>
#include <iostream>
#include <assert.h>

using std::ifstream;
using std::ios_base;
using std::cout;
using std::cin;
using std::endl;

void GBLineAppState::load_data(std::string filename)
{
    GBLineMeta *meta = new GBLineMeta();
    GBLineData *data = new GBLineData();

    long num_elements, dimensions, bytes_per_axis;
    long bytes_per_segment;
    int num_line_segment_ends = 2; /* by definition of a line segment */

    ifstream datafile(filename.c_str(), ios_base::in | ios_base::binary);

    datafile.read((char*) &num_elements, sizeof(num_elements));
    datafile.read((char*) &dimensions, sizeof(dimensions));
    datafile.read((char*) &bytes_per_axis, sizeof(bytes_per_axis));

    meta->num_elements = num_elements;
    meta->dimensions = dimensions;
    meta->bytes_per_axis = bytes_per_axis;
    
    bytes_per_segment  = dimensions * num_line_segment_ends * bytes_per_axis;
    assert(sizeof(LineSegment) == bytes_per_segment);
    
    LineSegment *segments = (LineSegment *)malloc(num_elements * bytes_per_segment);
    datafile.read((char *) segments, num_elements * bytes_per_segment);

    data->segments = segments;

    metadata = meta;
    drawdata = data;
}