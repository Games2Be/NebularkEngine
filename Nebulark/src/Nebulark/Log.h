#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Nebulark
{
	class NEBULARK_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:	
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define NA_CORE_ERROR(...)   ::Nebulark::Log::GetCoreLogger()   ->error(__VA_ARGS__)
#define NA_CORE_WARN(...)    ::Nebulark::Log::GetCoreLogger()   ->warn(__VA_ARGS__)
#define NA_CORE_INFO(...)    ::Nebulark::Log::GetCoreLogger()   ->info(__VA_ARGS__)
#define NA_CORE_TRACE(...)   ::Nebulark::Log::GetCoreLogger()   ->trace(__VA_ARGS__)
#define NA_CORE_FATAL(...)   ::Nebulark::Log::GetCoreLogger()   ->fatal(__VA_ARGS__)

// Client log macros
#define NA_CLIENT_ERROR(...) ::Nebulark::Log::GetClientLogger() ->error(__VA_ARGS__)
#define NA_CLIENT_WARN(...)  ::Nebulark::Log::GetClientLogger() ->warn(__VA_ARGS__)
#define NA_CLIENT_INFO(...)  ::Nebulark::Log::GetClientLogger() ->info(__VA_ARGS__)
#define NA_CLIENT_TRACE(...) ::Nebulark::Log::GetClientLogger() ->trace(__VA_ARGS__)
#define NA_CLIENT_FATAL(...) ::Nebulark::Log::GetClientLogger() ->fatal(__VA_ARGS__)
