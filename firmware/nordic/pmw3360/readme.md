# PMW3360

Example NCS app for Pixart PMW3360 mouse sensor, support [trigger (interrupt)](https://developer.nordicsemi.com/nRF_Connect_SDK/doc/2.1.2/zephyr/hardware/peripherals/sensor.html#triggers) or non-trigger.

Based on [PMW3360 driver](https://developer.nordicsemi.com/nRF_Connect_SDK/doc/2.1.2/nrf/drivers/pmw3360.html)

> Tested under [nRF Connect SDK](https://www.nordicsemi.com/Products/Development-software/nrf-connect-sdk) `v2.1.2` and [nRF52840 DK (PCA10056)](https://www.nordicsemi.com/Products/Development-hardware/nrf52840-dk).

## Pinmap

| PMW3360 |   nRF52840   |
| :-----: | :----------: |
|  SCLK   |     1.05     |
|  MOSI   |     1.08     |
|  MISO   |     1.09     |
|   CS    |     1.04     |
| Motion  |     0.31     |
|   RST   | N.C. or HIGH |
> Refer to [DTS](./nrf52840dk_nrf52840.overlay).