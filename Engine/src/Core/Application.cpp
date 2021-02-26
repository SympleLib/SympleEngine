#include "Symple/Engine/Core/Application.h"

namespace Symple::Engine
{
    Application *Application::s_Instance = nullptr;

    Application::Application(std::string_view name)
    {
        SY_ASSERT(!s_Instance, "Application already exists!")

        s_Instance = this;
        m_MainWindow = Window::Create(WindowProperties { .Title = name });
    }

    Window &Application::GetMainWindow()
    { return *m_MainWindow; }
}