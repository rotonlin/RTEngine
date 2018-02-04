#pragma once

#include "Core/PreDefines.h"
#include "Core/Math/MathUtil.h"

NSBEGIN

class Sphere
{
public:
	FORCE_INLINE Sphere() : radius(1.0f){}
	FORCE_INLINE Sphere(const glm::vec3& _position, float _radius)
		: position(_position)
		, radius(_radius) {}

	FORCE_INLINE bool containPoint(glm::vec3& point)
	{
		float magSq = RTEngine::magnitudeSq(position, point);
		float radSq = radius * radius;
		return magSq <= radSq;
	}

	FORCE_INLINE glm::vec3 closestPoint(glm::vec3& point)
	{
		glm::vec3 dir = glm::normalize(point - position);
		return position + dir * radius;
	}

	glm::vec3 position;
	float radius;
};

NSEND