#pragma once

#include <glm/glm.hpp>

class Camera
{
private:
    glm::mat4 proj_matrix;
    glm::mat4 view_matrix;

    glm::vec3 position;

    float yaw;
    float pitch;
    float rotation_sensitivity;

    glm::vec3 heading;
    glm::vec3 up;
    glm::vec3 right;
    const glm::vec3 WORLD_UP { 0.f, 1.f, 0.f };


public:
    Camera();

    void set_position( glm::vec3 position );
    glm::vec3 get_position() const;

    void set_yaw( float yaw );
    float get_yaw() const;
    void set_pitch( float pitch );
    float get_pitch() const;

    glm::vec3 get_heading() const;
    glm::vec3 get_up() const;
    glm::vec3 get_right() const;

    void update_view_matrix();
    glm::mat4 get_view_matrix() const;

    void set_projection_matrix( const glm::mat4& mat );
    const glm::mat4& get_projection_matrix() const;
};