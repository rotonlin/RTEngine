#pragma once

#include "Core/PreDefines.h"

NSBEGIN

class Plane
{
public:
	FORCE_INLINE Plane() : normal(1, 0, 0), distance(0.0f) {}
	FORCE_INLINE Plane(const glm::vec3& _normal, float _distance)
		: normal(_normal)
		, distance(_distance) {}

	FORCE_INLINE bool planeEquation(const glm::vec3& point) {
		float res = glm::dot(point, normal) - distance;
		return res <= FLT_MIN;
	}

	glm::vec3 normal;
	float distance;
};

NSEND