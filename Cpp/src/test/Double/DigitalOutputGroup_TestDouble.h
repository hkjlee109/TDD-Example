#ifndef DIGITALOUTPUTGROUP_TESTDOUBLE_H
#define DIGITALOUTPUTGROUP_TESTDOUBLE_H

#include "I_DigitalOutputGroup.h"

using namespace std;

class DigitalOutputGroup_TestDouble : public I_DigitalOutputGroup
{
private:
  bool *states;

public:
  DigitalOutputGroup_TestDouble(
    bool *states,
    uint16_t channelCount = 65535) :
      states(states) {};
  ~DigitalOutputGroup_TestDouble() {};

  bool GetState(uint16_t channel);

  virtual void Write(uint16_t channel, bool state) override;
};

#endif
