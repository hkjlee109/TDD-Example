#ifndef I_DIGITALOUTPUTGROUP_H
#define I_DIGITALOUTPUTGROUP_H

#include <cstdint>

struct I_DigitalOutputGroup
{
  virtual ~I_DigitalOutputGroup() {};
  virtual void Write(uint16_t channel, bool state) = 0;
};

#endif
