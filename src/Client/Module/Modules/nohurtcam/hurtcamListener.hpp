#pragma once

#include "../../../../SDK/SDK.hpp"
#include "../../../../SDK//Client/Network/Packet/TextPacket.hpp"
#include <format>
#include "../../../Events/Listener.hpp"
#include "../../../Events/Input/KeyEvent.hpp"
#include "../Module.hpp"
#include "../../../GUI/Engine/Engine.hpp"
#include "../../../../SDK/Client/Network/Packet/SetTitlePacket.hpp"
#include <Windows.h>

class hurtcamListener : public Listener {

    Module* module;
    bool prevPacketSent = false;

    void onLocalTick(TickEvent& event) override {
        if (!SDK::clientInstance->getLocalPlayer())
            return;

        auto LP = reinterpret_cast<LocalPlayer*>(event.getActor());
        if (LP->hurtTime != 0);
            
    }


public:
    explicit hurtcamListener(const char string[5], Module *module) {
        this->name = string;
        this->module = module;
    }

};

