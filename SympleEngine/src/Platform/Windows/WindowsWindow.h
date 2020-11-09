#pragma once

#include <GLFW/glfw3.h>

#include "Core/Core.h"

#include "Core/Window.h"

namespace Symple::Platform
{
	class SYMPLE_API Window : public ::Symple::Window
	{
	public:
		Window(const WindowProperties& props);
		virtual ~Window();

		void OnUpdate() override;

		inline uint32_t GetWidth() const override { return mData.Width; }
		inline uint32_t GetHeight() const override { return mData.Height; }

		// Window attributes
		inline void SetEventCallback(const EventCallbackFun& callback) override { mData.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		inline virtual void* GetNativeWindow() const override { return mWindow; }
	private:
		virtual void Init(const WindowProperties& props);
		virtual void Shutdown();
	private:
		GLFWwindow* mWindow;

		struct WindowData
		{
			std::string Title;
			uint32_t Width, Height;
			bool VSync;

			EventCallbackFun EventCallback;
		} mData;
	};
}