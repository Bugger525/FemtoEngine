#pragma once

#include "Image.h"
#include "../Core/IAsset.h"

namespace Femto
{
	class Texture : public IAsset
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

		bool IsValid() const override;
	};
}