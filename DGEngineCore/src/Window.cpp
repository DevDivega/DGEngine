#include "Window.hpp"
#include <iostream>

namespace dge
{

	Window::Window(const std::string& title, const WindowProperties& properties)
		: m_Title(title), m_Properties(properties)
	{
		if (!init())
		{
			std::cout << "INIT ERROR!" << std::endl;
			return;
		}
	}

	Window::Window(const std::string& title)
		: m_Title(title) {
		m_Properties = { 1280, 720, false, false };

		if (!init())
		{
			std::cout << "INIT ERROR!" << std::endl;
			return;
		}
	}

	Window::Window() {
		m_Title = "Test";
		m_Properties = { 1280, 720, false, false };

		if (!init())
		{
			std::cout << "INIT ERROR!" << std::endl;
			return;
		}
	}

	Window::~Window() {
		glfwTerminate();
		m_WindowHandle = nullptr;
	}

	bool Window::init()
	{

		if (!glfwInit()) {
			std::cout << "GLFW INIT ERROR!" << std::endl;
			return false;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		glfwWindowHint(GLFW_RESIZABLE, m_Properties.resizable ? GL_TRUE : GL_FALSE);

		m_WindowHandle = glfwCreateWindow(m_Properties.width, m_Properties.height, m_Title.c_str(), nullptr, nullptr);
		if (!m_WindowHandle)
		{
			std::cout << "GLFW CREATE WINDOW ERROR!" << std::endl;
			glfwTerminate();
			return false;
		}

		glfwMakeContextCurrent(m_WindowHandle);

		glfwSwapInterval(m_Properties.vsync ? 1 : 0);

		//TODO: Move to Renderer Class
		if (glewInit() != GLEW_OK)
			std::cout << "GLEW INIT ERROR!" << std::endl;

		return true;
	}

	void Window::update() const
	{
		glfwSwapBuffers(m_WindowHandle);

		glfwPollEvents();
	}

}
