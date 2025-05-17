#pragma once
#include <core/core.h>
//存储事件的基类


namespace HazelEvent {

    enum class EventType
    {
        None = 0,
        WindowClose = 1,
        WindowResize = 2,
        WindowFocus = 3,
        WindowLostFocus = 4,
        WindowMoved = 5,
        AppTick = 6,
        AppUpdate = 7,
        AppRender = 8,
        KeyPressed = 9,
        KeyReleased = 10,
        KeyTyped = 11,
        MouseButtonPressed = 12,
        MouseButtonReleased = 13,
        MouseMoved = 14,
        MouseScrolled = 15




    };
    enum EventCategory//  事件类别
    {
        None = 0,
        EventCategoryApplication = BIT(0),// 应用事件               BIT(0) → 1 << 0     → 000...0001（即 1）
        EventCategoryInput = BIT(1),// 输入事件                     BIT(1) → 1 << 1      → 000...0010（即 2）
        EventCategoryKeyboard = BIT(2),//  键盘事件                 BIT(2) → 1 << 2      → 000...0100（即 4）
        EventCategoryMouse = BIT(3),// 鼠标事件                     BIT(3) → 1 << 3       → 000...1000（即 8）
        EventCategoryMouseButton = BIT(4)// 鼠标按键事件             BIT(4) → 1 << 4       → 000...10000（即 16）
    };

#define EVENT_CLASS_TYPE(type) \
    static EventType GetStaticType() { return EventType::type; } \
    virtual EventType GetEventType() const override { return GetStaticType(); } \
    virtual const char* GetName() const override { return #type; }//当你在一个宏定义中使用 # 时，它会将宏参数转换成一个字符串,而## 作用是连接两个字符串，而不是替换字符串中的变量。


#define EVENT_CLASS_CATEGORY(category)          virtual int GetCategoryFlags() const override { return category; }

}






class HAZEL_API Event   //  事件基类
{
    friend class EventDispatcher;//  事件分发器

public:

    virtual HazelEvent::EventType GetEventType() const = 0;//获取事件类型
    virtual const char* GetName() const = 0;//获取事件名
    virtual int GetCategoryFlags() const = 0;//事件是否是属于某个类别
    //（以上三个函数都被宏函数 EVENT_CLASS_TYPE 和 EVENT_CLASS_CATEGORY 封装）
    virtual std::string ToString() const { return GetName(); }//将事件转化为字符串

    inline bool IsInCategory(HazelEvent::EventCategory category)
    {
        return GetCategoryFlags() & category;
        //检查 GetCategoryFlags() 返回的标志位（bitmask）中是否包含 category 指定的标志位，并返回匹配的结果
        //& 会对两个整数的每一位进行按位与运算：如果两个对应位都是 1，结果的该位为 1。否则，结果的该位为 0
    }

protected:

    bool Handled = false;// 事件是否被处理
};

class EventDispatcher//  事件分发器
{
    template<typename T>
    using EventFn = std::function<bool(T&)>;

public:
    EventDispatcher(Event& event)
        :m_Event(event)
    {
    }

    template<typename T>
    bool Dispatch(EventFn<T> func)
    {
        if (m_Event.GetEventType() == T::GetStaticType())//  判断事件类型是否匹配
        {
            m_Event.Handled = func(*(T*)&m_Event);// 调用事件处理函数
            return true;
        }
        return false;
    }
private:
    Event& m_Event;// 事件
};


inline std::ostream& operator<<(std::ostream& os, const Event& ev)
{
    return os << ev.ToString();// 将事件转化为字符串
}