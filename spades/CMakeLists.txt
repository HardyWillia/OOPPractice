cmake_minimum_required(VERSION 2.6)
project(spades CXX)


set(CMAKE_CXX_FLAGS "-std=c++1z")


add_executable(spades

	main.cpp
	card.cpp
)
