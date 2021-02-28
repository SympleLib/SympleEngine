#pragma once

#include "Symple/Engine/Core/Base.h"
#include "Symple/Engine/Graphics/Window.h"

int main(int argc, char *argv[]);

namespace Symple::Engine
{
    class SY_ENGINE_API Application
    {
    private:
        static Application *s_Instance;

        Scope<Window> m_MainWindow;

        friend int ::main(int argc, char *argv[]);
    protected:
        virtual void Start() = 0;
    public:
        Application(std::string_view name = "Symple App");
        virtual ~Application() = default;

        Window &GetMainWindow();

        SY_ENGINE_PROPERTY_GET(GetWindow) Window &MainWindow;
    };

    Application *StartApplication();
}