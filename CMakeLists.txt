cmake_minimum_required(VERSION 3.0.0)
project(Engine3D VERSION 0.1.0)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include(FetchContent)

FetchContent_Declare(
    SDL2
    GIT_REPOSITORY "https://github.com/libsdl-org/SDL"
    GIT_TAG main
)
FetchContent_Declare(
    SDL2_image
    GIT_REPOSITORY "https://github.com/libsdl-org/SDL_image"
    GIT_TAG main
)
# FetchContent_Declare(
#     SDL2_ttf
#     GIT_REPOSITORY "https://github.com/libsdl-org/SDL_ttf"
#     GIT_TAG main
# )
FetchContent_Declare(
    GLM
    GIT_REPOSITORY "https://github.com/g-truc/glm"
    GIT_TAG master
)

FetchContent_MakeAvailable( SDL2 SDL2_image GLM )


if(UNIX)
set(OpenGL_GL_PREFERENCE GLVND)
endif()

# findOpenGL should come with CMake installation
find_package(OpenGL REQUIRED)

find_package(GLEW REQUIRED)


add_library(${PROJECT_NAME} STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/Engine/Engine.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/GameObjects/GameObject.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/GameObjects/TransformableObject.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/GameObjects/SimpleEventListeningObject.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/ResourceManager/ResourceManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/PrimitiveRendering/PrimitiveRenderer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/PrimitiveRendering/Cube.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/GameObjects/CubeObject.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/GameObjects/LightObject.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/Testing/LightingTest.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources
    ${sdl2_SOURCE_DIR}
    ${sdl2_image_SOURCE_DIR}
    # ${sdl2_ttf_SOURCE_DIR}
    ${OPENGL_INCLUDE_DIR}
    ${GLEW_INCLUDE_DIRS}
    ${glm_SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME} SDL2 SDL2_image ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES})




add_executable(${PROJECT_NAME}_TEST 
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/Main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Sources/Testing/FirstCubeTestObject.cpp
)

target_link_libraries(${PROJECT_NAME}_TEST ${PROJECT_NAME})