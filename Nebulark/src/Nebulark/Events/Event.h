#pragma once

#include <SDL3/SDL_scancode.h>

namespace Nebulark
{
	enum class EventType
	{
		None, 
		Quit, 
		KeyDown,
		KeyUp,
		MouseButtonDown,
		MouseButtonUp,
		MouseMotion,
		Window
	};

	class Event
	{
	public:
		virtual EventType GetType() const = 0;
	};

	class QuitEvent : public Event {
	public:
		EventType GetType() const override { return EventType::Quit; }
		

		/*SDL_Keycode keyCode;

		KeyDownEvent(SDL_Keycode key) : keyCode(key) {}

		EventType GetType() const override { return EventType::KeyDown; }*/
	};
}
