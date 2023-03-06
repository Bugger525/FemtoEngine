#pragma once

struct GLFWwindow;

namespace Femto
{
	class Window;

	class GraphicsDevice
	{
	private:
		Window* m_Window;
	public:
		GraphicsDevice(Window* window);

		void Clear(/* color */);
		void Draw(/* args */);
	private:
		static void GLFWFrameBufferSizeCallback(GLFWwindow* window, int width, int height);
	};
}