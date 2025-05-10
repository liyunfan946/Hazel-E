#pragma once

namespace Hazel_E
{
	class  _declspec(dllexport) Application
	{
		public:

		Application();
       virtual ~Application();

       void Run();


	};

	Application*  CreateApplication();//这个函数是dll的入口函数，在dll中调用这个函数，返回一个Application的实例



}



