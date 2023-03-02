#pragma once

#include <string>
#include "../System/Vector2.h"
#include "../Graphics/GraphicsDevice.h"

struct GLFWwindow;
struct GLFWmonitor;

namespace Femto
{
	class Window
	{
	private:
		Vector2u m_Position;
		Vector2u m_Size;
		std::string m_Title;

		bool m_FullScreen;
		bool m_Resizable;

		GLFWwindow* m_Window;
		GLFWmonitor* m_Monitor;
	public:
		Window();
		~Window();

		GLFWwindow* GetRawWindow() const;

		Vector2u GetPosition() const;
		void SetPosX(unsigned int x);
		void SetPosY(unsigned int y);
		void SetPosition(unsigned int x, unsigned int y);

		Vector2u GetSize() const;
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
		static void GLFWSizeCallback(GLFWwindow* window, int width, int height);
	};
}