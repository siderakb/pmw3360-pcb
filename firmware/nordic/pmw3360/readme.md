# PMW3360

Example NCS app for Pixart PMW3360 mouse sensor, support [trigger (interrupt)](https://developer.nordicsemi.com/nRF_Connect_SDK/doc/2.1.2/zephyr/hardware/peripherals/sensor.html#triggers) or polling. Print to serial port (115200 8n1). Based on [PMW3360 driver](https://developer.nordicsemi.com/nRF_Connect_SDK/doc/2.1.2/nrf/drivers/pmw3360.html)

> Tested under [nRF Connect SDK](https://www.nordicsemi.com/Products/Development-software/nrf-connect-sdk) `v2.1.2` and [nRF52840 DK (PCA10056)](https://www.nordicsemi.com/Products/Development-hardware/nrf52840-dk).

## Pinmap

| PMW3360  |   nRF52840   |
| :------: | :----------: |
|   SCLK   |    P1.05     |
|   MOSI   |    P1.06     |
|   MISO   |    P1.07     |
|    CS    |    P1.08     |
| Motion\* | P1.10 or N.C |
|   RST    | N.C or HIGH  |

- Motion pin is only used when the trigger is enabled. 
- Refer to [DTS](./nrf52840dk_nrf52840.overlay).

## Trigger

Enable or disable trigger by editing [`prj.conf`](./prj.conf):

to enable:
```
CONFIG_PMW3360_MOTION=y
```

to disable:
```
CONFIG_PMW3360_MOTION=n
```

## License

Nordic-5-Clause.
