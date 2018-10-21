#include "LedDriver.h"

LedDriver::LedDriver(
  I_DigitalOutputGroup &digitalOutputGroup,
  const LedDriver_MappingConfiguration_t &configuration) :
    digitalOutputGroup(digitalOutputGroup),
    configuration(configuration) {};

void LedDriver::WriteGpio(uint16_t ledId, bool state)
{
  for(int i = 0; i < configuration.numberOfElements; i++)
  {
    if(ledId == this->configuration.mappingTable[i].ledId)
    {
      this->digitalOutputGroup.Write(
        this->configuration.mappingTable[i].gpioChannel,
        state);
      break;
    }
  }
};

void LedDriver::TurnOn(uint16_t ledId)
{
  this->WriteGpio(ledId, true);
};

void LedDriver::TurnOff(uint16_t ledId)
{
  this->WriteGpio(ledId, false);
};
