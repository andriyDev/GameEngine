
#include "Material.h"

#include <vector>

Material::Material(std::shared_ptr<Shader> VertexShader, std::shared_ptr<Shader> FragmentShader)
{
	this->VertexShader = VertexShader;
	this->FragmentShader = FragmentShader;

	Init();
}

void Material::Init()
{
	GLint Result = GL_FALSE;
	int InfoLogLength;

	ProgramID = glCreateProgram();
	glAttachShader(ProgramID, VertexShader->GLid);
	glAttachShader(ProgramID, FragmentShader->GLid);
	glLinkProgram(ProgramID);

	// Check the program
	glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
	glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if ( InfoLogLength > 0 ){
		std::vector<char> ProgramErrorMessage(InfoLogLength+1);
		glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
		printf("%s\n", &ProgramErrorMessage[0]);
	}
	glDetachShader(ProgramID, VertexShader->GLid);
	glDetachShader(ProgramID, FragmentShader->GLid);
}

void Material::Use()
{
	glUseProgram(ProgramID);
}

