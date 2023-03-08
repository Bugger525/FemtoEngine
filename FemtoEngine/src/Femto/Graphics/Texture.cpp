#include "Graphics/Texture.h"
#include <GL/glew.h>

namespace Femto
{
	Texture::Texture() : m_Texture(NULL)
	{
	}
	Texture::Texture(const Image& image) : m_Texture(NULL), m_Image(image)
	{
		glBindTexture(GL_TEXTURE_2D, m_Texture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Image.GetSize().X, m_Image.GetSize().Y, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_Image.GetRawImage().data());
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glBindTexture(GL_TEXTURE_2D, 0);
	}
	Texture::~Texture()
	{
		Cleanup();
	}
	void Texture::Bind() const
	{
		glBindTexture(GL_TEXTURE_2D, m_Texture);
	}
	const Image& Texture::GetImage() const
	{
		return m_Image;
	}
	void Texture::Cleanup()
	{
		if (m_Texture)
			glDeleteTextures(1, &m_Texture);
	}
}