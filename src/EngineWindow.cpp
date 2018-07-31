
#include "EngineWindow.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

bool EngineWindow::InitWindow(int width, int height, std::string title, GLFWmonitor* fullscreenMonitor)
{
	if(internal_window)
	{
		glfwSetWindowShouldClose(internal_window, GLFW_TRUE);
	}

	glewExperimental = true; // Needed for core profile
	if( !glfwInit() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		return false;
	}
	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL 

	// Open a window and create its OpenGL context
	internal_window = glfwCreateWindow( width, height, title.c_str(), fullscreenMonitor, NULL);
	if( internal_window== NULL ){
		fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(internal_window); // Initialize GLEW
	glewExperimental=true; // Needed in core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return false;
	}
	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(internal_window, GLFW_STICKY_KEYS, GL_TRUE);
	return true;
}

