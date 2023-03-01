#include "App.h"
#include "Timer.h"

namespace Femto
{
	void App::Run()
	{
		m_Window = std::make_unique<Window>();
		m_GraphicsDevice = std::make_unique<GraphicsDevice>(m_Window.get());

		Initialize();

		Timer timer{};
		while (m_Window->IsRunning())
		{
			timer.Tick();

			Update(timer.GetDeltaTime());
			Render(timer.GetDeltaTime());

			timer.Reset();

			m_Window->Update();
		}
		Cleanup();
	}
}