#pragma once

#include "Core/Window.h"
#include "Graphics/GraphicsDevice.h"
#include "Graphics/Shader.h"

namespace Femto
{
	class App
	{
	private:
		Shader m_DefaultShader;
	protected:
		Window m_Window;
		GraphicsDevice m_GraphicsDevice;

		virtual void Initialize() = 0;
		virtual void Update(float dt) = 0;
		virtual void Render(float dt) = 0;
		virtual void Cleanup() = 0;
	public:
		void Run();
	};
}