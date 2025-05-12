#pragma once
#include "Event.h"

namespace HazelEvent {

    class WindowCloseEvent : public Event
    {
    public:
        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(float width, float height)
            : m_Width(width), m_Height(height) {}

        inline float GetWidth() const { return m_Width; }
        inline float GetHeight() const { return m_Height; }

        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)

    private:
        float m_Width, m_Height;
    };

}
