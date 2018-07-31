
#include "RenderMesh.h"

RenderMesh::RenderMesh(std::shared_ptr<FullMesh> m)
{
	this->m = m;

	// TODO: Move this?
	Init();
}

void RenderMesh::Init()
{
}

void RenderMesh::Render()
{
	glBindVertexArray(m->VAId);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, m->BaseMesh->buffers[0]);
	glVertexAttribPointer(
	   0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
	   3,                  // size
	   GL_FLOAT,           // type
	   GL_FALSE,           // normalized?
	   0,                  // stride
	   (void*)0            // array buffer offset
	);
	glDrawArrays(GL_TRIANGLES, 0, m->GetVertCount());
	glDisableVertexAttribArray(0);
}

