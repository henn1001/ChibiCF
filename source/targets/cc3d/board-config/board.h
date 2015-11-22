/*
    ChibiOS - Copyright (C) 2006..2015 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#ifndef _BOARD_H_
#define _BOARD_H_

/*
 * Setup for the LeafLabs Maple Mini.
 */

/*
 * Board identifier.
 */
#define BOARD_CC3D
#define BOARD_NAME              "CC3D"

/*
 * Board frequencies.
 */
#define STM32_LSECLK            0
#define STM32_HSECLK            8000000

/*
 * MCU type, supported types are defined in ./os/hal/platforms/hal_lld.h.
 */
#define STM32F10X_MD

/*
 * IO pins assignments.
 */
#define GPIOA_S5_IN             0
#define GPIOA_S6_IN             1
#define GPIOA_S6_OUT            2
#define GPIOA_GYRO_INT          3  //MPU6000
#define GPIOA_SPI1_NSS          4  //*
#define GPIOA_SPI1_SCK          5  //*
#define GPIOA_SPI1_MISO         6  //*
#define GPIOA_SPI1_MOSI         7  //MPU6000
#define GPIOA_S4_OUT            8
#define GPIOA_UART1_TX          9  //Main-Port
#define GPIOA_UART1_RX          10 //Main-Port
#define GPIOA_USB_DN            11
#define GPIOA_USB_DP            12
#define GPIOA_SWDIO             13
#define GPIOA_SWCLK             14
//#define GPIOA_JTDI            15 Not Connected

#define GPIOB_S3_IN             0
#define GPIOB_S4_IN             1
#define GPIOB_INVERTER          2  //Main-Port-Inverter
#define GPIOB_LED_BLUE          3
#define GPIOB_S5_OUT            4
#define GPIOB_S2_IN             5
#define GPIOB_S1_IN             6
#define GPIOB_S3_OUT            7
#define GPIOB_S2_OUT            8
#define GPIOB_S1_OUT            9
#define GPIOB_UART3_RX          10 //Flexi-Port
#define GPIOB_UART3_TX          11 //Flexi-Port
#define GPIOB_CS_FLSH           12 //Flash-Storage
#define GPIOB_SPI2_SCLK         13 //*
#define GPIOB_SPI2_MISO        14 //*
#define GPIOB_SPI2_MOSI         15 //Flash-Storage


//#define GPIOC_PC13            13 Not Connected
#define GPIOC_VBUS Sense        14
//#define GPIOC_PC15            15 Not Connected

#define GPIOD_OSC_IN            0
#define GPIOD_OSC_OUT           1

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 *
 * The digits have the following meaning:
 *   0 - Analog input.
 *   1 - Push Pull output 10MHz.
 *   2 - Push Pull output 2MHz.
 *   3 - Push Pull output 50MHz.
 *   4 - Digital input.
 *   5 - Open Drain output 10MHz.
 *   6 - Open Drain output 2MHz.
 *   7 - Open Drain output 50MHz.
 *   8 - Digital input with PullUp or PullDown resistor depending on ODR.
 *   9 - Alternate Push Pull output 10MHz.
 *   A - Alternate Push Pull output 2MHz.
 *   B - Alternate Push Pull output 50MHz.
 *   C - Reserved.
 *   D - Alternate Open Drain output 10MHz.
 *   E - Alternate Open Drain output 2MHz.
 *   F - Alternate Open Drain output 50MHz.
 * Please refer to the STM32 Reference Manual for details.
 */

/*
 * Port A setup.
 * Everything input with pull-up except:
 * PA2  - Alternate output          (GPIOA_USART_TX).
 * PA3  - Normal input              (GPIOA_USART_RX).
 * PA13 - Pull-up input             (GPIOA_SWDIO).
 * PA14 - Pull-down input           (GPIOA_SWCLK).
 */
#define VAL_GPIOACRL            0x88884B88      /*  PA7...PA0 */
#define VAL_GPIOACRH            0x88888888      /* PA15...PA8 */
#define VAL_GPIOAODR            0xFFFFBFDF

/*
 * Port B setup.
 * Everything input with pull-up except:
 * PB3  - Push Pull output          (GPIOB_LED_BLUE).
 */
#define VAL_GPIOBCRL            0x88882888      /*  PB7...PB0 */
#define VAL_GPIOBCRH            0x88888888      /* PB15...PB8 */
#define VAL_GPIOBODR            0xFFFFFFFF

/*
 * Port C setup.
 * Everything input with pull-up except:
 */
#define VAL_GPIOCCRL            0x88888888      /*  PC7...PC0 */
#define VAL_GPIOCCRH            0x88888888      /* PC15...PC8 */
#define VAL_GPIOCODR            0xFFFFFFFF

/*
 * Port D setup.
 * Everything input with pull-up except:
 * PD0  - Normal input              (GPIOD_OSC_IN).
 * PD1  - Normal input              (GPIOD_OSC_OUT).
 */
#define VAL_GPIODCRL            0x88888844      /*  PD7...PD0 */
#define VAL_GPIODCRH            0x88888888      /* PD15...PD8 */
#define VAL_GPIODODR            0xFFFFFFFF

/*
 * Port E setup.
 * Everything input with pull-up except:
 */
#define VAL_GPIOECRL            0x88888888      /*  PE7...PE0 */
#define VAL_GPIOECRH            0x88888888      /* PE15...PE8 */
#define VAL_GPIOEODR            0xFFFFFFFF

/*
 * USB bus activation macro, required by the USB driver.
 */
#define usb_lld_connect_bus(usbp) palClearPad(GPIOB, GPIOB_USB_DISC)

/*
 * USB bus de-activation macro, required by the USB driver.
 */
#define usb_lld_disconnect_bus(usbp) palSetPad(GPIOB, GPIOB_USB_DISC)

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* _BOARD_H_ */
