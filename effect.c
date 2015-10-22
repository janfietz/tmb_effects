/**
 * @file    effect.c
 * @brief
 *
 * @addtogroup effects
 * @{
 */

#include "effect.h"
#include "display.h"
#include <stdlib.h>

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/


/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief
 *
 */

void EffectUpdate(struct Effect* effect, int16_t x, int16_t y, systime_t time, struct DisplayBuffer* display)
{
    if (effect != NULL)
    {
        effect->update(x, y, time, effect->effectcfg, effect->effectdata, effect->p_next, display);
    }
}

void EffectReset(struct Effect* effect, int16_t x, int16_t y, systime_t time)
{
    if (effect != NULL)
    {
        effect->reset(x, y, time, effect->effectcfg, effect->effectdata, effect->p_next);
    }
}

/** @} */
