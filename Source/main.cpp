#include <iostream>
#include "Core/Math/Line.h"
#include "Core/Math/Ray.h"

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/constants.hpp> // glm::pi

glm::mat4 camera(float Translate, glm::vec2 const& Rotate)
{
	glm::mat4 Projection = glm::perspective(glm::pi<float>() * 0.25f, 4.0f / 3.0f, 0.1f, 100.f);
	glm::mat4 View = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -Translate));
	View = glm::rotate(View, Rotate.y, glm::vec3(-1.0f, 0.0f, 0.0f));
	View = glm::rotate(View, Rotate.x, glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 Model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
	return Projection * View * Model;
}

int main(int argc, char* argv[])
{
	glm::mat4 Projectin = camera(10, glm::vec2(1, 2));

	std::cout << "Hello" << std::endl;


	RTEngine::Line line(glm::vec3(1, 2, 3), glm::vec3(2, 3, 4));
	float l = line.length();
	float l2 = line.lengthSq();
	//Line

	RTEngine::Ray ray(glm::vec3(1, 2, 3), glm::vec3(2, 3, 4));
}