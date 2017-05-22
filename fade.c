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
#define M_PI_F 3.14159265f
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

float FadeUpdateState(systime_t timeDiff, uint32_t period, struct EffectFadeState* state)
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

    val = sinf(((float)state->fadesequence/(float)period) * (M_PI_F / 2.0f));

    return val;

}

float FadeCyclicUpdateState(systime_t timeDiff, uint32_t period, struct EffectFadeState* state)
{
	float val = 1.0f;
	if (timeDiff > state->fadesequence)
	{
 		state->fadesequence = period - (timeDiff - state->fadesequence);
	}
	else
	{
		state->fadesequence -= timeDiff;
	}

	val = sinf(((float)state->fadesequence/(float)period) * (M_PI_F));

	return val;
}

void FadeResetState(uint32_t period, struct EffectFadeState* state)
{
    state->fadesequence = period;
}

void FadeRandomizeState(uint32_t period, struct EffectFadeState* state)
{
    state->fadesequence = rand() % period;
}

/** @} */
