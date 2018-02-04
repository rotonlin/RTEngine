#pragma once

#include "Core/PreDefines.h"

NSBEGIN

class OBB
{
public:
	FORCE_INLINE OBB() : extends(1, 1, 1) {}
	FORCE_INLINE OBB(const glm::vec3& _origin, const glm::vec3& _extends, const glm::quat& _rotation)
		: origin(_origin)
		, extends(_extends)
		, rotation(_rotation) {}

	FORCE_INLINE bool containPoint(glm::vec3& point)
	{
		glm::vec3 dir = point - origin;
		glm::mat3 transformMat = glm::mat3_cast(rotation);
		
		for (int i = 0; i < 3; ++i)
		{
			glm::vec3& cloum = transformMat[i];
			float dist = glm::dot(dir, cloum);
			if (dist > extends[i] || dist < -extends[i])
			{
				return false;
			}
		}

		return true;
	}

	FORCE_INLINE glm::vec3 closestPoint(glm::vec3& point)
	{
		glm::vec3 dir = point - origin;
		glm::mat3 transformMat = glm::mat3_cast(rotation);
		glm::vec3 res(0.0f, 0.0f, 0.0f);
		for (int i = 0; i < 3; ++i)
		{
			glm::vec3& cloum = transformMat[i];
			float dist = glm::dot(dir, cloum);
			if (dist > extends[i] || dist < -extends[i])
			{
				dist = extends[i];
			}
			res += cloum * dist;
		}
		return res;
	}

	glm::vec3 origin;
	glm::vec3 extends;
	glm::quat rotation;
};

NSEND