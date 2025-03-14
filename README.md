# Description

This repository contains the **MMA865xFC** accelerometer sensor driver.

# Dependencies

The driver relies on:

* An external `types.h` header file defining the **standard C types** of the targeted MCU.
* The **embedded utility functions** defined in the [embedded-utils](https://github.com/Ludovic-Lesur/embedded-utils) repository.

Here is the versions compatibility table:

| **mma865xfc-driver** | **embedded-utils** |
|:---:|:---:|
| [sw1.2](https://github.com/Ludovic-Lesur/mma865xfc-driver/releases/tag/sw1.2) | >= [sw7.0](https://github.com/Ludovic-Lesur/embedded-utils/releases/tag/sw7.0) |
| [sw1.1](https://github.com/Ludovic-Lesur/mma865xfc-driver/releases/tag/sw1.1) | >= [sw7.0](https://github.com/Ludovic-Lesur/embedded-utils/releases/tag/sw7.0) |
| [sw1.0](https://github.com/Ludovic-Lesur/mma865xfc-driver/releases/tag/sw1.0) | [sw5.0](https://github.com/Ludovic-Lesur/embedded-utils/releases/tag/sw5.0) to [sw6.2](https://github.com/Ludovic-Lesur/embedded-utils/releases/tag/sw6.2) |

# Compilation flags

| **Flag name** | **Value** | **Description** |
|:---:|:---:|:---:|
| `MMA865XFC_DRIVER_DISABLE_FLAGS_FILE` | `defined` / `undefined` | Disable the `mma865xfc_driver_flags.h` header file inclusion when compilation flags are given in the project settings or by command line. |
| `MMA865XFC_DRIVER_DISABLE` | `defined` / `undefined` | Disable the MMA865xFC driver. |
| `MMA865XFC_DRIVER_I2C_ERROR_BASE_LAST` | `<value>` | Last error base of the low level I2C driver. |
| `MMA865XFC_DRIVER_NUMBER_OF_BITS` | `10` / `12` | Number of bits of the acceleration data (depends on part number, refer to datasheet). |
