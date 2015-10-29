
/**
 * @file    display.h
 * @brief
 *
 * @addtogroup
 * @{
 */

#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include "color.h"
#include <stdint.h>
#include <stdbool.h>

/*===========================================================================*/
/* Effect constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Effect pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/
struct DisplayBuffer
{
    int16_t width;
    int16_t height;

    struct Color* pixels;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif
    void DisplayDraw(int16_t x, int16_t y, const struct Color* color, const struct DisplayBuffer* display);
    void DisplayPaint(void);

    void DisplayLedToCoord(uint16_t led, int16_t* x, int16_t* y, const struct DisplayBuffer* display);
    bool DisplayCoordToLed(int16_t x, int16_t y, uint16_t* led, const struct DisplayBuffer* display);
#ifdef __cplusplus
}
#endif

#endif /* _DISPLAY_H_ */


/** @} */
