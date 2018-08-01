
#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Shader.h"

class Material
{
public:
	Material(std::shared_ptr<Shader> VertexShader, std::shared_ptr<Shader> FragmentShader);

	void Init();

	void Use();
private:
	GLuint ProgramID;

	std::shared_ptr<Shader> VertexShader;
	std::shared_ptr<Shader> FragmentShader;
};

