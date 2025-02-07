# Sendance documentation

nrf sdk version 15.3 is used, because it has the same version of the Softdevice (s140 v6.1.1) that is used in Arduino
The version number of the softdevice has a representation in a hex code needed for generating the DFU packet.

s140 v6.1.1 => 0xB6  (this is used)

s140 7.0.1  => 0xCA 

Application is stored at 0x26000 on Softdevice s140 v6.1.1 and on 0x27000 on v7.0.1 onward!

```
nrfutil.exe pkg generate --hw-version 52 --sd-req 0xB6 --application-version 1 --application .\firmware.bin --key-file .\private.pem app_dfu_gridFW_sdCA.zip
```

This is the repo of the kaidyth bootloader: https://github.com/kaidyth/nrf52_bootloader

This is important for building by yourself: https://github.com/kaidyth/nrf52_bootloader/wiki/Getting-Started

Before changing to DEBUG=1 always delete folder... clean does not work?

NORDIC_SDK_PATH (Environmental variables in Windows)
C:/Users/JSE-Sendance/libraries/nRF5_SDK_15.3.0

Command: (make with chocolatey installed)
make BOARD=feather-express DEBUG=1 flash
nrfjprog.exe -f nrf52 --reset

nRF sdk 15.3.0
compiler: defined in Makefile.windows
GNU_INSTALL_ROOT := C:/Users/JSE-Sendance/libraries/arm_toolchain/9_2020-q2-update/bin/
(use exactly this version of the compiler, you can find it online)


Also for the debug build merge the bootloader_settings.hex file with the output of the make:
mergehex -m .\bootloader_settings.hex .\boards\feather-express\s140\_build\debug_feather-express_bootloader-v0.1.0-8-g49e881c-dirty_s140.hex -o bl.hex

And then flash:
nrfjprog -f nrf52 --program .\bl.hex --sectoranduicrerase --verify


Also important to read:
https://infocenter.nordicsemi.com/index.jsp?topic=%2Fcom.nordic.infocenter.sdk5.v15.0.0%2Flib_bootloader_dfu_banks.html

# RTT is disabled 
In the debug bootloader temporarily, so that the application can output to RTT. Both does only work with changes in the SDK and linker.


# Kaidyth Bootloader

[![Travis Build Status](https://img.shields.io/travis/com/charlesportwoodii/kaidyth_nrf52_bootloader.svg?label=TravisCI&style=flat-square)](https://travis-ci.com/charlesportwoodii/kaidyth_nrf52_bootloader)

A secure bluetooth DFU bootloader for nRF52 with support for the following boards:

- [nRF52840 MDK (Maker Diary)](https://wiki.makerdiary.com/nrf52840-mdk/)
- [nRF52840 MDK USB Dongle (Maker Diary)](https://wiki.makerdiary.com/nrf52840-mdk-usb-dongle/)
- [Nordic nRF52840DK PCA10056](https://www.nordicsemi.com/Software-and-Tools/Development-Kits/nRF52840-DK)
- [Nordic nRF52840DK PCA10059 ("Dongle")](https://www.nordicsemi.com/Software-and-Tools/Development-Kits/nRF52840-Dongle)
- [SparkFun Pro nRF52840](https://www.sparkfun.com/products/15025)
- [Adafruit nRF52840 Feather Express](https://www.adafruit.com/product/4062)
- [Particle Xenon](https://docs.particle.io/xenon/)

## Features

- Based on nRF52 Secure Bootloader
- DFU over BLE OTA + USB Serial
- Self Upgradable via OTA + USB Serial
- Optionally downgradable (`NRF_DFU_BL_ALLOW_DOWNGRADE` Makefile option)
- Double Reset DFU Trigger

### Planned Features

- Application Wipe via 2 Pin Reset
- DFU using UF2

## Flashing

### Using Prebuilt Binaries

If you're just looking to flash the bootloader to your device, simply grab the appropriate board file from the Github releases page and flash using JLink/nrfjprog.

```
nrfjprog -f nrf52 --erase
nrfjprog -f nrf52 --program nrf52840_xxaa_s140_<board>.hex

# For PCA10059 reset UICR before resetting
nrfjprog --memwr 0x10001304 --val 0xFFFFFFFD

nrfjprog -f nf52 --reset
```

> Note that the default bootloader is distributed with a public keypair for application signing. This will permit anyone who has access to the key to be able to flash and overwrite any application you have while in OTA DFU mode. If you're using this bootloader in a production setting, it is recommended to build your own binary with your own keypair.

### Building/Development

Cross platform builds are run through `Docker` to ensure build compatability, eliminate OS specific build issues, and ensure a functional build environment. Simply specify `DEBUG` and `BOARD` environment variables in `docker run` to build an appropriate build for your chip.

```
docker build . -t kaidyth_dfu/toolchain:latest
docker run -v${PWD-.}:/app --env BOARD=mdk-usb-dongle kaidyth_dfu/toolchain:latest
```

Hex and .zip archives for DFU flashes are outputted to the `_build_<board>` directory after compilation succeeds.z

> Note that patches the nRF52 SDK to to add some unoffocially supported functionality (such as `NRF_DFU_BL_ALLOW_DOWNGRADE` and `NRF_DFU_BL_ACCEPT_SAME_VERSION`). It's recommended to use the docker environment for building unless you plan on switching `NORDIC_SDK_PATH` between projects.

If you're interested in setting up your own development environment without docker, take a look at the [Getting Started](https://github.com/charlesportwoodii/kaidyth_nrf52_bootloader/wiki/Getting-Started) page for more information on the dependencies needed.