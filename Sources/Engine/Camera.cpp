#include "Camera.hpp"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GL/glew.h>

#include <algorithm>
#include <cmath>

Camera::Camera() 
{
    proj_matrix = glm::mat4(1.f);
    view_matrix = glm::mat4(1.f);

    position = glm::vec3(0.f);

    yaw = pitch = 0.f;
}

void Camera::set_position(glm::vec3 position) 
{
    this->position = position;
}

glm::vec3 Camera::get_position() const
{
    return position;
}

void Camera::set_yaw(float yaw) 
{
    this->yaw = yaw;
}

float Camera::get_yaw() const
{
    return yaw;
}

void Camera::set_pitch(float pitch) 
{
    this->pitch = std::clamp( pitch, -89.f, 89.f );
}

float Camera::get_pitch() const
{
    return pitch;
}

glm::vec3 Camera::get_heading() const
{
    return heading;
}

glm::vec3 Camera::get_up() const
{
    return up;
}

glm::vec3 Camera::get_right() const
{
    return right;
}

void Camera::update_view_matrix() 
{
    const float yaw_rad = glm::radians( yaw );
    const float pitch_rad = glm::radians( pitch );

    heading.x = std::cos( yaw_rad ) * std::cos( pitch_rad );
    heading.y = std::sin( pitch_rad );
    heading.z = std::sin( yaw_rad ) * std::cos( pitch_rad );
    heading = glm::normalize( heading );

    right = glm::normalize( glm::cross( heading, WORLD_UP ) );
    up = glm::normalize( glm::cross( right, heading ) );


    view_matrix = glm::lookAt( position, position + heading, up );
}

const glm::mat4& Camera::get_view_matrix() const
{
    return view_matrix;
}

void Camera::set_projection_matrix(const glm::mat4& mat) 
{
    proj_matrix = mat;

    glMatrixMode( GL_PROJECTION );
    glLoadMatrixf( glm::value_ptr( proj_matrix ) );
}

const glm::mat4& Camera::get_projection_matrix() const
{
    return proj_matrix;
}
