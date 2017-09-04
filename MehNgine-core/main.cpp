#include "src/graphics/window.h"

int main()
{
	using namespace mehngine;
	using namespace graphics;

	Window window("Title", 800, 600);
	glClearColor(0.2f, 0.3f, 0.7f, 1.0f);

	GLuint vao; 
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	while (!window.closed())
	{
		window.clear();
#if 0
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
#endif
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
		
		double x, y;

		window.getMousePosition(x, y);
		std::cout << x << "," << y << std::endl;
		window.update();
	}
	//system("Pause");
	return 0;
}