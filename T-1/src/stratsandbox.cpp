#include <Hazel_E.h>
//工厂模式，CreateApplication()函数创建一个Application对象  
 
// Sandbox类用于创建Application对象
namespace Hazel_E
{
    class Sandbox : public Application
    {
    public:
        Sandbox() {}
        ~Sandbox() {}
    };

    Application* CreateApplication()
    {
        return new Sandbox();//返回子类的构造函数
    }
}
