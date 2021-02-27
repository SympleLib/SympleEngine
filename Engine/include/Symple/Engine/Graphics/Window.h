#pragma once

#include <string>
#include <cstdint>

#include "Symple/Engine/Core/Base.h"

namespace Symple::Engine
{
    using NativeWindow_t = void;

    struct SY_ENGINE_API WindowProperties
    {
        std::string Title = "Symple Window";
        uint32_t Width = 1280, Height = 720;

        WindowProperties(std::string_view title = "Symple Window", uint32_t width = 1280, uint32_t height = 720)
            : Title(title), Width(width), Height(height) {}
    };

    class SY_ENGINE_API Window
    {
    private:
        WindowProperties m_Properties;
    public:
        virtual ~Window() = default;

        virtual void SetTitle(std::string_view title) const = 0;
        virtual const std::string &GetTitle() const = 0;

        virtual void SetWidth(uint32_t width) const = 0;
        virtual uint32_t GetWidth() const = 0;
        virtual void SetHeight(uint32_t height) const = 0;
        virtual uint32_t GetHeight() const = 0;

        virtual void SetVSync(bool enabled) const = 0;
        virtual bool IsVSync() const = 0;

        virtual NativeWindow_t *GetNativeWindow() const = 0;

        static Scope<Window> Create(const WindowProperties &properties = WindowProperties {});

        SY_ENGINE_PROPERTY_GET_SET(GetWidth, SetWidth) uint32_t Width;
        SY_ENGINE_PROPERTY_GET_SET(GetHeight, SetHeight) uint32_t Height;
        SY_ENGINE_PROPERTY_GET_SET(IsVSync, SetVSync) bool VSync;
        SY_ENGINE_PROPERTY_GET(GetNativeWindow) NativeWindow_t *NativeWindow;
    };
}