#include <Hazel_E.h>

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
        return new Sandbox();
    }
}
