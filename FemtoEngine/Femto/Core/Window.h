#pragma once

#include "WindowProperties.h"
#include "../Graphics/GraphicsDevice.h"

struct GLFWwindow;
struct GLFWmonitor;

namespace Femto
{
	class Window
	{
	private:
		WindowProperties m_Prop;
		GLFWwindow* m_Window;
		GLFWmonitor* m_Monitor;
	public:
		Window(const WindowProperties& prop);
		~Window();

		GLFWwindow* GetRawWindow() const;

		unsigned int GetPosX() const;
		unsigned int GetPosY() const;
		void SetPosX(unsigned int x);
		void SetPosY(unsigned int y);
		void SetPosition(unsigned int x, unsigned int y);

		unsigned int GetWidth() const;
		unsigned int GetHeight() const;
		void SetWidth(unsigned int width);
		void SetHeight(unsigned int height);
		void SetSize(unsigned int width, unsigned int height);

		std::string_view GetTitle() const;
		void SetTitle(std::string_view title);

		void SetFullScreen(bool fullScreen);
		void SetResizable(bool resizable);

		void Close();
		bool IsRunning() const;
		void Update() const;
		void Cleanup();
	private:
		friend void GraphicsDevice::GLFWFrameBufferSizeCallback(GLFWwindow* window, int width, int height);
	};
}