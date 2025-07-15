#pragma once
#include <SDL3/SDL.h>
#include "../Event.h"
#include <functional>
#include <unordered_map>
#include <vector>

namespace Nebulark
{
    class EventManager {
    public:
        using Listener = std::function<void(Event&)>;

        void PollEvents();
        void RegisterListener(EventType type, Listener listener);

    private:
        std::unordered_map<EventType, std::vector<Listener>> listeners;
        void DispatchEvent(Event& e);
    };
}