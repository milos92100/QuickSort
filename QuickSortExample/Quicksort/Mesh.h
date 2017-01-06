//
// Created by milos on 6.11.16..
//

#ifndef QUICKSORT_MESH_H
#define QUICKSORT_MESH_H

#include <glm/glm.hpp>
#include <GL/glew.h>

class Vertex {
public:
    Vertex(glm::vec3 pos) {
        this->pos = pos;
    }

protected:
private:
    glm::vec3 pos;
};


class Mesh {

public:
    Mesh(Vertex *vertices, unsigned int numVertices);

    ~Mesh();

    void draw();

private:

    enum {
        POSITION_VB,
        NUM_BUFFERS
    };

    GLuint m_vertexArrayObject;
    GLuint m_vertexArrayBuffer[NUM_BUFFERS];
    unsigned int m_drawCount;

};


#endif //QUICKSORT_MESH_H
