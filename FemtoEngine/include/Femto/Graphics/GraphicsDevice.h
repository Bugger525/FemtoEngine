#pragma once

#include "Shader.h"
#include "Texture.h"

struct GLFWwindow;

namespace Femto
{
	class Window;

	class GraphicsDevice
	{
	private:
		Window* m_Window;
	public:
		GraphicsDevice();
		GraphicsDevice(Window* window);

		void Clear(const Color& color);
		void Draw(const Shader& shader, const Texture& texture, const Vector2f& position, const Vector2f& size);
	private:
		static void GLFWFrameBufferSizeCallback(GLFWwindow* window, int width, int height);
	};
}