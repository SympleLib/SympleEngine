#pragma once

#include "Core.h"

namespace Symple
{
	class SYMPLE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Start();
	};

	Application* CreateApplication();
}