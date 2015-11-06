/**
 * @file    effect_volume.h
 * @brief
 *
 * @addtogroup effects
 * @{
 */

#ifndef _EFFECT_VOLUME_H_
#define _EFFECT_VOLUME_H_

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
struct EffectVolumeCfg
{
    struct Color fontColor;
    struct Color minColor;
    struct Color maxColor;

    uint8_t volume;
    systime_t speed;
};

struct EffectVolumeData
{
    systime_t lastStepupdate;
    uint8_t step;
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
void EffectVolumeUpdate(int16_t x, int16_t y, systime_t time, void* effectcfg,
        void* effectdata, struct Effect* next, struct DisplayBuffer* display);
void EffectVolumeReset(int16_t x, int16_t y, systime_t time, void* effectcfg,
        void* effectdata, struct Effect* next);
#ifdef __cplusplus
}
#endif

#endif /* _EFFECT_FADINGPIXELS_H_ */

/** @} */
