/**
 * @file    effect_plasma.c
 * @brief
 *
 * @addtogroup effects
 * @{
 */

#include "effect_plasma.h"
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

void EffectPlasmaUpdate(int16_t x, int16_t y, systime_t time, void* effectcfg, void* effectdata, struct Effect* next, struct DisplayBuffer* display)
{
    struct EffectPlasmaCfg* cfg = (struct EffectPlasmaCfg*) effectcfg;
    struct EffectPlasmaData* data = (struct EffectPlasmaData*) effectdata;

    bool newColors = false;
    systime_t diff = time - data->lastspawn;
    if (diff >= cfg->spawninterval)
    {
        newColors = true;
        data->lastspawn += cfg->spawninterval;
    }

    int16_t originX = display->width / 2;
    int16_t originY = display->height / 2;

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
                float distance = hypot(originX - width, originY - height) * cfg->period1;
                uint16_t value = (uint8_t)(128 + (127 * sin(time + distance)));

                value += (uint8_t)(128 + (127 * sin((time / 1000) + (height/(3+5*cos(width/11)) ) * cos((time / 1000) + (width/(3+5*sin(height/5)))))));

                ColorCopy(&cfg->palette[value / 2], &data->pixelColors[pixelNumber]);
            }
            DisplayDraw(width, height, &data->pixelColors[pixelNumber], display);
        }
    }
}

void EffectPlasmaReset(int16_t x, int16_t y, systime_t time, void* effectcfg,
        void* effectdata, struct Effect* next)
{
    (void) effectcfg;
    (void) effectdata;

    EffectReset(next, x, y, time);
}

/** @} */
