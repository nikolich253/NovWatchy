#pragma once

#include <Arduino.h>

//Weather Settings
// #define CITY_ID "3067695" //New York City https://openweathermap.org/current#cityid
#define CITY_ID "538836" //Kurganinsk https://openweathermap.org/current#cityid
#define OPENWEATHERMAP_APIKEY "b2f0aa0d8c683b68176385ce6c59132d" //use your own API key :)
#define OPENWEATHERMAP_URL "http://api.openweathermap.org/data/2.5/weather?id=" //open weather api
#define TEMP_UNIT "metric" //metric = Celsius , imperial = Fahrenheit
#define TEMP_LANG "en"
#define WEATHER_UPDATE_INTERVAL 30 //must be greater than 5, measured in minutes
//NTP Settings
#define NTP_SERVER "pool.ntp.org"
#define GMT_OFFSET_SEC 3600 * 3 //New York is UTC -5 EST, -4 EDT, will be overwritten by weather data

#define DARK_MODE false

typedef struct watchySettings {
  // Weather Settings
  String cityID;
  String lat;
  String lon;
  String weatherAPIKey;
  String weatherURL;
  String weatherUnit;
  String weatherLang;
  int8_t weatherUpdateInterval;
  // NTP Settings
  String ntpServer;
  int gmtOffset;
  //
  bool vibrateOClock;
  bool darkMode;
} watchySettings;

extern watchySettings settings;
