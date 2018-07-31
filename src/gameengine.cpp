
#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "EngineWindow.h"
#include "EngineInput.h"

using namespace glm;

int main(int argc, char* argv[])
{
	EngineWindow* window = new EngineWindow();
	EngineInput* Inp = new EngineInput();
	if (!window->InitWindow(1280, 720, "OpenGL", NULL))
	{
		return -1;
	}
	Inp->BindToWindow(window);
	Inp->AddBinding("Escape", std::pair<int, int>(GLFW_KEY_F4, GLFW_MOD_ALT));

	do
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window->GetRaw());
		Inp->PollEvents();
	}
	while(!Inp->IsKeyDown("Escape") &&
		glfwWindowShouldClose(window->GetRaw()) == 0);

	return 0;
}

