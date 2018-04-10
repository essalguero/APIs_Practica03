#include "Camera.h"
#include "State.h"



void Camera::prepare()
{
	State::projectionMatrix = this->projectionMatrix;
	
	/*glm::mat4 viewMatrix;

	viewMatrix[3] = glm::vec4(-position, 1.0f);
	State::viewMatrix = viewMatrix;*/

	State::viewMatrix = glm::translate(glm::mat4(), -position);
	State::viewMatrix = glm::rotate(State::viewMatrix, -glm::angle(getRotationQuat()), glm::axis(getRotationQuat()));

	

	glViewport(viewPort.s, viewPort.t, viewPort.p, viewPort.q);
	glScissor(viewPort.s, viewPort.t, viewPort.p, viewPort.q);
	glClearColor(clearColor.r, clearColor.g, clearColor.b, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}