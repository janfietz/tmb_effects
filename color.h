
/**
 * @file    color.h
 * @brief
 *
 * @addtogroup effects
 * @{
 */

#ifndef _COLOR_H_
#define _COLOR_H_

#include <stdint.h>
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
struct Color
{
    uint8_t R;
    uint8_t G;
    uint8_t B;
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
    void ColorCopy(const struct Color* src, struct Color* dst);
    void ColorRandom(struct Color* dst);
    void ColorBlend(const struct Color* src, const struct Color* dst, float factor, struct Color* result);
    uint32_t ColorToRGBValue(const struct Color* src);
    void ColorFromRGBValue(uint32_t src, struct Color* dst);
    void ColorScale(struct Color* color, float scale);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_ws2811 */


/** @} */
