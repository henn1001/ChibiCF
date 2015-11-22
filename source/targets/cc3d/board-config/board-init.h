/*
 * board-initialization.h
 *
 *  Created on: 21.11.2015
 *      Author: hendr
 */

#ifndef _BOARD_INIT_H_
#define _BOARD_INIT_H_

typedef struct sonarGPIOConfig_s {
    GPIO_TypeDef *gpio;
    uint16_t triggerPin;
    uint16_t echoPin;
} sonarGPIOConfig_t;

typedef struct drv_pwm_config_s {
    bool useParallelPWM;
    bool usePPM;
    bool useSerialRx;
    bool useRSSIADC;
    bool useCurrentMeterADC;
    bool useUART2;
    bool useVbat;
    bool useOneshot;
    bool useFastPWM;
    bool useSoftSerial;
    bool useLEDStrip;
#ifdef SONAR
    bool useSonar;
#endif
#ifdef USE_SERVOS
    bool useServos;
    bool useChannelForwarding;    // configure additional channels as servos
    uint16_t servoPwmRate;
    uint16_t servoCenterPulse;
#endif
    bool airplane;       // fixed wing hardware config, lots of servos etc
    uint16_t motorPwmRate;
    uint16_t idlePulse;  // PWM value to use when initializing the driver. set this to either PULSE_1MS (regular pwm),
                         // some higher value (used by 3d mode), or 0, for brushed pwm drivers.
    sonarGPIOConfig_t *sonarGPIOConfig;
} drv_pwm_config_t;

void init(void);

#endif /* _BOARD_INIT_H_ */
