#ifndef LCD_I2C_H
#define LCD_I2C_H

#include <stdint.h>
#include <stdbool.h>

/* LCD HD44780 (16x2) con mochila I2C PCF8574, modo 4 bits */
bool lcd_init(void);
void lcd_clear(void);
void lcd_set_cursor(uint8_t col, uint8_t row);
void lcd_print(const char *s);

/* Escribe la cadena en la fila y rellena con espacios hasta el final
 * (evita borrar toda la pantalla en cada actualizacion y asi no parpadea) */
void lcd_print_row(uint8_t row, const char *s);

#endif /* LCD_I2C_H */
