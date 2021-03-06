#include "Texture.h"
#include "../lib/stb-image/stb_image.h"

#include "common.h"

std::shared_ptr<Texture> Texture::load(const char* filename)
{
	//std::shared_ptr<Texture> texture;

	int imageHeight;
	int imageWidth;
	GLuint textureId;
	
	stbi_uc* stbiImageLoaded = stbi_load(filename, &imageHeight, &imageWidth, nullptr, 4);

	if (!stbiImageLoaded)
		return nullptr;

	glGenTextures(1, &textureId);

	glBindTexture(GL_TEXTURE_2D, textureId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
		imageWidth, imageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, stbiImageLoaded);

	glGenerateMipmap(GL_TEXTURE_2D);
	

	std::shared_ptr<Texture> texture(new Texture(textureId,imageHeight, imageWidth), destroy);

	stbi_image_free(stbiImageLoaded);

	return texture;
}

Texture::Texture(GLuint textureId, int height, int width) : textureId(textureId), imageHeight(height), imageWidth(width)
{

}

uint32_t Texture::getId() const
{
	return textureId;
}

const glm::ivec2& Texture::getSize() const
{
	return glm::ivec2(imageWidth, imageHeight);
}

void Texture::bind() const
{
	glBindTexture(GL_TEXTURE_2D, textureId);
}