#documents https://cmake.org/cmake/help/v3.10/manual/cmake-buildsystem.7.html#id15

cmake_minimum_required(VERSION 3.9)

project (RTEngine)

#init envs
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build/bin)
  
add_subdirectory(Source)

add_executable(RTEngine
	Source/main.cpp
	Source/Core/GeneratorTest.cpp
)

#includes
target_include_directories(RTEngine PUBLIC
	Source
)

#defines
target_compile_definitions(RTEngine PUBLIC
	#_RTE_EDITOR_
)

#target RTEngine propertys
