#include "window.h"


namespace mehngine
{
	namespace graphics
	{
		/*
		bool Window::m_Keys[MAX_KEYS];
		bool Window::m_MouseButtons[MAX_BUTTONS];
		double Window::mx;
		double Window::my; */
		void windowResize(GLFWwindow *window, int width, int height);

		Window::Window(const char* title, int width, int height)
		{
			m_Title = title;
			m_Width = width;
			m_Height = height;
			if (!init())
			{
				glfwTerminate();
			}

			for (int i = 0; i < MAX_KEYS; i++)
			{
				m_Keys[i] = false;
			}
			for (int i = 0; i < MAX_BUTTONS; i++)
			{
				m_MouseButtons[i] = false;
			}
		}

		Window::~Window()
		{
			glfwTerminate();
		}

		bool Window::init()
		{
			if (!glfwInit())
			{
				std::cout << "Failed to initialize GLFW" << std::endl;
				return false;
			}

			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);

			if (!m_Window)
			{
				std::cout << "Failed to create Window" << std::endl;
				return false;
			}

			glfwMakeContextCurrent(m_Window);
			glfwSetWindowUserPointer(m_Window, this);
			glfwSetWindowSizeCallback(m_Window, windowResize);
			glfwSetKeyCallback(m_Window, key_callback);
			glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
			glfwSetCursorPosCallback(m_Window, cursor_position_callback);

			if (glewInit() != GLEW_OK)
			{
				std::cout << "Could not initialize GLEW" << std::endl;
				return false;
			}

			std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;

			return true;
		}

		bool Window::isKeyPressed(unsigned int keycode)
		{
			//LOG this!
			if (keycode >= MAX_KEYS)
			{
				return false;
			}
			return m_Keys[keycode];
		}
		bool Window::isMouseButtonPressed(unsigned int button)
		{
			//LOG this!
			if (button >= MAX_BUTTONS)
			{
				return false;
			}
			return m_MouseButtons[button];
		}
		void Window::getMousePosition(double &x, double &y)
		{
			x = mx;
			y = my;
		}

		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::update()
		{
			glfwPollEvents();
			glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
			glfwSwapBuffers(m_Window);
		}

		bool Window::closed() const
		{
			return glfwWindowShouldClose(m_Window) == 1;
		}

		void windowResize(GLFWwindow *window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}

		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_Keys[key] = action != GLFW_RELEASE;
		}
		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_MouseButtons[button] = action != GLFW_RELEASE;
		}
		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->mx = xpos;
			win->my = ypos;
		}
	}
}