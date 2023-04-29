#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    ZiTe
#define PRODUCT         PMW3360 Test

/* key matrix size */
#define MATRIX_ROWS 1
#define MATRIX_COLS 1

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* key matrix pins */
#define MATRIX_ROW_PINS { D0 }
#define MATRIX_COL_PINS { D1 }

/* Pointing device */
#define PMW33XX_CS_PIN B6
#define PMW33XX_CPI 1200 // The CPI range is 100-12000, in increments of 100. Defaults to 1600 CPI.
#define POINTING_DEVICE_INVERT_Y

#define UNUSED_PINS

/* number of backlight levels */
#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 3
#endif

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

#ifdef RGB_DI_PIN
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 0
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#endif

#endif