/**
 * @file    fade.c
 * @brief
 *
 * @addtogroup effects
 * @{
 */

#include "fade.h"
#include <stdlib.h>
#include "float.h"
#include "math.h"

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

float FadeUpdateState(systime_t timeDiff, systime_t period, struct EffectFadeState* state)
{
    float val = 1.0f;
    if (timeDiff > state->fadesequence)
    {
        state->fadesequence = 0;
    }
    else
    {
        state->fadesequence -= timeDiff;
    }

    val = sinf(((float)state->fadesequence/(float)period) * (M_PI / 2.0));

    return val;

}

void FadeResetState(systime_t period, struct EffectFadeState* state)
{
    state->fadesequence = period;
}

/** @} */
