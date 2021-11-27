#pragma once

#include "Runtime/stdafx.h"
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Sudou {
	class SUDOU_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
};

// Core log macros
#define SD_CORE_TRACE(...)    ::Sudou::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SD_CORE_INFO(...)     ::Sudou::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SD_CORE_WARN(...)     ::Sudou::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SD_CORE_ERROR(...)    ::Sudou::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SD_CORE_FATAL(...)    ::Sudou::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define SD_TRACE(...)	      ::Sudou::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SD_INFO(...)	      ::Sudou::Log::GetClientLogger()->info(__VA_ARGS__)
#define SD_WARN(...)	      ::Sudou::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SD_ERROR(...)	      ::Sudou::Log::GetClientLogger()->error(__VA_ARGS__)
#define SD_FATAL(...)	      ::Sudou::Log::GetClientLogger()->fatal(__VA_ARGS__)