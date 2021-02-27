#include "Platform/GLFW/GLFWWindow.h"

namespace Symple::Engine
{
    static Scope<Window> Window::Create(const WindowProperties &props)
    { return MakeScope<GLFWWindow>(props); }
}