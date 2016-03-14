#pragma once

#include <cmath>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/noise.hpp>

#include "Mesh.h"

class Graph : public Mesh {
    public:
        Graph();
        ~Graph();
        void setup();
        void update();
        void render();

        void setMousePosition(int x, int y);

    protected:
        virtual GLfloat graphFunction(GLfloat x) = 0;
        GLfloat randomComponent();

        glm::vec2 m_mousePosition;

        void rebuildBuffer();
};
