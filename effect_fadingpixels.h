/**
 * @file    effect_fadingpixels.h
 * @brief
 *
 * @addtogroup effects
 * @{
 */

#ifndef _EFFECT_FADINGPIXELS_H_
#define _EFFECT_FADINGPIXELS_H_

#include "effect_defines.h"
#include "effect.h"
#include "display.h"
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
struct EffectFadingPixelsCfg
{
    struct Color color;
    bool randomColor;
    uint8_t number;
    systime_t spawninterval;
    systime_t fadeperiod;
};

struct EffectFadingPixelsData
{
    systime_t lastspawn;
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
extern "C"
{
#endif
void EffectFadingPixelsUpdate(int16_t x, int16_t y, systime_t time, void* effectcfg,
        void* effectdata, struct Effect* next, struct DisplayBuffer* display);
void EffectFadingPixelsReset(int16_t x, int16_t y, systime_t time, void* effectcfg,
        void* effectdata, struct Effect* next);
#ifdef __cplusplus
}
#endif

#endif /* _EFFECT_FADINGPIXELS_H_ */

/** @} */
