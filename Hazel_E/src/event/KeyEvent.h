#pragma once
#include "event/Event.h"

namespace Hazel_E {

	class HAZEL_API KeyEvent:public Event
	{
	public:
		inline int GetKeyCode() const {
			return m_KeyCode;
		}
EVENT_CLASS_CATEGORY(EventCategorKeyboard|EventCategoryInput)//	返回事件类型
	protected:
		KeyEvent(int keycode)
			: m_KeyCode(keycode){ }

		int m_KeyCode;

	};


	class Hazel_API KeyPressedEvent : public KeyEvent {

	public:
		KeyPressedEvent(int keycode,int repeatCount):
			KeyEvent(KeyCode),m_RepeatCount(repeatCount){ }


		inline int GetRepeatCount() const { return m_RepeatCount; }


		std::string ToString() const overrride {

			std::stringstream ss;
			ss << "KeyPressedEvent:" << m_KeyCode << "(" << m_RepeatCount << "repeats");

			return ss.str();


		}

		static EventType GetStaticType() {
			return EventType::KeyPressed;
		}
		virtual EventType GetEventType() const override {
			return GetStaticType();
		}
		virtual const char* GetName() const override {
			return "KeyPressed";
		}




		EVENT_CLASS_TYPE(KeyPressedEvent)

	private:
		int m_RepeatCount;//重复次数




	};

	class HAZEL_API KeyReleasedEvent : public KeyEvent {

	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) { }


		std::string ToString() const override {

			std::stringstream ss;
			ss << "KeyReleasedEvent:" << m_KeyCode;

			return ss.str();


		}

		EVENT_CLASS_TYPE(KeyReleasedEvent)

	};




}