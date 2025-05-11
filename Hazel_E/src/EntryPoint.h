#pragma once
//  定义了Hazel_E引擎的入口点函数。用于创建和运行应用程序。


#ifdef HZ_PLATFORM_WINDOWS

extern Hazel_E::Application* Hazel_E::CreateApplication();

int main(int argc, char** argv) {
    Hazel_E::Log::Init();
    Hazel_E::Log::GetCoreLogger()->info("Hazel_E Engine Started!");
    Hazel_E::Log::GetClientLogger()->info("Hazel_E Client Started!");
    auto app = Hazel_E::CreateApplication();
    app->Run();
    delete app;
    return 0;
}
#endif