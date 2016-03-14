#include "Mesh.h"

Mesh::Mesh() {
    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_VBO);
    glGenBuffers(1, &m_IBO);
    glGenBuffers(1, &m_NBO);

    m_nVertices = 0;
    m_nIndices = 0;
}

Mesh::~Mesh() {
    glDeleteBuffers(1, &m_VBO);
    glDeleteBuffers(1, &m_IBO);
    glDeleteBuffers(1, &m_NBO);
    glDeleteVertexArrays(1, &m_VAO);
}

void Mesh::bindVAO() {
    glBindVertexArray(getVAO());
}

void Mesh::unbindVAO() {
    glBindVertexArray(0);
}

GLuint Mesh::getVAO() {
    return m_VAO;
}

GLuint Mesh::getVertexCount() {
    return m_nVertices;
}

GLuint Mesh::getIndexCount() {
    return m_nIndices;
}
