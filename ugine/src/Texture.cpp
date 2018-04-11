#include "Texture.h"
#include "../lib/stb-image/stb_image.h"

#include "common.h"

std::shared_ptr<Texture> Texture::load(const char* filename)
{
	//std::shared_ptr<Texture> texture;

	int imageHeight;
	int imageWidth;
	
	stbi_uc* stbiImageLoaded = stbi_load(filename, &imageHeight, &imageWidth, nullptr, 4);

	//glGenTextures(1, &textureId);

	if (!stbiImageLoaded)
		return nullptr;

	

	std::shared_ptr<Texture> texture(new Texture(), destroy);
	//if (strcmp(p->error, "") != 0) {
	//texture = nullptr;

	stbi_image_free(stbiImageLoaded);

	return texture;
}

Texture::Texture()
{
	glGenTextures(1, &textureId);

	bind();

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
		imageWidth, imageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);

	glGenerateMipmap(GL_TEXTURE_2D);

	
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