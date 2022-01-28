#include "PrimitiveRenderer.hpp"

#include <GL/glew.h>

void PrimitiveRenderer::draw_points(const std::vector<glm::vec3>& points, glm::vec3 color, float point_size) 
{
    glPointSize(point_size);
    glColor3f( color.r, color.g, color.b );
    glEnableClientState( GL_VERTEX_ARRAY );
        glVertexPointer( 3, GL_FLOAT, 0, points.data() );
        glDrawArrays( GL_POINTS, 0, points.size() );
    glDisableClientState( GL_VERTEX_ARRAY );
    glColor3f( 1.f, 1.f, 1.f );
}

void PrimitiveRenderer::draw_points( const std::vector<ColoredVertex>& vertices, float point_size ) 
{
    glPointSize(point_size);
    glEnableClientState( GL_VERTEX_ARRAY );
    glEnableClientState( GL_COLOR_ARRAY );
        glVertexPointer( 3, GL_FLOAT, sizeof(ColoredVertex), vertices.data() );
        glColorPointer( 3, GL_FLOAT, sizeof(ColoredVertex), vertices.data() + offsetof(ColoredVertex, color) );
        glDrawArrays( GL_POINTS, 0, vertices.size() );
    glDisableClientState( GL_COLOR_ARRAY );
    glDisableClientState( GL_VERTEX_ARRAY );
}

void PrimitiveRenderer::draw_lines(const std::vector<glm::vec3>& lines, glm::vec3 color, float line_width) 
{
    glLineWidth(line_width);
    glColor3f( color.r, color.g, color.b );
    glEnableClientState( GL_VERTEX_ARRAY );
        glVertexPointer( 3, GL_FLOAT, 0, lines.data() );
        glDrawArrays( GL_LINES, 0, lines.size() );
    glDisableClientState( GL_VERTEX_ARRAY );
    glColor3f( 1.f, 1.f, 1.f );
}

void PrimitiveRenderer::draw_lines(const std::vector<ColoredVertex>& vertices, float line_width) 
{
    glLineWidth(line_width);
    glEnableClientState( GL_VERTEX_ARRAY );
    glEnableClientState( GL_COLOR_ARRAY );
        glVertexPointer( 3, GL_FLOAT, sizeof(ColoredVertex), vertices.data() );
        glColorPointer( 3, GL_FLOAT, sizeof(ColoredVertex), vertices.data() + offsetof(ColoredVertex, color) );
        glDrawArrays( GL_LINES, 0, vertices.size() );
    glDisableClientState( GL_COLOR_ARRAY );
    glDisableClientState( GL_VERTEX_ARRAY );
}

void PrimitiveRenderer::draw_multiline(const std::vector<glm::vec3>& points, glm::vec3 color, float line_width) 
{
    glLineWidth(line_width);
    glColor3f( color.r, color.g, color.b );
    glEnableClientState( GL_VERTEX_ARRAY );
        glVertexPointer( 3, GL_FLOAT, 0, points.data() );
        glDrawArrays( GL_LINE_STRIP, 0, points.size() );
    glDisableClientState( GL_VERTEX_ARRAY );   
    glColor3f( 1.f, 1.f, 1.f );
}

void PrimitiveRenderer::draw_multiline(const std::vector<ColoredVertex>& vertices, float line_width) 
{
    glLineWidth(line_width);
    glEnableClientState( GL_VERTEX_ARRAY );
    glEnableClientState( GL_COLOR_ARRAY );
        glVertexPointer( 3, GL_FLOAT, sizeof(ColoredVertex), vertices.data() );
        glColorPointer( 3, GL_FLOAT, sizeof(ColoredVertex), vertices.data() + offsetof(ColoredVertex, color) );
        glDrawArrays( GL_LINE_STRIP, 0, vertices.size() );
    glDisableClientState( GL_COLOR_ARRAY );
    glDisableClientState( GL_VERTEX_ARRAY );
}

void PrimitiveRenderer::draw_triangle(glm::vec3 p1, glm::vec3 p2, glm::vec3 p3, glm::vec3 color) 
{
    glm::vec3 points[3] = { p1, p2, p3 };

    glColor3f( color.r, color.g, color.b );
    glEnableClientState( GL_VERTEX_ARRAY );
        glVertexPointer( 3, GL_FLOAT, 0, points );
        glDrawArrays( GL_TRIANGLES, 0, 3 );
    glDisableClientState( GL_VERTEX_ARRAY );
    glColor3f( 1.f, 1.f, 1.f );   
}

void PrimitiveRenderer::draw_triangle(ColoredVertex p1, ColoredVertex p2, ColoredVertex p3) 
{
    ColoredVertex vertices[3] = { p1, p2, p3 };

    glEnableClientState( GL_VERTEX_ARRAY );
    glEnableClientState( GL_COLOR_ARRAY );
        glVertexPointer( 3, GL_FLOAT, sizeof(ColoredVertex), vertices );
        glColorPointer( 3, GL_FLOAT, sizeof(ColoredVertex), vertices + offsetof(ColoredVertex, color) );
        glDrawArrays( GL_TRIANGLES, 0, 3 );
    glDisableClientState( GL_COLOR_ARRAY );
    glDisableClientState( GL_VERTEX_ARRAY );
}

void PrimitiveRenderer::draw_triangle_fan( const std::vector<glm::vec3>& fan_vertices, glm::vec3 color ) 
{
    glColor3f( color.r, color.g, color.b );
    glEnableClientState( GL_VERTEX_ARRAY );
        glVertexPointer( 3, GL_FLOAT, 0, fan_vertices.data() );
        glDrawArrays( GL_TRIANGLE_FAN, 0, fan_vertices.size() );
    glDisableClientState( GL_VERTEX_ARRAY );
    glColor3f( 1.f, 1.f, 1.f );
}

void PrimitiveRenderer::draw_quad(glm::vec3 p1, glm::vec3 p2, glm::vec3 p3, glm::vec3 p4, glm::vec3 color) 
{
    glm::vec3 points[4] = { p1, p2, p3, p4 };

    glColor3f( color.r, color.g, color.b );
    glEnableClientState( GL_VERTEX_ARRAY );
        glVertexPointer( 3, GL_FLOAT, 0, points );
        glDrawArrays( GL_QUADS, 0, 4 );
    glDisableClientState( GL_VERTEX_ARRAY );   
    glColor3f( 1.f, 1.f, 1.f );
}

void PrimitiveRenderer::draw_quad(ColoredVertex p1, ColoredVertex p2, ColoredVertex p3, ColoredVertex p4) 
{
    ColoredVertex vertices[4] = { p1, p2, p3, p4 };

    glEnableClientState( GL_VERTEX_ARRAY );
    glEnableClientState( GL_COLOR_ARRAY );
        glVertexPointer( 3, GL_FLOAT, sizeof(ColoredVertex), vertices );
        glColorPointer( 3, GL_FLOAT, sizeof(ColoredVertex), vertices + offsetof(ColoredVertex, color) );
        glDrawArrays( GL_QUADS, 0, 4 );
    glDisableClientState( GL_COLOR_ARRAY );
    glDisableClientState( GL_VERTEX_ARRAY );
}
