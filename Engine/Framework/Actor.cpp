#include "Actor.h"

namespace neum {
	void Actor::Draw(neum::Renderer& renderer)
	{
		m_model.Draw(renderer, m_transform.position, m_transform.rotation, m_transform.scale);
	}
}
