#pragma once

#include <string>

namespace Femto
{
	struct WindowProperties
	{
		std::string Title{ "FemtoEngine Game" };
		unsigned int Width{ 800 }, Height{ 600 };
		unsigned int X{ 0 }, Y{ 0 };
		bool FullScreen{ false };
		bool Resizable{ true };
	};
}