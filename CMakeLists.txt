cmake_minimum_required (VERSION 2.6)
project (tmb_effects)


set(TMB_EFFECTS_SRC
   ${CMAKE_CURRENT_SOURCE_DIR}/color.c
   ${CMAKE_CURRENT_SOURCE_DIR}/display.c
   ${CMAKE_CURRENT_SOURCE_DIR}/effect.c
   #${CMAKE_CURRENT_SOURCE_DIR}/effect_fade.c
   ${CMAKE_CURRENT_SOURCE_DIR}/effect_font_5x5.c
   #${CMAKE_CURRENT_SOURCE_DIR}/effect_randomcolor.c
   ${CMAKE_CURRENT_SOURCE_DIR}/effect_simplecolor.c
   ${CMAKE_CURRENT_SOURCE_DIR}/effect_wandering.c
)

set(TMB_EFFECTS_HDR
   ${CMAKE_CURRENT_SOURCE_DIR}/color.h
   ${CMAKE_CURRENT_SOURCE_DIR}/display.h
   ${CMAKE_CURRENT_SOURCE_DIR}/effect.h
   #${CMAKE_CURRENT_SOURCE_DIR}/effect_fade.h
   #${CMAKE_CURRENT_SOURCE_DIR}/effect_font_5x5.h
   #${CMAKE_CURRENT_SOURCE_DIR}/effect_randomcolor.h
   #${CMAKE_CURRENT_SOURCE_DIR}/effect_simplecolor.h
   ${CMAKE_CURRENT_SOURCE_DIR}/effect_wandering.h
)

add_library(effects STATIC
${TMB_EFFECTS_SRC}
${TMB_EFFECTS_HDR}
)