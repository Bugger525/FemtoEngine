#pragma once

#include <vector>
#include "../System/Vector2.h"
#include <span>
#include "../Core/IAsset.h"

namespace Femto
{
	class Image : public IAsset
	{
	private:
		std::vector<unsigned char> m_Image;
		Vector2u m_Size;
	public:
		Image();
		Image(unsigned int width, unsigned int height, std::span<unsigned char> rawImage);

		const std::vector<unsigned char>& GetRawImage() const;
		Vector2u GetSize() const;

		bool IsValid() const override;
	};
}