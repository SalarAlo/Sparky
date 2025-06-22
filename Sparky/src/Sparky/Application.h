#pragma once

#include "Core.h"

namespace Sparky {
	class SPARKY_API Application 
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client
	Application* CreateApplication();
}

