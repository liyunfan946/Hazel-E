#include <Hazel_E.h>
//����ģʽ��CreateApplication()��������һ��Application����  
 
// Sandbox�����ڴ���Application����
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
        return new Sandbox();//��������Ĺ��캯��
    }
}
