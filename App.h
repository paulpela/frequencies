#pragma once

#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>

#include "GLSLProgram.h"
#include "Graph.h"
#include "Texture2D.h"

class App {
    public:
        App();
        ~App();

        void render();
        void update();

        void updateMouseMotion(int x, int y);
    private:
        glm::vec4 m_clearColor;
        GLfloat m_depthBufferDefault;

        glm::mat4 m_projectionMatrix;

        GLSLProgram *m_shader;

        Graph *m_graph[2];

        Texture2D *m_texture;
};
