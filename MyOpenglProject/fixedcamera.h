#pragma once

//#include <glad\glad.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include <vector>
#include <QDebug>

const float ZOOM = 30.0f;

class FixedCamera
{
public:
	//Camera Attributes
	glm::vec3 Position;
	glm::vec3 TargetPos;
	glm::vec3 WorldUp;
	glm::mat4 ViewMatrix;
	glm::vec3 Direction;//Actually the opposite Direction in which camera is looking
	glm::vec3 Up;
	glm::vec3 Right;
	float Zoom;

	FixedCamera(glm::vec3 pos = glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3 targetPos = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f))
	{
		Position = pos;
		WorldUp = up;
		TargetPos = targetPos;
		ViewMatrix = glm::lookAt(Position, TargetPos, WorldUp);
		Direction = glm::normalize(Position - TargetPos);
		Right = glm::normalize(glm::cross(Direction, WorldUp));
		Up = glm::normalize(glm::cross(Right, Direction));
        Zoom = ZOOM;
//        Zoom = 2;
	}

	glm::mat4 GetViewMatrix()
	{
		ViewMatrix = glm::lookAt(Position, TargetPos, WorldUp);
		Direction = glm::normalize(Position - TargetPos);
		Right = glm::normalize(glm::cross(Direction, WorldUp));
		Up = glm::normalize(glm::cross(Right, Direction));
		return ViewMatrix;
	}

	//Processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
	void ProcessMouseScroll(float yoffset)
	{

//        float tmpstep = yoffset/10.0;
//        if(Zoom-tmpstep > 0){
//            Zoom -= tmpstep;
//        }
//        qDebug() << "Zoom:" << Zoom << tmpstep;

        if (Zoom >= 1.0f && Zoom <= 179.0f)
            Zoom -= yoffset;
        if (Zoom <= 1.0f)
            Zoom = 1.0f;
        if (Zoom >= 179.0f)
            Zoom = 179.0f;

	}

};
