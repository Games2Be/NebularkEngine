#include "EventManager.h"  
#include <iostream>  
#include "SDL3/SDL.h"  
#include "../Types/KeyEvent.h"
#include "../Types/MouseEvent.h"


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