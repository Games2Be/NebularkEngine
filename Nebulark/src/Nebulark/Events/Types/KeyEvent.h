#pragma once
#include "../Event.h"
#include "SDL3/SDL.h"

namespace Nebulark {

    class KeyDownEvent : public Event {
    public:
        SDL_Keycode keyCode;

        KeyDownEvent(SDL_Keycode key) : keyCode(key) {}

        EventType GetType() const override { return EventType::KeyDown; }
    };

    class KeyUpEvent : public Event {
    public:
        SDL_Keycode keyCode;

        KeyUpEvent(SDL_Keycode key) : keyCode(key) {}

        EventType GetType() const override { return EventType::KeyUp; }
    };
}
