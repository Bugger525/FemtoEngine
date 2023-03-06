#pragma once

#include <string>
#include <format>
#include <source_location>

#define FEMTO_CRITICAL(fmt, ...) Femto::Debug::Critical(std::format(fmt, ##__VA_ARGS__));
#define FEMTO_ERROR(fmt, ...) Femto::Debug::Error(std::format(fmt, ##__VA_ARGS__));
#define FEMTO_WARN(fmt, ...) Femto::Debug::Warn(std::format(fmt, ##__VA_ARGS__));
#define FEMTO_INFO(fmt, ...) Femto::Debug::Info(std::format(fmt, ##__VA_ARGS__));

namespace Femto
{
	class Debug
	{
	private:
		static bool m_Init;

		static void Initialize();
	public:
		Debug() = delete;
		~Debug() = delete;

		static void Critical(std::string_view str, const std::source_location& location = std::source_location::current());
		static void Error(std::string_view str, const std::source_location& location = std::source_location::current());
		static void Warn(std::string_view str, const std::source_location& location = std::source_location::current());
		static void Info(std::string_view str, const std::source_location& location = std::source_location::current());
	private:
		static void __stdcall GLFWDebugOutput(unsigned int source, unsigned int type, unsigned int id, unsigned int severity, int length, const char* message, const void* userParam);
	};
}