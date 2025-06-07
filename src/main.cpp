#include "main.h"

wf_params_t *wf_params_ptr = nullptr;

void timerButtonCallback(TimerHandle_t xTimer)
{
  wf_params_ptr->lastPressedButton = NULL_BTN;
}

void timerFaceCallback(TimerHandle_t xTimer)
{
  // Например, обновляем экран каждые 5 секунд
  wf_params_ptr->sfm = SIMPLE;
  showWatchFace(true);
}

void setup()
{
  // Device either restarted or woken up from deep sleep
  hardware_setup();

  gui_setup();

  wf_params_ptr->watchyTimerFace = xTimerCreate(
      "WatchyTimerFace",    // Название (для отладки)
      pdMS_TO_TICKS(15000), // Период (15 секунд)
      pdFALSE,              // Автоповтор (true)
      (void *)0,            // ID таймера (можно передать данные)
      timerFaceCallback     // Функция-обработчик
  );

  // Создаём таймер сброса кнопок (период 5 секунд, автоперезагрузка)
  wf_params_ptr->watchyTimerButton = xTimerCreate(
      "WatchyTimerButton", // Название (для отладки)
      pdMS_TO_TICKS(1000), // Период (1 секунд)
      pdFALSE,             // Автоповтор (true)
      (void *)0,           // ID таймера (можно передать данные)
      timerButtonCallback  // Функция-обработчик
  );

  wf_params_ptr->darkMode = false;
  wf_params_ptr->lastPressedButton = NULL_BTN;
  wf_params_ptr->hours_am_pm = false;
  wf_params_ptr->sfm = SIMPLE;

  // Создаем таймер сброса на простой циферблат(период 5 секунд, автоперезагрузка)
  wf_params_ptr->watchyTimerFace = xTimerCreate(
      "WatchyTimerFace",    // Название (для отладки)
      pdMS_TO_TICKS(15000), // Период (15 секунд)
      pdFALSE,              // Автоповтор (true)
      (void *)0,            // ID таймера (можно передать данные)
      timerFaceCallback     // Функция-обработчик
  );

  // Создаём таймер сброса кнопок (период 5 секунд, автоперезагрузка)
  wf_params_ptr->watchyTimerButton = xTimerCreate(
      "WatchyTimerButton", // Название (для отладки)
      pdMS_TO_TICKS(1000), // Период (1 секунд)
      pdFALSE,             // Автоповтор (true)
      (void *)0,           // ID таймера (можно передать данные)
      timerButtonCallback  // Функция-обработчик
  );

  // After all is processed put device back to sleep
  deep_sleep();
}

void loop()
{
}
