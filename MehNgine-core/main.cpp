#include "src/graphics/window.h"
#include "src/maths/vec2.h"

int main()
{
	using namespace mehngine;
	using namespace graphics;
	using namespace maths;

	Window window("Title", 800, 600);
	glClearColor(0.2f, 0.3f, 0.7f, 1.0f);

	GLuint vao; 
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	vec2 vector(1.0f, 2.0f);
	vec2 a(1.0f, 1.0f);
	vector.add(vec2(2.0f, 2.0f));

	vec2 b = vector - a;
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