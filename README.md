# PMW3360 PCB 
[PixArt PMW3360DM-T2QU](https://www.pixart.com/products-detail/10/PMW3360DM-T2QU) optical mouse sensor breakout board.

[Demo video (Rev 1.0)](https://youtu.be/X6r8fS4WcTc)

> EDA: [KiCad](https://www.kicad.org/)

## Preview

| Front                                     | Back                                     |                                      |
| ----------------------------------------- | ---------------------------------------- | ------------------------------------ |
| ![front](https://i.imgur.com/eC6rQCU.jpg) | ![back](https://i.imgur.com/R6FjmGU.jpg) | ![](https://i.imgur.com/ATaLw1g.jpg) |

Go to [Releases](https://github.com/ziteh/pmw3360-pcb/releases) for schematic and Gerber files.

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
> - Adjust the V_DD voltage with the value of R3 and R4.
>   - For 1.8V V_DD, R3=28.0kΩ and R4=56.2kΩ.
>   - R3 and R4 are not necessary if you have fixed voltage LDO on U2.
> - V_DD range: 1.8\~2.1V, Typ. 1.9V.
> - V_IO range: 1.8\~3.6V, Typ. 1.9V, must be same or greater than V_DD.

## Jumper Config

- JP1: V_IO voltage selection
  - \[1-2 3\]: V_IO=V_IN
  - \[1 2-3\]: V_IO=V_DD
