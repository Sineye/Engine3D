#pragma once

#include <glm/glm.hpp>

class Camera
{
public:
    glm::mat4 view_matrix;
    glm::mat4 proj_matrix;
};