# Q29. Sensor Calibration

Sensor calibration is the process of adjusting a sensor so that its readings match the actual value. It is important in IoT systems because accurate sensor data improves monitoring and decision-making.

For an analog soil moisture sensor, the two-point calibration method is used:

1. Measure the sensor value in completely dry soil (Dry Value).
2. Measure the sensor value in fully wet soil (Wet Value).
3. Use these two values to map future readings to a 0–100% moisture scale using the Arduino `map()` function.

This method improves the accuracy and reliability of soil moisture measurements.
