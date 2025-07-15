#pragma once

#include "Handlers/EventManager.h"
#include "Types/KeyEvent.h"
#include "Types/MouseEvent.h"
#include <unordered_set>

namespace Nebulark {

    class InputManager {
    public:
        explicit InputManager(EventManager& eventManager);
        
        // Keyboard input
        bool IsKeyDown(SDL_Keycode key) const;
        bool IsKeyUp(SDL_Keycode key) const;
        bool IsKeyJustPressed(SDL_Keycode key) const;
        bool IsKeyJustReleased(SDL_Keycode key) const;

        // Mouse button input
        bool IsMouseButtonDown(int button) const;
        bool IsMouseButtonUp(int button) const;
        bool IsMouseButtonJustPressed(int button) const;
        bool IsMouseButtonJustReleased(int button) const;

        // Mouse position
        int GetMouseX() const;
        int GetMouseY() const;
        void Reset();
       

    private:
        void OnKeyDown(Event& e);
        void OnKeyUp(Event& e);
        void OnMouseButtonDown(Event& e);
        void OnMouseButtonUp(Event& e);
       

        EventManager& eventManager;
        std::unordered_set<SDL_Keycode> keysDown;
        std::unordered_set<int> mouseButtonsDown;
        std::unordered_set<SDL_Keycode> keysJustPressed;
        std::unordered_set<SDL_Keycode> keysJustReleased;
        std::unordered_set<int> mouseButtonsJustPressed;
        std::unordered_set<int> mouseButtonsJustReleased;

        int mouseX = 0;
        int mouseY = 0;

    };

}
