#include "Window.h"
#include <GLFW/glfw3.h>
#include "Debug.h"

namespace Femto
{
	Window::Window(const WindowProperties& prop) : m_Prop(prop), m_Window(nullptr), m_Monitor(nullptr)
	{
		if (!glfwInit())
		{
			Debug::Critical("Femto::Core::Window error; Failed to initialize GLFW.");
			return;
		}
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

		m_Monitor = glfwGetPrimaryMonitor();

		if (m_Prop.FullScreen)
			m_Window = glfwCreateWindow(m_Prop.Width, m_Prop.Height, m_Prop.Title.c_str(), m_Monitor, nullptr);
		else
			m_Window = glfwCreateWindow(m_Prop.Width, m_Prop.Height, m_Prop.Title.c_str(), nullptr, nullptr);
		if (m_Window == nullptr)
		{
			Debug::Critical("Femto::Core::Window error; Failed to create GLFWwindow.");
			return;
		}
		glfwSetWindowPos(m_Window, m_Prop.X, m_Prop.Y);

		glfwMakeContextCurrent(m_Window);

		glfwFocusWindow(m_Window);

		glfwSetWindowUserPointer(m_Window, this);
	}
	Window::~Window()
	{
		Cleanup();
	}
	void* Window::GetRawWindow() const
	{
		return m_Window;
	}
	unsigned int Window::GetPosX() const
	{
		return m_Prop.X;
	}
	unsigned int Window::GetPosY() const
	{
		return m_Prop.Y;
	}
	void Window::SetPosX(unsigned int x)
	{
		m_Prop.X = x;
		glfwSetWindowPos(m_Window, m_Prop.X, m_Prop.Y);
	}
	void Window::SetPosY(unsigned int y)
	{
		m_Prop.Y = y;
		glfwSetWindowPos(m_Window, m_Prop.X, m_Prop.Y);
	}
	void Window::SetPosition(unsigned int x, unsigned int y)
	{
		m_Prop.X = x;
		m_Prop.Y = y;
		glfwSetWindowPos(m_Window, m_Prop.X, m_Prop.Y);
	}
	unsigned int Window::GetWidth() const
	{
		return m_Prop.Width;
	}
	unsigned int Window::GetHeight() const
	{
		return m_Prop.Height;
	}
	void Window::SetWidth(unsigned int width)
	{
		if (m_Prop.Width == width) return;

		m_Prop.Width = width;
		glfwSetWindowSize(m_Window, m_Prop.Width, m_Prop.Height);
	}
	void Window::SetHeight(unsigned int height)
	{
		if (m_Prop.Height == height) return;

		m_Prop.Height = height;
		glfwSetWindowSize(m_Window, m_Prop.Width, m_Prop.Height);
	}
	void Window::SetSize(unsigned int width, unsigned int height)
	{
		if (m_Prop.Width != width)
			m_Prop.Width = width;

		if (m_Prop.Height != height)
			m_Prop.Height = height;

		if (m_Prop.Width != width || m_Prop.Height != height)
			glfwSetWindowSize(m_Window, m_Prop.Width, m_Prop.Height);
	}
	std::string_view Window::GetTitle() const
	{
		return m_Prop.Title;
	}
	void Window::SetTitle(std::string_view title)
	{
		if (m_Prop.Title == title) return;

		m_Prop.Title = title;
		glfwSetWindowTitle(m_Window, m_Prop.Title.c_str());
	}
	void Window::SetFullScreen(bool fullScreen)
	{
		if (m_Prop.FullScreen == fullScreen) return;

		m_Prop.FullScreen = fullScreen;
		if (m_Prop.FullScreen)
		{
			const GLFWvidmode* mode = glfwGetVideoMode(m_Monitor);
			glfwSetWindowMonitor(m_Window, m_Monitor, 0, 0, mode->width, mode->height, 0);
		}
		else
		{
			glfwSetWindowMonitor(m_Window, nullptr, m_Prop.X, m_Prop.Y, m_Prop.Width, m_Prop.Height, 0);
			SetResizable(true);
		}
	}
	void Window::SetResizable(bool resizable)
	{
		if (m_Prop.Resizable == resizable) return;

		m_Prop.Resizable = resizable;
		if (m_Prop.Resizable)
			glfwSetWindowAttrib(m_Window, GLFW_RESIZABLE, GLFW_TRUE);
		else
			glfwSetWindowAttrib(m_Window, GLFW_RESIZABLE, GLFW_FALSE);
	}
	void Window::Close()
	{
		glfwSetWindowShouldClose(m_Window, true);
	}
	bool Window::IsRunning() const
	{
		return !glfwWindowShouldClose(m_Window);
	}
	void Window::Update() const
	{
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}
	void Window::Cleanup()
	{
		if (m_Window)
		{
			glfwDestroyWindow(m_Window);
			glfwTerminate();
		}
	}
}