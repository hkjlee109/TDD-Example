#ifndef LEDDRIVER_H
#define LEDDRIVER_H

#include "I_DigitalOutputGroup.h"

using namespace std;

typedef struct
{
   uint8_t ledId;
   uint16_t gpioChannel;
} LedDriver_MappingElement_t;

typedef struct
{
   const LedDriver_MappingElement_t *mappingTable;
   uint16_t numberOfElements;
} LedDriver_MappingConfiguration_t;

class LedDriver
{
private:
  I_DigitalOutputGroup& digitalOutputGroup;
  const LedDriver_MappingConfiguration_t &configuration;

  void WriteGpio(uint16_t ledId, bool state);

public:
  LedDriver(
    I_DigitalOutputGroup &digitalOutputGroup,
    const LedDriver_MappingConfiguration_t &configuration);

  void TurnOn(uint16_t ledId);
  void TurnOff(uint16_t ledId);
};

#endif
