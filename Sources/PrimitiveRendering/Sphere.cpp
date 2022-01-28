#include "Sphere.hpp"

#include <cmath>

Sphere::Sphere(float radius, int sector_count, int stack_count, glm::vec3 color) 
{
    float x, y, z, xy;                              // vertex position
    float nx, ny, nz, lengthInv = 1.0f / radius;    // vertex normal

    float sectorStep = 2 * M_PI / sector_count;
    float stackStep = M_PI / stack_count;
    float sectorAngle, stackAngle;

    for(int i = 0; i <= stack_count; ++i)
    {
        stackAngle = M_PI / 2 - i * stackStep;        // starting from pi/2 to -pi/2
        xy = radius * cosf(stackAngle);             // r * cos(u)
        z = radius * sinf(stackAngle);              // r * sin(u)

        // add (sectorCount+1) vertices per stack
        // the first and last vertices have same position and normal, but different tex coords
        for(int j = 0; j <= sector_count; ++j)
        {
            sectorAngle = j * sectorStep;           // starting from 0 to 2pi

            // vertex position (x, y, z)
            x = xy * cosf(sectorAngle);             // r * cos(u) * cos(v)
            y = xy * sinf(sectorAngle);             // r * cos(u) * sin(v)
            vec_vertices.push_back(x);
            vec_vertices.push_back(y);
            vec_vertices.push_back(z);

            // normalized vertex normal (nx, ny, nz)
            nx = x * lengthInv;
            ny = y * lengthInv;
            nz = z * lengthInv;
            vec_normals.push_back(nx);
            vec_normals.push_back(ny);
            vec_normals.push_back(nz);

            vec_colors.push_back( color.r );
            vec_colors.push_back( color.g );
            vec_colors.push_back( color.b );
        }
        
    }

    int k1, k2;
    for(int i = 0; i < stack_count; ++i)
    {
        k1 = i * (sector_count + 1);     // beginning of current stack
        k2 = k1 + sector_count + 1;      // beginning of next stack

        for(int j = 0; j < sector_count; ++j, ++k1, ++k2)
        {
            // 2 triangles per sector excluding first and last stacks
            // k1 => k2 => k1+1
            if(i != 0)
            {
                vec_indices.push_back(k1);
                vec_indices.push_back(k2);
                vec_indices.push_back(k1 + 1);
            }

            // k1+1 => k2 => k2+1
            if(i != (stack_count-1))
            {
                vec_indices.push_back(k1 + 1);
                vec_indices.push_back(k2);
                vec_indices.push_back(k2 + 1);
            }
        }
    }
}

const float* Sphere::get_vertices() const 
{
    return vec_vertices.data();
}

const unsigned int* Sphere::get_indices() const 
{
    return vec_indices.data();
}

const unsigned int Sphere::get_index_count() const 
{
    return vec_indices.size();
}

const float* Sphere::get_colors() const 
{
    return vec_colors.data();
}

const float* Sphere::get_normals() const 
{
    return vec_normals.data();
}
