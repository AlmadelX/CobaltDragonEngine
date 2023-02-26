#include "cdepch.h"
#include "Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace CDE {

	void Log::Init()
	{
		spdlog::set_pattern("%^%T %n: %v%$");
		spdlog::set_level(spdlog::level::trace);

		s_CoreLogger = spdlog::stdout_color_mt("ENGINE");
		s_ClientLogger = spdlog::stdout_color_mt("APP");
	}

	Log::Logger Log::s_CoreLogger;
	Log::Logger Log::s_ClientLogger;

}
