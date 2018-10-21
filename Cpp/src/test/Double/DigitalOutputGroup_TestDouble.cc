#include "DigitalOutputGroup_TestDouble.h"

bool DigitalOutputGroup_TestDouble::GetState(uint16_t channel)
{
  return this->states[channel];
}

void DigitalOutputGroup_TestDouble::Write(uint16_t channel, bool state)
{
  this->states[channel] = state;
}
