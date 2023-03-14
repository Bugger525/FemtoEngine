#pragma once

#include "../Core/Window.h"
#include "../Graphics/GraphicsDevice.h"
#include "../Graphics/Shader.h"
#include "../Core/ContextSettings.h"
#include "../Core/Assets.h"
#include <memory>

namespace Femto
{
	class App
	{
	private:
		ContextSettings m_ContextSettings;
	public:
		void Run();
	protected:
		std::unique_ptr<Window> m_Window;
		std::unique_ptr<GraphicsDevice> m_GraphicsDevice;

		virtual ContextSettings SetupContext();
		virtual void Initialize() = 0;
		virtual void Update(float dt) = 0;
		virtual void Render(float dt) = 0;
		virtual void Cleanup() = 0;
	};
}