
/**
 * @file    font_5x5.h
 * @brief
 *
 * @addtogroup
 * @{
 */

#ifndef _FONT_5x5_H_
#define _FONT_5x5_H_

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
    void Font5x5DrawChar(int16_t x, int16_t y, const char c, const struct Color* color, struct DisplayBuffer* display);
#ifdef __cplusplus
}
#endif

#endif /* _FONT_5x5_H_ */


/** @} */
