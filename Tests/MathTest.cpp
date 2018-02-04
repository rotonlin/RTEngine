#ifdef _ENABLE_TEST_
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Core/PreDefines.h"
#include "Core/Math/AABB.h"
#include "Core/Math/Sphere.h"
#include "Core/Math/OBB.h"
#include "Core/Math/Plane.h"
#include "Core/Math/Triangle.h"
#include "Core/Math/MathUtil.h"

using namespace RTEngine;

TEST_CASE("math lib 3dpointtests", "[3dpointtests]") {
	Sphere sphere(glm::vec3(0, 0, 0), 1);
	REQUIRE(sphere.containPoint(glm::vec3(1, 0, 0)) == true);
	REQUIRE(sphere.containPoint(glm::vec3(2, 0, 0)) == false);
	REQUIRE(sphere.closestPoint(glm::vec3(2, 0, 0)) == glm::vec3(1, 0, 0));
	REQUIRE(sphere.closestPoint(glm::vec3(1, 0, 0)) == glm::vec3(1, 0, 0));

	AABB aabb(glm::vec3(0, 0, 0), glm::vec3(1, 1, 1));
	REQUIRE(aabb.containPoint(glm::vec3(1, 0, 0)) == true);
	REQUIRE(aabb.containPoint(glm::vec3(2, 0, 0)) == false);
	REQUIRE(aabb.containPoint(glm::vec3(0, 0, 0)) == true);
	REQUIRE(aabb.containPoint(glm::vec3(1, 1, 1)) == true);
	REQUIRE(aabb.closestPoint(glm::vec3(2, 0, 0)) == glm::vec3(1, 0, 0));
	REQUIRE(aabb.closestPoint(glm::vec3(1, 0, 0)) == glm::vec3(1, 0, 0));

	glm::quat rot(glm::vec3(glm::pi<float>() * 0.25f, 0, 0));
	OBB obb(glm::vec3(0, 0, 0), glm::vec3(1, 1, 1), rot);
	REQUIRE(obb.containPoint(glm::vec3(1, 0, 0)) == true);
	REQUIRE(obb.containPoint(glm::vec3(0, 1, 1)) == false);
	REQUIRE(obb.closestPoint(glm::vec3(1, 0, 0)) == glm::vec3(1, 0, 0));


}

#endif