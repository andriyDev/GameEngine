
#include "Mesh.h"

void Mesh::Init(unsigned int verts)
{
	this->verts = verts;
	glGenBuffers(1, &buffers[0]);
}

void Mesh::BufferVertData(GLfloat* floatData)
{
	glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
	glBufferData(GL_ARRAY_BUFFER, verts * 3 * sizeof(GLfloat), floatData, GL_STATIC_DRAW);
}

FullMesh::FullMesh(std::shared_ptr<Mesh> BaseMesh)
{
	this->BaseMesh = BaseMesh;

	Init();
}

void FullMesh::Init()
{
	glGenVertexArrays(1, &VAId);
	glBindVertexArray(VAId);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, BaseMesh->buffers[0]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
}

std::shared_ptr<Mesh> SpawnPrimitiveQuad()
{
	Mesh* m = new Mesh();
	m->Init(6);
	GLfloat verts[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, 0.5f, 0.0,
		0.5f, -0.5f, 0.0f,
		0.5f, 0.5f, 0.0,
		-0.5f, 0.5f,  0.0f,
		-0.5f, -0.5f, 0.0f,
	};
	m->BufferVertData(verts);
	return std::shared_ptr<Mesh>(m);
}

