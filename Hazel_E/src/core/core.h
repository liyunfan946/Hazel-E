#pragma once

#ifdef HZ_PLATFORM_WINDOWS//这里是windows平台下的宏定义  VS里设置好后就会根据这个宏定义来判断是编译dll还是导入dll
	#ifdef HZ_BUILD_DLL//这里是编译dll
		#define HAZEL_API __declspec(dllexport)// 导出dll
	#else
		#define HAZEL_API __declspec(dllimport)// 导入dll
	#endif
#else
	#error Hazel_E only supports Windows!
#endif
#define BIT(x) (1U << (x))   