# Q30. I2C Protocol

I2C (Inter-Integrated Circuit) is a communication protocol used to connect multiple IoT sensors and devices using only two wires. It is simple, fast, and allows many devices to communicate with a single microcontroller.

## SDA and SCL Lines
- SDA (Serial Data): Used to transfer data between devices.
- SCL (Serial Clock): Provides the clock signal to synchronize communication.

## I2C Addressing
Each I2C device has a unique address (usually 7-bit). The master device (such as Arduino) uses this address to communicate with a specific sensor on the same I2C bus.

## Common I2C Sensors
1. BMP280 (Temperature & Pressure Sensor)
2. MPU6050 (Accelerometer & Gyroscope)
3. OLED Display (SSD1306)
