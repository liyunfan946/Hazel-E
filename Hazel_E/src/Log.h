#pragma once

#include <memory>
#include "core/core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Hazel_E
{
    class HAZEL_API Log
    {
    public:
        static void Init();
        static std::shared_ptr<spdlog::logger>& GetCoreLogger();
        static std::shared_ptr<spdlog::logger>& GetClientLogger();

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };

    // Static member function implementations
    inline std::shared_ptr<spdlog::logger>& Log::GetCoreLogger() { return s_CoreLogger; }
    inline std::shared_ptr<spdlog::logger>& Log::GetClientLogger() { return s_ClientLogger; }
}

// Core logging macros
#define HAZEL_CORE_ERROR(...)       ::Hazel_E::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HAZEL_CORE_WARN(...)        ::Hazel_E::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HAZEL_CORE_INFO(...)        ::Hazel_E::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HAZEL_CORE_TRACE(...)       ::Hazel_E::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HZ_TRACE(...)               ::Hazel_E::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Client logging macros
#define HAZEL_ERROR(...)            ::Hazel_E::Log::GetClientLogger()->error(__VA_ARGS__)
#define HAZEL_WARN(...)             ::Hazel_E::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HAZEL_INFO(...)             ::Hazel_E::Log::GetClientLogger()->info(__VA_ARGS__)
#define HAZEL_TRACE(...)            ::Hazel_E::Log::GetClientLogger()->trace(__VA_ARGS__)