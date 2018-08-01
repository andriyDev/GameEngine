
#pragma once

#include <string>
#include <memory>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Shader
{
public:
	static std::shared_ptr<Shader> LoadFromFile(std::string file_path, GLenum shaderType);

private:
	GLuint GLid;

	friend class Material;
};

