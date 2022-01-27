#pragma once

#include "../Utility/ColoredVertex.hpp"

#include <vector>

class PrimitiveRenderer
{
public:
    static void draw_points( const std::vector<glm::vec3>& points, glm::vec3 color, float point_size = 1 );
    static void draw_points( const std::vector<ColoredVertex>& vertices, float point_size = 1 );
    // points are grouped in pairs to represent lines
    static void draw_lines( const std::vector<glm::vec3>& lines, glm::vec3 color, float line_width = 1 );
    static void draw_lines( const std::vector<ColoredVertex>& vertices, float line_width = 1 );
    static void draw_multiline( const std::vector<glm::vec3>& points, glm::vec3 color, float line_width = 1 );
    static void draw_multiline( const std::vector<ColoredVertex>& vertices, float line_width = 1 );
    static void draw_triangle( glm::vec3 p1, glm::vec3 p2, glm::vec3 p3, glm::vec3 color );
    static void draw_triangle( ColoredVertex p1, ColoredVertex p2, ColoredVertex p3 );
    static void draw_triangle_fan( const std::vector<glm::vec3>& fan_vertices, glm::vec3 color );
    static void draw_quad( glm::vec3 p1, glm::vec3 p2, glm::vec3 p3, glm::vec3 p4, glm::vec3 color );
    static void draw_quad( ColoredVertex p1, ColoredVertex p2, ColoredVertex p3, ColoredVertex p4 );
};