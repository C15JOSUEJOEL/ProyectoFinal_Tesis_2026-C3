#ifndef AS5600_APP_H
#define AS5600_APP_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    bool magnet_detected;   /* MD: hay iman */
    bool magnet_too_weak;   /* ML: iman muy debil / lejos */
    bool magnet_too_strong; /* MH: iman muy fuerte / cerca */
} as5600_status_t;

/* Devuelve true si el chip respondio por I2C */
bool as5600_read_status(as5600_status_t *st);

/* Angulo de 12 bits (0..4095). Devuelve false si falla el I2C */
bool as5600_read_angle(uint16_t *raw);

/* Convierte a centesimas de grado (0..35999) sin usar float */
uint32_t as5600_raw_to_centideg(uint16_t raw);

#endif /* AS5600_APP_H */
