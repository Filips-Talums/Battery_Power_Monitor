# Learning PlatformIO

During the software development aspect of the project, an alternative to Arduino IDE came to light: PlatformIO on Visual Studio Code.

It proved to compile and upload code in a much more streamlined manner compared to Arduino IDE, which displayed everything in a friendly and bare-bones manner. However, PlatformIO began to bring light to the real-world embedded systems project design process, showing how the software is not one big `.ino` file but rather multiple modules based on header and source files that compile together. A benefit of this already demonstrated during development is its easy interchangeability and expandability.

## Understanding Multi-File Projects

Initially, at the start of this project, it was required to understand what each pin on the ESP32 does and which pins would be required for this project. This was done using the components that were available at hand. However, through consultation with ChatGPT, the method of having one long file would quickly become a bottleneck if projects were to become bigger and more advanced.

A solution to this was using header and source files. Through previous experience of digging through config files of a game to change the resolution or FOV when not available through the menu, it was easier than if the code itself had to be changed by the developers. So, a multi-file system was adopted which consisted of a config file containing constant values including GPIO output/input pins, limit parameters for voltage, current and voltage drop, shunt value, and the module’s address, where it can all be easily called at any point without multiple lines having to be changed.

Initially, it was intimidating, but after understanding that the header file is used to set the names of the callable functions while the source file contains the script of the functions themselves, it all fell into place in how much more organised a project can be.

## Mock Sensor Testing

The modules required for this project were ordered from AliExpress. As the parts were being sourced from China, they would take time to arrive. Sitting idle was not an option, so the next step was to prepare the software side of the project before the modules arrived.

Instead of waiting for the INA226 module to return real data, the code was temporarily adjusted to return constant float values for voltage and current. The power value was then calculated from these fake values. This allowed the program structure, serial output, and PlatformIO setup to be tested without the physical sensor connected.

After the code was adjusted, an attempt was made to compile it. As expected, it failed at first. One mistake was that the INA226 library uses `getBusVoltage()` rather than `getVoltage()`, which caused compilation errors. Once this was fixed, the code compiled successfully.

The program was then uploaded to the ESP32 and tested using the Serial Monitor. The fake voltage, current, and power values printed correctly, confirming that the multi-file structure, function calls, and serial communication were working before the real sensor arrived.

## Serial Monitor Test Result

The Serial Monitor showed the expected values:

Voltage (V): 9.00

Current (A): 0.52

Power (W): 4.68

This confirmed that the test code was performing as expected. The next step is to implement the OLED display once it arrives.

## Problems Encountered

During testing, several errors were encountered while setting up the multi-file structure. One issue was a linker error caused by function names not matching between the header file, source file, and main file. This showed that declarations in `.h` files must match the function definitions in `.cpp` files exactly.

Another issue was caused by defining non-constant values inside the config header file. As this file was included in multiple source files, the same variable was created more than once, causing linker errors. This was fixed by using constant values for configuration settings such as the INA226 address.

The final issue encountered was the Serial Monitor baud rate. The output first appeared as unreadable characters because the monitor speed did not match the baud rate set in the code. This was fixed by adding `monitor_speed = 115200` to the `platformio.ini` file, matching the value used in `Serial.begin(115200)`.

This testing process helped explain the difference between compiling and linking, and showed why modular code needs to be structured carefully.
