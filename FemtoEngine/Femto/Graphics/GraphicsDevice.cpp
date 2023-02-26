#include "GraphicsDevice.h"
#include "../Core/Window.h"
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

	}
}