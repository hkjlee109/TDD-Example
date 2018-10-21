#ifndef LEDDRIVER_H
#define LEDDRIVER_H

#include <vector>
#include "I_DigitalOutputGroup.h"

using namespace std;

typedef vector<pair<uint8_t, uint16_t>> LedDriver_MappingTable_t;

class LedDriver
{
private:
  I_DigitalOutputGroup& digitalOutputGroup;
  const LedDriver_MappingTable_t &mappingTable;

  void WriteGpio(uint16_t ledId, bool state);

public:
  LedDriver(
    I_DigitalOutputGroup &digitalOutputGroup,
    const LedDriver_MappingTable_t &mappingTable);

  void TurnOn(uint16_t ledId);
  void TurnOff(uint16_t ledId);
};

#endif
