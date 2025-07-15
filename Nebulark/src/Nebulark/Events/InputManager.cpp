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
    }
}
