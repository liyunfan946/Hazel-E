#pragma once

#include <memory>
#include "core/core.h"
#include "spdlog/spdlog.h"

namespace Hazel_E
{
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
#define HAZEL_CORE_ERROR(...)       ::Hazel_E::Log::GetCoreLogger()->error(__VA_ARGS__)//ʹ�ú궨���Ա������־   ��ǰ���::��ʾ��ȷ����ȫ�ֵ�Hazel_E������
#define HAZEL_CORE_WARN(...)        ::Hazel_E::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HAZEL_CORE_INFO(...)        ::Hazel_E::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HAZEL_CORE_TRACE(...)       ::Hazel_E::Log::GetCoreLogger()->trace(__VA_ARGS__)

#define HAZEL_ERROR(...)            ::Hazel_E::Log::GetClientLogger()->error(__VA_ARGS__)//�ͻ�����־��
#define HAZEL_WARN(...)             ::Hazel_E::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HAZEL_INFO(...)             ::Hazel_E::Log::GetClientLogger()->info(__VA_ARGS__)
#define HAZEL_TRACE(...)            ::Hazel_E::Log::GetClientLogger()->trace(__VA_ARGS__)