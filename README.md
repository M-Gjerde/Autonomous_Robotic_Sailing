[![Current version on Arduino](https://img.shields.io/badge/Arduino-v1.8.5-blue.svg)](https://www.arduino.cc/en/Main/Software)
[![Current version of release](https://img.shields.io/github/release/Plymouth-Sailboat/SailBoatArduinoInterface/all.svg)](https://github.com/Plymouth-Sailboat/SailBoatArduinoInterface/releases/latest)

# SailBoatArduinoInterface
Arduino code for [Plymouth's Autonomous Sailboat](https://plymouth-sailboat.github.io/). This contains the libraries, controllers and architecture of our arduino low-level controller for our sailboats. This arduino acquires all the data from the different sensors and send them to the main PC. It has also security features in case the PC shuts down.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

- Arduino IDE : https://www.arduino.cc/en/Main/Software
- Arduino Mega 2560 : (tested and working)
- Connected to a Raspberry Pi 3 containing our [ROS packages](https://github.com/Plymouth-Sailboat/SailBoatROS)

### Installing

[Current version of release](https://github.com/Plymouth-Sailboat/SailBoatArduinoInterface/releases/latest). You can download the .hex files and upload them directly on the Arduino using [avrdude](http://www.ladyada.net/learn/avr/avrdude.html). Or you can compile the project yourself with the Arduino IDE if you are not familiar with avrdude commands.

### ROS_LIB
The Arduino depends on the ros_lib library. This library needs to be up to date, built from your Raspberry Pi. To do so, follow the [README](https://github.com/Plymouth-Sailboat/SailBoatROS#ROS_LIB) from the Raspberry PI package.  
You essentially need to build a library on the Raspberry Pi side running the command :
```
rosrun rosserial_arduino make_libraries.py .
```
And replace the folder __ros_lib__ in the Arduino library folder by this one, and reupload your code to the Arduino.

### Building and Uploading

First copy the folder `libraries` and put it in `~/Documents/Arduino/` on your PC (or `~/Arduino/` for Ubuntu users).

You should now be able to launch the *.ino* sketch, compile and upload to the arduino using the [Arduino IDE](https://www.arduino.cc/en/Guide/ArduinoMega2560).
This will launch the Arduino into Stanby Mode, just receiving data from the sensors and sending them to the PC. It will put the rudder at angle 0 and the sail fully opened. After that it won't and shouldn't move the rudder or the sail.

## Authors

* **[Ulysse VAUTIER](https://ulyssevautier.github.io/)**

## Contributor

* **[Christophe VIEL](https://www.researchgate.net/profile/Christophe_Viel)**

## License

This project is licensed under the GNU General Public License v3.0 - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments
This project uses well-known libraries from :
* [Adafruit GPS](https://github.com/adafruit/Adafruit_GPS)
* [TinyGPS++](http://arduiniana.org/libraries/tinygpsplus/)
* [LiquidCrystal](https://bitbucket.org/fmalpartida/new-liquidcrystal/wiki/Home)
We are also using EnableInterrupt librarie to have more interrupts on our boards :
* [EnableInterrupt](https://github.com/GreyGnome/EnableInterrupt)

## Look at the Wiki!
If you want more information about the arduino and the boat, please look at [the wiki](https://github.com/Plymouth-Sailboat/SailBoatArduinoInterface/wiki)
