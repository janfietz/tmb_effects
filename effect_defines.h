
/**
 * @file    effect_defines.h
 * @brief
 *
 * @addtogroup effects
 * @{
 */

#ifndef _EFFECT_DEFINES_H_
#define _EFFECT_DEFINES_H_
#include <stdint.h>
#include "hal.h"
 	
/**
 * @brief   Type of a message.
 */
typedef int32_t msg_t;

/**
 * @brief   Type of system time counter.
 */
#ifdef CH_CFG_ST_RESOLUTION
#if CH_CFG_ST_RESOLUTION == 32
typedef uint32_t systime_t;
#elif CH_CFG_ST_RESOLUTION == 16
typedef uint16_t systime_t;
#else
#error "invalid CH_CFG_ST_RESOLUTION setting"
#endif
#else
typedef uint32_t systime_t;
#endif


#ifndef MS2ST
#define MS2ST(msec)                                                         \
  ((systime_t)(((((uint32_t)(msec)) *                                       \
                 ((uint32_t)1)) + 999UL) / 1000UL))
#endif
#endif



/** @} */
