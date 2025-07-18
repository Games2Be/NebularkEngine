#include "InputManager.h"
#include <iostream>
#include "Handlers/EventManager.h"
#include "../Log.h"

namespace Nebulark {

    InputManager::InputManager(EventManager& eventMgr)
        : eventManager(eventMgr)
    {
        eventManager.RegisterListener(EventType::KeyDown, [this](Event& e) { OnKeyDown(e); });
        eventManager.RegisterListener(EventType::KeyUp, [this](Event& e) { OnKeyUp(e); });
        eventManager.RegisterListener(EventType::MouseButtonDown, [this](Event& e) { OnMouseButtonDown(e); });
        eventManager.RegisterListener(EventType::MouseButtonUp, [this](Event& e) { OnMouseButtonUp(e); });
		eventManager.RegisterListener(EventType::MouseMotion, [this](Event& e) { SetMouseX(e); SetMouseY(e); });
        eventManager.RegisterListener(EventType::StickDown, [this](Event& e) { OnStickDown(e); });
        eventManager.RegisterListener(EventType::StickUp, [this](Event& e) { OnStickUp(e); });
        
    }

    void InputManager::OnKeyDown(Event& e)
    {
        auto& keyEvent = static_cast<KeyDownEvent&>(e);
        if (keysDown.find(keyEvent.keyCode) == keysDown.end()) {
            keysJustPressed.insert(keyEvent.keyCode); // only if it wasn't already down
        }
        keysDown.insert(keyEvent.keyCode);

    }

    void InputManager::OnKeyUp(Event& e)
    {
        auto& keyEvent = static_cast<KeyUpEvent&>(e);
        if (keysDown.find(keyEvent.keyCode) != keysDown.end()) {
            keysJustReleased.insert(keyEvent.keyCode); // only if it was down
        }
        keysDown.erase(keyEvent.keyCode);

    }

    void InputManager::OnMouseButtonDown(Event& e)
    {
        auto& mouseEvent = static_cast<MouseButtonDownEvent&>(e);
        if (mouseButtonsDown.find(mouseEvent.button) == mouseButtonsDown.end()) {
            mouseButtonsJustPressed.insert(mouseEvent.button);
        }
        mouseButtonsDown.insert(mouseEvent.button);
        mouseX = mouseEvent.x;
        mouseY = mouseEvent.y;

    }

    void InputManager::OnMouseButtonUp(Event& e)
    {
        auto& mouseEvent = static_cast<MouseButtonUpEvent&>(e);
        if (mouseButtonsDown.find(mouseEvent.button) != mouseButtonsDown.end()) {
            mouseButtonsJustReleased.insert(mouseEvent.button);
        }
        mouseButtonsDown.erase(mouseEvent.button);
        mouseX = mouseEvent.x;
        mouseY = mouseEvent.y;

    }

    void InputManager::SetMouseX(Event& e)
    {
        auto& mouseEvent = static_cast<MouseMotionEvent&>(e);

        mouseX = mouseEvent.x;

    }
    void InputManager::SetMouseY(Event& e)
    {
        auto& mouseEvent = static_cast<MouseMotionEvent&>(e);
        mouseY = mouseEvent.y;
    }
    bool InputManager::IsKeyDown(SDL_Keycode key) const
    {
        return keysDown.find(key) != keysDown.end();
    }

    bool InputManager::IsKeyUp(SDL_Keycode key) const
    {
        return keysDown.find(key) == keysDown.end();
    }

    bool InputManager::IsKeyJustPressed(SDL_Keycode key) const
    {
        return keysJustPressed.find(key) != keysJustPressed.end();
    }

    bool InputManager::IsKeyJustReleased(SDL_Keycode key) const
    {
        return keysJustReleased.find(key) != keysJustReleased.end();
    }

    bool InputManager::IsMouseButtonDown(int button) const
    {
        return mouseButtonsDown.find(button) != mouseButtonsDown.end();
    }

    bool InputManager::IsMouseButtonUp(int button) const
    {
        return mouseButtonsDown.find(button) == mouseButtonsDown.end();
    }

    bool InputManager::IsMouseButtonJustPressed(int button) const
    {
        return mouseButtonsJustPressed.find(button) != mouseButtonsJustPressed.end();
    }

    bool InputManager::IsMouseButtonJustReleased(int button) const
    {
        return mouseButtonsJustReleased.find(button) != mouseButtonsJustReleased.end();
    }

    int InputManager::GetMouseX() const
    {
        return mouseX;
    }

    int InputManager::GetMouseY() const
    {
        return mouseY;
    }

    void InputManager::Reset()
    {
        keysJustPressed.clear();
        keysJustReleased.clear();
        mouseButtonsJustPressed.clear();
        mouseButtonsJustReleased.clear();
		sticksJustPressed.clear();
		sticksJustReleased.clear();

    }
    bool InputManager::IsStickDown(SDL_GamepadButton button) const
    {
        return sticksDown.find(button) != sticksDown.end();
    }
    bool InputManager::IsStickUp(SDL_GamepadButton button) const
    {
        return sticksDown.find(button) == sticksDown.end();
    }
    bool InputManager::IsStickJustPressed(SDL_GamepadButton button) const
    {
        return sticksJustPressed.find(button) != sticksJustPressed.end();
    }
    bool InputManager::IsStickJustReleased(SDL_GamepadButton button) const
    {
        return sticksJustReleased.find(button) != sticksJustReleased.end();
    }
    float InputManager::GetLeftStickX() const
    {
        return leftStickX;
    }
    float InputManager::GetLeftStickY() const
    {
        return leftStickY;
    }
    float InputManager::GetRightStickX() const
    {
        return rightStickX;
    }
    float InputManager::GetRightStickY() const
    {
        return rightStickY;
    }
    float InputManager::GetLeftTrigger() const
    {
        return leftTrigger;
    }
    float InputManager::GetRightTrigger() const
    {
        return rightTrigger;
    }
    void InputManager::OnStickDown(Event& e)
    {
		auto& stickEvent = static_cast<StickDownEvent&>(e);
        if (sticksDown.find(stickEvent.button) == sticksDown.end()) {
            sticksJustPressed.insert(stickEvent.button); // only if it wasn't already down
        }
        sticksDown.insert(stickEvent.button);
    }

	void InputManager::OnStickUp(Event& e)
	{
        auto& stickEvent = static_cast<StickUpEvent&>(e);
        if (sticksDown.find(stickEvent.button) == sticksDown.end()) {
            sticksJustReleased.insert(stickEvent.button); // only if it was down
        }
        sticksDown.erase(stickEvent.button);
	}
   
}
