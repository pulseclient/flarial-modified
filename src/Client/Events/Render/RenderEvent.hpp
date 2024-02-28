
#pragma once
#include "../Event.hpp"
#include "../Cancellable.hpp"
#pragma once
#include "../Event.hpp"
#include "../Cancellable.hpp"
#include "../../../SDK/Client/Render/MinecraftUIRenderContext.hpp"



class RenderEvent : public Event {

public:
	MinecraftUIRenderContext* muirc;

};