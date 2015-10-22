
/**
 * @file    effect_wandering.h
 * @brief
 *
 * @addtogroup effects
 * @{
 */

#ifndef _EFFECT_WANDERING_H_
#define _EFFECT_WANDERING_H_

#include "effect_defines.h"
#include "effect.h"
#include "color.h"
#include <stdbool.h>
/*===========================================================================*/
/* Effect constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Effect pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/
struct EffectWanderingCfg
{
    int speed;
    int ledbegin;
    int ledend;
    int8_t dir;
    uint8_t trailLength;
    bool turn;
};

struct EffectWanderingData
{
    uint16_t pos;
    int8_t dir_x;
    int8_t dir_y;
    systime_t lastupdate;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif
    void EffectWanderingUpdate(int16_t x, int16_t y, systime_t time, void* effectcfg, void* effectdata, struct Effect* next, struct DisplayBuffer* display);
    void EffectWanderingReset(int16_t x, int16_t y, systime_t time, void* effectcfg, void* effectdata, struct Effect* next);
#ifdef __cplusplus
}
#endif

#endif /* _EFFECT_WANDERING_H_ */


/** @} */
