
#include <iostream>
#include <sstream>
#include <fstream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "EngineWindow.h"
#include "EngineInput.h"

#include "RenderMesh.h"
#include "Mesh.h"
#include "Shader.h"
#include "Material.h"

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

	std::shared_ptr<RenderMesh> mesh(new RenderMesh(std::shared_ptr<FullMesh>(new FullMesh(SpawnPrimitiveQuad()))));
	
	std::shared_ptr<Shader> VertexShader(Shader::LoadFromFile("../res/v.v", GL_VERTEX_SHADER));
	std::shared_ptr<Shader> FragmentShader(Shader::LoadFromFile("../res/f.f", GL_FRAGMENT_SHADER));

	std::shared_ptr<Material> Mat(new Material(VertexShader, FragmentShader));
	Mat->Use();

	do
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		mesh->Render();

		glfwSwapBuffers(window->GetRaw());
		Inp->PollEvents();
	}
	while(!Inp->IsKeyDown("Escape") &&
		glfwWindowShouldClose(window->GetRaw()) == 0);

	return 0;
}

