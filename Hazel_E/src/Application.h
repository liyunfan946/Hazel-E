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

	Application*  CreateApplication();//���������dll����ں�������dll�е����������������һ��Application��ʵ��



}



