/*
 * mma865xfc.h
 *
 *  Created on: 16 nov. 2024
 *      Author: Ludo
 */

#ifndef __MMA865XFC_H__
#define __MMA865XFC_H__

#ifndef MMA865XFC_DRIVER_DISABLE_FLAGS_FILE
#include "mma865xfc_driver_flags.h"
#endif
#include "math.h"
#include "types.h"

/*** MMA865XFC structures ***/

/*!******************************************************************
 * \enum MMA865XFC_status_t
 * \brief MMA865XFC driver error codes.
 *******************************************************************/
typedef enum {
    // Driver errors.
    MMA865XFC_SUCCESS = 0,
    MMA865XFC_ERROR_NULL_PARAMETER,
    MMA865XFC_ERROR_CONFIGURATION_SIZE,
    MMA865XFC_ERROR_AXIS,
    // Low level drivers errors.
    MMA865XFC_ERROR_BASE_I2C = 0x0100,
    MMA865XFC_ERROR_BASE_MATH = (MMA865XFC_ERROR_BASE_I2C + MMA865XFC_DRIVER_I2C_ERROR_BASE_LAST),
    // Last base value.
    MMA865XFC_ERROR_BASE_LAST = (MMA865XFC_ERROR_BASE_MATH + MATH_ERROR_BASE_LAST)
} MMA865XFC_status_t;

#ifndef MMA865XFC_DRIVER_DISABLE

/*!******************************************************************
 * \enum MMA865XFC_register_t
 * \brief MMA865XFC registers set.
 *******************************************************************/
typedef enum {
    MMA865XFC_REGISTER_STATUS = 0x00,
    MMA865XFC_REGISTER_OUT_X_MSB = 0x01,
    MMA865XFC_REGISTER_OUT_X_LSB = 0x02,
    MMA865XFC_REGISTER_OUT_Y_MSB = 0x03,
    MMA865XFC_REGISTER_OUT_Y_LSB = 0x04,
    MMA865XFC_REGISTER_OUT_Z_MSB = 0x05,
    MMA865XFC_REGISTER_OUT_Z_LSB = 0x06,
    MMA865XFC_REGISTER_SYSMOD = 0x0B,
    MMA865XFC_REGISTER_INT_SOURCE = 0x0C,
    MMA865XFC_REGISTER_WHO_AM_I = 0x0D,
    MMA865XFC_REGISTER_XYZ_DATA_CFG = 0x0E,
    MMA865XFC_REGISTER_PL_STATUS = 0x10,
    MMA865XFC_REGISTER_PL_CFG = 0x11,
    MMA865XFC_REGISTER_PL_COUNT = 0x12,
    MMA865XFC_REGISTER_PL_BF_ZCOMP = 0x13,
    MMA865XFC_REGISTER_PL_THS_REG = 0x14,
    MMA865XFC_REGISTER_FF_MT_CFG = 0x15,
    MMA865XFC_REGISTER_FF_MT_SRC = 0x16,
    MMA865XFC_REGISTER_FF_MT_THS = 0x17,
    MMA865XFC_REGISTER_FF_MT_COUNT = 0x18,
    MMA865XFC_REGISTER_ASLP_COUNT = 0x29,
    MMA865XFC_REGISTER_CTRL_REG1 = 0x2A,
    MMA865XFC_REGISTER_CTRL_REG2 = 0x2B,
    MMA865XFC_REGISTER_CTRL_REG3 = 0x2C,
    MMA865XFC_REGISTER_CTRL_REG4 = 0x2D,
    MMA865XFC_REGISTER_CTRL_REG5 = 0x2E,
    MMA865XFC_REGISTER_OFF_X = 0x2F,
    MMA865XFC_REGISTER_OFF_Y = 0x30,
    MMA865XFC_REGISTER_OFF_Z = 0x31,
    MMA865XFC_REGISTER_LAST
} MMA865XFC_register_t;

