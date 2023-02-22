#pragma once

#include "WindowProperties.h"

namespace Femto
{
	class App
	{
	protected:
		virtual WindowProperties InitializeWindow();

		virtual void Initialize() = 0;
		virtual void Update(float dt) = 0;
		virtual void Render(float dt) = 0;
		virtual void Cleanup() = 0;
	};
}