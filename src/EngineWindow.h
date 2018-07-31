
#pragma once

#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class EngineWindow
{
public:
	bool InitWindow(int width, int height, std::string title, GLFWmonitor* fullscreenMonitor);

	GLFWwindow* GetRaw() { return internal_window; }

private:
	GLFWwindow* internal_window;

};

