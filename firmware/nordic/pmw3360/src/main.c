/*
 * Copyright (c) 2021 Teslabs Engineering S.L.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/* Ref: https://developer.nordicsemi.com/nRF_Connect_SDK/doc/2.1.2/nrf/drivers/pmw3360.html. */

#include <stdio.h>
#include <zephyr/zephyr.h>
#include <zephyr/device.h>
#include <zephyr/drivers/sensor.h>

const struct device *pmw3360 = DEVICE_DT_GET_ONE(pixart_pmw3360);

static struct sensor_trigger pmw3360_trigger = {
    .type = SENSOR_TRIG_DATA_READY,
    .chan = SENSOR_CHAN_ALL,
};

/**
 * @brief Read X/Y value from PMW3360.
 *
 * @param dev PMW3360
 * @param x X axis value.
 * @param y Y axis value.
 * @return 0 if successful, otherwise error code.
 */
static int read_pmw3360(const struct device *dev, int *x, int *y)
{
  *x = 0;
  *y = 0;
  struct sensor_value sen_x;
  struct sensor_value sen_y;
  int ret;

  ret = sensor_sample_fetch_chan(dev, SENSOR_CHAN_ALL);
  if (ret < 0)
  {
    printf("Could not fetch (%d)\n", ret);
    return ret;
  }

  ret = sensor_channel_get(dev, SENSOR_CHAN_POS_DX, &sen_x);
  if (ret < 0)
  {
    printf("Could not get value X (%d)\n", ret);
    return ret;
  }

  ret = sensor_channel_get(dev, SENSOR_CHAN_POS_DY, &sen_y);
  if (ret < 0)
  {
    printf("Could not get value Y (%d)\n", ret);
    return ret;
  }

  *x = sen_x.val1;
  *y = sen_y.val1;
  return 0; /* Successful. */
}

static void pmw3360_trg_handler(const struct device *dev, const struct sensor_trigger *trig)
{
  int x;
  int y;
  int rec = read_pmw3360(dev, &x, &y);
  if (rec != 0)
  {
    printf("Trigger fail (%d)", rec);
    (void)sensor_trigger_set(dev, trig, NULL);
    return;
  }

  printf("X: %5d, Y: %5d \n", x, y);
}

void main(void)
{
  if (!device_is_ready(pmw3360))
  {
    printk("sensor: device %s not ready.\n", pmw3360->name);
    return;
  }

  printk("PMW3360 is ready.\n");
  k_sleep(K_MSEC(1500));

#if defined(CONFIG_PMW3360_MOTION)

  int rec = sensor_trigger_set(pmw3360, &pmw3360_trigger, pmw3360_trg_handler);
  if (rec != 0)
  {
    printf("Cannot config trigger (%d)", rec);
    return;
  }

  while (1)
  {
    k_sleep(K_MSEC(1000));
  }

#else

  while (1)
  {
    int x;
    int y;
    int ret = read_pmw3360(pmw3360, &x, &y);
    if (ret != 0)
    {
      printf("Cannot get value (%d)", ret);
      continue;
    }

    printf("X: %6d, Y: %6d \n", x, y);
    k_sleep(K_MSEC(500)); /* Delay */
  }

#endif
}
