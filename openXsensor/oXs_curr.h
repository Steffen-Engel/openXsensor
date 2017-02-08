#ifndef OXS_CURRENT_h
#define OXS_CURRENT_h

#include <Arduino.h>
#include "oXs_config.h"

struct CURRENTDATA {
//  bool available;          // true if data is available
struct ONE_MEASUREMENT milliAmps;       // in mA
//  int32_t milliAmps;       // in mA
//  bool milliAmpsAvailable;
  int32_t consumedMilliAmps; // in mA
  float floatConsumedMilliAmps; // in mA
  bool consumedMilliAmpsAvailable;
  
  int32_t sumCurrent ;
//  int32_t sumForMampH ;
 
//  int32_t maxMilliAmps;       // in mA
//  int32_t minMilliAmps;       // in mA
};

class OXS_CURRENT {
public:
#ifdef DEBUG  
  #ifdef ARDUINO_AVR_LEONARDO
    OXS_CURRENT(uint8_t pinCurrent, Serial_ &print);
  #else
    OXS_CURRENT(uint8_t pinCurrent, HardwareSerial &print);
  #endif
#else
  OXS_CURRENT(uint8_t pinCurrent) ;
#endif
  CURRENTDATA currentData ;
  void setupCurrent() ;
  void readSensor();
  void resetValues();

private:
#ifdef DEBUG  
#ifdef ARDUINO_AVR_LEONARDO
  Serial_* printer;
#else
  HardwareSerial* printer;
#endif
#endif
  byte _pinCurrent;
  float offsetCurrentSteps ;
  float mAmpPerStep ; 

};

#endif // OXS_CURRENT_h




