#include "DGEngine.hpp"

using namespace dge;

class Application : public IGame {

public:
	Application()
	{

	}

	~Application()
	{

	}

	void init() override {

	}

	void input() override {
	
	}
	
	void update(double dt) override {

	}

	void render(double alpha) override {

	}

};


int main(void)
{
	Engine engine = { new Application(), "Test Title", { 800, 600, false, false } };
	engine.start();

	return 0;
}
