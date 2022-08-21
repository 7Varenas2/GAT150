#pragma once
#include "Resource.h"
#include <cstdarg>
#include <map>
#include <string>
#include <memory>

// vector[#,#,#,#] - > [#,#,#,#,#,#]
// [4] [#,#,#,#]
// list [#] -> [#] -> [#]
// map <key, data>

namespace neum
{
	class ResourceManager
	{
	public:
		ResourceManager() = default;
		~ResourceManager() = default;

		void Initialize();
		void Shutdown();

		template <typename T, typename ... TArgs>
		std::shared_ptr<T> Get(const std::string& name, TArgs ... args);

	private:
		std::map<std::string, std::shared_ptr<Resource>> m_resources;

	};

	template<typename T, typename ... TArgs>
	inline std::shared_ptr<T> ResourceManager::Get(const std::string& name, TArgs ... args)
	{
		if (m_resources.find(name) != m_resources.end())
		{
			// Found
			return std::dynamic_pointer_cast<T>(m_resources[name]);
		}
		else
		{
			// Not found, create resource and neter into resources
			std::shared_ptr<T> resource = std::make_shared<T>();
			resource->Create(name, args...);
			m_resources[name] = resource;

			return resource;
		}

		//return std::shared_ptr<T>();
	}
}