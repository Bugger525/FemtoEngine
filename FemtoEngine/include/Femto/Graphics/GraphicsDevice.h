#pragma once

#include "Color.h"
#include <string>
#include <utility>
#include "../Core/ContextSettings.h"

struct GLFWwindow;

namespace Femto
{
	class Window;

	class GraphicsDevice
	{
	private:
		Window* m_Window;
		std::pair<unsigned int, unsigned int> m_Version;
	public:
		GraphicsDevice();
		GraphicsDevice(Window* window, const ContextSettings& contextSettings);

		void Clear(const Color& color);

		std::string_view GetHardwareInfo() const;
		const std::pair<unsigned int, unsigned int>& GetGLVersion() const;
	private:
		static void GLFWFrameBufferSizeCallback(GLFWwindow* window, int width, int height);
	};
}