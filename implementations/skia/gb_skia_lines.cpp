#include <SkImageEncoder.h>
#include <SkCanvas.h>
#include <SkBitmap.h>
#include <SkPaint.h>
#include <SkGraphics.h>
#include <SkString.h>
#include <SkTemplates.h>
#include <SkTypeface.h>
#include <utils/gb_utils_timer.h>
#include "gb_skia_lines.h"

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


void GBSkiaLineBenchmark::init()
{
    return;
}

void GBSkiaLineBenchmark::render()
{
    SkAutoGraphics ag;
    // todo: parametrise
    int counter;
    SkPaint paint;

    //Set Text ARGB Color
    paint.setARGB(255, 255, 255, 255);

    //Turn AntiAliasing On
    paint.setAntiAlias(true);
    paint.setLCDRenderText(true);

    SkString path("skhello.png");

    //Set Image Width & Height
    int width = 1920;
    int height = 1200;

    SkBitmap bitmap;
    bitmap.setConfig(SkBitmap::kARGB_8888_Config, width, height);
    bitmap.allocPixels();

    //Create Canvas
    SkCanvas canvas(bitmap);
    canvas.drawARGB(255, 25, 25, 25);

    //Set Style and Stroke Width
    paint.setStyle(SkPaint::kStroke_Style);
    paint.setStrokeWidth(1);
    
    GBTimer timer;

    //  fAlpha = 0x80;
    //paint.setAlpha(0x99);
    paint.setColor(0xffffffff);            // yellow
    paint.setStyle(SkPaint::kStroke_Style);
    paint.setAntiAlias(true);

    timer.start();


    for (counter=0; counter < app_state.metadata->num_elements; counter++)
    {
        LineSegment segment = app_state.drawdata->segments[counter];
        canvas.drawLine(   SkIntToScalar(segment.begin_x), SkIntToScalar(segment.begin_x),
                            SkIntToScalar(segment.end_x), SkIntToScalar(segment.end_y), paint);
    }

    timer.stop();
    SkImageEncoder::EncodeFile("foo.png", bitmap, SkImageEncoder::kJPEG_Type, 80);
    cout << "Skia lines: " << timer << endl;

}

