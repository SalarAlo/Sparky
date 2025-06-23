#pragma once

#ifdef SPY_PLATFORM_WINDOWS 

extern Sparky::Application* Sparky::CreateApplication();

int main(int argc, char** argv) {
	Sparky::Log::Init();
	SPY_CORE_WARN("Initialised Log!");
	SPY_INFO("Hello!");

	auto app = Sparky::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif
