#pragma once

#include "Core/PreDefines.h"

NSBEGIN

class Triangle
{
public:
	FORCE_INLINE Triangle() {}
	FORCE_INLINE Triangle(const glm::vec3& _v1, const glm::vec3& _v2, const glm::vec3& _v3)
		: v1(_v1)
		, v2(_v2)
		, v3(_v3){}

	//accesors
	union
	{
		struct
		{
			glm::vec3 v1;
			glm::vec3 v2;
			glm::vec3 v3;
		};
		glm::vec3 points[3];
		float values[9];
	};
};

NSEND