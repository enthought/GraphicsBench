#include "gb_utils_save_buffer.h"

void gb_save_buffer(std::string filename, unsigned char* buf, unsigned width, unsigned height, unsigned bpp, cairo_format_t format)
{
    cairo_surface_t * surface = cairo_image_surface_create_for_data (buf, format, width, height, width * bpp);
    cairo_surface_write_to_png (surface, filename.c_str());
    cairo_surface_destroy (surface);
}
