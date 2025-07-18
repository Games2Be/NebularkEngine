#include "EventManager.h"  
#include <iostream>  
#include "SDL3/SDL.h"  
#include "../Types/KeyEvent.h"
#include "../Types/MouseEvent.h"
#include "../Types/JoystickEvent.h"
#include "../../Log.h"


namespace Nebulark  
{  
   void EventManager::PollEvents() {  
       SDL_Event sdlEvent;  
       while (SDL_PollEvent(&sdlEvent)) {  
           if (sdlEvent.type == SDL_EVENT_QUIT) {  
               
               QuitEvent e;  
               DispatchEvent(e);  
           }  
           else if (sdlEvent.type == SDL_EVENT_KEY_DOWN) {
               KeyDownEvent e(sdlEvent.key.key);
               DispatchEvent(e);
           }

           else if (sdlEvent.type == SDL_EVENT_KEY_UP) {  
               KeyUpEvent e(sdlEvent.key.key);  
               DispatchEvent(e);  
           }  
           else if (sdlEvent.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
               MouseButtonDownEvent e(sdlEvent.button.button, sdlEvent.button.x, sdlEvent.button.y);
               DispatchEvent(e);
           }
           else if (sdlEvent.type == SDL_EVENT_MOUSE_BUTTON_UP) {
               MouseButtonUpEvent e(sdlEvent.button.button, sdlEvent.button.x, sdlEvent.button.y);
               DispatchEvent(e);
           }
           else if (sdlEvent.type == SDL_EVENT_MOUSE_MOTION) {
               MouseMotionEvent e(sdlEvent.motion.x, sdlEvent.motion.y, sdlEvent.motion.xrel, sdlEvent.motion.yrel);
               DispatchEvent(e);
           }

           else if (sdlEvent.type == SDL_EVENT_GAMEPAD_ADDED) {
               SDL_Gamepad* pad = SDL_OpenGamepad(sdlEvent.gdevice.which);
               if (pad) {
                   SDL_JoystickID id = SDL_GetGamepadID(pad);
				   NBL_CORE_INFO("Gamepad connected: ID = {0}, Name = {1}", id, SDL_GetGamepadName(pad));
               }
               else {
				   NBL_CORE_WARN("Failed to open gamepad: {0}", SDL_GetError());
               }
           }
           else if (sdlEvent.type == SDL_EVENT_GAMEPAD_BUTTON_DOWN) {
               StickDownEvent e = StickDownEvent(static_cast<SDL_GamepadButton>(sdlEvent.gbutton.button));
			   NBL_CORE_INFO("Gamepad button pressed: {0}", static_cast<int>(sdlEvent.gbutton.button));
               DispatchEvent(e);
           }

           else if (sdlEvent.type == SDL_EVENT_GAMEPAD_BUTTON_UP) {
               StickUpEvent e = StickUpEvent(static_cast<SDL_GamepadButton>(sdlEvent.gbutton.button));
			   NBL_CORE_INFO("Gamepad button released: {0}", static_cast<int>(sdlEvent.gbutton.button));
               DispatchEvent(e);
           }
           else if (sdlEvent.type == SDL_EVENT_GAMEPAD_AXIS_MOTION) {
               StickMotionEvent e(static_cast<SDL_GamepadButton>(sdlEvent.gaxis.axis),
                   sdlEvent.gaxis.value / 32767.0f, // Normalize to -1.0 to 1.0
                   0.0f); // Placeholder for y-axis, can be extended
               NBL_CORE_INFO("Gamepad axis motion: {0}, value: {1}", static_cast<int>(sdlEvent.gaxis.axis), e.x);
           }



           // Add more SDL event translation here (e.g. KeyDownEvent, MouseMoveEvent...)  
       }  
   }  

   void EventManager::RegisterListener(EventType type, Listener listener) {  
       listeners[type].push_back(listener);  
   }  

   void EventManager::DispatchEvent(Event& e) {  
       auto& vec = listeners[e.GetType()];  
       for (auto& listener : vec)  
           listener(e);  
   }  
}