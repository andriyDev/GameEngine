
#include "Transform.h"

#include <glm/gtx/transform.hpp>

Matrix Transform::GetLocalMatrix()
{
	return glm::translate(LocalRotation.toMat4() * glm::scale(LocalScale.x, LocalScale.y, LocalScale.z), LocalPosition);
}

