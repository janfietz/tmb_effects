
/**
 * @file    effect_nightsky.h
 * @brief
 *
 * @addtogroup effects
 * @{
 */

#ifndef _EFFECT_NIGHTSKY_H_
#define _EFFECT_NIGHTSKY_H_

#include "effect_defines.h"
#include "effect.h"
#include "color.h"
#include "fade.h"
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
struct EffectNightSkyCfg
{
    struct Color color;
    bool randomColor;
    int16_t randomizePropability;
    systime_t fadeperiod;
};

struct EffectNightSkyData
{
    bool randomizeFades;
    systime_t lastupdate;
    struct EffectFadeState* fadeStates;
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
    void EffectNightSkyUpdate(int16_t x, int16_t y, systime_t time, void* effectcfg,
            void* effectdata, struct Effect* next, struct DisplayBuffer* display);
    void EffectNightSkyReset(int16_t x, int16_t y, systime_t time, void* effectcfg,
            void* effectdata, struct Effect* next);
#ifdef __cplusplus
}
#endif

#endif /* _EFFECT_NIGHTSKY_H_ */


/** @} */
