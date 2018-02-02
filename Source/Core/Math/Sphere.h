#pragma once

#include "Core/PreDefines.h"
#include "glm/glm.hpp"

NSBEGIN

class Sphere
{
public:
	FORCE_INLINE Sphere() : radius(1.0f){}
	FORCE_INLINE Sphere(const glm::vec3& _position, float _radius)
		: position(_position)
		, radius(_radius) {}


	glm::vec3 position;
	float radius;
};

NSEND