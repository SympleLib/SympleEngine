#pragma once

#include "Core.h"

namespace Symple
{
	class SYMPLE_API Window
	{
	private:
	public:
		virtual void Setup();
		virtual void Update();
		virtual void Render();
	};
}