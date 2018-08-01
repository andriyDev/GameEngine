
#include "Shader.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

std::shared_ptr<Shader> Shader::LoadFromFile(std::string file_path, GLenum shaderType)
{
	Shader* shader = new Shader();

	GLuint ShaderID = glCreateShader(shaderType);

	std::string ShaderCode;
	std::ifstream ShaderStream(file_path.c_str(), std::ios::in);
	if(ShaderStream.is_open()){
		std::stringstream sstr;
		sstr << ShaderStream.rdbuf();
		ShaderCode = sstr.str();
		ShaderStream.close();
	}else{
		printf("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !\n", file_path.c_str());
		getchar();
		return 0;
	}

	GLint Result = GL_FALSE;
	int InfoLogLength;

	// Compile Vertex Shader
	printf("Compiling shader : %s\n", file_path.c_str());
	char const * SourcePointer = ShaderCode.c_str();
	glShaderSource(ShaderID, 1, &SourcePointer , NULL);
	glCompileShader(ShaderID);

	// Check Vertex Shader
	glGetShaderiv(ShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(ShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if ( InfoLogLength > 0 ){
		std::vector<char> ShaderErrorMessage(InfoLogLength+1);
		glGetShaderInfoLog(ShaderID, InfoLogLength, NULL, &ShaderErrorMessage[0]);
		printf("%s\n", &ShaderErrorMessage[0]);
	}

	shader->GLid = ShaderID;
	return std::shared_ptr<Shader>(shader);
}

