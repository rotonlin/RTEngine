#pragma once

#include "Core/PreDefines.h"
#include "glm/glm.hpp"

NSBEGIN

class Line
{
public:
	FORCE_INLINE Line() {}
	FORCE_INLINE Line(const glm::vec3& s, const glm::vec3& e)
		: start(s)
		, end(e) {}

	FORCE_INLINE float length()
	{
		return glm::length(end - start);
	}

	FORCE_INLINE float lengthSq()
	{
		glm::vec3 t = end - start;
		return t.x * t.x + t.y * t.y + t.z * t.z;
	}

	glm::vec3 start;
	glm::vec3 end;
};

NSEND