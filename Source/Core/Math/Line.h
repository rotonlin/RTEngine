#pragma once

#include "Core/PreDefines.h"
#include "Core/Math/MathUtil.h"

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
		return RTEngine::magnitudeSq(start, end);
	}

	glm::vec3 start;
	glm::vec3 end;
};

NSEND