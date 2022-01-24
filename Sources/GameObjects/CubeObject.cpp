#include "CubeObject.hpp"

#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

CubeObject::CubeObject(float size_side, glm::vec3 color) : Cube(size_side, color) 
{

}

void CubeObject::draw() 
{
	load_transformation();
	
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	    glVertexPointer(3, GL_FLOAT, 0, vertices);
	    glColorPointer(3, GL_FLOAT, 0, colors);
	    glNormalPointer(GL_FLOAT, 0, normals);

	    glDrawElements(GL_TRIANGLES, sizeof(unsigned char) * INDEX_COUNT, GL_UNSIGNED_BYTE, indices);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}
