/**
 * @file    effect_buttons.h
 * @brief
 *
 * @addtogroup effects
 * @{
 */

#ifndef _EFFECT_BUTTONS_H_
#define _EFFECT_BUTTONS_H_

#include "effect_defines.h"
#include "effect.h"
#include "display.h"
#include "color.h"
#include "fade.h"
#include <stdbool.h>
/*===========================================================================*/
/* Effect constants.                                                         */
/*===========================================================================*/
#define EFFECT_BUTTON_MODE_PLAY 0
#define EFFECT_BUTTON_MODE_PAUSE 1
#define EFFECT_BUTTON_MODE_STOP 2
#define EFFECT_BUTTON_MODE_EMPTYPLAYLIST 3
/*===========================================================================*/
/* Effect pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/
struct Button
{
    int16_t x;
    int16_t y;
    struct Color color;
};

struct EffectButtonsCfg
{
    struct Button play;
    struct Button vol_up;
    struct Button vol_down;
    struct Button next;
    struct Button prev;
    struct Button special;

    uint8_t playMode;
    struct Color colorModeEmptyPlayList;
    struct Color colorModePause;
    struct Color colorModeStop;

    systime_t blendperiod;
};

struct EffectButtonsData
{
    uint8_t lastPlayMode;
    float lastBlendStep;
    struct Color lastPlayModeColor;
    systime_t lastUpdate;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C"
{
#endif
void EffectButtonsUpdate(int16_t x, int16_t y, systime_t time, void* effectcfg,
        void* effectdata, struct Effect* next, struct DisplayBuffer* display);
void EffectButtonsReset(int16_t x, int16_t y, systime_t time, void* effectcfg,
        void* effectdata, struct Effect* next);
#ifdef __cplusplus
}
#endif

#endif /* _EFFECT_FADINGPIXELS_H_ */

/** @} */
