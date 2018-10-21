#include "LedDriver.h"

LedDriver::LedDriver(
  I_DigitalOutputGroup &digitalOutputGroup,
  const LedDriver_MappingTable_t &mappingTable) :
    digitalOutputGroup(digitalOutputGroup),
    mappingTable(mappingTable) {};

void LedDriver::WriteGpio(uint16_t ledId, bool state)
{
  for(auto &map : this->mappingTable)
  {
    if(ledId == map.first)
    {
      this->digitalOutputGroup.Write(
        map.second,
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
