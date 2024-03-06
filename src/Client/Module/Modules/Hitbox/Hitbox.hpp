#pragma once

#include "../Module.hpp"
#include "../../../Client.hpp"
#include "HitboxListener.hpp"

class Hitbox : public Module {

public:

    Hitbox() : Module("Hitbox", "Displays hitboxes of entities\nthrought blocks", "\\Flarial\\assets\\block.png", 'C') {

        onEnable();

    };

    void onEnable() override {
        EventHandler::registerListener(new HitboxListener("Hitbox", this));

        Module::onEnable();

    }

    void NormalRender(int index, std::string text, std::string value) override {

    }

    virtual void DefaultConfig() override {
        if (settings.getSettingByName<std::string>("color") == nullptr) settings.addSetting("color", (std::string)"FFFFFF");
        if (settings.getSettingByName<bool>("color_rgb") == nullptr) settings.addSetting("color_rgb", false);
        if (settings.getSettingByName<float>("colorOpacity") == nullptr) settings.addSetting("colorOpacity", 0.6f);
        if (settings.getSettingByName<std::string>("animalcolor") == nullptr) settings.addSetting("animalcolor", (std::string)"5adb58");
        if (settings.getSettingByName<bool>("animalcolor_rgb") == nullptr) settings.addSetting("animalcolor_rgb", false);
        if (settings.getSettingByName<float>("animalcolorOpacity") == nullptr) settings.addSetting("animalcolorOpacity", 0.6f);
        if (settings.getSettingByName<std::string>("monstercolor") == nullptr) settings.addSetting("monstercolor", (std::string)"d6d64b");
        if (settings.getSettingByName<bool>("monstercolor_rgb") == nullptr) settings.addSetting("monstercolor_rgb", false);
        if (settings.getSettingByName<float>("monstercolorOpacity") == nullptr) settings.addSetting("monstercolorOpacity", 0.6f);
        if (settings.getSettingByName<int>("distance") == nullptr) settings.addSetting("distance", 30);
    }

    void onDisable() override {
        Module::onDisable();
    }

    void SettingsRender() override {

        


        float textWidth = Constraints::RelativeConstraint(0.12, "height", true);
        const float textHeight = Constraints::RelativeConstraint(0.029, "height", true);

        float sliderX = Constraints::PercentageConstraint(0.019, "left");
        float sliderY = Constraints::PercentageConstraint(0.10, "top") ;
        sliderY += Constraints::SpacingConstraint(0.35, textWidth);

        float x = Constraints::PercentageConstraint(0.019, "left");
        float y = Constraints::PercentageConstraint(0.10, "top");

        FlarialGUI::FlarialTextWithFont(sliderX, sliderY, L"Distance: ", textWidth * 6.9f, textHeight,
            DWRITE_TEXT_ALIGNMENT_LEADING,
            Constraints::RelativeConstraint(0.12, "height", true),
            DWRITE_FONT_WEIGHT_NORMAL);

        FlarialGUI::FlarialTextWithFont(x, y, FlarialGUI::to_wide("Color").c_str(), textWidth * 6.9f, textHeight,
            DWRITE_TEXT_ALIGNMENT_LEADING, Constraints::SpacingConstraint(1.05, textWidth),
            DWRITE_FONT_WEIGHT_NORMAL);

        FlarialGUI::ColorPicker(0, x + Constraints::SpacingConstraint(0.95, textWidth), y - Constraints::SpacingConstraint(0.017, textWidth), settings.getSettingByName<std::string>("color")->value, settings.getSettingByName<float>("colorOpacity")->value, settings.getSettingByName<bool>("color_rgb")->value);
        FlarialGUI::ColorPickerWindow(0, settings.getSettingByName<std::string>("color")->value, settings.getSettingByName<float>("colorOpacity")->value, settings.getSettingByName<bool>("color_rgb")->value);

        //FlarialGUI::FlarialTextWithFont(x, y, FlarialGUI::to_wide("Animals").c_str(), textWidth * 6.9f, textHeight,
            //DWRITE_TEXT_ALIGNMENT_LEADING, Constraints::SpacingConstraint(2.10, textWidth),
            //DWRITE_FONT_WEIGHT_NORMAL);

        FlarialGUI::ColorPicker(0, x + Constraints::SpacingConstraint(1.90, textWidth), y - Constraints::SpacingConstraint(0.017, textWidth), settings.getSettingByName<std::string>("animalcolor")->value, settings.getSettingByName<float>("animalcolorOpacity")->value, settings.getSettingByName<bool>("animalcolor_rgb")->value);
        FlarialGUI::ColorPickerWindow(0, settings.getSettingByName<std::string>("animalcolor")->value, settings.getSettingByName<float>("animalcolorOpacity")->value, settings.getSettingByName<bool>("animalcolor_rgb")->value);

        //FlarialGUI::FlarialTextWithFont(x, y, FlarialGUI::to_wide("Monsters?").c_str(), textWidth * 6.9f, textHeight,
            //DWRITE_TEXT_ALIGNMENT_LEADING, Constraints::SpacingConstraint(3.15, textWidth),
            //DWRITE_FONT_WEIGHT_NORMAL);

        FlarialGUI::ColorPicker(0, x + Constraints::SpacingConstraint(2.85, textWidth), y - Constraints::SpacingConstraint(0.017, textWidth), settings.getSettingByName<std::string>("monstercolor")->value, settings.getSettingByName<float>("monstercolorOpacity")->value, settings.getSettingByName<bool>("monstercolor_rgb")->value);
        FlarialGUI::ColorPickerWindow(0, settings.getSettingByName<std::string>("monstercolor")->value, settings.getSettingByName<float>("monstercolorOpacity")->value, settings.getSettingByName<bool>("monstercolor_rgb")->value);

        

        float percent = FlarialGUI::Slider(1, sliderX + FlarialGUI::SettingsTextWidth("distance: "),
            sliderY, this->settings.getSettingByName<int>("distance")->value, 1000, 0, 0);

        this->settings.getSettingByName<int>("distance")->value = percent;

    }

};
