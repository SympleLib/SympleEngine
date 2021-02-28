#pragma once

#include <GLFW/glfw3.h>

#include "Symple/Engine/Core/Base.h"
#include "Symple/Engine/Graphics/Window.h"

namespace Symple::Engine
{
    class SY_ENGINE_API GLFWWindow: public Window
    {
    private:
        GLFWwindow *m_Handle;

        struct WindowData
        {
            union
            {
                WindowProperties Properties;

                struct
                {
                    std::string Title;
                    uint32_t Width, Height;
                };
            };

            bool VSync;
        } m_Data;
    public:
        GLFWWindow(const WindowProperties &properties = WindowProperties {});
        virtual ~GLFWWindow() override;

        virtual uint32_t GetWidth() const override;
        virtual uint32_t GetHeight() const override;

        virtual void SetVSync(bool enabled) const override;
        virtual bool IsVSync() const override;

        virtual NativeWindow_t *GetNativeWindow() const override;
    };
}