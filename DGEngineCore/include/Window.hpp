#ifndef DGENGINE_WINDOW_HPP
#define DGENGINE_WINDOW_HPP

#include "Common.hpp"

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <string>

namespace dge
{

	struct DGE_API WindowProperties
	{
		uint width, height;
		bool resizable;
		bool vsync;
	};

	class DGE_API Window
	{

	private:
		std::string m_Title;
		WindowProperties m_Properties;
		GLFWwindow* m_WindowHandle;

	public:
		Window(const std::string& title, const WindowProperties& properties);
		Window(const std::string& title);
		Window();
		~Window();
		void update() const;

		inline uint getWidth() const { return m_Properties.width; }
		inline uint getHeight() const { return m_Properties.height; }
		inline std::string getTitle() const { return m_Title; }
		inline int shouldClose() const { return glfwWindowShouldClose(m_WindowHandle); }
		//		inline GLFWwindow* getHandle() const { return m_WindowHandle; }

	private:
		bool init();

	};

}

#endif
