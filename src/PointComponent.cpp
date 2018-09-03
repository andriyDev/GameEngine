
#include "PointComponent.h"

Matrix PointComponent::GetWorldMatrix()
{
	PointComponent* p = this;
	Matrix m = Matrix(1.0f);
	while(p)
	{
		m = p->transform.GetLocalMatrix() * m;
		p = p->Parent.get();
	}
	return m;
}

void PointComponent::SetParent(ptr<PointComponent> NewParent)
{
	Parent = NewParent;
}

