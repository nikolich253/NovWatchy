#ifndef FACE_H
#define FACE_H

#include <floatToString.h>

#include "gui.h"
#include "hardware/hardware.h"
#include "hardware/bma.h"
#include "hardware/rtc_sram.h"
#include "app/weather.h"

#include "fonts/Seven_Segment10pt7b.h"
#include "fonts/DSEG7_Classic_Bold_53.h"
#include "fonts/DSEG7_Classic_Regular_15.h"
#include "fonts/DSEG7_Classic_Bold_25.h"
#include "fonts/DSEG7_Classic_Regular_39.h"
#include "icons.h"
#include "settings.h"
#include "main.h"

void showWatchFace(bool partialRefresh);
void drawWatchFace();
void drawTime();
void drawDate();
void drawSteps();
void drawWeather();
void drawBattery();

#endif