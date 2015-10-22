
/**
 * @file    effect.h
 * @brief
 *
 * @addtogroup effects
 * @{
 */

#ifndef _EFFECT_H_
#define _EFFECT_H_

#include "effect_defines.h"
#include "color.h"
#include "display.h"
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
struct Effect;

/**
 * @brief
 *
 * @param[in]
 * @param[in]
 */
typedef void (*effect_update)(int16_t x, int16_t y, systime_t time, void* effectcfg, void* effectdata, struct Effect* next, struct DisplayBuffer* display);
typedef void (*effect_reset)(int16_t x, int16_t y, systime_t time, void* effectcfg, void* effectdata, struct Effect* next);

struct Effect
{
    void* effectcfg;
    void* effectdata;
    effect_update update;
    effect_reset reset;
    struct Effect* p_next;
};


/**
 * @brief   Generic effects single link list, it works like a stack.
 */
struct effect_list {
    struct Effect*              p_next;    /**< @brief Next in the list/queue.     */
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
    void EffectUpdate(struct Effect* effect, int16_t x, int16_t y, systime_t time, struct DisplayBuffer* display);
    void EffectReset(struct Effect* effect, int16_t x, int16_t y, systime_t time);
#ifdef __cplusplus
}
#endif

#endif /* _EFFECT_WANDERING_H_ */


/** @} */
