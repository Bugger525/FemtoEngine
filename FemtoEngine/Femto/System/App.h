#pragma once

#include "WindowProperties.h"

namespace Femto
{
	class App
	{
	protected:
		virtual WindowProperties CreateWindow();

		virtual void Initialize() = 0;
		virtual void Update() = 0;
		virtual void Render() = 0;
		virtual void Cleanup() = 0;
	public:
		void Run();
	};
}