#pragma once

#ifdef HZ_PLATFORM_WINDOWS//������windowsƽ̨�µĺ궨��  VS�����úú�ͻ��������궨�����ж��Ǳ���dll���ǵ���dll
	#ifdef HZ_BUILD_DLL//�����Ǳ���dll
		#define HAZEL_API __declspec(dllexport)// ����dll
	#else
		#define HAZEL_API __declspec(dllimport)// ����dll
	#endif
#else
	#error Hazel_E only supports Windows!
#endif