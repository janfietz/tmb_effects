cmake_minimum_required (VERSION 2.6)
project (tmb_effects)


set(TMB_EFFECTS_SRC
   ${CMAKE_CURRENT_SOURCE_DIR}/color.c
   ${CMAKE_CURRENT_SOURCE_DIR}/display.c
   ${CMAKE_CURRENT_SOURCE_DIR}/effect.c
   ${CMAKE_CURRENT_SOURCE_DIR}/fade.c
   ${CMAKE_CURRENT_SOURCE_DIR}/font_5x5.c
   ${CMAKE_CURRENT_SOURCE_DIR}/effect_font_5x5.c
   ${CMAKE_CURRENT_SOURCE_DIR}/effect_randompixels.c
   ${CMAKE_CURRENT_SOURCE_DIR}/effect_simplecolor.c
   ${CMAKE_CURRENT_SOURCE_DIR}/effect_fadingpixels.c
   ${CMAKE_CURRENT_SOURCE_DIR}/effect_wandering.c
   ${CMAKE_CURRENT_SOURCE_DIR}/effect_plasma.c
   ${CMAKE_CURRENT_SOURCE_DIR}/effect_fallingpixels.c
   ${CMAKE_CURRENT_SOURCE_DIR}/effect_volume.c
   ${CMAKE_CURRENT_SOURCE_DIR}/effect_buttons.c
)

set(TMB_EFFECTS_HDR
   ${CMAKE_CURRENT_SOURCE_DIR}/color.h
   ${CMAKE_CURRENT_SOURCE_DIR}/display.h
   ${CMAKE_CURRENT_SOURCE_DIR}/effect.h
   ${CMAKE_CURRENT_SOURCE_DIR}/fade.h
   ${CMAKE_CURRENT_SOURCE_DIR}/font_5x5.h
   ${CMAKE_CURRENT_SOURCE_DIR}/effect_font_5x5.h
   ${CMAKE_CURRENT_SOURCE_DIR}/effect_randompixels.h
   ${CMAKE_CURRENT_SOURCE_DIR}/effect_simplecolor.h
   ${CMAKE_CURRENT_SOURCE_DIR}/effect_fadingpixels.h
   ${CMAKE_CURRENT_SOURCE_DIR}/effect_wandering.h
   ${CMAKE_CURRENT_SOURCE_DIR}/effect_plasma.h
   ${CMAKE_CURRENT_SOURCE_DIR}/effect_fallingpixels.h
   ${CMAKE_CURRENT_SOURCE_DIR}/effect_volume.h
   ${CMAKE_CURRENT_SOURCE_DIR}/effect_buttons.h
)

add_library(effects STATIC
${TMB_EFFECTS_SRC}
${TMB_EFFECTS_HDR}
)