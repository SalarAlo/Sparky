#pragma once

#ifdef SPY_PLATFORM_WINDOWS 
extern Sparky::Application* Sparky::CreateApplication();

int main(int argc, char** argv) {
	auto app = Sparky::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif
