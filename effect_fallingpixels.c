/**
 * @file    effect_fallingpixels.c
 * @brief
 *
 * @addtogroup effects
 * @{
 */

#include "effect_fallingpixels.h"
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
static void SetRandomColor(struct Color* color, struct EffectFallingPixelsCfg* cfg)
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

void EffectFallingPixelsUpdate(int16_t x, int16_t y, systime_t time, void* effectcfg, void* effectdata, struct Effect* next, struct DisplayBuffer* display)
{
    (void) x;
    (void) y;
    (void) next;
    struct EffectFallingPixelsCfg* cfg = (struct EffectFallingPixelsCfg*) effectcfg;
    struct EffectFallingPixelsData* data = (struct EffectFallingPixelsData*) effectdata;

    bool newSpawn = false;
    systime_t diffSpawn = time - data->lastspawn;
    systime_t diffUpdate = time - data->lastupdate;
    if (diffSpawn >= cfg->spawninterval)
    {
        newSpawn = true;
        data->lastspawn += cfg->spawninterval;
    }

    int16_t pixel;
    for (pixel = 0; pixel < 30; pixel++)
    {
        struct EffectFallingPixelHead* pixelHead = &data->pixelHeads[pixel];
        if (pixelHead->active == true)
        {
            pixelHead->time += diffUpdate;
            if (pixelHead->time >= pixelHead->speed)
            {
                pixelHead->time -= pixelHead->speed;
                pixelHead->posY += 1;
                uint16_t pixelNumber = 0;
                if (DisplayCoordToLed(pixelHead->posX, pixelHead->posY, &pixelNumber, display) == true)
                {
                    FadeResetState(cfg->fadeperiod, &data->fadeStates[pixelNumber]);
                    ColorCopy(&pixelHead->color, &data->pixelColors[pixelNumber]);
                }
                else
                {
                    pixelHead->active = false;
                }
            }

        }
        else if (newSpawn == true)
        {
            //spawn a new head
            pixelHead->active = true;

            pixelHead->posX = rand() % display->width;
            pixelHead->posY = 0;

            pixelHead->speed = 1000 + rand() % 100;
            pixelHead->time = 0;

            SetRandomColor(&pixelHead->color, cfg);
            uint16_t pixelNumber = 0;
            DisplayCoordToLed(pixelHead->posX, pixelHead->posY, &pixelNumber, display);
            FadeResetState(cfg->fadeperiod, &data->fadeStates[pixelNumber]);
            ColorCopy(&pixelHead->color, &data->pixelColors[pixelNumber]);

            newSpawn = false;
        }
    }

    int16_t width;
    int16_t height;
    for (width = 0; width < display->width; width++)
    {
        for (height = 0; height < display->height; height++)
        {
            uint16_t pixelNumber = 0;
            DisplayCoordToLed(width, height, &pixelNumber, display);
            float fade = FadeUpdateState(diffUpdate, cfg->fadeperiod, &data->fadeStates[pixelNumber]);
            ColorScale(&data->pixelColors[pixelNumber], fade);
            DisplayDraw(width, height, &data->pixelColors[pixelNumber], display);
        }
    }

    data->lastupdate = time;
}

void EffectFallingPixelsReset(int16_t x, int16_t y, systime_t time, void* effectcfg,
        void* effectdata, struct Effect* next)
{
    (void) effectcfg;
    (void) effectdata;

    struct EffectFallingPixelsData* data = (struct EffectFallingPixelsData*) effectdata;

    int16_t pixel;
    for (pixel = 0; pixel < 30; pixel++)
    {
        struct EffectFallingPixelHead* pixelHead = &data->pixelHeads[pixel];
        pixelHead->active = false;
    }

    data->lastspawn = time;
    data->lastupdate = time;

    EffectReset(next, x, y, time);
}

/** @} */
