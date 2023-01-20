# PMW3360 PCB 
[PixArt PMW3360DM-T2QU](https://www.pixart.com/products-detail/10/PMW3360DM-T2QU) optical mouse sensor breakout board.

[Demo video (Rev 2.1)](https://youtu.be/orrze81mV_8?t=312)

Go to [Releases](https://github.com/ziteh/pmw3360-pcb/releases) for schematic and Gerber files.

> A part of [ErgoSNM keyboard](https://github.com/ziteh/ergo-snm-keyboard) project.  
> EDA: KiCad.

## Preview

| Front                                     | Back                                     |                                      |
| ----------------------------------------- | ---------------------------------------- | ------------------------------------ |
| ![front](https://i.imgur.com/eC6rQCU.jpg) | ![back](https://i.imgur.com/R6FjmGU.jpg) | ![](https://i.imgur.com/ATaLw1g.jpg) |

- V_IN range: 2.0\~5.5V, must be same or greater then V_DD+0.2V. Depends on LDO specs and JP1 config.
- V_DD (i.e. VDD of PMW3360) range: 1.8\~2.1V, Typ. 1.9V.
- V_IO (i.e. VDDIO of PMW3360) range: 1.8\~3.6V, Typ. 1.9V, must be same or greater than V_DD.

If you want it to work with a 3.3V MCU, then connect V_IN to 3.3V, and connect `1` and `2` pads of JP1 with solder let V_IO=V_IN.

> NRESET pin of PMW3360 has a built in weak pull up circuit.

## BOM

| Ref(s) | Value           | Footprint              |
| ------ | --------------- | ---------------------- |
| C1     | 4.7uF/10V       | SMD 0603 (1608 Metric) |
| C2     | 100nF           | SMD 0603 (1608 Metric) |
| C3     | 1uF             | SMD 0603 (1608 Metric) |
| C4     | 4.7uF           | SMD 0603 (1608 Metric) |
| R1     | 39R             | SMD 0603 (1608 Metric) |
| R2     | 10k             | SMD 0603 (1608 Metric) |
| R3\*   | *Adj_R1*        | SMD 0603 (1608 Metric) |
| R4\*   | *Adj_R2*        | SMD 0603 (1608 Metric) |
| U1     | PMW3360DM-T2QU  | PMW3360DM-T2QU 16 Pin  |
| U2\*   | TPS73601DBV     | SOT-23-5               |
| J1     | Pin Connector   | 2.54mm 1*8P            |
| JP1    | Solder Jumper   | 1.0*1.5mm              |
| TP1\*  | V_IO Test Point | D1.5mm                 |
| TP2\*  | V_DD Test Point | D1.5mm                 |
| TP3    | GND Test Point  | D1.5mm                 |
- Adjust the V_DD voltage with the value of R3 and R4.
  - For 1.8V V_DD, R3=28.0kΩ and R4=56.2kΩ.
- U2 LDO can be replace by RT9193-18GB, just change C3 and C4 to 1uF, change R4 to a 22nF or larger ceramic capacitor, and R3 don't install.

## Jumper Config

- JP1: V_IO voltage selection
  - \[1-2 3\]: V_IO=V_IN
  - \[1 2-3\]: V_IO=V_DD
  
## Firmware

- [QMK example](https://github.com/ziteh/ergo-snm-keyboard-qmk/tree/main/qmk/pmw3360_test)
- [nRF Connect SDK (NCS) example](https://github.com/ziteh/ergo-snm-keyboard-qmk/tree/main/nrf/pmw3360)
