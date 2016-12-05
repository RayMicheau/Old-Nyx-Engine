#pragma once
#include "AbstractRenderer.h"
#include <vector>
#include "OpenGL\include\glew.h"
#include "OpenGL\include\glut.h"
#include "vgl.h"
#include "glm\glm\glm.hpp"
#include "glm\glm\gtc\matrix_transform.hpp"
#include "LoadShaders.h"
#include "Camera.h"

class OpenGLRenderer :
	public AbstractRenderer
{

public:
	OpenGLRenderer();
	~OpenGLRenderer();

	enum VAO_IDs { Triangles, NumVAOs };
	enum Buffer_IDs { ArrayBuffer, NumBuffers };
	enum Attrib_IDs { vPosition = 0 };

	GLuint VAOs[NumVAOs];
	GLuint Buffers[NumBuffers];
	float CamDist = 1;
	GLuint location, location2, location3;
	Camera* CameraOne;

	float AminX, AmaxX, AminY, AmaxY, AminZ, AmaxZ;
	float BminX, BmaxX, BminY, BmaxY, BminZ, BmaxZ;
	float CminX, CmaxX, CminY, CmaxY, CminZ, CmaxZ;
	int playerScore = 0, aiScore = 0;

	void PreRender();
	void PostRender();
	void renderPrimitive(PRIMITIVETYPE prim);
	bool AABBTemp();


	float movementX = 0.3;
	float movementY = 0.2f;

	glm::vec3 zero = glm::vec3(0, 0, 0);

	//bool loadOBJ(const char* path, std::vector<glm::vec3> &out_vertices, std::vector<glm::vec2> &out_uvs, std::vector<glm::vec3> &out_normals);
};

