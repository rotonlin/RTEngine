#pragma once

#include "Core/PreDefines.h"

NSBEGIN

class Ray
{
public:
	FORCE_INLINE Ray() 
	{
		origin = glm::vec3(0, 0, 1);
		direction = glm::normalize(direction);
	}
	FORCE_INLINE Ray(const glm::vec3& _origin, const glm::vec3& _direction)
		: origin(_origin)
		, direction(glm::normalize(_direction)) {}

	FORCE_INLINE static Ray fromPoints(const glm::vec3& from, const glm::vec3& to)
	{
		return Ray(from, glm::normalize(to - from));
	}

	glm::vec3 origin;
	glm::vec3 direction;
};

NSEND