/**
 * @file    effect_volume.c
 * @brief
 *
 * @addtogroup effects
 * @{
 */

#include "effect_volume.h"
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

void EffectVolumeUpdate(int16_t x, int16_t y, systime_t time, void* effectcfg,
        void* effectdata, struct Effect* next, struct DisplayBuffer* display)
{
    (void) x;
    (void) y;
    (void) next;
    struct EffectVolumeCfg* cfg = (struct EffectVolumeCfg*) effectcfg;
    struct EffectVolumeData* data =
            (struct EffectVolumeData*) effectdata;

    int16_t width;
    int16_t height;

    struct Color c;
    ColorBlend(&cfg->minColor, &cfg->maxColor, (float)cfg->volume / 100.0f, &c);


    int16_t center = display->width / 2;
    int16_t stepWidth = 100 / center;
    int16_t colums = 1;
    colums = data->step / stepWidth;

    for (width = 0; width < colums; width++)
    {
        for (height = 0; height < display->height; height++)
        {
            DisplayDraw(center, height, &c, display);
            DisplayDraw(center + width, height, &c, display);
            DisplayDraw(center - width, height, &c, display);
        }
    }

    float scale = (data->step % stepWidth) * ((float)center / 100.0f);
    ColorScale(&c, scale);
    for (height = 0; height < display->height; height++)
    {
        DisplayDraw(center + width, height, &c, display);
        DisplayDraw(center - width, height, &c, display);
    }

    if (cfg->showNumber == true)
    {
        char number = '0' + (cfg->volume / 10);
        Font5x5DrawChar(center - 2 , 0, number, &cfg->fontColor, display);
    }

    // set next step for animation
    systime_t diffUpdate = time - data->lastStepupdate;
    if (diffUpdate >= cfg->speed)
    {
        if (data->step < cfg->volume)
        {
            data->step += 1;
        }
        else if (data->step > cfg->volume)
        {
            data->step -= 1;
        }
        data->lastStepupdate += cfg->speed;
    }
}

void EffectVolumeReset(int16_t x, int16_t y, systime_t time, void* effectcfg,
        void* effectdata, struct Effect* next)
{
    (void) effectcfg;
    (void) effectdata;

    struct EffectVolumeData* data = (struct EffectVolumeData*) effectdata;

    data->lastStepupdate = time;
    data->step = 0;

    EffectReset(next, x, y, time);

}

/** @} */
