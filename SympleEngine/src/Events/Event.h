#pragma once

#include <functional>

#include "Core/Core.h"

namespace Symple
{
	enum class EventType
	{
		None = -1,
		WindowClose, WindowResize, WindowFocus, WindowUnFocus, WindowMove,
		AppTick, AppUpdate, AppRender,
		KeyPress, KeyRelease, KeyType,
		MousePress, MosueRelease, MouseMove, MouseScroll
	};

	enum EventCategory
	{
		None = -1,
		EventCategoryApplication = 1 << 0,
		EventCategoryInput       = 1 << 1,
		EventCategoryKeyboard    = 1 << 2,
		EventCategoryMouse       = 1 << 3,
		EventCategoryMouseButton = 1 << 4,
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; } virtual EventType GetEventType() const override { return GetStaticType(); } virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class Event
	{
	public:
		virtual ~Event() = default;

		bool Handled = false;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	};

	class EventDispatcher
	{
	public:
		EventDispatcher(Event& event)
			: mEvent(event)
		{}

		template<typename T, typename F>
		bool Dispatch(const F& func)
		{
			if (mEvent.GetEventType() == T::GetStaticType())
			{
				mEvent.Handled |= func(static_cast<T&>(mEvent));
				return true;
			}
			return false;
		}
	private:
		Event& mEvent;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}