# Q19. Difference between analogWrite() and analogRead() in Arduino

## analogWrite()
- Used to generate a PWM (Pulse Width Modulation) signal on PWM-enabled pins.
- It controls the average power supplied to devices like LEDs and motors.
- Value range: 0–255.

**IoT Example:**
An IoT smart street light uses `analogWrite()` to adjust LED brightness automatically based on the ambient light level.

---

## analogRead()
- Used to read the voltage from an analog sensor connected to an analog input pin.
- Converts the analog voltage into a digital value.
- Value range: 0–1023 (10-bit ADC on most Arduino boards).

**IoT Example:**
An IoT weather station uses `analogRead()` to read data from an LDR or soil moisture sensor and sends the readings to the cloud.

---

## What is PWM?
PWM (Pulse Width Modulation) is a technique used to simulate analog output by rapidly switching a digital pin ON and OFF. By changing the duty cycle, Arduino can control the average voltage supplied to a device.

**Why is it used?**
- To control LED brightness.
- To control motor speed.
- To save power while providing smooth control.
