#include <Hazel_E.h>


class Sandbox : public Hazel_E::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Hazel_E::Application* Hazel_E::CreateApplication()
{
	return new Sandbox();
}
