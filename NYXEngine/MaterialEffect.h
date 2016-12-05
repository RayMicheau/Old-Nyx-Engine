#pragma once
#ifndef MATERIALEFFECT_H
#define MATERIALEFFECT_H
#endif // !
#include "glm\glm\glm.hpp"

class MaterialEffect
{
public:
	MaterialEffect();
	~MaterialEffect();

	glm::vec3 ambientCol;
	glm::vec3 diffuseCol;
	glm::vec3 specularCol;

	//This is where the exponent would go
	//...
	//IF I HAD ONE :C

	//TEXTURES GO UNDER HERE
	//ImageTexture Ambient;
	//ImageTexture Diffuse;
	//ImageTexture Bumpmap;
	//ANYTHING ELSE

};

