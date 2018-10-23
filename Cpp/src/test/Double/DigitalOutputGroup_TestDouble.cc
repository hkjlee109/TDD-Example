#include "DigitalOutputGroup_TestDouble.h"

DigitalOutputGroup_TestDouble::DigitalOutputGroup_TestDouble(
  bool *states,
  uint16_t channelCount = 65535) :
    states(states)
{
};

DigitalOutputGroup_TestDouble::~DigitalOutputGroup_TestDouble()
{
};

bool DigitalOutputGroup_TestDouble::GetState(uint16_t channel)
{
  return this->states[channel];
}

void DigitalOutputGroup_TestDouble::Write(uint16_t channel, bool state)
{
  this->states[channel] = state;
}
