#pragma once

#include "Core/PreDefines.h"
#include "glm/glm.hpp"

NSBEGIN

class AABB
{
public:
	FORCE_INLINE AABB() : extends(1, 1, 1){}
	FORCE_INLINE AABB(const glm::vec3& _origin, const glm::vec3& _extends)
		: origin(origin)
		, extends(_extends) {}


	FORCE_INLINE static AABB fromMinMax(const glm::vec3& _min, const glm::vec3& _max)
	{

	}

	FORCE_INLINE glm::vec3 getMax()
	{

	}

	FORCE_INLINE glm::vec3 getMin()
	{
		vec3 p1 = position + extends;
		vec3 p2 = position - extends;
		return glm::vec3(glm::min(p1.x, p2.x), glm::min(p1.y, p2.y), glm::min(p1.z, p2.z));
	}

	glm::vec3 origin;
	glm::vec3 extends;
};

NSEND