#pragma once

#include <map>
#include <string>
#include <filesystem>
#include <memory>
#include "IAsset.h"
#include "Debug.h"

namespace fs = std::filesystem;

namespace Femto
{
	class Assets
	{
	private:
		std::map<std::string, std::unique_ptr<IAsset>> m_Assets;
	public:
		std::string AssetsPath;

		template <typename T>
		inline T* Load(std::string_view name)
		{
			if (!Exists(name)) return nullptr;
			return static_cast<T*>(m_Assets[std::string(name)].get());
		}
		bool Exists(std::string_view name);
		void Clear();
	};
}