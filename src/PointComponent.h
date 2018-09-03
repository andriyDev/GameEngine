
#pragma once

#include "common.h"
#include "Transform.h"
#include "Component.h"

class PointComponent : public Component
{
public:
	Transform transform;

	Matrix GetWorldMatrix();



	void SetParent(ptr<PointComponent> NewParent);
private:
	ptr<PointComponent> Parent;
}

