#include <Sparky.h>

class Sandbox : public Sparky::Application {
public:
	Sandbox() {
	}
	~Sandbox() {
	}
};

Sparky::Application* Sparky::CreateApplication() {
	return new Sandbox();
}