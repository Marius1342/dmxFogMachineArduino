# dmxFogMachineArduino
## __Use cases__
I use this to control my own fog machine, which does not have a dmx port. But a button. I connected a relay to this button, every time the channel 20 is active as an example, the relay gets turned on.

## What do you need?
- 📋  An Arduino or something like an Arduino
- 📋 Some power source, like an old power adapter
- 📋  A "RS-485-Module", here is an link, to [amazon](https://amzn.eu/d/3U1l6WY)
- 📋  A dmx (xlr) port, here is also a link, to [amazon](https://amzn.eu/d/h2HQj6V)
- 📋  Optional an oled display and 3 buttons to set new dmx address and show some stats
- 📋  Some time and good soldering skills
- 📋  If you use a OLED display, google your SCK and SCL port for your arduino

*You can find the pre configured ports [here](/lib/config/src/config.h)*

## Here is an wiring diagram
![image](https://raw.githubusercontent.com/Marius1342/dmxFogMachineArduino/main/docs/Picture.jpg)
I hope you can read it.
On the RS-485 Module, where DMX stands, there you have to connect the dmx pins A and B.
The T stands for a button.
The button and OLED display is not required but useful.

### wiring basic without display
- GND => GND 
- GND => RS-485 DI,DE,RE
- RX => RS-485 RO
- 5V => RS-485 VCC
- 5V => Relay VCC
- D11 => Relay EN
- GND => Relay GND

## What will come next?
- 📝 New wiring diagram
- 📝 Clean up the code

## Upload
1. Configure the [config](/lib/config/src/config.h) for your purpose 
2. Upload to your arduino
3. Test and send bug reports if you found some km3814837@gmail.com 📫


*Currently i dont have very much free time, thats why this version have some bugs and i cannot update this project frequently*