#ifndef MAIN_H
#define MAIN_H

#include <Arduino.h>
#include "hardware/hardware.h"
#include "gui/gui.h"
#include "gui/face.h"

typedef enum faceMode_t
{
    SIMPLE,
    DETAIL,
} faceMode_t;

typedef enum face_mode
{
    MAIN_BIG_FACE = 0,
    MAIN_STANDART_FACE = 1,
    ONLY_STANDART_FACE = 2,
} face_mode;

typedef enum buttons
{
    NULL_BTN,
    UP_BTN,
    DOWN_BTN,
    BACK_BTN,
    MENU_BTN,
} buttons;

typedef struct wf_params_t
{
    buttons lastPressedButton;
    faceMode_t sfm;
    face_mode current_face_mode;
    bool darkMode;
    bool hours_am_pm;
    TimerHandle_t watchyTimerFace;
    TimerHandle_t watchyTimerButton;
} wf_params_t;

extern wf_params_t *wf_params_ptr;

void timerFaceCallback(TimerHandle_t xTimer);
void timerButtonCallback(TimerHandle_t xTimer);

#endif