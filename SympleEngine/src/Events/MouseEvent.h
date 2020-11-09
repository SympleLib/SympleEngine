#pragma once

#include <sstream>

#include "Events/Event.h"

#include "Core/MouseCode.h"

namespace Symple
{
	class MouseMoveEvent : public Event
	{
	public:
		MouseMoveEvent(float x, float y)
			: mMouseX(x), mMouseY(y)
		{}

		float GetX() const { return mMouseX; }
		float GetY() const { return mMouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMoveEvent: " << mMouseX << ", " << mMouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMove)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		const float mMouseX, mMouseY;
	};

	class MouseScrollEvent : public Event
	{
	public:
		MouseScrollEvent(float x, float y)
			: mScrollX(x), mScrollY(y)
		{}

		float GetX() const { return mScrollX; }
		float GetY() const { return mScrollY; }

		EVENT_CLASS_TYPE(MouseScroll)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		const float mScrollX, mScrollY;
	};

	class MouseButtonEvent : public Event
	{
	public:
		MouseCode GetMouseButton() const { return mButton; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput | EventCategoryMouseButton)
	protected:
		MouseButtonEvent(MouseCode button)
			: mButton(button)
		{}

		const MouseCode mButton;
	};

	class MousePressEvent : public MouseButtonEvent
	{
	public:
		MousePressEvent(MouseCode button)
			: MouseButtonEvent(button)
		{}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MousePressEvent: " << mButton;
		}

		EVENT_CLASS_TYPE(MousePress)
	};

	class MouseReleaseEvent: public MouseButtonEvent
	{
	public:
		MouseReleaseEvent(MouseCode button)
			: MouseButtonEvent(button)
		{}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MousePressEvent: " << mButton;
		}

		EVENT_CLASS_TYPE(MouseRelease)
	};
}