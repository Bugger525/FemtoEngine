#include "Core/AssetStream.h"
#include <fstream>
#include <sstream>
#include "Core/Debug.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace Femto
{
	AssetStream::AssetStream()
	{
	}
	AssetStream::AssetStream(std::string_view rootDir) : m_RootDir(rootDir)
	{
	}
	std::string_view AssetStream::ReadText(std::string_view file)
	{
		std::string p;
		if (m_RootDir.length() > 0)
		{
			p = m_RootDir;
			p += file;
		}
		else
		{
			p = file;
		}
		std::string text;
		try
		{
			std::ifstream file(p.data());

			std::stringstream stream;
			stream << file.rdbuf();

			file.close();

			text = stream.str();
		}
		catch (std::ifstream::failure e)
		{
			FEMTO_ERROR("Failed to read shader code: {}", e.what());
			return nullptr;
		}
		return text;
	}
	Image AssetStream::ReadImage(std::string_view file)
	{
		std::string p;
		if (m_RootDir.length() > 0)
		{
			p = m_RootDir;
			p += file;
		}
		else
		{
			p = file;
		}
		int width, height, nrChannels;
		Image image;

		unsigned char* data = stbi_load(p.data(), &width, &height, &nrChannels, STBI_rgb_alpha);
		if (!data)
		{
			FEMTO_ERROR("Failed to load texture: {}", stbi_failure_reason());
		}
		else
		{
			image = Image(width, height, std::span<unsigned char>(data, width * height * STBI_rgb_alpha));
		}
		stbi_image_free(data);

		return image;
	}
}