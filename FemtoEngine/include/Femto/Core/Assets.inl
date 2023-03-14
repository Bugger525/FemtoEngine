#include "Assets.h"
#include "Debug.h"
#include <rapidjson/document.h>
#include <fstream>
#include <sstream>
#include <Graphics/Texture.h>

using namespace rapidjson;

namespace Femto
{
	template <typename T>
	std::map<std::string, std::unique_ptr<T>> Assets::m_Assets;

	void Assets::Load(std::string_view assetsPath)
	{
		Document doc;
		doc.Parse(ReadAssets(assetsPath).data());

		if (!doc.HasMember("assets"))
		{
			Debug::Error("Femto::Core::Assets; Failed to bring assets data.");
			return;
		}
		if (!doc["assets"].IsArray())
		{
			Debug::Error("Femto::Core::Assets; data `assets` is not array.");
			return;
		}
		for (auto& object : doc["assets"].GetArray())
		{
			int type = object["type"].GetInt();

			switch (type)
			{
			case 1:
				Texture
			}
		}

	}
	template<typename T>
	T* Assets::Get(std::string_view name)
	{
		if (!Exists<T>(name)) return nullptr;

		return m_Assets<T>[std::string(name)].get();
	}
	template <typename T>
	bool Assets::Exists(std::string_view name)
	{
		return m_Assets<T>.find(std::string(name)) != m_Assets.end();
	}
	template <typename T>
	void Assets::Clear()
	{
		m_Assets<T>.clear();
	}
	std::string_view Assets::ReadAssets(std::string_view assetsPath)
	{
		std::string code;
		try
		{
			std::ifstream file(assetsPath.data());
			std::stringstream stream;
			stream << file.rdbuf();

			file.close();
			code = stream.str();
		}
		catch (std::ifstream::failure e)
		{
			FEMTO_ERROR("Femto::Core::Assets; Failed to read assets: {}", e.what());
			return nullptr;
		}
		return code;
	}
	/*
	* assets file
	* type
	* 0: text
	* 1: image
	* 2: sound
	*/
}