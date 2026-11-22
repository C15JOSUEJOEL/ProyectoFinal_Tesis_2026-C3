#include "as5600_app.h"
#include "app_config.h"

#define AS5600_REG_STATUS  0x0BU
#define AS5600_REG_ANGLE   0x0EU   /* angulo con filtro, 12 bits */

static bool as5600_read_regs(uint8_t reg, uint8_t *buf, size_t len)
{
    lpi2c_master_transfer_t xfer = {0};

    xfer.slaveAddress   = AS5600_ADDR;
    xfer.direction      = kLPI2C_Read;
    xfer.subaddress     = reg;
    xfer.subaddressSize = 1;
    xfer.data           = buf;
    xfer.dataSize       = len;

    return (LPI2C_MasterTransferBlocking(APP_I2C_BASE, &xfer) == kStatus_Success);
}

bool as5600_read_status(as5600_status_t *st)
{
    uint8_t s = 0;

    if (!as5600_read_regs(AS5600_REG_STATUS, &s, 1)) {
        return false;
    }
    st->magnet_too_strong = (s & (1U << 3)) != 0U;  /* MH */
    st->magnet_too_weak   = (s & (1U << 4)) != 0U;  /* ML */
    st->magnet_detected   = (s & (1U << 5)) != 0U;  /* MD */
    return true;
}

bool as5600_read_angle(uint16_t *raw)
{
    uint8_t b[2] = {0};

    if (!as5600_read_regs(AS5600_REG_ANGLE, b, 2)) {
        return false;
    }
    *raw = (uint16_t)(((uint16_t)b[0] << 8) | b[1]) & 0x0FFFU;
    return true;
}

uint32_t as5600_raw_to_centideg(uint16_t raw)
{
    return ((uint32_t)raw * 36000UL) / 4096UL;
}
