
/**
 * @file    effect_plasma.h
 * @brief
 *
 * @addtogroup effects
 * @{
 */

#ifndef _EFFECT_PLASMA_H_
#define _EFFECT_PLASMA_H_

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
struct EffectPlasmaCfg
{
    systime_t spawninterval;
    uint8_t period1;
    struct Color palette[256];
};

struct EffectPlasmaData
{
    systime_t lastspawn;
    struct Color* pixelColors;
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
    void EffectPlasmaUpdate(int16_t x, int16_t y, systime_t time, void* effectcfg,
            void* effectdata, struct Effect* next, struct DisplayBuffer* display);
    void EffectPlasmaReset(int16_t x, int16_t y, systime_t time, void* effectcfg,
            void* effectdata, struct Effect* next);
#ifdef __cplusplus
}
#endif

#endif /* _EFFECT_PLASMA_H_ */


/** @} */
