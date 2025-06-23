#include "Application.h"

#include "Sparky/Event/Event.h"
#include "Sparky/Event/ApplicationEvent.h"
#include "Sparky/Log.h"

namespace Sparky {
	Application::Application() {
	}

	Application::~Application() {
	}


	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			SPY_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			SPY_TRACE(e);
		}

		while (true);
	} 
}
