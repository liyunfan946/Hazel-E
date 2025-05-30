#include "Application.h"
#include "Log.h"

namespace Hazel_E
{ 

    Application::Application()
    {
        
    }

    Application::~Application()
    {
        
    }

    void Application::Run()
    {
        Hazel_E::WindowResizeEvent event(1280, 720);
        HZ_TRACE("Window resize event: {}", event.ToString());

        if (event.IsInCategory( Hazel_E::EventCategoryApplication)) {
            HZ_TRACE("Event is in application category");
        }
        if (event.IsInCategory( Hazel_E::EventCategoryInput)) {
            HZ_TRACE("Event is in input category");
        }

        while (true)
        {
            
        }
    }

}
