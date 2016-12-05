#include "pch.h"
#include "OpenGLRenderer.h"
#include "glm\glm\glm.hpp"
#include "glm\glm\gtc\matrix_transform.hpp"


static const GLfloat bg[] = { .10f, 0.0f, .20f, 1.0f };
static const int NumVertices = 24;
float angle;

OpenGLRenderer::OpenGLRenderer()
{
	CameraOne = new Camera();
}

//bool OpenGLRenderer::loadOBJ(const char* path, std::vector<glm::vec3> &out_vertices, std::vector<glm::vec2> &out_uvs, std::vector<glm::vec3> &out_normals)
//{
//	std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
//
//	std::vector<glm::vec3> temp_vertices;
//	std::vector<glm::vec2> temp_uvs;
//	std::vector<glm::vec3> temp_normals;
//
//	FILE* file;
//
//	file = fopen(path, "r");
//	if (file == NULL)
//	{
//		printf("CANNOT OPEN THE FILE\n");
//		return false;
//	}
//
//	while (1)
//	{
//		char lineHeader[128];
//
//		//read first word of line
//		int res = fscanf_s(file, "%s", lineHeader);
//
//		if (res == EOF)
//			break;
//
//		if (strcmp(lineHeader, "v") == 0)
//		{
//			glm::vec3 vertex;
//			fscanf_s(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
//			temp_vertices.push_back(vertex);
//		}
//		else if (strcmp(lineHeader, "vt") == 0)
//		{
//			glm::vec2 uv;
//			fscanf_s(file, "%f, %f\n", &uv.x, &uv.y);
//			temp_uvs.push_back(uv);
//		}
//		else if (strcmp(lineHeader, "vn") == 0)
//		{
//			glm::vec3 normal;
//			fscanf_s(file, "%f, %f, %f\n", &normal.x, &normal.y, &normal.z);
//			temp_normals.push_back(normal);
//		}
//		else if (strcmp(lineHeader, "f") == 0)
//		{
//			std::string vertex1, vertex2, vertex3;
//			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
//			int matches = fscanf_s(file, "%d%d%d %d%d%d %d%d%d\n",
//				&vertexIndex[0], &uvIndex[0], &normalIndex[0],
//				&vertexIndex[1], &uvIndex[1], &normalIndex[1],
//				&vertexIndex[2], &uvIndex[2], &normalIndex[2]);
//			if (matches != 9)
//			{
//				printf("File can't be read by simple parser... :( try exporting with different options!");
//				return false;
//			}
//			vertexIndices.push_back(vertexIndex[0]);
//			vertexIndices.push_back(vertexIndex[1]);
//			vertexIndices.push_back(vertexIndex[2]);
//			uvIndices.push_back(uvIndex[0]);
//			uvIndices.push_back(uvIndex[1]);
//			uvIndices.push_back(uvIndex[2]);
//			normalIndices.push_back(normalIndex[0]);
//			normalIndices.push_back(normalIndex[1]);
//			normalIndices.push_back(normalIndex[2]);
//			for (unsigned int i = 0; i < vertexIndices.size(); i++)
//			{
//				unsigned int vertexIndex = vertexIndices[i];
//
//				glm::vec3 vertex = temp_vertices[vertexIndex - 1];
//
//				out_vertices.push_back(vertex);
//			}
//		}
//	}
//	fclose(file);
//
//}

