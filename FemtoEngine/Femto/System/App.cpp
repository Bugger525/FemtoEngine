#include "App.h"
#include "../Core/Window.h"

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

		while (window.IsRunning())
		{
			Update();
			Render();

			window.Update();
		}
		Cleanup();
	}
}