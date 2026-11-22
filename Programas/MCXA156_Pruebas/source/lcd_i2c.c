#include "lcd_i2c.h"
#include "app_config.h"
#include "fsl_common.h"

#define LCD_RS   0x01U
#define LCD_EN   0x04U
#define LCD_BL   0x08U

static uint8_t s_backlight = LCD_BL;

static void delay_us(uint32_t us)
{
    SDK_DelayAtLeastUs(us, SystemCoreClock);
}

static bool pcf_write(uint8_t value)
{
    lpi2c_master_transfer_t xfer = {0};

    xfer.slaveAddress = LCD_ADDR;
    xfer.direction    = kLPI2C_Write;
    xfer.data         = &value;
    xfer.dataSize     = 1;

    return (LPI2C_MasterTransferBlocking(APP_I2C_BASE, &xfer) == kStatus_Success);
}

static void write_nibble(uint8_t nibble, uint8_t rs)
{
    uint8_t base = (uint8_t)((nibble << 4) | s_backlight | rs);

    (void)pcf_write((uint8_t)(base | LCD_EN));
    delay_us(50);
    (void)pcf_write(base);
    delay_us(200);
}

static void write_byte(uint8_t value, uint8_t rs)
{
    write_nibble((uint8_t)(value >> 4), rs);
    write_nibble((uint8_t)(value & 0x0FU), rs);
}

static void lcd_cmd(uint8_t cmd)
{
    write_byte(cmd, 0);
}

bool lcd_init(void)
{
    delay_us(100000);

    if (!pcf_write(s_backlight)) {
        return false;
    }

    write_nibble(0x03, 0); delay_us(10000);
    write_nibble(0x03, 0); delay_us(500);
    write_nibble(0x03, 0); delay_us(500);
    write_nibble(0x02, 0); delay_us(500);

    lcd_cmd(0x28);
    lcd_cmd(0x0C);
    lcd_cmd(0x06);
    lcd_clear();
    return true;
}

void lcd_clear(void)
{
    lcd_cmd(0x01);
    delay_us(5000);
}

void lcd_set_cursor(uint8_t col, uint8_t row)
{
    static const uint8_t row_off[4] = {0x00, 0x40, 0x14, 0x54};

    if (row >= LCD_ROWS) {
        row = LCD_ROWS - 1U;
    }
    lcd_cmd((uint8_t)(0x80U | (row_off[row] + col)));
}

void lcd_print(const char *s)
{
    while (*s != '\0') {
        write_byte((uint8_t)*s++, LCD_RS);
    }
}

void lcd_print_row(uint8_t row, const char *s)
{
    uint8_t n = 0;

    lcd_set_cursor(0, row);
    while ((*s != '\0') && (n < LCD_COLS)) {
        write_byte((uint8_t)*s++, LCD_RS);
        n++;
    }
    while (n < LCD_COLS) {
        write_byte(' ', LCD_RS);
        n++;
    }
}
