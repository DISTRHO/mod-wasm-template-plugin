#!/usr/bin/make -f
# Makefile for DISTRHO Plugins #
# ---------------------------- #
# Created by falkTX
#

# --------------------------------------------------------------
# Project name, used for binaries

NAME = mod-wasm-example

# require for modgui builds
MODGUI_CLASS_NAME = distrho_examples_ImGuiSimpleGain

# --------------------------------------------------------------
# Files to build

FILES_DSP = \
	PluginDSP.cpp

FILES_UI = \
	PluginUI.cpp \
	../dpf-widgets/opengl/DearImGui.cpp

# --------------------------------------------------------------
# Do some magic

include ../dpf/Makefile.plugins.mk

BUILD_CXX_FLAGS += -I../dpf-widgets/opengl

# --------------------------------------------------------------
# Enable all possible plugin types

all: lv2_dsp modgui

# --------------------------------------------------------------
