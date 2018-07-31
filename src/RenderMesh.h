
#pragma once

#include <memory>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Renderable.h"
#include "Mesh.h"

class RenderMesh : public IRenderable
{
public:
	RenderMesh(std::shared_ptr<FullMesh> m);

	void Init();

	virtual void Render() override;
private:
	std::shared_ptr<FullMesh> m;

	GLuint VAId;
};

