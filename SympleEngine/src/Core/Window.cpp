#include "Core/Window.h"

namespace Symple
{
	Scope<Window> Window::Create(const WindowProperties& props)
	{
		Scope<Window> window;
#ifdef SY_PLATFORM_WINDOWS
		window = MakeScope<Platform::Window>(props);
#endif
	}
}