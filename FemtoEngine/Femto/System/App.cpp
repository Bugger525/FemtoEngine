#include "App.h"
#include "../Core/Window.h"
#include "Timer.h"

namespace Femto
{
	WindowProperties App::CreateWindow()
	{
		return WindowProperties();
	}
	void App::Run()
	{
		Window window{ CreateWindow() };

		Initialize();

		Timer timer{};
		while (window.IsRunning())
		{
			timer.Tick();

			Update(timer.GetDeltaTime());
			Render(timer.GetDeltaTime());

			timer.Reset();

			window.Update();
		}
		Cleanup();
	}
}