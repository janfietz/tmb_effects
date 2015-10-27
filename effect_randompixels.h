
/**
 * @file    effect_randompixels.h
 * @brief
 *
 * @addtogroup effects
 * @{
 */

#ifndef _EFFECT_RANDOMPIXELS_H_
#define _EFFECT_RANDOMPIXELS_H_

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
struct EffectRandomPixelsCfg
{
    systime_t spawninterval;

    struct Color color;
    bool randomRed;
    bool randomGreen;
    bool randomBlue;
};

struct EffectRandomPixelsData
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
    void EffectRandomPixelsUpdate(int16_t x, int16_t y, systime_t time, void* effectcfg,
            void* effectdata, struct Effect* next, struct DisplayBuffer* display);
    void EffectRandomPixelsReset(int16_t x, int16_t y, systime_t time, void* effectcfg,
            void* effectdata, struct Effect* next);
#ifdef __cplusplus
}
#endif

#endif /* _EFFECT_RANDOMCOLOR_H_ */


/** @} */
