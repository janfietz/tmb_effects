/**
 * @file    effect_randompixels.c
 * @brief
 *
 * @addtogroup effects
 * @{
 */

#include "effect_randompixels.h"
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
static void SetRandomColor(struct Color* color, struct EffectRandomPixelsCfg* cfg)
{
    ColorCopy(&cfg->color, color);
    if (cfg->randomRed == true)
    {
        color->R = rand() % 256;
    }
    if (cfg->randomGreen == true)
    {
        color->G = rand() % 256;
    }
    if (cfg->randomBlue == true)
    {
        color->B = rand() % 256;
    }
}

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief
 *
 */

void EffectRandomPixelsUpdate(int16_t x, int16_t y, systime_t time, void* effectcfg, void* effectdata, struct Effect* next, struct DisplayBuffer* display)
{
    (void) x;
    (void) y;
    (void) next;
    struct EffectRandomPixelsCfg* cfg = (struct EffectRandomPixelsCfg*) effectcfg;
    struct EffectRandomPixelsData* data = (struct EffectRandomPixelsData*) effectdata;

    bool newColors = false;
    systime_t diff = time - data->lastspawn;
    if (diff >= cfg->spawninterval)
    {
        newColors = true;
        data->lastspawn += cfg->spawninterval;
    }

    int16_t width;
    int16_t height;
    for (width = 0; width < display->width; width++)
    {
        for (height = 0; height < display->height; height++)
        {
            uint16_t pixelNumber = 0;
            DisplayCoordToLed(width, height, &pixelNumber, display);
            if (newColors == true)
            {
                SetRandomColor(&data->pixelColors[pixelNumber], cfg);
            }
            DisplayDraw(width, height, &data->pixelColors[pixelNumber], display);
        }
    }
}

void EffectRandomPixelsReset(int16_t x, int16_t y, systime_t time, void* effectcfg,
        void* effectdata, struct Effect* next)
{
    (void) effectcfg;
    struct EffectRandomPixelsData* data = (struct EffectRandomPixelsData*) effectdata;
    data->lastspawn = time;

    EffectReset(next, x, y, time);
}

/** @} */
