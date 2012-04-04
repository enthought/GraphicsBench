#pragma once

#include "gb_cairo_benchmark.h"
#include <gb_box.h>
#include <QWidget>


class GBCairoMemmoveBenchmark : public GBBenchmark<GBBoxMeta, GBBoxData, CairoContext>
{
public:
    GBBoxAppState app_state;
    virtual void init();
    virtual void render();
};

class CairoQTWidget : public QWidget
{
  Q_OBJECT  

  public:
    CairoQTWidget(QWidget *parent = 0);

  protected:
    void paintEvent(QPaintEvent *event);

};