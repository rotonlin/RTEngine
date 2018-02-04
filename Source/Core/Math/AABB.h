#pragma once

#include "Core/PreDefines.h"

NSBEGIN

class AABB
{
public:
	FORCE_INLINE AABB() : extends(1, 1, 1){}
	FORCE_INLINE AABB(const glm::vec3& _origin, const glm::vec3& _extends)
		: origin(_origin)
		, extends(_extends) {}


	FORCE_INLINE static AABB fromMinMax(const glm::vec3& _min, const glm::vec3& _max)
	{
		return AABB((_min + _max) * 0.5f, (_max - _min) * 0.5f);
	}

	FORCE_INLINE glm::vec3 getMax()
	{
		glm::vec3 p1 = origin + extends;
		glm::vec3 p2 = origin - extends;
		return glm::vec3(glm::max(p1.x, p2.x), glm::max(p1.y, p2.y), glm::max(p1.z, p2.z));
	}

	FORCE_INLINE glm::vec3 getMin()
	{
		glm::vec3 p1 = origin + extends;
		glm::vec3 p2 = origin - extends;
		return glm::vec3(glm::min(p1.x, p2.x), glm::min(p1.y, p2.y), glm::min(p1.z, p2.z));
	}

	FORCE_INLINE bool containPoint(glm::vec3& point)
	{
		glm::vec3 min = getMin();
		glm::vec3 max = getMax();
		if (point.x < min.x || point.y < min.y || point.z < min.z)
		{
			return false;
		}
		if (point.x > max.x || point.y > max.y || point.z > max.z)
		{
			return false;
		}
		return true;
	}

	FORCE_INLINE glm::vec3 closestPoint(glm::vec3& point)
	{
		return glm::clamp(point, getMin(), getMax());
	}

	glm::vec3 origin;
	glm::vec3 extends;
};

NSEND