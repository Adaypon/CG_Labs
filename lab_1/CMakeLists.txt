cmake_minimum_required(VERSION 3.0)

project(lab1)

find_package(OpenGL REQUIRED)

# Add C++11 support
set(CMAKE_CXX_STANDARD 11)

# Disable building unused glfw staff
set(${GLFW_BUILD_DOCS} OFF CACHE BOOL  FORCE)
set(${GLFW_BUILD_TESTS} OFF CACHE BOOL  FORCE)
set(${GLFW_BUILD_EXAMPLES} OFF CACHE BOOL  FORCE)

# Build and include glfw
message(STATUS "GLFW - START")
add_subdirectory(../glfw glfw)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../glfw/include)
message(STATUS "GLFW - DONE")

# Build and include glut
# message(STATUS "GLUT - START")
# add_subdirectory(../freeglut glut)
# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../freeglut/include)
# message(STATUS "GLUT - DONE")

# Adding project source files
add_executable(${PROJECT_NAME}  
    src/main.cpp
)

# Link lib libraries
target_link_libraries(${PROJECT_NAME} PUBLIC
    glfw
    ${OPENGL_LIBRARY}
    # ${GLUT_LIBRARY}
    ${GLFW_LIBRARIES}
)