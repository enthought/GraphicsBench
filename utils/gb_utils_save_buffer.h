#pragma once

#include <string>
#include <cairo.h>

void gb_save_buffer(    std::string filename, unsigned char* buf, unsigned width, 
                        unsigned height, unsigned bpp, cairo_format_t format);
