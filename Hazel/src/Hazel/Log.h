#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Hazel {
	class HAZEL_API Log
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

//Core log macros
#define HZ_CORE_TRACE(...)   ::HAZEL::Log::GetCoreLogger()->trace(_VA_ARGS_)
#define HZ_CORE_INFO(...)    ::HAZEL::Log::GetCoreLogger()->info(_VA_ARGS_)
#define HZ_CORE_WARN(...)    ::HAZEL::Log::GetCoreLogger()->warn(_VA_ARGS_)
#define HZ_CORE_ERROR(...)   ::HAZEL::Log::GetCoreLogger()->error(_VA_ARGS_)
#define HZ_CORE_FATAL(...)   ::HAZEL::Log::GetCoreLogger()->fatal(_VA_ARGS_)

// Client log macros
#define HZ_TRACE(...)        ::HAZEL::Log::GetClientLogger()->trace(_VA_ARGS_)
#define HZ_INFO(...)         ::HAZEL::Log::GetClientLogger()->info(_VA_ARGS_)
#define HZ_WARN(...)         ::HAZEL::Log::GetClientLogger()->warn(_VA_ARGS_)
#define HZ_ERROR(...)        ::HAZEL::Log::GetClientLogger()->error(_VA_ARGS_)
#define HZ_FATAL(...)        ::HAZEL::Log::GetClientLogger()->fatal(_VA_ARGS_)