cmake_minimum_required(VERSION 3.30)
project(GrahamCracker)

set(CMAKE_CXX_STANDARD 26)

#Finds SDL2 library
find_package(SDL2 REQUIRED)

add_executable(GrahamCracker main.cpp)


#Link SDL2
target_include_directories(GrahamCracker PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(GrahamCracker PRIVATE ${SDL2_LIBRARIES})