OpenGLRenderer::~OpenGLRenderer()
{
	
}
void OpenGLRenderer::renderPrimitive(PRIMITIVETYPE prim)
{
	GLfloat colorData[NumVertices][3];
	GLfloat verts[NumVertices][3];
	glEnable(GL_DEPTH_TEST);

	ShaderInfo shaders[] = {
		{ GL_VERTEX_SHADER, "triangles.vert" },
		{ GL_FRAGMENT_SHADER, "triangles.frag" },
		{ GL_NONE, NULL }
	};


	switch (prim) {
	case AbstractRenderer::PRIMITIVETYPE::NONE:

		break;

	case AbstractRenderer::PRIMITIVETYPE::POINT:

		break;

	case AbstractRenderer::PRIMITIVETYPE::TRIANGLE:
		verts[0][0] = 0;
		verts[0][1] = .25f;
		verts[0][2] = 0;

		verts[1][0] = -.25f;
		verts[1][1] = -.25f;
		verts[1][2] = .25f;

		verts[2][0] = .25f;
		verts[2][1] = -.25f;
		verts[2][2] = .25f;

		colorData[0][0] = 0;
		colorData[0][1] = 1;
		colorData[0][2] = 0;
		colorData[1][0] = 0;
		colorData[1][1] = 1;
		colorData[1][2] = 0;
		colorData[2][0] = 0;
		colorData[2][1] = 1;
		colorData[2][2] = 0;


		verts[3][0] = 0;
		verts[3][1] = .25f;
		verts[3][2] = 0;

		verts[4][0] = -.25f;
		verts[4][1] = -.25f;
		verts[4][2] = .25f;

		verts[5][0] = 0;
		verts[5][1] = -.25f;
		verts[5][2] = -.25f;

		colorData[3][0] = 1;
		colorData[3][1] = 0;
		colorData[3][2] = 0;
		colorData[4][0] = 1;
		colorData[4][1] = 0;
		colorData[4][2] = 0;
		colorData[5][0] = 1;
		colorData[5][1] = 0;
		colorData[5][2] = 0;

		verts[6][0] = 0;
		verts[6][1] = .25f;
		verts[6][2] = 0;

		verts[7][0] = 0;
		verts[7][1] = -.25f;
		verts[7][2] = -.25f;

		verts[8][0] = .25f;
		verts[8][1] = -.25f;
		verts[8][2] = .25f;

		colorData[6][0] = 0;
		colorData[6][1] = 0;
		colorData[6][2] = 1;
		colorData[7][0] = 0;
		colorData[7][1] = 0;
		colorData[7][2] = 1;
		colorData[8][0] = 0;
		colorData[8][1] = 0;
		colorData[8][2] = 1;
		break;

	case AbstractRenderer::PRIMITIVETYPE::RECT:
		//Front
		verts[0][0] = 0.0f;
		verts[0][1] = 0.0f;
		verts[0][2] = 0.0f;

		verts[1][0] = 0.0f;
		verts[1][1] = 1.0f;
		verts[1][2] = 0.0f;

		verts[2][0] = 1.0f;
		verts[2][1] = 1.0f;
		verts[2][2] = 0.0f;

		verts[3][0] = 1.0f;
		verts[3][1] = 0.0f;
		verts[3][2] = 0.0f;

		//Back
		verts[4][0] = 0.0f;
		verts[4][1] = 0.0f;
		verts[4][2] = 1.0f;

		verts[5][0] = 0.0f;
		verts[5][1] = 1.0f;
		verts[5][2] = 1.0f;

		verts[6][0] = 1.0f;
		verts[6][1] = 1.0f;
		verts[6][2] = 1.0f;

		verts[7][0] = 1.0f;
		verts[7][1] = 0.0f;
		verts[7][2] = 1.0f;

		//Left
		verts[8][0] = 0.0f;
		verts[8][1] = 0.0f;
		verts[8][2] = 0.0f;

		verts[9][0] = 0.0f;
		verts[9][1] = 1.0f;
		verts[9][2] = 0.0f;

		verts[10][0] = 0.0f;
		verts[10][1] = 1.0f;
		verts[10][2] = 1.0f;

		verts[11][0] = 0.0f;
		verts[11][1] = 0.0f;
		verts[11][2] = 1.0f;


		//Right
		verts[12][0] = 1.0f;
		verts[12][1] = 0.0f;
		verts[12][2] = 0.0f;

		verts[13][0] = 1.0f;
		verts[13][1] = 1.0f;
		verts[13][2] = 0.0f;

		verts[14][0] = 1.0f;
		verts[14][1] = 1.0f;
		verts[14][2] = 1.0f;

		verts[15][0] = 1.0f;
		verts[15][1] = 0.0f;
		verts[15][2] = 1.0f;



		//bottom
		verts[16][0] = 0.0f;
		verts[16][1] = 0.0f;
		verts[16][2] = 0.0f;

		verts[17][0] = 1.0f;
		verts[17][1] = 0.0f;
		verts[17][2] = 0.0f;
		
		verts[18][0] = 1.0f;
		verts[18][1] = 0.0f;
		verts[18][2] = 1.0f;

		verts[19][0] = 0.0f;
		verts[19][1] = 0.0f;
		verts[19][2] = 1.0f;


		//Top
		verts[20][0] = 0.0f;
		verts[20][1] = 1.0f;
		verts[20][2] = 0.0f;

		verts[21][0] = 1.0f;
		verts[21][1] = 1.0f;
		verts[21][2] = 0.0f;

		verts[22][0] = 1.0f;
		verts[22][1] = 1.0f;
		verts[22][2] = 1.0f;

		verts[23][0] = 0.0f;
		verts[23][1] = 1.0f;
		verts[23][2] = 1.0f;


		//Front
		colorData[0][0] = 1;
		colorData[0][1] = 1;
		colorData[0][2] = 0;
		colorData[1][0] = 1;
		colorData[1][1] = 1;
		colorData[1][2] = 0;
		colorData[2][0] = 1;
		colorData[2][1] = 1;
		colorData[2][2] = 0;
		colorData[3][0] = 1;
		colorData[3][1] = 1;
		colorData[3][2] = 0;

		//Back
		colorData[4][0] = 0;
		colorData[4][1] = 1;
		colorData[4][2] = 1;
		colorData[5][0] = 0;
		colorData[5][1] = 1;
		colorData[5][2] = 1;
		colorData[6][0] = 0;
		colorData[6][1] = 1;
		colorData[6][2] = 1;
		colorData[7][0] = 0;
		colorData[7][1] = 1;
		colorData[7][2] = 1;

		//Left
		colorData[8][0] = 1;
		colorData[8][1] = 0;
		colorData[8][2] = 1;
		colorData[9][0] = 1;
		colorData[9][1] = 0;
		colorData[9][2] = 1;
		colorData[10][0] = 1;
		colorData[10][1] = 0;
		colorData[10][2] = 1;
		colorData[11][0] = 1;
		colorData[11][1] = 0;
		colorData[11][2] = 1;

		//Right
		colorData[12][0] = 1;
		colorData[12][1] = 1;
		colorData[12][2] = 1;
		colorData[13][0] = 1;
		colorData[13][1] = 1;
		colorData[13][2] = 1;
		colorData[14][0] = 1;
		colorData[14][1] = 1;
		colorData[14][2] = 1;
		colorData[15][0] = 1;
		colorData[15][1] = 1;
		colorData[15][2] = 1;

		//Bottom
		colorData[16][0] = 1;
		colorData[16][1] = 0;
		colorData[16][2] = 0;
		colorData[17][0] = 1;
		colorData[17][1] = 0;
		colorData[17][2] = 0;
		colorData[18][0] = 1;
		colorData[18][1] = 0;
		colorData[18][2] = 0;
		colorData[19][0] = 1;
		colorData[19][1] = 0;
		colorData[19][2] = 0;

		//Top
		colorData[20][0] = 0;
		colorData[20][1] = 1;
		colorData[20][2] = 0;
		colorData[21][0] = 0;
		colorData[21][1] = 1;
		colorData[21][2] = 0;
		colorData[22][0] = 0;
		colorData[22][1] = 1;
		colorData[22][2] = 0;
		colorData[23][0] = 0;
		colorData[23][1] = 1;
		colorData[23][2] = 0;
		break;
	}

	GLuint program = LoadShaders(shaders);
	glUseProgram(program);

	glGenBuffers(2, Buffers);
	glBindBuffer(GL_ARRAY_BUFFER, Buffers[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
	glBindAttribLocation(program, 0, "vPosition");
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, Buffers[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colorData), colorData, GL_STATIC_DRAW);
	glBindAttribLocation(program, 1, "vertexColor");
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray(1);

	location = glGetUniformLocation(program, "model_matrix");
	location2 = glGetUniformLocation(program, "camera_matrix");
	location3 = glGetUniformLocation(program, "proj_matrix");

}

void OpenGLRenderer::PreRender()
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	angle += 0.005f;

	glm::mat4 model_view = glm::translate(glm::mat4(1.0), zero);
	model_view = glm::rotate(model_view, angle, glm::vec3(0.0f, 1.0f, 0.0f));
	glUniformMatrix4fv(location, 1, GL_FALSE, &model_view[0][0]);


	CameraOne->RenderCam();
	//glm::mat4 camera_matrix = glm::lookAt(glm::vec3(0.0, 0.0, CameraOne->CamDist), glm::vec3(0.0, 0.0, -1.0), glm::vec3(0.0, 1.0, 0.0));
	glm::mat4 camera_matrix = *CameraOne->camera_matrix;
	glUniformMatrix4fv(location2, 1, GL_FALSE, &camera_matrix[0][0]);

	glm::mat4 projection_matrix = glm::perspective(45.0f, 1.0f, 1.0f, 100.0f);
	//glm::mat4 projection_matrix = *CameraOne->projection_matrix;
	glUniformMatrix4fv(location3, 1, GL_FALSE, &projection_matrix[0][0]);

	//BOX ONE
	glDrawArrays(GL_QUADS, 0, NumVertices);

}

void OpenGLRenderer::PostRender()
{
	//glDrawArrays(GL_TRIANGLE_STRIP, 0, 3);
	//glFlush();
}

bool OpenGLRenderer::AABBTemp()
{
	return(AminX <= CmaxX && AmaxX >= CminX) && 
		(AminY <= CmaxY && AmaxY >= CminY) && 
		(AminZ <= CmaxZ && AmaxZ >= CminZ);
}
