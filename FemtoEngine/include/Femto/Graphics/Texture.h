#pragma once

#include "Image.h"

namespace Femto
{
	class Texture
	{
	private:
		unsigned int m_Texture;
		Image m_Image;
	public:
		Texture();
		Texture(const Image& image);
		~Texture();

		void Bind() const;

		const Image& GetImage() const;

		void Cleanup();
	};
}