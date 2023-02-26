#pragma once

namespace Femto
{
	class Window;

	class GraphicsDevice
	{
	private:
		Window* m_Window;
	public:
		GraphicsDevice(Window* window);
	};
}