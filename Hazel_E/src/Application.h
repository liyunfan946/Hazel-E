#pragma once
#include "core/core.h"
#include "event/Event.h"
#include "event/WindowEvent.h"

namespace Hazel_E
{
    class HAZEL_API Application
    {
    public:
        Application();
        virtual ~Application();
        void Run();
    };

    Application* CreateApplication();
}
