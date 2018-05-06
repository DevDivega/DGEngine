#ifndef DGENGINE_ENGINE_HPP
#define DGENGINE_ENGINE_HPP

#include "Common.hpp"

#include "Window.hpp"
#include "Interfaces\IGame.hpp"

#include <string>

namespace dge {

	enum class DGE_API EngineState {
		INVALID, INITIALIZING, RUNNING
	};

	class DGE_API Engine {

	private:
		EngineState m_EngineState = EngineState::INVALID;
		IGame* m_Game;
		uint m_FPS;
		uint m_UPS;
		std::string m_Title;
		Window* m_Window;
		WindowProperties m_windowProperties;

	public:
		Engine(IGame* game, const std::string& title, const WindowProperties& properties);
		~Engine();

		void start();
		void stop();
		

	protected:
		void init();

	private:
		void run();
		void update(const double dt);
		void render(const double alpha);
		bool shutdown();

	};

}

#endif // !DGENGINE_ENGINE_HPP

