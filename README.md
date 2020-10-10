### Original Code can be found here:
[drvolcano/Volumio-ESP32](https://github.com/drvolcano/Volumio-ESP32)
[...on Volumio Forum...](https://community.volumio.org/t/wifi-remote-for-volumio-based-on-esp32-and-oled/39146)

## This is a moded Version...
### and actually under construction!

## To-Do's:

- [ ] Remove all Monochrome Display parts 

  -> Only support for ssd1351 (in progress)

  -> maybe support other (bigger) colour-Displays later
  
- [ ] Support for Album-Art from Volumio-API
  
  -> Think this will be a key element:[https://github.com/Bodmer/TJpg_Decoder](https://github.com/Bodmer/TJpg_Decoder)

- [ ] Multiple Layouts
  
  -> selectable in Menu

- [ ] Support for "Status-LED's"

  -> https://github.com/DjamesSuhanko/EasyPCF8574

- [ ] Preconfiguration for (touch-) Button-Functions (play, pause, next...)

- [ ] Maybe a Preconfiguration-script for PC

  -> Like the install.sh of NR1-UI

- [ ] Fill the Wiki

  -> Installation instructions

  -> Config- HowTo's

  -> etc.

## Allready done:

#### 08.10.2020:
- [x] added File-Format, Samplerate and Bitdepth to Main-Screen
- [x] added a seccond "Main-Screen" which changes every 12 seconds

#### 09.10.2020:
- [x] disabled "stars"-Background
- [x] changed colours of UI
- [x] activated Buttons for: Play/Pause, Stop, Previous, Next (Updated Wiring)

#### 10.10.2020
- [x] fixed Wifi "AUTH_FAIL" bug by reenabling [Code after Line 685](https://github.com/Maschine2501/Volumio-ESP32/blob/3154605cc0bf50a21a37f0314f13afc1339804dc/src/main.cpp#L685)

## [Wiring - Cabling](https://github.com/Maschine2501/Volumio-ESP32/wiki/Wiring)

## [Which Hardware is needed?](https://github.com/Maschine2501/Volumio-ESP32/wiki/Used-Hardware)

