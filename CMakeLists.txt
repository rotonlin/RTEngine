#documents https://cmake.org/cmake/help/v3.10/manual/cmake-buildsystem.7.html#id15

cmake_minimum_required(VERSION 3.9)

project (RTEngine)

#init envs
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build/bin)

add_executable(RTEngine
	Source/main.cpp
	Tests/MathTest.cpp
)

#includes
target_include_directories(RTEngine PUBLIC
	Source
	ThirdPartys/glm
	ThirdPartys/Catch2
)

#defines
target_compile_definitions(RTEngine PUBLIC
	#_RTE_EDITOR_
	_ENABLE_TEST_
)
