#pragma once

#include "Mesh.hpp"

#include <glm/glm.hpp>

#include <vector>

class Sphere : public IMesh
{
private:
    std::vector<float> vec_vertices;
    std::vector<unsigned int> vec_indices;
    std::vector<float> vec_normals;
    std::vector<float> vec_colors;


public:
    Sphere( float radius, int sector_count, int stack_count, glm::vec3 color );

    const float *get_vertices() const override;
    const unsigned int *get_indices() const override;
    const unsigned int get_index_count() const override;

    const float *get_colors() const override;

    const float *get_normals() const override;
};