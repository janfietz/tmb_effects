
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
 	
/**
 * @brief   Type of a message.
 */
typedef int32_t msg_t;

/**
 * @brief   Type of system time counter.
 */
typedef uint32_t systime_t;

#ifndef MS2ST
#define MS2ST(msec)                                                         \
  ((systime_t)(((((uint32_t)(msec)) *                                       \
                 ((uint32_t)1)) + 999UL) / 1000UL))
#endif
#endif



/** @} */
