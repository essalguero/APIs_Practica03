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

}