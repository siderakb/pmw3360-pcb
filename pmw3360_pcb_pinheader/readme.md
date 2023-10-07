# PMW3360 PCB Pin Header

|                Front                 |                 Back                 |                Layers                |
| :----------------------------------: | :----------------------------------: | :----------------------------------: |
| ![](https://i.imgur.com/VEpilMU.jpg) | ![](https://i.imgur.com/O1CKSMO.jpg) | ![](https://i.imgur.com/jaK5cri.png) |

Online preview available [here](https://kicanvas.org/?github=https%3A%2F%2Fgithub.com%2Fsiderakb%2Fpmw3360-pcb%2Ftree%2Fmain%2Fpmw3360_pcb_pinheader), powered by [KiCanvas](https://github.com/theacodes/kicanvas).

- `J1`: 2.54mm pin header connector.
- Mounting holes: 4x M3 (∅3.2mm).

## PCB Characteristics

- Copper layer count: 2
- Board overall dimensions: 23.5 mm x 33 mm
- Min track/spacing: 0.2 mm / 0.2 mm
- Min hole diameter: 0.3 mm
- Castellated pads: No
- Plated board edge: No
- Edge card connectors: No

## Changelog

### [P.1.0] - 2023-10-07

- Changed LDO from TPS73601DBV to TLV74318PDBVR.
- Added PCBA info.
- Update PCB silkscreen.

### [P.0.0] - 2023-06-29

- Update connector pin order.
- Changed mounting holes to NPTH.
- Reduce the board size to 23.5 x 33 mm.
- Reserved RESET pin pull up resistor added.
- Update PWM3360 footprint (reduce the size of the pads).

### [2.1.0] - 2022-10-17

- Align the optical len with the center of the board.
- Resize the board to 26.162 x 35.052 mm.
- Update PWM3360 footprint (reduce the size of the pads).

### [2.0.0] - 2022-10-14

- Changed LDO to TPS73601DBV.
- Removed voltage-level shifter.

### [1.0.0] - 2022-08-20

- First release.
