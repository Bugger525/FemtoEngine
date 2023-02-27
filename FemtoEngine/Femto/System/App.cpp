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
		Window = Femto::Window{ CreateWindow() };

		Initialize();

		Timer timer{};
		while (Window.IsRunning())
		{
			timer.Tick();

			Update(timer.GetDeltaTime());
			Render(timer.GetDeltaTime());

			timer.Reset();

			Window.Update();
		}
		Cleanup();
	}
}