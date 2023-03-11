#pragma once

namespace Femto
{
	struct ContextSettings
	{
		unsigned int OpenGLMajorVersion = 3;
		unsigned int OpenGLMinorVersion = 3;
		unsigned int FPS = 30;
		bool Debug = true;
	};
}