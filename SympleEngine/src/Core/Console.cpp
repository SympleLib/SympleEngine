#include "syegpch.h"
#include "Console.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace Symple
{
	std::shared_ptr<spdlog::logger> Console::sCoreLogger;
	std::shared_ptr<spdlog::logger> Console::sProgramLogger;

	void Console::Initialize()
	{
		spdlog::set_pattern("%^[%l](%T) %n: %v%$");
		sCoreLogger = spdlog::stdout_color_mt("Symple");
		sCoreLogger->set_level(spdlog::level::trace);
		sProgramLogger = spdlog::stdout_color_mt("Program");
		sProgramLogger->set_level(spdlog::level::trace);
	}
}