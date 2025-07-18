#pragma once
#include "../Event.h"
#include "SDL3/SDL.h"

namespace Nebulark {

    // This event represents when a game controller button is pressed
    class StickDownEvent : public Event {
    public:
        SDL_GamepadButton button;

        StickDownEvent(SDL_GamepadButton btn) : button(btn) {}

        EventType GetType() const override { return EventType::StickDown; }
    };

    // This event represents when a game controller button is released
    class StickUpEvent : public Event {
    public:
        SDL_GamepadButton button;

        StickUpEvent(SDL_GamepadButton btn) : button(btn) {}

        EventType GetType() const override { return EventType::StickUp; }
    };

    class StickMotionEvent : public Event {
	public:
		SDL_GamepadButton button;
		float x; // normalized x-axis value
		float y; // normalized y-axis value
		StickMotionEvent(SDL_GamepadButton btn, float xpos, float ypos)
			: button(btn), x(xpos), y(ypos) {
		}
		EventType GetType() const override { return EventType::StickMotion; }
    };

}
