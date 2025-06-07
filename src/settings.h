#ifndef SETTINGS_H
#define SETTINGS_H

#include <Arduino.h>

typedef struct watchySettings
{
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
} watchySettings;

// Weather Settings
//  #define CITY_ID "5128581" //New York City https://openweathermap.org/current#cityid
#define CITY_ID "538836"                                         // Kurganinsk https://openweathermap.org/current#cityid
#define OPENWEATHERMAP_APIKEY "b2f0aa0d8c683b68176385ce6c59132d" // use your own API key :)
// You can also use LAT,LON for your location instead of CITY_ID, but not both
#define LAT "44.885368" // Kurganinsk, Looked up on https://www.latlong.net/
#define LON "40.591190"

#ifdef CITY_ID
#define OPENWEATHERMAP_URL "http://api.openweathermap.org/data/2.5/weather?id={cityID}&lang={lang}&units={units}&appid={apiKey}" // open weather api using city ID
#else
#define OPENWEATHERMAP_URL "http://api.openweathermap.org/data/2.5/weather?lat={lat}&lon={lon}&lang={lang}&units={units}&appid={apiKey}" // open weather api using lat lon
#endif

#define TEMP_UNIT "metric" // metric = Celsius , imperial = Fahrenheit
#define TEMP_LANG "en"
#define WEATHER_UPDATE_INTERVAL 30 // must be greater than 5, measured in minutes
// NTP Settings
#define NTP_SERVER "pool.ntp.org"
#define GMT_OFFSET_SEC 3600 * 3 // Kurganinsk is UTC +3 EST will be overwritten by weather data

extern watchySettings settings{
#ifdef CITY_ID
    .cityID = CITY_ID,
#else
    .cityID = "",
    .lat = LAT,
    .lon = LON,
#endif
    .weatherAPIKey = OPENWEATHERMAP_APIKEY,
    .weatherURL = OPENWEATHERMAP_URL,
    .weatherUnit = TEMP_UNIT,
    .weatherLang = TEMP_LANG,
    .weatherUpdateInterval = WEATHER_UPDATE_INTERVAL,
    .ntpServer = NTP_SERVER,
    .gmtOffset = GMT_OFFSET_SEC,
    .vibrateOClock = true,
};

#endif