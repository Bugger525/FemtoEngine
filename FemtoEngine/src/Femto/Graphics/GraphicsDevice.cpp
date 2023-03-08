#include "Graphics/GraphicsDevice.h"
#include "Core/Window.h"
#include "Core/Debug.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

extern "C"
{
	__declspec(dllexport) unsigned long NvOptimusEnablement = 1;
	__declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;
}

namespace Femto
{
	GraphicsDevice::GraphicsDevice(Window* window) : m_Window(window)
	{
		if (glewInit() != GLEW_OK)
		{
			Debug::Critical("Femto::Graphics::GraphicsDevice; Failed to initialized GLEW.");
			return;
		}
		glfwSetFramebufferSizeCallback(m_Window->GetRawWindow(), GLFWFrameBufferSizeCallback);
	}
	void GraphicsDevice::Clear(const Color& color)
	{
		glClearColor(static_cast<float>(color.R), static_cast<float>(color.G), static_cast<float>(color.B), static_cast<float>(color.A));
		glClear(GL_COLOR_BUFFER_BIT); // Advanced?
	}
	void GraphicsDevice::GLFWFrameBufferSizeCallback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
}