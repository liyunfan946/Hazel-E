#pragma once
#include "Event.h"

namespace Hazel_E {

    class WindowCloseEvent : public Event
    {
    public:
        EVENT_CLASS_TYPE(WindowClose)//这个宏的作用是给这个类添加一个类型，这个类型是这个类的名字
       
        EVENT_CLASS_CATEGORY(EventCategoryApplication)//返回应用程序事件
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

