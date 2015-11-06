/**
 * @file    effect_buttons.c
 * @brief
 *
 * @addtogroup effects
 * @{
 */

#include "effect_buttons.h"
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
static void ModeColor(uint8_t mode, const struct EffectButtonsCfg* cfg, struct Color* newColor)
{
    if (mode == EFFECT_BUTTON_MODE_PLAY)
    {
        ColorCopy(&cfg->play.color, newColor);
    }
    else if (mode == EFFECT_BUTTON_MODE_PAUSE)
    {
        ColorCopy(&cfg->colorModePause, newColor);
    }
    else if (mode == EFFECT_BUTTON_MODE_STOP)
    {
        ColorCopy(&cfg->colorModeStop, newColor);
    }
    else if (mode == EFFECT_BUTTON_MODE_EMPTYPLAYLIST)
    {
        ColorCopy(&cfg->colorModeEmptyPlayList, newColor);
    }
}
/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief
 *
 */

void EffectButtonsUpdate(int16_t x, int16_t y, systime_t time, void* effectcfg,
        void* effectdata, struct Effect* next, struct DisplayBuffer* display)
{
    (void) x;
    (void) y;
    (void) next;
    struct EffectButtonsCfg* cfg = (struct EffectButtonsCfg*) effectcfg;
    struct EffectButtonsData* data =
            (struct EffectButtonsData*) effectdata;

    struct Color newColor;
    if (data->lastPlayMode != cfg->playMode)
    {
        ModeColor(data->lastPlayMode, cfg, &newColor);
        // save current color
        ColorBlend(&data->lastPlayModeColor, &newColor, data->lastBlendStep, &data->lastPlayModeColor);

        data->lastBlendStep = 0.0f;
        data->lastPlayMode = cfg->playMode;
    }

    ModeColor(cfg->playMode, cfg, &newColor);

    // update blend step
    systime_t diff = time - data->lastUpdate;
    data->lastUpdate = time;

    data->lastBlendStep += (float)diff / (float)cfg->blendperiod;
    if (data->lastBlendStep > 1.0f)
    {
        data->lastBlendStep = 1.0f;
    }
    ColorBlend(&data->lastPlayModeColor, &newColor, data->lastBlendStep, &newColor);
    DisplayDraw(cfg->play.x, cfg->play.y, &newColor, display);


    DisplayDraw(cfg->vol_up.x, cfg->vol_up.y, &cfg->vol_up.color, display);
    DisplayDraw(cfg->vol_down.x, cfg->vol_down.y, &cfg->vol_down.color, display);
    DisplayDraw(cfg->next.x, cfg->next.y, &cfg->next.color, display);
    DisplayDraw(cfg->prev.x, cfg->prev.y, &cfg->prev.color, display);
    DisplayDraw(cfg->special.x, cfg->special.y, &cfg->special.color, display);
}

void EffectButtonsReset(int16_t x, int16_t y, systime_t time, void* effectcfg,
        void* effectdata, struct Effect* next)
{
    (void) effectcfg;
    (void) effectdata;

    struct EffectButtonsData* data = (struct EffectButtonsData*) effectdata;
    data->lastUpdate = time;

    EffectReset(next, x, y, time);

}

/** @} */
