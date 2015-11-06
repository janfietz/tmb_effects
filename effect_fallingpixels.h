
/**
 * @file    effect_fallingixels.h
 * @brief
 *
 * @addtogroup effects
 * @{
 */

#ifndef _EFFECT_FALLINGPIXELS_H_
#define _EFFECT_FALLINGPIXELS_H_

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
struct EffectFallingPixelsCfg
{
    systime_t spawninterval;
    systime_t fadeperiod;
    systime_t speed;
    systime_t speedVariance;

    struct Color color;
    bool randomRed;
    bool randomGreen;
    bool randomBlue;
};

struct EffectFallingPixelHead
{
    struct Color color;
    bool active;
    systime_t speed;
    systime_t time;
    int16_t posX;
    int16_t posY;
};

struct EffectFallingPixelsData
{
    systime_t lastspawn;
    systime_t lastupdate;
    struct Color* pixelColors;
    struct EffectFadeState* fadeStates;
    struct EffectFallingPixelHead pixelHeads[30];
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
    void EffectFallingPixelsUpdate(int16_t x, int16_t y, systime_t time, void* effectcfg,
            void* effectdata, struct Effect* next, struct DisplayBuffer* display);
    void EffectFallingPixelsReset(int16_t x, int16_t y, systime_t time, void* effectcfg,
            void* effectdata, struct Effect* next);
#ifdef __cplusplus
}
#endif

#endif /* _EFFECT_RANDOMCOLOR_H_ */


/** @} */
