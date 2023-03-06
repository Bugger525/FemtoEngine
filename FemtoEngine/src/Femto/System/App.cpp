#include "System/App.h"
#include "System/Timer.h"

namespace Femto
{
	void App::Run()
	{
		std::string_view vertexShaderCode;
		std::string_view fragmentShaderCode;

		m_Shader.Attach(vertexShaderCode, ShaderType::Vertex);
		m_Shader.Attach(fragmentShaderCode, ShaderType::Fragment);

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