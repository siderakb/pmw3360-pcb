# PMW3360 PCB

[![license](https://img.shields.io/badge/License-CERN--OHL--P_v2-limegreen)](https://github.com/siderakb/pmw3360-pcb/blob/main/LICENSE-CERN-OHL-P)
[![kicad](https://img.shields.io/badge/KiCad-v7-orange)](https://kicanvas.org/?github=https%3A%2F%2Fgithub.com%2Fsiderakb%2Fpmw3360-pcb%2Ftree%2Fmain%2Fpmw3360_pcb_pinheader)

| 2.54mm Pin Header                                                                                     | 0.5mm FFC/FPC                                                                                         |
| ----------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------- |
| <a href="https://i.imgur.com/dnOzjEC.jpg"><img src="https://i.imgur.com/dnOzjEC.jpg" width="300"></a> | <a href="https://i.imgur.com/n6hp9wy.jpg"><img src="https://i.imgur.com/n6hp9wy.jpg" width="300"></a> |

[PixArt PMW3360DM-T2QU](https://www.pixart.com/products-detail/10/PMW3360DM-T2QU) optical mouse sensor breakout board, can be operated with either a 1.8V or 3.3V voltage level.  
Also look at [PMW3610 PCB](https://github.com/siderakb/pmw3610-pcb).

[Demo video 1](https://youtu.be/orrze81mV_8?t=312), [Demo video 2](https://youtu.be/CSA7Ih7nAls?si=umx-Psb8-lRDeviu)

## PCB

Online preview available [here](https://kicanvas.org/?github=https%3A%2F%2Fgithub.com%2Fsiderakb%2Fpmw3360-pcb%2Ftree%2Fmain%2Fpmw3360_pcb_pinheader), powered by [KiCanvas](https://github.com/theacodes/kicanvas).

![Schematic](https://i.imgur.com/PXqMESW.jpg)

### BOM

| Ref  | Value         | Footprint             |
| ---- | ------------- | --------------------- |
| C1   | 4.7uF/10V     | SMD 0603              |
| C2   | 100nF         | SMD 0603              |
| C3   | 1uF           | SMD 0603              |
| C4\* | 1uF           | SMD 0603              |
| C5\* | *DNI*         | SMD 0603              |
| R1\* | *DNI* or 10kΩ | SMD 0603              |
| R2   | 10kΩ          | SMD 0603              |
| R3   | 39Ω           | SMD 0603              |
| R4\* | *DNI*         | SMD 0603              |
| U1   | PMW3360       | PMW3360DM-T2QU 16 Pin |
| U2\* | TLV74318PDBVR | SOT-23-5              |
| J1\* | 8 Pin         |                       |

- *DNI*: don't install.
- SMD 0603 (Imperial) aka 1608 Metric.
- PMW3360 needs to be used with LM19-LSI lens.
- `R1` is optional/additional RESET pull up resistor, RESET pin of PMW3360 has a built in weak pull up circuit.
- `J1` connector have the following options:
    - 2.54mm pin header: [`pmw3360_pcb_pinheader/`](/pmw3360_pcb_pinheader/)
    - 0.5mm FFC/FPC: [`pmw3360_pcb_ffc/`](/pmw3360_pcb_ffc/)
    - JST GH 1.25mm: [`pmw3360_pcb_jst/`](/pmw3360_pcb_jst/)
- `U2` LDO regulator have the following options:

|  Ref  | Default       | Alt.           | Alt.        |
| :---: | ------------- | -------------- | ----------- |
|  U2   | TLV74318PDBVR | RT9193-18GB    | TPS73601DBV |
|  C4   | 1uF           | 1uF            | 4.7uF       |
|  C5   | *DNI*         | 22nF or larger | 56.2k**Ω**  |
|  R4   | *DNI*         | *DNI*          | 28kΩ        |
| Note  | Fixed 1.8V    | Fixed 1.8V     | Adj. 1.8V   |

### PCB Dimensions & Characteristics

Please refer to:
- 2.54mm pin header: [`pmw3360_pcb_pinheader/`](/pmw3360_pcb_pinheader/)
- 0.5mm FFC/FPC: [`pmw3360_pcb_ffc/`](/pmw3360_pcb_ffc/)
- JST GH 1.25mm: [`pmw3360_pcb_jst/`](/pmw3360_pcb_jst/)

> PCB sizes vary among different connector editions.

## Power

### Voltage-Level Config

3 configs available:

|          |   3.3V    |    1.8 with LDO     |         1.8V without LDO          |
| -------- | :-------: | :-----------------: | :-------------------------------: |
| VIN Typ. |   3.3V    | (VDD + 0.2V) ~ 5.5V |               1.8V                |
| VIN Max. |   3.6V    |        5.5V         |               2.1V                |
| JP1      | `[1-2 3]` |      `[1 2-3]`      |             `[1-2-3]`             |
| Note     |           |                     | `U2`, `R4`, `C3~5` can be omitted |

### Jumper

| JP1 Config |                     | Description                  |
| :--------: | ------------------- | ---------------------------- |
| `[1-2 3]`  | 2 and 1 close, 3 NC | VIO = VIN                    |
| `[1 2-3]`  | 2 and 3 close, 1 NC | VIO = VDD (i.e. LDO output)  |
| `[1-2-3]`  | 1, 2 and 3 close    | VIO = VDD = VIN (LDO bypass) |

### Operating Voltage Range

- **VDD**: 1.8 ~ 2.1V (i.e. LDO Vout)
- **VIO**: VDD ~ 3.6V (i.e. VDDIO)
- **VIN**: Depends on [Voltage-Level config](#voltage-level-config)

## Firmware Examples

- QMK
    - [RP2040](/firmware/qmk/pmw3360_rp2040/)
    - [Pro Micro](/firmware/qmk/pmw3360_promicro/)
- [nRF Connect SDK (NCS)](/firmware/nordic/)

Pre-Build firmware can be found in [Releases](https://github.com/siderakb/pmw3360-pcb/releases/tag/fw_v0.1.0).

## License

- KiCad files (e.g. schematics, PCBs, footprints and symbols): [CERN-OHL-P v2](/LICENSE-CERN-OHL-P).
- `firmware/qmk/`: [GPL v2](/LICENSE-QMK).
- `firmware/nordic/`: [Nordic-5-Clause](/LICENSE-Nordic).
