#include <CppUTest/TestHarness.h>
#include "LedDriver.h"
#include "DigitalOutputGroup_TestDouble.h"

#define Given
#define When

#define NUM_ELEMENTS(array) (sizeof(array)/sizeof(array[0]))

enum
{
  NumberOfDigitalOutput = 10,

  ON = true,
  OFF = false
};

enum
{
  LedId_Green,
  LedId_Yellow,
  LedId_Red,
  LedId_Blue,

  GpioChannel_GreenLed,
  GpioChannel_YellowLed,
  GpioChannel_RedLed,
  GpioChannel_BlueLed
};

static const LedDriver_MappingElement_t mappingElements[] =
  {
    { LedId_Green,  GpioChannel_GreenLed  },
    { LedId_Yellow, GpioChannel_YellowLed },
    { LedId_Red,    GpioChannel_RedLed    },
    { LedId_Blue,   GpioChannel_BlueLed   }
  };

static const LedDriver_MappingConfiguration_t mappingConfiguration =
   {
      mappingElements,
      NUM_ELEMENTS(mappingElements)
   };

TEST_GROUP(LedDriver)
{
  bool digitalOutputTestBuffer[NumberOfDigitalOutput];
  LedDriver *ledDriver;
  DigitalOutputGroup_TestDouble *digitalOutputGroupTestDouble;

  void setup()
  {
    digitalOutputGroupTestDouble =
      new DigitalOutputGroup_TestDouble(
        digitalOutputTestBuffer,
        sizeof(digitalOutputTestBuffer));
  }

  void teardown()
  {
    delete ledDriver;
    delete digitalOutputGroupTestDouble;
  }

  void LedDriverIsInitialized()
  {
    ledDriver = new LedDriver(
      *digitalOutputGroupTestDouble,
      mappingConfiguration);
  }

  void LedRequestedTurn(bool state, uint16_t ledId)
  {
    state ? ledDriver->TurnOn(ledId) : ledDriver->TurnOff(ledId);
  }

  void LedShouldBeTurned(bool expected, uint16_t channel)
  {
     CHECK_EQUAL(expected, digitalOutputGroupTestDouble->GetState(channel));
  }

  void AllLedsShouldBeTurned(bool expected)
  {
    for(uint16_t channel = 0; channel < NumberOfDigitalOutput; channel++)
    {
      LedShouldBeTurned(expected, channel);
    }
  }
};

TEST(LedDriver, ShouldTurnOffAllWhenInitialized)
{
  Given LedDriverIsInitialized();
  AllLedsShouldBeTurned(OFF);
}

TEST(LedDriver, ShouldBeAbleToTurnOneLedOn)
{
  Given LedDriverIsInitialized();

  When LedRequestedTurn(ON, LedId_Green);
  LedShouldBeTurned(ON, GpioChannel_GreenLed);
  LedShouldBeTurned(OFF, GpioChannel_YellowLed);
  LedShouldBeTurned(OFF, GpioChannel_RedLed);
  LedShouldBeTurned(OFF, GpioChannel_BlueLed);
}

TEST(LedDriver, ShouldBeAbleToTurnMultipleLedsOn)
{
  Given LedDriverIsInitialized();

  LedRequestedTurn(ON, LedId_Green);
  LedRequestedTurn(ON, LedId_Yellow);

  LedShouldBeTurned(ON, GpioChannel_GreenLed);
  LedShouldBeTurned(ON, GpioChannel_YellowLed);
  LedShouldBeTurned(OFF, GpioChannel_RedLed);
  LedShouldBeTurned(OFF, GpioChannel_BlueLed);
}

TEST(LedDriver, ShouldBeAbleToTurnLedsOff)
{
  Given LedDriverIsInitialized();

  LedRequestedTurn(ON, LedId_Green);
  LedRequestedTurn(ON, LedId_Yellow);

  LedRequestedTurn(OFF, LedId_Green);
  LedRequestedTurn(OFF, LedId_Yellow);

  AllLedsShouldBeTurned(OFF);
}
