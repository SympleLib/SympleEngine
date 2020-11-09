#pragma once

#include <sstream>

#include "Events/Event.h"

namespace Symple
{
	class MouseMoveEvent : public Event
	{
	public:
		MouseMoveEvent(const float x, const float y)
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
		float mMouseX, mMouseY;
	};

	class MouseScrollEvent : public Event
	{};
}