#pragma once

#include <spdlog/spdlog.h>

#include "Core.h"

namespace Symple
{
	class SYMPLE_API Console
	{
	public:
		static void Initialize();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return sCoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetProgramLogger() { return sProgramLogger; }
	private:
		static std::shared_ptr<spdlog::logger> sCoreLogger;
		static std::shared_ptr<spdlog::logger> sProgramLogger;
	};
}

#define SY_CORE_TRACE(...) ::Symple::Console::GetCoreLogger()->trace(__VA_ARGS__)
#define SY_CORE_INFO(...) ::Symple::Console::GetCoreLogger()->info(__VA_ARGS__)
#define SY_CORE_DEBUG(...) ::Symple::Console::GetCoreLogger()->debug(__VA_ARGS__)
#define SY_CORE_WARN(...) ::Symple::Console::GetCoreLogger()->warn(__VA_ARGS__)
#define SY_CORE_ERROR(...) ::Symple::Console::GetCoreLogger()->error(__VA_ARGS__)
#define SY_CORE_FATAL(...) ::Symple::Console::GetCoreLogger()->critical(__VA_ARGS__)

#define SY_TRACE(...) ::Symple::Console::GetProgramLogger()->trace(__VA_ARGS__)
#define SY_DEBUG(...) ::Symple::Console::GetProgramLogger()->debug(__VA_ARGS__)
#define SY_INFO(...) ::Symple::Console::GetProgramLogger()->info(__VA_ARGS__)
#define SY_WARN(...) ::Symple::Console::GetProgramLogger()->warn(__VA_ARGS__)
#define SY_ERROR(...) ::Symple::Console::GetProgramLogger()->error(__VA_ARGS__)
#define SY_FATAL(...) ::Symple::Console::GetProgramLogger()->critical(__VA_ARGS__)