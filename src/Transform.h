
#pragma once

#include "common.h"

struct Transform
{
public:
	Vector LocalPosition;
	Vector LocalScale;
	Quat LocalRotation;

	Matrix GetLocalMatrix();
private:
};

