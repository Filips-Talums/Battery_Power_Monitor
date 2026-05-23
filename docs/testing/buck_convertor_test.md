### Buck Converter Test

## Set-up

# Soldering

When the buck converter was received, it did not include pin headers suitable for breadboard use, therefore jumper cables were soldered directly onto the module connections. The module contains four connection points: IN+, IN−, OUT+, and OUT−.

For organisational and safety purposes, coloured jumper cables were assigned to each connection. A red cable was connected to IN+, a black cable to IN−, an orange cable to OUT+, and a blue cable to OUT−. This reduced the likelihood of wiring errors during testing and assembly.

The colour coding also helped prevent accidental reverse or incorrect connections between the input and output terminals. Incorrect wiring could result in the unregulated input voltage being applied directly to components designed to operate at 5 V, potentially causing permanent damage to the ESP32, OLED display, or other connected components.

The soldering procedure began by inserting the exposed end of a jumper cable through the pad hole on the converter module. The cable was then bent slightly to mechanically anchor it in position before soldering. Flux was applied to improve solder flow and joint quality. A soldering iron set to 330 °C was used to preheat the pad and wire before solder was applied to form the joint. This process was repeated for the remaining three jumper cables.

Once all solder joints were completed, the board was cleaned using 95% isopropyl alcohol to remove excess flux residue and contamination from the surface.




<img width="450" height="1379" alt="Top_View_BuckConvertor" src="https://github.com/user-attachments/assets/d1130507-2254-4376-883c-ab38ef57aed5" />


<img width="450" height="3135" alt="Top_Down_SolderingTools" src="https://github.com/user-attachments/assets/2632b939-eb85-4e35-b2e1-e3fb8aafd26e" />


<img width="450" height="3735" alt="Adjusting_BuckConvertor" src="https://github.com/user-attachments/assets/9f4256d6-6d5d-4744-b1fd-5f930d8cb047" />


<img width="450" height="1188" alt="BUCK_OUT_INITIAL_ON" src="https://github.com/user-attachments/assets/c3f5f7ce-f80b-451a-b753-fe5c0764470c" />

<p align="center">
  <img src="Top_View_BuckConvertor.png" width="450"><br><br>
  <img src="Top_Down_SolderingTools.png" width="450"><br><br>
  <img src="Adjusting_BuckConvertor.png" width="450"><br><br>
  <img src="BUCK_OUT_INITIAL_ON.png" width="450">
</p>
