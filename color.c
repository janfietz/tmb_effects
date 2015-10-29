/**
 * @file    color.c
 * @brief   color algorithms.
 *
 * @addtogroup effects
 * @{
 */

#include "color.h"
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
static uint8_t BlendComponent(uint8_t s, uint8_t d, float factor)
{
    int16_t component = (int16_t)s;
    component -= (int16_t)d;
    component *= factor;
    component -= (int16_t)s;

    if (component < 0)
    {
        component *= -1;
    }

    return component;
}

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Copy one color to another.
 *
 */

void ColorCopy(const struct Color* src, struct Color* dst)
{
    dst->R = src->R;
    dst->G = src->G;
    dst->B = src->B;
}

void ColorRandom(struct Color* dst)
{
    dst->R = rand() % 256;
    dst->G = rand() % 256;
    dst->B = rand() % 256;
}

void ColorScale(struct Color* color, float scale)
{
    color->R = color->R * scale;
    color->G = color->G * scale;
    color->B = color->B * scale;
}

void ColorBlend(const struct Color* src, const struct Color* dst, float factor, struct Color* result)
{
    result->R = BlendComponent(src->R, dst->R, factor);
    result->G = BlendComponent(src->G, dst->G, factor);
    result->B = BlendComponent(src->B, dst->B, factor);
}

/** @} */
