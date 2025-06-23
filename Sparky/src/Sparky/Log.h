#pragma once

#include <memory>

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

#include "Core.h"

namespace Sparky {
	class Log {
	public:
		SPARKY_API static void Init();
		SPARKY_API inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
		SPARKY_API inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// CORE LOGGER MACROS
#define SPY_CORE_TRACE(...)      ::Sparky::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SPY_CORE_INFO(...)       ::Sparky::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SPY_CORE_ERROR(...)      ::Sparky::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SPY_CORE_WARN(...)       ::Sparky::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SPY_CORE_CRITICAL(...)   ::Sparky::Log::GetCoreLogger()->critical(__VA_ARGS__)

// CLIENT LOGGER MACROS
#define SPY_TRACE(...)           ::Sparky::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SPY_INFO(...)            ::Sparky::Log::GetClientLogger()->info(__VA_ARGS__)
#define SPY_ERROR(...)           ::Sparky::Log::GetClientLogger()->error(__VA_ARGS__)
#define SPY_WARN(...)            ::Sparky::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SPY_CRITICAL(...)        ::Sparky::Log::GetClientLogger()->critical(__VA_ARGS__)
