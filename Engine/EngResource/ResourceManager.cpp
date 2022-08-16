#include "ResourceManager.h"

namespace neum {
	void ResourceManager::Initialize()
	{
	}

	void ResourceManager::Shutdown()
	{
		m_resources.clear();
	}
}