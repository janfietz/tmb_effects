/**
 * @file    effect_simplecolor.h
 * @brief
 *
 * @addtogroup effects
 * @{
 */

#ifndef _EFFECT_SIMPLECOLOR_H_
#define _EFFECT_SIMPLECOLOR_H_

#include "effect_defines.h"
#include "effect.h"
#include "display.h"
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
struct EffectSimpleColorCfg
{
    struct Color color;
    bool fillbuffer;
};

struct EffectSimpleColorData
{
    bool reset;
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
void EffectSimpleUpdate(int16_t x, int16_t y, systime_t time, void* effectcfg,
        void* effectdata, struct Effect* next, struct DisplayBuffer* display);
void EffectSimpleReset(int16_t x, int16_t y, systime_t time, void* effectcfg,
        void* effectdata, struct Effect* next);
#ifdef __cplusplus
}
#endif

#endif /* _EFFECT_SIMPLECOLOR_H_ */

/** @} */
