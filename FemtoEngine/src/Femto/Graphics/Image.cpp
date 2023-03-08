#include "Graphics/Image.h"

namespace Femto
{
	Image::Image() : m_Size(0, 0)
	{
	}
	Image::Image(unsigned int width, unsigned int height, std::span<unsigned char> rawImage) : m_Size(width, height)
	{
		m_Image.assign(rawImage.begin(), rawImage.end());
	}
	const std::vector<unsigned char>& Image::GetRawImage() const
	{
		return m_Image;
	}
	Vector2u Image::GetSize() const
	{
		return m_Size;
	}
}