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

/** @} */