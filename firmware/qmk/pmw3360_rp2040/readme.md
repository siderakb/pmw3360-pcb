# PMW3360-RP2040

[PMW3360 PCB](https://github.com/siderakb/pmw3360-pcb) QMK example RP2040 edition.

Pre-Build firmware can be found in [Releases](https://github.com/siderakb/pmw3360-pcb/releases/tag/fw_v0.1.0).

## Usage

Copy and paste this folder to `qmk_firmware\keyboards\`, and build:
```
qmk compile -kb pmw3360_rp2040 -km default
```

> Tested on QMK version `0.21.6`.

## Pin Map

| PMW3360 PCB | RP2040 |
| ----------- | ------ |
| VIN         | 3.3V   |
| GND         | GND    |
| SCLK        | GP22   |
| MOSI        | GP23   |
| MISO        | GP20   |
| CS          | GP21   |
| MOTION      | --     |
| RESET       | --     |

- "--" means do not connect.
- JP1: 2 and 1 close, 3 NC.
