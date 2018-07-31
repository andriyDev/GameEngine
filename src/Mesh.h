
#pragma once

#include <memory>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Mesh
{
public:
	void Init(unsigned int verts);
	void BufferVertData(GLfloat* floatData);

	unsigned int GetVertCount() { return verts; }
private:
public:
	GLuint buffers[1];
	unsigned int verts;

	friend class FullMesh;
};

class FullMesh
{
public:
	FullMesh(std::shared_ptr<Mesh> BaseMesh);

	void Init();

	unsigned int GetVertCount() { return BaseMesh->GetVertCount(); }
private:
public:
	std::shared_ptr<Mesh> BaseMesh;

	GLuint VAId;

	friend class RenderMesh;
};

std::shared_ptr<Mesh> SpawnPrimitiveQuad();

