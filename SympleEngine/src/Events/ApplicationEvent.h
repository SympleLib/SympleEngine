#pragma once

#include <sstream>
#include <cstdint>

#include "Events/Event.h"

namespace Symple
{
	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(uint32_t width, uint32_t height)
		{

		}
	};
}