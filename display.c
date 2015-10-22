/**
 * @file    display.c
 * @brief
 *
 * @addtogroup
 * @{
 */

#include "display.h"
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
void DisplayLedToCoord(uint16_t led, int16_t* x, int16_t* y, const struct DisplayBuffer* display)
{
    *x = led % display->width;
    *y = led / display->width;
}

bool DisplayCoordToLed(int16_t x, int16_t y, uint16_t* led, const struct DisplayBuffer* display)
{
    /* check if out of bounds */
    if (x < 0)
        return false;
    else if (x >= display->width)
        return false;

    if (y < 0)
        return false;
    else if (y >= display->height)
        return false;

    *led = x + (y * display->width);
    return true;
}

void DisplayDraw(int16_t x, int16_t y, const struct Color* color, const struct DisplayBuffer* display)
{
    /* convert 2d space coordinate to led number */
    uint16_t lednum = 0;
    if (DisplayCoordToLed(x, y, &lednum, display) == true)
    {
        ColorCopy(color, display->pixels[lednum]);
    }
}

void DisplayPaint(void)
{

}

/** @} */
