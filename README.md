# Robotic Pan/Tilt System

This project focuses on creating embedded software for controlling a robotic Pan/Tilt system using the Tiva C Series TM4C123GH6PM microcontroller. The software is written in C and utilizes the FreeRTOS (Real-Time Operating System) for efficient task management.

## Project Structure

- **FreeRTOS:** Contains the FreeRTOS source code and configuration files.

- **inc:** Header files directory containing declarations for various modules.

- **README.md:** This file, providing an overview of the project.

- **display_color.c:** Implementation of functions related to color display.

- **display_color.h:** Header file declaring functions and structures for color display.

- **emp_type.h:** Header file defining custom data types for the project.

- **gpio.c:** Implementation of General Purpose Input/Output (GPIO) functions.

- **gpio.h:** Header file declaring GPIO functions and related definitions.

- **main.c:** Main program file containing the entry point and initialization code.

- **spiTask.c:** Implementation of tasks related to Serial Peripheral Interface (SPI) communication.

- **spiTask.h:** Header file declaring functions and structures for SPI tasks.

- **spi_config.c:** Configuration file for SPI communication.

- **spi_config.h:** Header file declaring SPI configuration parameters.

- **taskHandlers.h:** Header file declaring handlers for various tasks in the system.

- **tasktest.c:** Implementation of a test task for validating the functionality of the system.

- **tasktest.h:** Header file declaring functions and structures for the test task.

- **tm4c123gh6pm.h:** Tiva C Series TM4C123GH6PM microcontroller register definitions.

- **tm4c123gh6pm_startup_ccs_gcc.c:** Startup code for the Code Composer Studio (CCS) and GCC toolchains.

## Getting Started

1. Clone the repository to your local machine.

    ```bash
    git clone <repository-url>
    ```

2. Set up your development environment with the necessary toolchains and dependencies.

3. Open the project in your preferred Integrated Development Environment (IDE).

4. Build and flash the code onto the Tiva C Series TM4C123GH6PM microcontroller.

5. Power on the Pan/Tilt system and observe its behavior.

## Note

This README provides a high-level overview of the project structure and files. For detailed explanations of each file and folder, please refer to the comments and documentation within the source code.

Feel free to explore and modify the code to suit your specific Pan/Tilt system requirements. Happy coding!
