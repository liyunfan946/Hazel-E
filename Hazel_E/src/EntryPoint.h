#pragma once
//  定义了Hazel_E引擎的入口点函数。用于创建和运行应用程序。
#ifdef HZ_PLATFORM_WINDOWS



extern Hazel_E::Application* Hazel_E::CreateApplication();
// 它的作用是让​​主程序​​能够创建​​Hazel_E引擎​​的Application对象，
// 而不需要知道具体的实现细节。



int main(int arrc,char** argv) {
	auto app = Hazel_E::CreateApplication(); //从 DLL 获取 Application 对象
	
	app->Run();
	delete app;
	
}
#endif