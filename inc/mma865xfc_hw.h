/*
 * mma865xfc_hw.h
 *
 *  Created on: 16 nov. 2024
 *      Author: Ludo
 */

#ifndef __MMA865XFC_HW_H__
#define __MMA865XFC_HW_H__

#ifndef MMA865XFC_DRIVER_DISABLE_FLAGS_FILE
#include "mma865xfc_driver_flags.h"
#endif
#include "mma865xfc.h"
#include "types.h"

#ifndef MMA865XFC_DRIVER_DISABLE

/*** MMA865XFC HW functions ***/

/*!******************************************************************
 * \fn MMA865XFC_status_t MMA865XFC_HW_init(void)
 * \brief Init MMA865XFC hardware interface.
 * \param[in]   none
 * \param[out]  none
 * \retval      Function execution status.
 *******************************************************************/
MMA865XFC_status_t MMA865XFC_HW_init(void);

/*!******************************************************************
 * \fn MMA865XFC_status_t MMA865XFC_HW_de_init(void)
 * \brief Release MMA865XFC hardware interface.
 * \param[in]   none
 * \param[out]  none
 * \retval      Function execution status.
 *******************************************************************/
MMA865XFC_status_t MMA865XFC_HW_de_init(void);

/*!******************************************************************
 * \fn MMA865XFC_status_t MMA865XFC_HW_i2c_write(uint8_t i2c_address, uint8_t* data, uint8_t data_size_bytes, uint8_t stop_flag)
 * \brief Write data to sensor over I2C bus.
 * \param[in]   i2c_address: 7-bits sensor address.
 * \param[in]   data: Byte array to send.
 * \param[in]   data_size_bytes: Number of bytes to send.
 * \param[in]   stop_flag: Generate stop condition at the end of the transfer if non zero.
 * \param[out]  none
 * \retval      Function execution status.
 *******************************************************************/
MMA865XFC_status_t MMA865XFC_HW_i2c_write(uint8_t i2c_address, uint8_t* data, uint8_t data_size_bytes, uint8_t stop_flag);

/*!******************************************************************
 * \fn MMA865XFC_status_t MMA865XFC_HW_i2c_read(uint8_t i2c_address, uint8_t* data, uint8_t data_size_bytes)
 * \brief Read data from sensor over I2C bus.
 * \param[in]   i2c_address: 7-bits sensor address.
 * \param[in]   data_size_bytes: Number of bytes to read.
 * \param[out]  data: Byte array that will contain the read data.
 * \retval      Function execution status.
 *******************************************************************/
MMA865XFC_status_t MMA865XFC_HW_i2c_read(uint8_t i2c_address, uint8_t* data, uint8_t data_size_bytes);

#endif /* MMA865XFC_DRIVER_DISABLE */

#endif /* __MMA865XFC_HW_H__ */
