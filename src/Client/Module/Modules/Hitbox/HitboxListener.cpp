#include "HitboxListener.hpp"

#include "../../Manager.hpp"
#include "../../../../Utils/Render/DrawUtils.hpp"
//#include "../../../../Utils/Render/DrawUtils.cpp"

#include <iostream>
#include "../../../../SDK/SDK.hpp"
#include <format>
#include "../../../Events/Listener.hpp"
#include "../../../Events/Input/KeyEvent.hpp"
#include "../Module.hpp"
#include "../../../GUI/Engine/Engine.hpp"
#include "../../../../SDK/SDK.hpp"
#include "../../../../SDK/Client/Render/BaseActorRenderContext.hpp"
#include "../../../../SDK/Client/Render/ItemRenderer.hpp"
#include <Windows.h>
#include <chrono>
#include "../../../../SDK/Client/Render/Matrix.hpp"


//#include "../../Client/GUI/Engine/Engine.hpp"
//#include "../../SDK/SDK.hpp"

void renderBox(Player* player) {
	Player* ent = player;

	Module* box = ModuleManager::getModule("Hitbox");

	//event.muirc->screenContext
	D2D1_COLOR_F color2;
	D2D1_COLOR_F color3;
	D2D1_COLOR_F color4;

	if (box->settings.getSettingByName<bool>("color_rgb")->value) color2 = FlarialGUI::rgbColor;
	else color2 = FlarialGUI::HexToColorF(box->settings.getSettingByName<std::string>("color")->value);
	if (box->settings.getSettingByName<bool>("monstercolor_rgb")->value) color3 = FlarialGUI::rgbColor;
	else color3 = FlarialGUI::HexToColorF(box->settings.getSettingByName<std::string>("monstercolor")->value);
	if (box->settings.getSettingByName<bool>("animalcolor_rgb")->value) color4 = FlarialGUI::rgbColor;
	else color4 = FlarialGUI::HexToColorF(box->settings.getSettingByName<std::string>("animalcolor")->value);

	auto localPlayer = SDK::clientInstance->getLocalPlayer();
	float dist = localPlayer->getPosition()->dist(*player->getPosition());
	if (player == nullptr) return;
	// This may let through some entites (real)
	//|| !HitboxListener::canSeeArrXD[player->getNametag()] 
	if (!player || !player->isAlive() || !localPlayer->isValidTarget(player) || dist > box->settings.getSettingByName<int>("distance")->value)
		return;
	//player == localPlayer ||  GEHT DES?  ne gehts nd (doch gehts)
	if (player->hasCategory(ActorCategory::Player))	{
		DrawUtils::addEntityBox(player, (float)fmax(0.5f, 1 / (float)fmax(1, localPlayer->getRenderPositionComponent()->renderPos.dist(player->getRenderPositionComponent()->renderPos))), color2);
	} else if (player->hasCategory(ActorCategory::Monster)) {
		DrawUtils::addEntityBox(player, (float)fmax(0.5f, 1 / (float)fmax(1, localPlayer->getRenderPositionComponent()->renderPos.dist(player->getRenderPositionComponent()->renderPos))), color3);
	}
	else
	{
		DrawUtils::addEntityBox(player, (float)fmax(0.5f, 1 / (float)fmax(1, localPlayer->getRenderPositionComponent()->renderPos.dist(player->getRenderPositionComponent()->renderPos))), color4);
	}
	
	
	
	

}


void HitboxListener::onRender(RenderEvent& event) {
	if (!this->module->settings.getSettingByName<bool>("enabled")->value)
		return;

	if (!SDK::clientInstance || !SDK::clientInstance->getLocalPlayer() || !SDK::clientInstance->mcgame->mouseGrabbed || !SDK::clientInstance->getLocalPlayer()->level)
		return;

	auto player = SDK::clientInstance->getLocalPlayer();

    if(player != nullptr) {
        for (const auto& ent: player->level->getRuntimeActorList()) {
			if (ent != nullptr || ent->hasCategory(ActorCategory::Monster))
				// && ent->isPlayer() && ent->hasCategory(ActorCategory::Player) checkt nach player
            renderBox((Player*)ent);
			
        }
    }
}

