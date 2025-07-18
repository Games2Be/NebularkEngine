#pragma once

#include "Handlers/EventManager.h"
#include "InputManager.h"
#include "Types/KeyEvent.h"
#include "Types/MouseEvent.h"
#include "Types/JoystickEvent.h"
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

		// Gamepad input

        bool IsStickDown(SDL_GamepadButton button) const;
        bool IsStickUp(SDL_GamepadButton button) const;
        bool IsStickJustPressed(SDL_GamepadButton button) const;
        bool IsStickJustReleased(SDL_GamepadButton button) const;


		// Gamepad stick position
        float GetLeftStickX() const;
        float GetLeftStickY() const;

		float GetRightStickX() const;
		float GetRightStickY() const;

		float GetLeftTrigger() const;
		float GetRightTrigger() const;
       

    private:
        void OnKeyDown(Event& e);
        void OnKeyUp(Event& e);
        void OnMouseButtonDown(Event& e);
        void OnMouseButtonUp(Event& e);
        // Gamepad Input
        void OnStickDown(Event& e);
        void OnStickUp(Event& e);

        void SetMouseX(Event& e);
		void SetMouseY(Event& e);
       

        EventManager& eventManager;
        std::unordered_set<SDL_Keycode> keysDown;
        std::unordered_set<int> mouseButtonsDown;
        std::unordered_set<SDL_Keycode> keysJustPressed;
        std::unordered_set<SDL_Keycode> keysJustReleased;
        std::unordered_set<int> mouseButtonsJustPressed;
        std::unordered_set<int> mouseButtonsJustReleased;
		std::unordered_set<SDL_GamepadButton> sticksDown;
		std::unordered_set<SDL_GamepadButton> sticksJustPressed;
		std::unordered_set<SDL_GamepadButton> sticksJustReleased;


        int mouseX = 0;
        int mouseY = 0;

		float leftStickX = 0.0f; // normalized x-axis value
		float leftStickY = 0.0f; // normalized y-axis value
		float rightStickX = 0.0f; // normalized x-axis value
		float rightStickY = 0.0f; // normalized y-axis value
		float leftTrigger = 0.0f; // normalized left trigger value
		float rightTrigger = 0.0f; // normalized right trigger value



    };

}
