# Buck Converter Test

## Soldering

When the buck converter was received, it did not include pin headers suitable for breadboard use, therefore jumper cables were soldered directly onto the module connections. The module contains four connection points: IN+, IN−, OUT+, and OUT−.

For organisational and safety purposes, coloured jumper cables were assigned to each connection. A red cable was connected to IN+, a black cable to IN−, an orange cable to OUT+, and a blue cable to OUT−. This reduced the likelihood of wiring errors during testing and assembly.

The colour coding also helped prevent accidental reverse or incorrect connections between the input and output terminals. Incorrect wiring could result in the unregulated input voltage being applied directly to components designed to operate at 5 V, potentially causing permanent damage to the ESP32, OLED display, or other connected components.

The soldering procedure began by inserting the exposed end of a jumper cable through the pad hole on the converter module. The cable was then bent slightly to mechanically anchor it in position before soldering. Flux was applied to improve solder flow and joint quality. A soldering iron set to 330 °C was used to preheat the pad and wire before solder was applied to form the joint. This process was repeated for the remaining three jumper cables.

Once all solder joints were completed, the board was cleaned using 95% isopropyl alcohol to remove excess flux residue and contamination from the surface.


<table align="center">
  <tr>
    <td align="center">
      <img src="https://github.com/user-attachments/assets/d1130507-2254-4376-883c-ab38ef57aed5" width="350"><br>
      <b>Fig. 1:</b> Top View of Buck Converter<br>
      <sub>LM2596 buck converter - Top View.</sub>
    </td>
    <td align="center">
      <img src="https://github.com/user-attachments/assets/2632b939-eb85-4e35-b2e1-e3fb8aafd26e" width="350"><br>
      <b>Fig. 2:</b> Soldering Tools<br>
      <sub>Tools used during soldering.</sub>
    </td>
  </tr>
</table>

## Operation

Initially, when the 9 V supply voltage (Vs) was connected to the IN+ and IN− terminals of the buck converter, the multimeter displayed an output voltage of approximately 8.5 V. This output voltage was adjusted using the onboard trimmer potentiometer. A precision adjustment screwdriver, shown in Figure 3, was used to rotate the potentiometer until the multimeter displayed a stable output voltage slightly above 5 V between the OUT+ and OUT− terminals.

Once the output voltage was verified to be a stable 5.03 V using the multimeter, the buck converter was tested by powering the ESP32 development board from the 9 V source through the converter. The OUT+ and OUT− terminals of the buck converter were connected directly to the 5 V and GND pins of the ESP32 using male-to-female jumper cables.

Immediately after connection, a solid green LED illuminated on the ESP32 development board, indicating that a stable power source was present. The multimeter probes remained connected for approximately one minute to monitor the output voltage and ensure that the converter remained stable under operation. During this observation period, the voltage remained constant, confirming that the buck converter was functioning correctly and was suitable for integration into the main project.


<table align="center">
  <tr>
    <td align="center">
      <img src="https://github.com/user-attachments/assets/9f4256d6-6d5d-4744-b1fd-5f930d8cb047" width="350"><br>
      <b>Fig. 3:</b> Adjusting the Buck Converter<br>
      <sub>Adjusting the onboard trimmer potentiometer.</sub>
    </td>
    <td align="center">
      <img src="https://github.com/user-attachments/assets/c3f5f7ce-f80b-451a-b753-fe5c0764470c" width="350"><br>
      <b>Fig. 4:</b> Buck Converter Output Verification<br>
      <sub>Buck Converter In-Use.</sub>
    </td>
  </tr>
</table>

## Testing Procedure

To verify the buck converter across the voltages specified I used a variable power supply, voltages that will be tested against is 5v - 12v.

With testing was shown 4.5 V Vs is the lowest the power pack can go before the buck converter and the esp32 turns on and the pack max go to 12v whcih is the highest tested, a 15v source is going to have to be sourced to verify it can read up to 15 v

## Testing Results

| Input Voltage - Vin (V) | Output Voltage - Vout (V) | Observation |
|---|---|---|
| 12.03 V | 5.01 V | Stable output voltage |
| 9.13 V | 5.00 V | Stable output voltage |
| 7.64 V | 5.01 V | Stable output voltage |
| 6.10 V | 4.98 V | Stable output voltage |
| 5.13 V | 4.33 V | ESP32 powered on successfully; however, further testing is required with the INA226 power monitor and OLED display connected to determine the minimum stable operating voltage of the system. |

