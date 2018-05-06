#include "Engine.hpp"

#include <iostream>

namespace dge {

	Engine::Engine(IGame* game, const std::string& title, const WindowProperties& properties)
		: m_Title(title), m_windowProperties(properties)
	{
		m_Game = game;
		m_Window = new Window(m_Title, m_windowProperties);
	}

	Engine::~Engine() {
		delete m_Game;
		delete m_Window;
	}

	void Engine::start() {
		if (m_EngineState == EngineState::RUNNING)
			return;

		run();
	}

	void Engine::stop() {
		if (m_EngineState == EngineState::INVALID)
			return;

		m_EngineState = EngineState::INVALID;
	}

	void Engine::init() {
		m_EngineState = EngineState::INITIALIZING;

		m_Game->init();
		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	}

	void Engine::run() {

		init();

		m_EngineState = EngineState::RUNNING;

		const double frameCap = 100.0;
		const double dt = 1.0 / frameCap;
		double accumulator = 0;

		double startTime = glfwGetTime();
		double timer = startTime;

		uint frames = 0, updates = 0;

		while (m_EngineState == EngineState::RUNNING) {

			const double currentTime = glfwGetTime();

			accumulator += currentTime - startTime;

			startTime = currentTime;

			if (accumulator > 0.2f)
				accumulator = 0.2f;

			while (accumulator > dt) {

				if (m_Window->shouldClose())
					stop();

				update(dt);
				updates++;
				accumulator -= dt;
			}

			const double alpha = accumulator / dt;

			render(alpha);
			frames++;

			if (glfwGetTime() - timer > 1.0) {
				timer++;
				m_UPS = updates;
				m_FPS = frames;
				updates = 0;
				frames = 0;
				std::cout << "FPS: " << m_FPS << " UPS: " << m_UPS << std::endl;
			}

		}
	}

	void Engine::update(const double dt) {
		m_Game->update(dt);
	}

	void Engine::render(const double alpha) {
		m_Game->render(alpha);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		m_Window->update();
	}

	bool Engine::shutdown() {
		return true;
	}

}