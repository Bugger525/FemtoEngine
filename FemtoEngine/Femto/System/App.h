#pragma once

#include "../Core/Window.h"

namespace Femto
{
	class App
	{
	protected:
		Window Window;

		virtual WindowProperties CreateWindow();

		virtual void Initialize() = 0;
		virtual void Update(float dt) = 0;
		virtual void Render(float dt) = 0;
		virtual void Cleanup() = 0;
	public:
		void Run();
	};
}