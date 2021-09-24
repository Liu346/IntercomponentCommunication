/*
 *  ======== ti_drivers_config.h ========
 *  Configured TI-Drivers module declarations
 *
 *  The macros defines herein are intended for use by applications which
 *  directly include this header. These macros should NOT be hard coded or
 *  copied into library source code.
 *
 *  Symbols declared as const are intended for use with libraries.
 *  Library source code must extern the correct symbol--which is resolved
 *  when the application is linked.
 *
 *  DO NOT EDIT - This file is generated for the CC3220SF_LAUNCHXL
 *  by the SysConfig tool.
 */
#ifndef ti_drivers_config_h
#define ti_drivers_config_h

#define CONFIG_SYSCONFIG_PREVIEW

#define CONFIG_CC3220SF_LAUNCHXL
#ifndef DeviceFamily_CC3220
#define DeviceFamily_CC3220
#endif

#include <ti/devices/DeviceFamily.h>

#include <stdint.h>

/* support C++ sources */
#ifdef __cplusplus
extern "C" {
#endif


/*
 *  ======== ADC ========
 */

/* P58 */
extern const uint_least8_t          CONFIG_ADC_0_CONST;
#define CONFIG_ADC_0                0


/*
 *  ======== GPIO ========
 */

/* P64, LaunchPad LED D10 (Red) */
extern const uint_least8_t          CONFIG_GPIO_LED_0_CONST;
#define CONFIG_GPIO_LED_0           0
/* P02, LaunchPad LED D8 (Green) */
extern const uint_least8_t          CONFIG_GPIO_LED_1_CONST;
#define CONFIG_GPIO_LED_1           1
/* P03 */
extern const uint_least8_t          GPIO_0_P03_CONST;
#define GPIO_0_P03                  2
/* P05 */
extern const uint_least8_t          GPIO_1_P05_CONST;
#define GPIO_1_P05                  3
/* P06 */
extern const uint_least8_t          GPIO_2_P06_CONST;
#define GPIO_2_P06                  4
/* P07 */
extern const uint_least8_t          GPIO_3_P07_CONST;
#define GPIO_3_P07                  5
/* P08 */
extern const uint_least8_t          GPIO_4_P08_CONST;
#define GPIO_4_P08                  6
/* P18 */
extern const uint_least8_t          GPIO_5_P18_CONST;
#define GPIO_5_P18                  7
/* P21 */
extern const uint_least8_t          GPIO_6_P21_CONST;
#define GPIO_6_P21                  8
/* P45 */
extern const uint_least8_t          GPIO_7_P50_CONST;
#define GPIO_7_P50                  9

/* LEDs are active high */
#define CONFIG_GPIO_LED_ON  (1)
#define CONFIG_GPIO_LED_OFF (0)

#define CONFIG_LED_ON  (CONFIG_GPIO_LED_ON)
#define CONFIG_LED_OFF (CONFIG_GPIO_LED_OFF)


/*
 *  ======== Timer ========
 */

extern const uint_least8_t          CONFIG_TIMER_0_CONST;
#define CONFIG_TIMER_0              0
extern const uint_least8_t          CONFIG_TIMER_1_CONST;
#define CONFIG_TIMER_1              1

/*
 *  ======== UART ========
 */

/*
 *  TX: P55
 *  RX: P57
 *  XDS110 UART
 */
extern const uint_least8_t          CONFIG_UART_0_CONST;
#define CONFIG_UART_0               0


/*
 *  ======== Board_init ========
 *  Perform all required TI-Drivers initialization
 *
 *  This function should be called once at a point before any use of
 *  TI-Drivers.
 */
extern void Board_init(void);

/*
 *  ======== Board_initGeneral ========
 *  (deprecated)
 *
 *  Board_initGeneral() is defined purely for backward compatibility.
 *
 *  All new code should use Board_init() to do any required TI-Drivers
 *  initialization _and_ use <Driver>_init() for only where specific drivers
 *  are explicitly referenced by the application.  <Driver>_init() functions
 *  are idempotent.
 */
#define Board_initGeneral Board_init

#ifdef __cplusplus
}
#endif

#endif /* include guard */
