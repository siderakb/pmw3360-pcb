# PMW3360-Pro Micro

[PMW3360 PCB](https://github.com/siderakb/pmw3360-pcb) QMK example Pro Micro edition.

Pre-Build firmware can be found in [Releases](https://github.com/siderakb/pmw3360-pcb/releases/tag/fw_v0.1.0).

## Usage

Note the processor frequency settings in `rules.mk`, default is 8MHz.

Copy and paste this folder to `qmk_firmware\keyboards\`, and build:
```
qmk compile -kb pmw3360_promicro -km default
```

> Tested on QMK version `0.21.6`.

## Pin Map

| PMW3360 PCB | Pro Micro | ATmega32U4 |
| ----------- | --------- | ---------- |
| VIN         | VCC       | VCC        |
| GND         | GND       | GND        |
| SCLK        | 15        | PB1        |
| MOSI        | 16        | PB2        |
| MISO        | 14        | PB3        |
| CS          | 10        | PB6        |
| MOTION      | --        | --         |
| RESET       | --        | --         |

- "--" means do not connect.
- 3.3V config.
- For 5V Pro Micro, voltage-level shifter is required.
