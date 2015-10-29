/**
 * @file    effect_simplecolor.c
 * @brief
 *
 * @addtogroup effects
 * @{
 */

#include "effect_simplecolor.h"

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

void EffectSimpleUpdate(int16_t x, int16_t y, systime_t time, void* effectcfg,
        void* effectdata, struct Effect* next, struct DisplayBuffer* display)
{
    (void) x;
    (void) y;
    (void) effectdata;
    struct EffectSimpleColorCfg* cfg = (struct EffectSimpleColorCfg*) effectcfg;

    if (cfg->fillbuffer == true)
    {
        int16_t width;
        int16_t height;
        for (width = 0; width < display->width; width++)
        {
            for (height = 0; height < display->height; height++)
            {
                DisplayDraw(width, height, &cfg->color, display);
                EffectUpdate(next, width, height, time, display);
            }
        }
    }
    else
    {
        DisplayDraw(x, y, &cfg->color, display);
        EffectUpdate(next, x, y, time, display);
    }
}

void EffectSimpleReset(int16_t x, int16_t y, systime_t time, void* effectcfg,
        void* effectdata, struct Effect* next)
{
    (void) effectcfg;
    (void) effectdata;

    EffectReset(next, x, y, time);

}

/** @} */
