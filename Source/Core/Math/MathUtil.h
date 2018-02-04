#pragma once

#include "Core/PreDefines.h"

NSBEGIN

FORCE_INLINE float magnitudeSq(const glm::vec3& p1, const glm::vec3& p2)
{
	glm::vec3 t = p2 - p1;
	return t.x * t.x + t.y * t.y + t.z * t.z;
}

NSEND