# PMW3360 PCB 
[PixArt PMW3360DM-T2QU](https://www.pixart.com/products-detail/10/PMW3360DM-T2QU) optical mouse sensor breakout board.

[Demo video (Rev 1.0)](https://youtu.be/X6r8fS4WcTc)

> EDA: [KiCad](https://www.kicad.org/)

## Preview

| Front                                     | Back                                     |                                      |
| ----------------------------------------- | ---------------------------------------- | ------------------------------------ |
| ![front](https://i.imgur.com/YNuyznL.png) | ![back](https://i.imgur.com/ay0Sjee.png) | ![](https://i.imgur.com/O2wRAaS.png) |

![sch](https://i.imgur.com/fngHbs6.jpg)

## BOM

| Ref(s) | Value           | Footprint      | Qty |
| ------ | --------------- | -------------- | --- |
| C1     | 4.7uF/10V       | SMD 0603       | 1   |
| C2     | 100nF           | SMD 0603       | 1   |
| C3     | 1uF             | SMD 0603       | 1   |
| C4     | 4.7uF           | SMD 0603       | 1   |
| R1     | 39R             | SMD 0603       | 1   |
| R2     | 10k             | SMD 0603       | 1   |
| R3*    | *Adj_R1*        | SMD 0603       | 1   |
| R4*    | *Adj_R2*        | SMD 0603       | 1   |
| U1     | PMW3360DM-T2QU  | PMW3360DM-T2QU | 1   |
| U2*    | TPS73601DBV     | SOT-23-5       | 1   |
| J1     | Connector Pin   | 2.54mm 1*8P    | 1   |
| JP1    | Solder Jumper   | 1.0*1.5mm      | 1   |
| TP1*   | V_IO Test Point | D1.5mm         | 1   |
| TP2*   | V_DD Test Point | D1.5mm         | 1   |
| TP3    | GND Test Point  | D1.5mm         | 1   |
> - Adjust the V_DD voltage with the value of R3 and R4.
>   - For 1.8V V_DD, R3=28.0kΩ and R4=56.2kΩ.
>   - R3 and R4 are not necessary if you have fixed voltage LDO on U2.
> - V_DD range: 1.8\~2.1V, Typ. 1.9V.
> - V_IO range: 1.8\~3.6V, Type. 1.9V, must be same or greater than V_DD.

## Jumper Config

- JP1: V_IO voltage selection
  - \[1-2 3\]: V_IO=V_IN
  - \[1 2-3\]: V_IO=V_DD
