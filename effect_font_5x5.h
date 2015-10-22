
/**
 * @file    effect_font_5x5.h
 * @brief
 *
 * @addtogroup effects
 * @{
 */

#ifndef _EFFECT_FONT_5X5_H_
#define _EFFECT_FONT_5X5_H_

#include "effect_defines.h"
#include "effect.h"
#include "color.h"
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

struct EffectFont5x5Cfg
{
    int speed;
    char text[20];
};

struct EffectFont5x5Data
{
    int pos;
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
    void EffectFont5x5Update(int16_t x, int16_t y, systime_t time, void* effectcfg, void* effectdata, struct Effect* next, struct DisplayBuffer* display);
    void EffectFont5x5Reset(int16_t x, int16_t y, systime_t time, void* effectcfg, void* effectdata, struct Effect* next);
#ifdef __cplusplus
}
#endif

#endif /* _EFFECT_FONT_5X5_H_ */


/** @} */
