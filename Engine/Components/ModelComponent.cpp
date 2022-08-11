#include "ModelComponent.h"
#include "../Framework/Actor.h"

namespace neum
{
	void ModelComponent::Update()
	{

	}


	void ModelComponent::Draw(Renderer& renderer)
	{
		m_model->Draw(renderer, Component::m_owner->m_transform);
	}

}