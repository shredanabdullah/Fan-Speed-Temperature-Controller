# Fan Speed Temperature Control
C Project - Based on Atmega32 Microcontroller
- Developed a system that controls the speed of a fan depending on the temperature
- Drivers: GPIO, ADC, PWM, LM35 Sensor, LCD and DC-Motor

## System Requirements
Implement the following Fan Controller system with the specifications listed below:
### 1. The aim of this project is to design a temperature-controlled fan using ATmega32 microcontroller, in which the fan is automatically turned ON or OFF according to the temperature.
### 2. In this project, the LM35 temperature sensor will give continuous analog output corresponding to the temperature sensed by it. This analog signal is given to the ADC, which converts the analog values to digital values.
### 3. The digital output of the ADC is equivalent to sensed analog voltage.
### 4. In order to get the temperature from the sensed analog voltage, we need to perform some calculations in the programming for the microcontroller.
### 5. Once the calculations are done by the microcontroller according to the logic, the temperature is displayed on the LCD.
### 6. The microcontroller will continuously monitor the temperature and based on the temperature value, the microcontroller will drive the fan like that:
a. If the temperature is less than 30C turn off the fan.

b. If the temperature is greater than or equal 30C turn on the fan with 25% of its maximum speed.

c. If the temperature is greater than or equal 60C turn on the fan with 50% of its maximum speed.

d. If the temperature is greater than or equal 90C turn on the fan with 75% of its maximum speed.

e. If the temperature is greater than or equal 120C turn on the fan with 100% of its maximum speed.
### 7. The main principle of the circuit is to switch on/off the fan connected to DC motor based on temperature value. The DC-Motor rotates in clock-wise direction or stopped based on the fan state.
### 8. The LCD should display the temperature value and the fan state continuously.


## Contributors <a name = "contributors"></a>

<table>
  <tr>
    <td align="center">
    <a href="https://github.com/shredanabdullah" target="_black">
    <img src="https://avatars.githubusercontent.com/u/105118008?v=4" width="150px;" alt="Shredan Abdallah"/>
    <br />
    <sub><b>Shredan Abdallah</b></sub></a>
    </td>
