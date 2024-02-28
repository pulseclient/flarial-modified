#pragma once

#include "../Module.hpp"
#include "../../../Events/EventHandler.hpp"
#include "hurtcamListener.hpp"


class hurtcam : public Module {

public:


    hurtcam() : Module("NoHurtCam", "Automatically sends a message when you\nwin a game. (Doesn't work everywhere)", "\\Flarial\\assets\\like.png", 'o') {

        onEnable();

    };

    void onEnable() override {

        Module::onEnable();

        EventHandler::registerListener(new hurtcamListener("hurtcam", this));
    }

    void onDisable() override {

        EventHandler::unregisterListener("hurtcam");

        Module::onDisable();

    }

    void SettingsRender() override {

        
    }
};

