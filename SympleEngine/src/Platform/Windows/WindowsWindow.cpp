#include "syegpch.h"
#include "Platform/Windows/WindowsWindow.h"

#include "Core/Assert.h"

#include <GLFW/glfw3.h>

namespace Symple::Platform
{
	static uint8_t sGLFWWindowCount = 0;

	static void GLFWErrorCallback(int error, const char* description)
	{
		SY_CORE_FATAL("GLFW Error ({0}): {1}", error, description);
	}

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

		SY_CORE_INFO("Creating Window '{0}' of size (Width: {1}, Height: {2})", mData.Title, mData.Width, mData.Height);

		if (sGLFWWindowCount == 0)
		{
			int status;
			if (!(status = glfwInit()))
			{
				SY_CORE_FATAL("Could not initialize GLFW!!!");
			}
			glfwSetErrorCallback(GLFWErrorCallback);
		}
	}
	
	void Window::Shutdown()
	{
		glfwDestroyWindow(mWindow);
		sGLFWWindowCount--;

		if (sGLFWWindowCount == 0)
		{
			glfwTerminate();
		}
	}

	void Window::OnUpdate()
	{
		glfwPollEvents();
	}

	void Window::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		mData.VSync = enabled;
	}

	bool Window::IsVSync() const
	{
		return mData.VSync;
	}
}