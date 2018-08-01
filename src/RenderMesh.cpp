
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
	glDrawArrays(GL_TRIANGLES, 0, m->GetVertCount());
}

