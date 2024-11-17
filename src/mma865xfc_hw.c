/*
 * mma865xfc_hw.c
 *
 *  Created on: 16 nov. 2024
 *      Author: Ludo
 */

#include "mma865xfc_hw.h"

#ifndef MMA865XFC_DRIVER_DISABLE_FLAGS_FILE
#include "mma865xfc_driver_flags.h"
#endif
#include "mma865xfc.h"
#include "types.h"

#ifndef MMA865XFC_DRIVER_DISABLE

/*** MMA865XFC HW functions ***/

/*******************************************************************/
MMA865XFC_status_t __attribute__((weak)) MMA865XFC_HW_init(void) {
    // Local variables.
    MMA865XFC_status_t status = MMA865XFC_SUCCESS;
    /* To be implemented */
    return status;
}

/*******************************************************************/
MMA865XFC_status_t __attribute__((weak)) MMA865XFC_HW_de_init(void) {
    // Local variables.
    MMA865XFC_status_t status = MMA865XFC_SUCCESS;
    /* To be implemented */
    return status;
}

/*******************************************************************/
MMA865XFC_status_t __attribute__((weak)) MMA865XFC_HW_i2c_write(uint8_t i2c_address, uint8_t* data, uint8_t data_size_bytes, uint8_t stop_flag) {
    // Local variables.
    MMA865XFC_status_t status = MMA865XFC_SUCCESS;
    /* To be implemented */
    UNUSED(i2c_address);
    UNUSED(data);
    UNUSED(data_size_bytes);
    UNUSED(stop_flag);
    return status;
}

/*******************************************************************/
MMA865XFC_status_t __attribute__((weak)) MMA865XFC_HW_i2c_read(uint8_t i2c_address, uint8_t* data, uint8_t data_size_bytes) {
    // Local variables.
    MMA865XFC_status_t status = MMA865XFC_SUCCESS;
    /* To be implemented */
    UNUSED(i2c_address);
    UNUSED(data);
    UNUSED(data_size_bytes);
    return status;
}

#endif /* MMA865XFC_DRIVER_DISABLE */
