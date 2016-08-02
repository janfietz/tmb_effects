/**
 * @file    effect_nightsky.c
 * @brief
 *
 * @addtogroup effects
 * @{
 */

#include "effect_nightsky.h"
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

void EffectNightSkyUpdate(int16_t x, int16_t y, systime_t time, void* effectcfg, void* effectdata, struct Effect* next, struct DisplayBuffer* display)
{
    (void) x;
    (void) y;
    (void) next;
    struct EffectNightSkyCfg* cfg = (struct EffectNightSkyCfg*) effectcfg;
    struct EffectNightSkyData* data =
            (struct EffectNightSkyData*) effectdata;

    struct Color pixelColor;
    int16_t width;
    int16_t height;
    if (data->randomizeFades == true)
    {
        data->randomizeFades = false;
        for (width = 0; width < display->width; width++)
        {
            for (height = 0; height < display->height; height++)
            {
                uint16_t pixelNumber = 0;
                DisplayCoordToLed(width, height, &pixelNumber, display);
                FadeRandomizeState(cfg->fadeperiod, &data->fadeStates[pixelNumber]);
                float fade = FadeCyclicUpdateState(0, cfg->fadeperiod, &data->fadeStates[pixelNumber]);
                ColorCopy(&cfg->color, &data->pixelColors[pixelNumber]);
            }
        }
    }

    systime_t diff = time - data->lastupdate;

    for (width = 0; width < display->width; width++)
    {
        for (height = 0; height < display->height; height++)
        {
            uint16_t pixelNumber = 0;
            DisplayCoordToLed(width, height, &pixelNumber, display);
            float fade = FadeCyclicUpdateState(diff, cfg->fadeperiod, &data->fadeStates[pixelNumber]);
            if (fade < 0.01f)
            {
                if (cfg->randomColor && ((rand() % cfg->randomizePropability) == 1))
                {
                    ColorRandom(&data->pixelColors[pixelNumber]);
                }
                else
                {
                    ColorCopy(&cfg->color, &data->pixelColors[pixelNumber]);
                }
            }
            ColorCopy(&data->pixelColors[pixelNumber], &pixelColor);
            ColorScale(&pixelColor, fade);
            DisplayDraw(width, height, &pixelColor, display);
        }
    }
    data->lastupdate = time;
}

void EffectNightSkyReset(int16_t x, int16_t y, systime_t time, void* effectcfg,
        void* effectdata, struct Effect* next)
{
    (void) effectcfg;
    struct EffectNightSkyData* data = (struct EffectNightSkyData*) effectdata;

    data->randomizeFades = true;
    data->lastupdate = time;

    EffectReset(next, x, y, time);
}

/** @} */
