/*
 * Copyright (c) 2021 Teslabs Engineering S.L.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/* Ref: https://developer.nordicsemi.com/nRF_Connect_SDK/doc/2.1.2/nrf/drivers/pmw3360.html. */

/* Uncommented to enable sensor trigger. */
// #define ENABLE_INTERRUPT

#include <stdio.h>
#include <zephyr/zephyr.h>
#include <zephyr/device.h>
#include <zephyr/drivers/sensor.h>

static struct sensor_trigger pmw3360_trigger;

static int process_pmw3360(const struct device *dev)
{
  struct sensor_value x;
  struct sensor_value y;
  int ret;

  ret = sensor_sample_fetch_chan(dev, SENSOR_CHAN_ALL);
  if (ret < 0)
  {
    printf("Could not fetch (%d)\n", ret);
    return ret;
  }

  ret = sensor_channel_get(dev, SENSOR_CHAN_POS_DX, &x);
  if (ret < 0)
  {
    printf("Could not get value X (%d)\n", ret);
    return ret;
  }

  ret = sensor_channel_get(dev, SENSOR_CHAN_POS_DY, &y);
  if (ret < 0)
  {
    printf("Could not get value Y (%d)\n", ret);
    return ret;
  }

  printf("X: %f, Y: %f \n",
         sensor_value_to_double(&x),
         sensor_value_to_double(&y));

  return 0; /* Successful. */
}

static void handle_pmw3360(const struct device *dev, const struct sensor_trigger *trig)
{
  int rec = process_pmw3360(dev);
  if (rec != 0)
  {
    printf("Trigger fail (%d)", rec);
    (void)sensor_trigger_set(dev, trig, NULL);
    return;
  }
}

void main(void)
{
  const struct device *dev = DEVICE_DT_GET_ONE(pixart_pmw3360);
  if (!device_is_ready(dev))
  {
    printk("sensor: device %s not ready.\n", dev->name);
    return;
  }

  k_sleep(K_MSEC(1500));

#if defined(ENABLE_INTERRUPT)
  /* Setup interrupt triger. */
  pmw3360_trigger = (struct sensor_trigger){
      .type = SENSOR_TRIG_DATA_READY,
      .chan = SENSOR_CHAN_ALL,
  };

  int rec = sensor_trigger_set(dev, &pmw3360_trigger, handle_pmw3360);
  if (rec != 0)
  {
    printf("Cannot config trigger (%d)", rec);
    return;
  }
#else
  while (1)
  {
    int ret = process_pmw3360(dev);
    if (ret != 0)
    {
      printf("Cannot get value (%d)", ret);
      return;
    }

    k_sleep(K_MSEC(500));
  }
#endif
}
