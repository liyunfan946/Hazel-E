#pragma once

#include <functional>
#include "core/core.h"

namespace Hazel_E
{
    enum class EventType
    {
        None = 0,
        WindowClose, WindowResize,
        AppTick, AppUpdate,
        KeyPressed, KeyReleased,
        MouseButtonPressed, MouseButtonReleased,
        MouseMoved, MouseScrolled
    };

    enum EventCategory
    {
        None = 0,
        EventCategoryApplication = BIT(0),
        EventCategoryInput = BIT(1),
        EventCategoryKeyboard = BIT(2),
        EventCategoryMouse = BIT(3),
        EventCategoryMouseButton = BIT(4)
    };

    #define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
                                   virtual EventType GetEventType() const override { return GetStaticType(); }\
                                   virtual const char* GetName() const override { return #type; }\
                                   virtual std::string ToString() const override { return GetName(); }

    #define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

    class HAZEL_API Event
    {
    public:
        virtual EventType GetEventType() const = 0;
        virtual const char* GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual std::string ToString() const { return GetName(); }

        inline bool IsInCategory(EventCategory category)
        {
            return GetCategoryFlags() & category;
        }
    };

    class HAZEL_API EventDispatcher
    {
    public:
        EventDispatcher(Event& event)
            : m_Event(event)
        {
        }

        template<typename T, typename F>
        bool Dispatch(const F& func)
        {
            if (m_Event.GetEventType() == T::GetStaticType())
            {
                m_EventHandled = func(static_cast<T&>(m_Event));
                return m_EventHandled;
            }
            return false;
        }

    private:
        Event& m_Event;
        bool m_EventHandled = false;
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& e)
    {
        return os << e.ToString();
    }

    // Application events
    class HAZEL_API ApplicationEvent : public Event
    {
    public:
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class HAZEL_API AppTickEvent : public ApplicationEvent
    {
    public:
        EVENT_CLASS_TYPE(AppTick)
    };

    class HAZEL_API AppUpdateEvent : public ApplicationEvent
    {
    public:
        EVENT_CLASS_TYPE(AppUpdate)
    };

    // Window events
    class HAZEL_API WindowCloseEvent : public ApplicationEvent
    {
    public:
        EVENT_CLASS_TYPE(WindowClose)
    };

    class HAZEL_API WindowResizeEvent : public ApplicationEvent
    {
    public:
        WindowResizeEvent(unsigned int width, unsigned int height)
            : m_Width(width), m_Height(height)
        {
        }

        inline unsigned int GetWidth() const { return m_Width; }
        inline unsigned int GetHeight() const { return m_Height; }

        EVENT_CLASS_TYPE(WindowResize)

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
            return ss.str();
        }

    private:
        unsigned int m_Width, m_Height;
    };
}
