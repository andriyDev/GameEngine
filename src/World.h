
#pragma once

#include <memory>
#include <vector>

#include "common.h"

class World
{
public:
private:
	std::vector<class CameraComponent> Cameras;
	std::vector<class IRenderable> Renderable;
};

