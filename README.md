# PMW3360 PCB

<a href="https://i.imgur.com/dnOzjEC.jpg"><img src="https://i.imgur.com/dnOzjEC.jpg" width="300"></a>  

[PixArt PMW3360DM-T2QU](https://www.pixart.com/products-detail/10/PMW3360DM-T2QU) optical mouse sensor breakout board. Support 1.8V or 3.3V.

[Demo video (Rev 2.1)](https://youtu.be/orrze81mV_8?t=312)

> A part of [ErgoSNM keyboard](https://github.com/ziteh/ergo-snm-keyboard) project.  
> EDA: KiCad.

## Preview

| Front                                     | Back                                     | Layers                               |
| ----------------------------------------- | ---------------------------------------- | ------------------------------------ |
| ![front](https://i.imgur.com/OyAF7rm.jpg) | ![back](https://i.imgur.com/2qvz6Kv.jpg) | ![](https://i.imgur.com/r5hJnPY.jpg) |

🚩**NOTE**: `Rev 3.X` is designed to be used with [ErgoSNM](https://github.com/ziteh/ergo-snm-keyboard/releases/tag/v2.0.0), if you prefer ***2.54mm pin header*** instead of FPC connector, please refer to [`Rev 2.1`](https://github.com/ziteh/pmw3360-pcb/releases/tag/v2.1.0).

- V_IN range: 2.0\~5.5V. Must be same or greater then V_DD+0.2V, depends on LDO specs and JP1 config.
- V_DD (i.e. VDD of PMW3360) range: 1.8\~2.1V, Typ. 1.9V.
- V_IO (i.e. VDDIO of PMW3360) range: 1.8\~3.6V, Typ. 1.9V. Must be same or greater than V_DD.

If you want it to work with a 3.3V MCU, then connect V_IN to 3.3V, and connect `1` and `2` pads of JP1 with solder let V_IO=V_IN.

## BOM

| Ref    | Value           | Footprint              |
| ------ | --------------- | ---------------------- |
| C1     | 4.7uF/10V       | SMD 0603 (1608 Metric) |
| C2     | 100nF           | SMD 0603 (1608 Metric) |
| C3     | 1uF             | SMD 0603 (1608 Metric) |
| C4     | 4.7uF           | SMD 0603 (1608 Metric) |
| R1     | 39R             | SMD 0603 (1608 Metric) |
| R2     | 10k             | SMD 0603 (1608 Metric) |
| R3\*   | *DNI* or 10k    | SMD 0603 (1608 Metric) |
| R4\*   | *Adj_R1*        | SMD 0603 (1608 Metric) |
| R5\*   | *Adj_R2*        | SMD 0603 (1608 Metric) |
| U1     | PMW3360DM-T2QU  | PMW3360DM-T2QU 16 Pin  |
| U2\*   | TPS73601DBV     | SOT-23-5               |
| J1     | 0.5mm FPC 8P    | AFC01-S08FCA-00        |

- Adjust the V_DD voltage with the value of R4 and R5.
  - For 1.8V V_DD, *Adj_R1*=28.0kΩ and *Adj_R2*=56.2kΩ.
- U2 LDO can be replace by RT9193-18GB, just change C3 and C4 to 1uF, change R5 to a 22nF or larger ceramic capacitor, and R4 don't install.
- R3 is optional/additional nRESET pull up resistor, nRESET pin of PMW3360 has a built in weak pull up circuit.

## Jumper Config

- JP1: V_IO voltage selection
  - 1 and 2 ON (close): V_IO = V_IN
  - 3 and 2 ON (close): V_IO = V_DD

## PCB Characteristics
- Copper layer count: 2
- Board overall dimensions: 27 mm x 28 mm
- Min track/spacing: 0.2 mm / 0.2 mm
- Min hole diameter: 0.3 mm
- Castellated pads: No
- Plated board edge: No
- Edge card connectors: No
  
## Firmware

- [QMK example](https://github.com/ziteh/ergo-snm-keyboard-qmk/tree/main/qmk/pmw3360_test)
- [nRF Connect SDK (NCS) example](https://github.com/ziteh/ergo-snm-keyboard-qmk/tree/main/nrf/pmw3360)
