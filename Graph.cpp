#include "config.h"
#include "Graph.h"
#include <iostream>
#include <glm/glm.hpp>

Graph::Graph() : Mesh() {
    m_mousePosition = glm::vec2(10.0f, 10.0f);
}

Graph::~Graph() {

}

void Graph::setup() {
    bindVAO();

    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, SCREEN_X * 2 * sizeof(GLfloat), NULL, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), 0);
    glEnableVertexAttribArray(0);

    unbindVAO();
}

void Graph::render() {
    bindVAO();

    rebuildBuffer();

    glDrawArrays(GL_LINE_STRIP, 0, SCREEN_X);
    unbindVAO();
}

void Graph::update() {

}

void Graph::rebuildBuffer() {
    glm::vec2 buffer[SCREEN_X];
    
    for(int i = 0; i < SCREEN_X; i++) {
        buffer[i].x = (GLfloat) i;
        buffer[i].y = graphFunction((GLfloat) i);
    }
    
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferSubData(GL_ARRAY_BUFFER, 0, SCREEN_X * 2 * sizeof(GLfloat), buffer);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

GLfloat Graph::randomComponent() {
    return (GLfloat) random() / (GLfloat) RAND_MAX;
}

void Graph::setMousePosition(int x, int y) {
    m_mousePosition.x = (GLfloat) x;
    m_mousePosition.y = (GLfloat) y;

    if(x == 0) {
        m_mousePosition.x = 1.0f;
    }

    if(y == 0) {
        m_mousePosition.y = 1.0f;
    }
}
