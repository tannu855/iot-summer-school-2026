# Q20. setup() and loop() Functions in Arduino

## setup()
- `setup()` runs only once when the Arduino is powered on or reset.
- It is used to initialize pins, sensors, Serial communication, and other settings.

## loop()
- `loop()` runs continuously after `setup()` finishes.
- It contains the main program logic that keeps repeating.

## What happens if a long `delay()` is used inside `loop()`?
A long `delay()` stops the Arduino from doing other tasks during that time. As a result, sensor readings and other operations are delayed, making the system less responsive.

## Effect on Sensor Reading Responsiveness
Sensors are checked less frequently, so important changes may
