#ifndef APP_CONFIG_H
#define APP_CONFIG_H

#include "fsl_lpi2c.h"

/* LPI2C0 -> P0_16 = SDA, P0_17 = SCL (Arduino J2) */
#define APP_I2C_BASE        LPI2C0
#define APP_I2C_BAUD_HZ     100000U
#define APP_I2C_CLK_HZ      12000000U   /* FRO 12 MHz atado a LPI2C0 */

#define AS5600_ADDR         0x36U

#define LCD_ADDR            0x27U       /* el escaner te dira si es 0x27 o 0x3F */
#define LCD_COLS            16U
#define LCD_ROWS            2U

#define APP_LOOP_MS         100U

#endif /* APP_CONFIG_H */
