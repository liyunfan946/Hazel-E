#pragma once
#include "core/core.h"

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
