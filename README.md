# dmxFogMachineArduino
#### __Use cases__
I use this to control my own fog machine, which does not have a dmx port. But a button. I connected a relay to this button, every time the channel 21 as an example, the relay gets turned on.

## What do you need?
1. An Arduino or something like an Arduino
2. Some power source, like an old power adapter
3. A "RS-485-Module", here is an link, to [amazon](https://amzn.eu/d/3U1l6WY)
4. A dmx (xlr) port, here is also a link, to [amazon](https://amzn.eu/d/h2HQj6V)
5. Optional an oled display to set new dmx address and show some stats
7. Some time and good soldering skills


## Here is an wiring diagram
TODO


## Upload
1. Configure the [config](/lib/config/src/config.h) for your purpose 
2. Upload to your arduino
3. Test and send bug reports if you found some km3814837@gmail.com