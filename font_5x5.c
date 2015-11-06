/**
 * @file    font_5x5.c
 * @brief
 *
 * @addtogroup
 * @{
 */

#include "font_5x5.h"
#include <stdlib.h>

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/
struct EffectFontConfig
{
    uint8_t a[5];
    uint8_t b[5];
    uint8_t c[5];
    uint8_t d[5];
    uint8_t e[5];
    uint8_t f[5];
    uint8_t g[5];
    uint8_t h[5];
    uint8_t i[5];
    uint8_t j[5];
    uint8_t k[5];
    uint8_t l[5];
    uint8_t m[5];
    uint8_t n[5];
    uint8_t o[5];
    uint8_t p[5];
    uint8_t q[5];
    uint8_t r[5];
    uint8_t s[5];
    uint8_t t[5];
    uint8_t u[5];
    uint8_t v[5];
    uint8_t w[5];
    uint8_t x[5];
    uint8_t y[5];
    uint8_t z[5];

    uint8_t ze[5];
    uint8_t on[5];
    uint8_t tw[5];
    uint8_t th[5];
    uint8_t fo[5];
    uint8_t fi[5];
    uint8_t si[5];
    uint8_t se[5];
    uint8_t ei[5];
    uint8_t ni[5];
};

static struct EffectFontConfig charSet =
{
    .a = {0b01111100,
          0b01000100,
          0b01000100,
          0b01111100,
          0b01000100},
    .b = {0b01111100,
          0b01000100,
          0b01111000,
          0b01000100,
          0b01111100},
    .c = {0x7c,0x40,0x40,0x40,0x7c},
    .d = {0x78,0x44,0x44,0x44,0x78},
    .e = {0x7c,0x40,0x78,0x40,0x7c},
    .f = {0x7c,0x40,0x70,0x40,0x40},
    .g = {0x7c,0x40,0x4c,0x44,0x7c},
    .h = {0x44,0x44,0x7c,0x44,0x44},
    .i = {0x7c,0x10,0x10,0x10,0x7c},
    .j = {0x0c,0x04,0x04,0x44,0x7c},
    .k = {0x44,0x48,0x70,0x48,0x44},
    .l = {0x40,0x40,0x40,0x40,0x7c},
    .m = {0x44,0x6c,0x54,0x44,0x44},
    .n = {0x44,0x64,0x54,0x4c,0x44},
    .o = {0x38,0x44,0x44,0x44,0x38},
    .p = {0x78,0x44,0x78,0x40,0x40},
    .q = {0x7c,0x44,0x44,0x7c,0x10},
    .r = {0x78,0x44,0x78,0x44,0x44},
    .s = {0x7c,0x40,0x7c,0x04,0x7c},
    .t = {0x7c,0x10,0x10,0x10,0x10},
    .u = {0x44,0x44,0x44,0x44,0x7c},
    .v = {0x44,0x44,0x28,0x28,0x10},
    .w = {0x44,0x44,0x54,0x54,0x28},
    .x = {0x44,0x28,0x10,0x28,0x44},
    .y = {0x44,0x44,0x28,0x10,0x10},
    .z = {0x7c,0x08,0x10,0x20,0x7c},
    .ze = {0x7c,0x4c,0x54,0x64,0x7c},
    .on = {0x10,0x30,0x10,0x10,0x38},
    .tw = {0x78,0x04,0x38,0x40,0x7c},
    .th = {0x7c,0x04,0x38,0x04,0x7c},
    .fo = {0x40,0x40,0x50,0x7c,0x10},
    .fi = {0x7c,0x40,0x78,0x04,0x78},
    .si = {0x7c,0x40,0x7c,0x44,0x7c},
    .se = {0x7c,0x04,0x08,0x10,0x10},
    .ei = {0x7c,0x44,0x7c,0x44,0x7c},
    .ni = {0x7c,0x44,0x7c,0x04,0x7c},
};
/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/
static uint8_t* GetCharConf(const char c)
{
    if (c == 'a')
        return charSet.a;
    if (c == 'b')
        return charSet.b;
    if (c == 'c')
        return charSet.c;
    if (c == 'd')
        return charSet.d;
    if (c == 'e')
        return charSet.e;
    if (c == 'f')
        return charSet.f;
    if (c == 'g')
        return charSet.g;
    if (c == 'h')
        return charSet.h;
    if (c == 'i')
        return charSet.i;
    if (c == 'j')
        return charSet.j;
    if (c == 'k')
        return charSet.k;
    if (c == 'l')
        return charSet.l;
    if (c == 'm')
        return charSet.m;
    if (c == 'n')
        return charSet.n;
    if (c == 'o')
        return charSet.o;
    if (c == 'p')
        return charSet.p;
    if (c == 'q')
        return charSet.q;
    if (c == 'r')
        return charSet.r;
    if (c == 's')
        return charSet.s;
    if (c == 't')
        return charSet.t;
    if (c == 'u')
        return charSet.u;
    if (c == 'v')
        return charSet.v;
    if (c == 'w')
        return charSet.w;
    if (c == 'x')
        return charSet.x;
    if (c == 'y')
        return charSet.y;
    if (c == 'z')
        return charSet.z;
    if (c == '0')
        return charSet.ze;
    if (c == '1')
        return charSet.on;
    if (c == '2')
        return charSet.tw;
    if (c == '3')
        return charSet.th;
    if (c == '4')
        return charSet.fo;
    if (c == '5')
        return charSet.fi;
    if (c == '6')
        return charSet.si;
    if (c == '7')
        return charSet.se;
    if (c == '8')
        return charSet.ei;
    if (c == '9')
        return charSet.ni;

    return NULL;
}

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/
void Font5x5DrawChar(int16_t x, int16_t y, const char c, const struct Color* color, struct DisplayBuffer* display)
{
    uint8_t* charConf = GetCharConf(c);
    if (charConf != NULL)
    {
        uint8_t column;
        for (column = 0; column < 5; column++)
        {
            uint8_t line;
            uint8_t lineCfg = charConf[column] >> 2;
            for (line = 0; line < 5; line++)
            {
                if ((lineCfg & (0x10 >> line)) > 0)
                {
                    DisplayDraw(x + line, y + column, color, display);
                }
            }
        }
    }
}


/** @} */
