
TMB_EFFECTS_DIR := $(dir $(lastword $(MAKEFILE_LIST)))
CSRC += $(wildcard $(TMB_EFFECTS_DIR)/*.c)
EXTRAINCDIRS += $(TMB_EFFECTS_DIR)

CFLAGS += -DHAS_TMB_EFFECTS
