/**
 * @file    effect_fadingpixels.c
 * @brief
 *
 * @addtogroup effects
 * @{
 */

#include "effect_fadingpixels.h"

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

void EffectFadingPixelsUpdate(int16_t x, int16_t y, systime_t time, void* effectcfg,
        void* effectdata, struct Effect* next, struct DisplayBuffer* display)
{
    (void) x;
    (void) y;
    struct EffectFadingPixelsCfg* cfg = (struct EffectFadingPixelsCfg*) effectcfg;
    struct EffectFadingPixelsData* data =
            (struct EffectFadingPixelsData*) effectdata;

    systime_t diff = time - data->lastupdate;
    int16_t width;
    int16_t height;
    for (width = 0; width < display->width; width++)
    {
        for (height = 0; height < display->height; height++)
        {
            int16_t pixelNumber = 0;
            DisplayCoordToLed(width, height, &pixelNumber, display);
            float fade = FadeUpdateState(diff, cfg->fadeperiod, &data->fadeStates[pixelNumber]);
            ColorScale(&data->pixelColors[pixelNumber], fade);
            DisplayDraw(width, height, &data->pixelColors[pixelNumber], display);
        }
    }
    data->lastupdate = time;

    diff = time - data->lastspawn;
    if (diff >= cfg->spawninterval)
    {
        uint8_t pixel;
        for (pixel = 0; pixel < cfg->number; pixel++)
        {
            int16_t x = (int16_t)(rand() % display->width);
            int16_t y = (int16_t)(rand() % display->height);

            int16_t pixelNumber = 0;
            if (DisplayCoordToLed(x, y, &pixelNumber, display) == true)
            {
                if (cfg->randomColor == true)
                {
                    ColorRandom(&data->pixelColors[pixelNumber]);
                }
                else
                {
                    ColorCopy(&cfg->color, &data->pixelColors[pixelNumber]);
                }
                FadeResetState(cfg->fadeperiod, &data->fadeStates[pixelNumber]);
                DisplayDraw(x, y, &data->pixelColors[pixelNumber], display);
            }
        }
        data->lastspawn += cfg->spawninterval;
    }
}

void EffectFadingPixelsReset(int16_t x, int16_t y, systime_t time, void* effectcfg,
        void* effectdata, struct Effect* next)
{
    (void) effectcfg;
    (void) effectdata;

    EffectReset(next, x, y, time);

}

/** @} */
