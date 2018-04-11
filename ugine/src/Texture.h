#pragma once

#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#endif // !STB_IMAGE_IMPLEMENTATION

#include "common.h"

#include "../lib/glew/glew.h"

class Texture
{
public:
	

	static std::shared_ptr<Texture>	load(const char* filename);
	uint32_t						getId() const;
	const glm::ivec2&				getSize() const;
	void							bind() const;

protected:
	Texture();
	~Texture() {};
	static void destroy(Texture* p) {
		delete p;
	}

private:
	uint32_t textureId;

	int imageHeight;
	int imageWidth;
};