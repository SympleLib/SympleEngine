#include "Platform/Windows/WindowsWindow.h"

#include "Core/Console.h"

namespace Symple::Platform
{
	Window::Window(const WindowProperties& props)
	{
		Init(props);
	}

	Window::~Window()
	{
		Shutdown();
	}

	void Window::Init(const WindowProperties& props)
	{
		mData.Title = props.Title;
		mData.Height = props.Width;
		mData.Width = props.Height;

		SY_CORE_INFO("Creating Window '{0}'");
	}
}