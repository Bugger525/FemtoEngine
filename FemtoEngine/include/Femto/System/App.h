#pragma once

#include "../Core/Window.h"
#include "../Graphics/GraphicsDevice.h"
#include <memory>

namespace Femto
{
	class App
	{
	protected:
		std::unique_ptr<Window> m_Window;
		std::unique_ptr<GraphicsDevice> m_GraphicsDevice;

		virtual void Initialize() = 0;
		virtual void Update(float dt) = 0;
		virtual void Render(float dt) = 0;
		virtual void Cleanup() = 0;
	public:
		void Run();
	};
}