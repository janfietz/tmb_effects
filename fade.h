
/**
 * @file    fade.h
 * @brief
 *
 * @addtogroup effects
 * @{
 */

#ifndef _FADE_H_
#define _FADE_H_

#include "effect_defines.h"
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
struct EffectFadeState
{
    systime_t fadesequence;
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
    float FadeUpdateState(systime_t time, systime_t period, struct EffectFadeState* state);
    void FadeResetState(systime_t period, struct EffectFadeState* state);
#ifdef __cplusplus
}
#endif

#endif /* _FADE_H_ */


/** @} */
