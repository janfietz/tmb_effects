/**
 * @file    effect_wandering.c
 * @brief
 *
 * @addtogroup effects
 * @{
 */

#include "effect_wandering.h"
#include <stdlib.h>
#include "display.h"

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

void EffectWanderingUpdate(int16_t x, int16_t y, systime_t time, void* effectcfg, void* effectdata, struct Effect* next, struct DisplayBuffer* display)
{

    (void) x;
    (void) y;
    struct EffectWanderingCfg* cfg = (struct EffectWanderingCfg*) effectcfg;
    struct EffectWanderingData* data = (struct EffectWanderingData*) effectdata;

    systime_t diff = time - data->lastupdate;
    int16_t local_x;
    int16_t local_y;
    DisplayLedToCoord(data->pos, &local_x, &local_y, display);

    if (diff >= cfg->speed)
    {
        data->lastupdate += cfg->speed;

        if (data->pos >= (cfg->ledend))
        {
            if (cfg->turn == true)
            {
                data->dir_x *= -1;
                data->dir_y *= -1;
            }
            else
            {
                if (data->dir_x > 0)
                {
                    DisplayLedToCoord(cfg->ledbegin, &local_x, &local_y, display);
                    if (cfg->dir == 0)
                    {
                        local_x -= data->dir_x;
                    }
                    else if (cfg->dir == 1)
                    {
                        local_y -= data->dir_y;
                    }
                }
            }
        }
        else if (data->pos == cfg->ledbegin)
        {
            if (cfg->turn == true)
            {
                data->dir_x *= -1;
                data->dir_y *= -1;
            }
            else
            {
                if (data->dir_x < 0)
                {
                    DisplayLedToCoord(cfg->ledend, &local_x, &local_y, display);
                    if (cfg->dir == 0)
                    {
                        local_x -= data->dir_x;
                    }
                    else if (cfg->dir == 1)
                    {
                        local_y -= data->dir_y;
                    }
                }
            }
        }

        if (cfg->dir == 0)
        {
            local_x += data->dir_x;

            if (local_x >= display->width)
            {
                local_x = 0;
                local_y += data->dir_y;
            }
            else if(local_x < 0)
            {
                local_x = display->width - 1;
                local_y += data->dir_y;
            }
        }
        else if (cfg->dir == 1)
        {
            local_y += data->dir_y;

            if (local_y >= display->height)
            {
                local_y = 0;
                local_x += data->dir_x;
            }
            else if(local_y < 0)
            {
                local_y = display->height - 1;
                local_x += data->dir_x;
            }
        }

        DisplayCoordToLed(local_x, local_y, &data->pos, display);
    }

    EffectUpdate(next, local_x, local_y, time, display);
}

void EffectWanderingReset(int16_t x, int16_t y, systime_t time, void* effectcfg, void* effectdata, struct Effect* next)
{
    struct EffectWanderingCfg* cfg = (struct EffectWanderingCfg*) effectcfg;
    struct EffectWanderingData* data = (struct EffectWanderingData*) effectdata;

    data->pos = cfg->ledbegin;
    if (cfg->dir == 0)
    {
        data->dir_x = 1;
        data->dir_y = 1;
    }
    else if(cfg->dir == 1)
    {
        data->dir_x = 1;
        data->dir_y = 1;
    }

    data->lastupdate = time;

    EffectReset(next, x, y, time);
}

/** @} */
