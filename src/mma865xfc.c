/*
 * mma865xfc.c
 *
 *  Created on: 16 nov. 2024
 *      Author: Ludo
 */

#include "mma865xfc.h"

#ifndef MMA865XFC_DRIVER_DISABLE_FLAGS_FILE
#include "mma865xfc_driver_flags.h"
#endif
#include "error.h"
#include "math.h"
#include "mma865xfc_hw.h"
#include "types.h"

#ifndef MMA865XFC_DRIVER_DISABLE

/*** MMA865XFC macros ***/

#define MMA865XFC_WRITE_TRANSFER_SIZE_BYTES     2

/*** MMA865XFC functions ***/

/*******************************************************************/
MMA865XFC_status_t MMA865XFC_init(void) {
    // Local variables.
    MMA865XFC_status_t status = MMA865XFC_SUCCESS;
    // Init hardware interface.
    status = MMA865XFC_HW_init();
    if (status != MMA865XFC_SUCCESS) goto errors;
errors:
    return status;
}

/*******************************************************************/
MMA865XFC_status_t MMA865XFC_de_init(void) {
    // Local variables.
    MMA865XFC_status_t status = MMA865XFC_SUCCESS;
    // Init hardware interface.
    status = MMA865XFC_HW_de_init();
    if (status != MMA865XFC_SUCCESS) goto errors;
errors:
    return status;
}

/*******************************************************************/
MMA865XFC_status_t MMA865XFC_get_id(uint8_t i2c_address, uint8_t* chip_id) {
    // Local variables.
    MMA865XFC_status_t status = MMA865XFC_SUCCESS;
    uint8_t local_addr = MMA865XFC_REGISTER_WHO_AM_I;
    // Check parameter.
    if (chip_id == NULL) {
        status = MMA865XFC_ERROR_NULL_PARAMETER;
        goto errors;
    }
    // Read register.
    status = MMA865XFC_HW_i2c_write(i2c_address, &local_addr, 1, 0);
    if (status != MMA865XFC_SUCCESS) goto errors;
    status = MMA865XFC_HW_i2c_read(i2c_address, chip_id, 1);
    if (status != MMA865XFC_SUCCESS) goto errors;
errors:
    return status;
}

/*******************************************************************/
MMA865XFC_status_t MMA865XFC_write_configuration(uint8_t i2c_address, const MMA865XFC_register_setting_t* mma865xfc_configuration, uint8_t mma865xfc_configuration_size) {
    // Local variables.
    MMA865XFC_status_t status = MMA865XFC_SUCCESS;
    uint8_t tx_data[MMA865XFC_WRITE_TRANSFER_SIZE_BYTES];
    uint8_t reg_idx = 0;
    if (mma865xfc_configuration == NULL) {
        status = MMA865XFC_ERROR_NULL_PARAMETER;
        goto errors;
    }
    if (mma865xfc_configuration_size == 0) {
        status = MMA865XFC_ERROR_CONFIGURATION_SIZE;
        goto errors;
    }
    // Write configuration.
    for (reg_idx = 0; reg_idx < mma865xfc_configuration_size; reg_idx++) {
        // Build frame.
        tx_data[0] = (mma865xfc_configuration[reg_idx].address);
        tx_data[1] = (mma865xfc_configuration[reg_idx].value);
        // Write register.
        status = MMA865XFC_HW_i2c_write(i2c_address, tx_data, MMA865XFC_WRITE_TRANSFER_SIZE_BYTES, 1);
        if (status != MMA865XFC_SUCCESS) goto errors;
    }
errors:
    return status;
}

/*******************************************************************/
MMA865XFC_status_t MMA865XFC_get_acceleration(uint8_t i2c_address, MMA865XFC_axis_t axis, int32_t* acceleration_data_xbits) {
    // Local variables.
    MMA865XFC_status_t status = MMA865XFC_SUCCESS;
    MATH_status_t math_status = MATH_SUCCESS;
    MMA865XFC_register_t reg_addr = 0;
    uint8_t reg_value = 0;
    uint32_t acceleration_data = 0;
    // Check parameters.
    if (axis >= MMA865XFC_AXIS_LAST) {
        status = MMA865XFC_ERROR_AXIS;
        goto errors;
    }
    if (acceleration_data_xbits == NULL) {
        status = MMA865XFC_ERROR_NULL_PARAMETER;
        goto errors;
    }
    // MSB.
    reg_addr = (MMA865XFC_REGISTER_OUT_X_MSB + (axis << 1));
    status = MMA865XFC_HW_i2c_write(i2c_address, &reg_addr, 1, 0);
    if (status != MMA865XFC_SUCCESS) goto errors;
    status = MMA865XFC_HW_i2c_read(i2c_address, &reg_value, 1);
    if (status != MMA865XFC_SUCCESS) goto errors;
    acceleration_data |= (reg_value << (MMA865XFC_DRIVER_NUMBER_OF_BITS - MATH_U8_SIZE_BITS));
    // LSB.
    reg_addr++;
    status = MMA865XFC_HW_i2c_write(i2c_address, &reg_addr, 1, 0);
    if (status != MMA865XFC_SUCCESS) goto errors;
    status = MMA865XFC_HW_i2c_read(i2c_address, &reg_value, 1);
    if (status != MMA865XFC_SUCCESS) goto errors;
    acceleration_data |= (reg_value >> (MATH_U8_SIZE_BITS - (MMA865XFC_DRIVER_NUMBER_OF_BITS - MATH_U8_SIZE_BITS)));
    // Convert to signed value.
    math_status = MATH_two_complement_to_integer(acceleration_data, (MMA865XFC_DRIVER_NUMBER_OF_BITS - 1), acceleration_data_xbits);
    MATH_exit_error(MMA865XFC_ERROR_BASE_MATH);
errors:
    return status;
}

#endif /* MMA865XFC_DRIVER_DISABLE */
