// Events/MouseEvent.h
#pragma once

#include "../Event.h"

namespace Nebulark {

    class MouseButtonDownEvent : public Event {
    public:
        int button;
        int x;
        int y;

        MouseButtonDownEvent(int btn, int xpos, int ypos)
            : button(btn), x(xpos), y(ypos) {
        }

        EventType GetType() const override { return EventType::MouseButtonDown; }
    };

    class MouseButtonUpEvent : public Event {
    public:
        int button;
        int x;
        int y;

        MouseButtonUpEvent(int btn, int xpos, int ypos)
            : button(btn), x(xpos), y(ypos) {
        }

        EventType GetType() const override { return EventType::MouseButtonUp; }
    };

    class MouseMotionEvent : public Event {
    public:
        int x;
        int y;
        int xrel;
        int yrel;

        MouseMotionEvent(int xpos, int ypos, int xrelative, int yrelative)
            : x(xpos), y(ypos), xrel(xrelative), yrel(yrelative) {
        }

        EventType GetType() const override { return EventType::MouseMotion; }
    };

}
