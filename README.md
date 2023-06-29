# PMW3360 PCB

| 2.54mm Pin Header                                                                                     | 0.5mm FFC/FPC                                                                                         |
| ----------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------- |
| <a href="https://i.imgur.com/dnOzjEC.jpg"><img src="https://i.imgur.com/dnOzjEC.jpg" width="300"></a> | <a href="https://i.imgur.com/n6hp9wy.jpg"><img src="https://i.imgur.com/n6hp9wy.jpg" width="300"></a> |

[PixArt PMW3360DM-T2QU](https://www.pixart.com/products-detail/10/PMW3360DM-T2QU) optical mouse sensor breakout board, can be operated with either a 1.8V or 3.3V voltage level.

[Demo video (Rev 2.1)](https://youtu.be/orrze81mV_8?t=312)

> EDA: KiCad 7.

## PCB

![Schematic](https://i.imgur.com/Yu6TUAT.png)

3 connector editions are available:
- 2.54mm pin header: [`pmw3360_pcb_pinheader/`](/pmw3360_pcb_pinheader/)
- JST GH 1.25mm: [`pmw3360_pcb_jst/`](/pmw3360_pcb_jst/)
- 0.5mm FFC/FPC: [`pmw3360_pcb_ffc/`](/pmw3360_pcb_ffc/)

### BOM

| Ref  | Value          | Footprint              |
| ---- | -------------- | ---------------------- |
| C1   | 4.7uF/10V      | SMD 0603 (1608 Metric) |
| C2   | 100nF          | SMD 0603 (1608 Metric) |
| C3   | 1uF            | SMD 0603 (1608 Metric) |
| C4   | 4.7uF          | SMD 0603 (1608 Metric) |
| R1\* | *DNI* or 10k   | SMD 0603 (1608 Metric) |
| R2   | 10k            | SMD 0603 (1608 Metric) |
| R3   | 39R            | SMD 0603 (1608 Metric) |
| R4\* | 28k            | SMD 0603 (1608 Metric) |
| R5\* | 56.2k          | SMD 0603 (1608 Metric) |
| U1   | PMW3360DM-T2QU | PMW3360DM-T2QU 16 Pin  |
| U2\* | TPS73601DBV    | SOT-23-5               |

- Adjust the VDD voltage with the value of R4 and R5. In the above case, VDD is set to 1.8V.
- U2 LDO can be replace by RT9193-18GB. To make replacement, change C4 to 1uF, change R5 to a 22nF or larger ceramic capacitor, and don't install R4.
- R1 is optional/additional RESET pull up resistor, RESET pin of PMW3360 has a built in weak pull up circuit.

## Power

If you want to use it with a 3.3V MCU, please connect VIN to the 3.3V power supply. Then, solder the 1 and 2 pads of JP1 together to set **VIO = VIN = 3.3V**.

For 1.8V MCU, please connect VIN to 2.0\~5.5V, solder and connect the 2 and 3 pads of JP1.

### Voltage Range

- **VIN**: 2.0\~5.5V. Must be same or greater then VDD+0.2V, depends on LDO specs and JP1 config.
- **VDD**: 1.8\~2.1V, typical 1.9V.
- **VIO**: 1.8\~3.6V, typical 1.9V. Must be same or greater than VDD.

### Jumper Config

| JP1 Config          | Description                 |
| ------------------- | --------------------------- |
| 2 and 1 close, 3 NC | VIO = VIN                   |
| 2 and 3 close, 1 NC | VIO = VDD (i.e. LDO output) |

## Firmware Examples

- [QMK](/firmware/qmk/pmw3360_test/)
- [nRF Connect SDK (NCS)](/firmware/nordic/)

## License

- KiCad Files (e.g. schematics, PCBs, footprints and symbols): [MIT](/LICENSE).
- `firmware/qmk/`: [GPL v2](/LICENSE_QMK).
- `firmware/nordic/`: [Nordic-5-Clause](/LICENSE_Nordic).
