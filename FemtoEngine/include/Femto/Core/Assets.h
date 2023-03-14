#pragma once

#include <map>
#include <string>
#include <memory>

namespace Femto
{
	class Assets
	{
	private:
		template <typename T>
		static std::map<std::string, std::unique_ptr<T>> m_Assets;
	public:
		static void Load(std::string_view assetsPath);
		template <typename T>
		static T* Get(std::string_view name);
		template <typename T>
		static bool Exists(std::string_view name);
		template <typename T>
		static void Clear();
	private:
		static std::string_view ReadAssets(std::string_view assetsPath);
	};
}
#include "Assets.inl"