/*!******************************************************************
 * \struct MMA865XFC_register_setting_t
 * \brief MMA865XFC register structure.
 *******************************************************************/
typedef struct {
    uint8_t address;
    uint8_t value;
} MMA865XFC_register_setting_t;

/*!******************************************************************
 * \enum MMA865XFC_axis_t
 * \brief MMA865XFC axis list.
 *******************************************************************/
typedef enum {
    MMA865XFC_AXIS_X = 0,
    MMA865XFC_AXIS_Y,
    MMA865XFC_AXIS_Z,
    MMA865XFC_AXIS_LAST
} MMA865XFC_axis_t;

/*** MMA865XFC functions ***/

/*!******************************************************************
 * \fn MMA865XFC_status_t MMA865XFC_init(void)
 * \brief Init MMA865XFC interface.
 * \param[in]   none
 * \param[out]  none
 * \retval      Function execution status.
 *******************************************************************/
MMA865XFC_status_t MMA865XFC_init(void);

/*!******************************************************************
 * \fn MMA865XFC_status_t MMA865XFC_de_init(void)
 * \brief Release MMA865XFC interface.
 * \param[in]   none
 * \param[out]  none
 * \retval      Function execution status.
 *******************************************************************/
MMA865XFC_status_t MMA865XFC_de_init(void);

/*!******************************************************************
 * \fn MMA865XFC_status_t MMA865XFC_get_id(uint8_t i2c_address, uint8_t* chip_id)
 * \brief Read accelerometer chip ID.
 * \param[in]   i2c_address: I2C address of the sensor.
 * \param[in]   none
 * \param[out]  chip_id: Pointer to the read chip ID.
 * \retval      Function execution status.
 *******************************************************************/
MMA865XFC_status_t MMA865XFC_get_id(uint8_t i2c_address, uint8_t* chip_id);

/*!******************************************************************
 * \fn MMA865XFC_status_t MMA865XFC_write_configuration(uint8_t i2c_address, const MMA865XFC_register_setting_t* mma865xfc_configuration, uint8_t mma865xfc_configuration_size)
 * \brief Set accelerometer configuration.
 * \param[in]   i2c_address: I2C address of the sensor.
 * \param[in]   mma865xfc_config: List of registers and values to set.
 * \param[in]   mma865xfc_config_size: Size of the configuration.
 * \param[out]  none
 * \retval      Function execution status.
 *******************************************************************/
MMA865XFC_status_t MMA865XFC_write_configuration(uint8_t i2c_address, const MMA865XFC_register_setting_t* mma865xfc_configuration, uint8_t mma865xfc_configuration_size);

/*!******************************************************************
 * \fn MMA865XFC_status_t MMA865XFC_get_acceleration(uint8_t i2c_address, MMA865XFC_axis_t axis, int32_t* acceleration_data_xbits)
 * \brief Read raw accelerometer data.
 * \param[in]   i2c_address: I2C address of the sensor.
 * \param[in]   axis: Accelerometer axis to read.
 * \param[out]  acceleration_data_xbits: Pointer that will contain the axis acceleration value.
 * \retval      Function execution status.
 *******************************************************************/
MMA865XFC_status_t MMA865XFC_get_acceleration(uint8_t i2c_address, MMA865XFC_axis_t axis, int32_t* acceleration_data_xbits);

/*******************************************************************/
#define MMA865XFC_exit_error(base) { ERROR_check_exit(mma865xfc_status, MMA865XFC_SUCCESS, base) }

/*******************************************************************/
#define MMA865XFC_stack_error(base) { ERROR_check_stack(mma865xfc_status, MMA865XFC_SUCCESS, base) }

/*******************************************************************/
#define MMA865XFC_stack_exit_error(base, code) { ERROR_check_stack_exit(mma865xfc_status, MMA865XFC_SUCCESS, base, code) }

#endif /* MMA865XFC_DRIVER_DISABLE */

#endif /* __MMA865XFC_H__ */
