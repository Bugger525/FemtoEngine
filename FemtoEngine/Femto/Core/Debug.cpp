#include "Debug.h"
#include <iostream>
#include <Windows.h>

namespace Femto
{
	bool Debug::m_Init = false;

	void Debug::Initialize()
	{
		if (m_Init) return;
#ifdef _WIN32
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		DWORD dwMode = NULL;
		GetConsoleMode(hOut, &dwMode);
		dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
		SetConsoleMode(hOut, dwMode);
#endif
		m_Init = true;
	}
	void Debug::Critical(std::string_view str, const std::source_location& location)
	{
		Initialize();
		std::cout << std::format("[\x1b[41mCRITICAL\x1b[0m] {}\nAt {}({}:{}) `{}`\n",
			str,
			location.file_name(),
			location.line(),
			location.column(),
			location.function_name())
			<< std::endl;
	}
	void Debug::Error(std::string_view str, const std::source_location& location)
	{
		Initialize();
		std::cout << std::format("[\x1b[91mERROR\x1b[0m] {}\nAt {}({}:{}) `{}`\n",
			str,
			location.file_name(),
			location.line(),
			location.column(),
			location.function_name())
			<< std::endl;
	}
	void Debug::Warn(std::string_view str, const std::source_location& location)
	{
		Initialize();
		std::cout << std::format("[\x1b[33mWARN\x1b[0m] {}\nAt {}({}:{}) `{}`\n",
			str,
			location.file_name(),
			location.line(),
			location.column(),
			location.function_name())
			<< std::endl;
	}
	void Debug::Info(std::string_view str, const std::source_location& location)
	{
		Initialize();
		std::cout << std::format("[\x1b[94mLOG\x1b[0m] {}\nAt {}({}:{}) `{}`\n",
			str,
			location.file_name(),
			location.line(),
			location.column(),
			location.function_name())
			<< std::endl;
	}
}