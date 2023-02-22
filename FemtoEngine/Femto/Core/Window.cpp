#include "Window.h"
#include <GLFW/glfw3.h>
#include <Windows.h>

namespace Femto
{
	Window::Window(const WindowProperties& prop) : m_Prop(prop), m_Window(nullptr), m_Monitor(nullptr)
	{
		if (!glfwInit())
		{
			// Debug
			return;
		}
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

		m_Monitor = glfwGetPrimaryMonitor();

		if (m_Prop.FullScreen)
			m_Window = glfwCreateWindow(m_Prop.Width, m_Prop.Height, m_Prop.Title.c_str(), static_cast<GLFWmonitor*>(m_Monitor), nullptr);
		else
			m_Window = glfwCreateWindow(m_Prop.Width, m_Prop.Height, m_Prop.Title.c_str(), nullptr, nullptr);
		if (m_Window == nullptr)
		{
			// Debug
			return;
		}
		glfwSetWindowPos(static_cast<GLFWwindow*>(m_Window), m_Prop.X, m_Prop.Y);
		glfwMakeContextCurrent(static_cast<GLFWwindow*>(m_Window));
		glfwFocusWindow(static_cast<GLFWwindow*>(m_Window));
		glfwSetWindowUserPointer(static_cast<GLFWwindow*>(m_Window), this);

		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		DWORD dwMode = NULL;
		GetConsoleMode(hOut, &dwMode);
		dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
		SetConsoleMode(hOut, dwMode);
	}
	Window::~Window()
	{
		Cleanup();
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
		glfwSetWindowPos(static_cast<GLFWwindow*>(m_Window), m_Prop.X, m_Prop.Y);
	}
	void Window::SetPosY(unsigned int y)
	{
		m_Prop.Y = y;
		glfwSetWindowPos(static_cast<GLFWwindow*>(m_Window), m_Prop.X, m_Prop.Y);
	}
	void Window::SetPosition(unsigned int x, unsigned int y)
	{
		m_Prop.X = x;
		m_Prop.Y = y;
		glfwSetWindowPos(static_cast<GLFWwindow*>(m_Window), m_Prop.X, m_Prop.Y);
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
		m_Prop.Width = width;
		glfwSetWindowSize(static_cast<GLFWwindow*>(m_Window), m_Prop.Width, m_Prop.Height);
	}
	void Window::SetHeight(unsigned int height)
	{
		m_Prop.Height = height;
		glfwSetWindowSize(static_cast<GLFWwindow*>(m_Window), m_Prop.Width, m_Prop.Height);
	}
	void Window::SetSize(unsigned int width, unsigned int height)
	{
		m_Prop.Width = width;
		m_Prop.Height = height;
		glfwSetWindowSize(static_cast<GLFWwindow*>(m_Window), m_Prop.Width, m_Prop.Height);
	}
	std::string_view Window::GetTitle() const
	{
		return m_Prop.Title;
	}
	void Window::SetTitle(std::string_view title)
	{
		m_Prop.Title = title;
		glfwSetWindowTitle(static_cast<GLFWwindow*>(m_Window), m_Prop.Title.c_str());
	}
	void Window::SetFullScreen(bool fullScreen)
	{
		m_Prop.FullScreen = fullScreen;
	}
	void Window::SetResizable(bool resizable)
	{
		m_Prop.Resizable = resizable;
	}
	void Window::Close()
	{
		glfwSetWindowShouldClose(static_cast<GLFWwindow*>(m_Window), true);
	}
	bool Window::IsRunning()
	{
		return !glfwWindowShouldClose(static_cast<GLFWwindow*>(m_Window));
	}
	void Window::Update()
	{
		glfwSwapBuffers(static_cast<GLFWwindow*>(m_Window));
		glfwPollEvents();
	}
	void Window::Cleanup()
	{
		if (m_Window)
		{
			glfwDestroyWindow(static_cast<GLFWwindow*>(m_Window));
			glfwTerminate();
		}
	}
}