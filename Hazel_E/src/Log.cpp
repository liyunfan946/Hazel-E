#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"
namespace Hazel_E
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
    std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

   

    void Log::Init()
    { 
        spdlog::set_pattern("%^[%T] %n: %v%$");//设置日志格式为         | [时间] |日志器名称: 日志内容
        s_CoreLogger = spdlog::stdout_color_mt("HAZEL");// 创建一个控制台日志器
        s_CoreLogger->set_level(spdlog::level::trace);//  设置日志等级为trace

        s_ClientLogger = spdlog::stdout_color_mt("EditorAPP");
        s_ClientLogger->set_level(spdlog::level::trace);
    }



}

