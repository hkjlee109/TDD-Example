### How To Build

MacOS
```
make cpputest
make
```

```
MacBookPro:Cpp Harry$ make
g++ -o target/test src/test/AllTests.o src/test/LedDriver/LedDriver_Test.o src/main/LedDriver/LedDriver.o src/test/Double/DigitalOutputGroup_TestDouble.o -Lcpputest-3.8/lib -lCppUTest
target/test -v
TEST(LedDriver, ShouldBeAbleToTurnLedsOff) - 0 ms
TEST(LedDriver, ShouldBeAbleToTurnMultipleLedsOn) - 0 ms
TEST(LedDriver, ShouldBeAbleToTurnOneLedOn) - 0 ms
TEST(LedDriver, ShouldTurnOffAllWhenInitialized) - 0 ms

OK (4 tests, 4 ran, 16 checks, 0 ignored, 0 filtered out, 0 ms)
```
