/*
 * ImGui plugin example
 * Copyright (C) 2021 Jean Pierre Cimalando <jp-dev@inbox.ru>
 * Copyright (C) 2021-2022 Filipe Coelho <falktx@falktx.com>
 * SPDX-License-Identifier: ISC
 */

#include "DistrhoUI.hpp"

START_NAMESPACE_DISTRHO

// --------------------------------------------------------------------------------------------------------------------

class ImGuiPluginUI : public UI
{
    float fGain = 0.0f;

    // ----------------------------------------------------------------------------------------------------------------

public:
   /**
      UI class constructor.
      The UI should be initialized to a default state that matches the plugin side.
    */
    ImGuiPluginUI()
        : UI(DISTRHO_UI_DEFAULT_WIDTH, DISTRHO_UI_DEFAULT_HEIGHT)
    {
        setFontSize(20);
    }

protected:
    // ----------------------------------------------------------------------------------------------------------------
    // DSP/Plugin Callbacks

   /**
      A parameter has changed on the plugin side.@n
      This is called by the host to inform the UI about parameter changes.
    */
    void parameterChanged(uint32_t index, float value) override
    {
        DISTRHO_SAFE_ASSERT_RETURN(index == 0,);

        fGain = value;
        repaint();
    }

    // ----------------------------------------------------------------------------------------------------------------
    // Widget Callbacks

   /**
      ImGui specific onDisplay function.
    */
    void onImGuiDisplay() override
    {
        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::SetNextWindowSize(ImVec2(getWidth(), getHeight()));

        if (ImGui::Begin("Simple gain", nullptr, ImGuiWindowFlags_NoResize))
        {
            static char aboutText[256] = "This is a demo plugin made with ImGui.\n";
            ImGui::InputTextMultiline("About", aboutText, sizeof(aboutText), ImVec2(390, getHeight()*2/3));

            if (ImGui::SliderFloat("Gain (dB)", &fGain, -90.0f, 30.0f))
            {
                if (ImGui::IsItemActivated())
                    editParameter(0, true);

                setParameterValue(0, fGain);
            }

            if (ImGui::IsItemDeactivated())
            {
                editParameter(0, false);
            }
        }
        ImGui::End();
    }

    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ImGuiPluginUI)
};

// --------------------------------------------------------------------------------------------------------------------

UI* createUI()
{
    return new ImGuiPluginUI();
}

// --------------------------------------------------------------------------------------------------------------------

END_NAMESPACE_DISTRHO
