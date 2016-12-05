#include "pch.h"
#include "Camera.h"
#include <stdio.h>
Camera::Camera()
{
	CamDistZ = -10;
	CamDistX = 0;
	camera_matrix = new glm::mat4();
	camera_matrix = &glm::translate(glm::mat4(1.0), glm::vec3(0.0, 0.0, 0.0));
	projection_matrix = new glm::mat4();
	projection_matrix = &glm::perspective(45.0f, 1024.0f / 1024.0f, 1.0f, 100.0f);
	printf("hello");
}
void Camera::RenderCam() {
	camera_matrix = &glm::lookAt(glm::vec3(CamDistX, 0.0, CamDistZ), glm::vec3(0.0, 0.0, -1.0), glm::vec3(0.0, 1.0, 0.0));
}