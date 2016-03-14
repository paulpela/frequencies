#pragma once

#include <GL/glew.h>

class Mesh {
    public:
        Mesh();
        ~Mesh();
        virtual void setup() = 0;
        virtual void update() = 0;
        virtual void render() = 0;

        void bindVAO();
        void unbindVAO();

        GLuint getVAO();

        GLuint getVertexCount();
        GLuint getIndexCount();

    protected:
        GLuint m_VAO;
        GLuint m_VBO;
        GLuint m_IBO;
        GLuint m_NBO;

        GLuint m_nVertices;
        GLuint m_nIndices;
};
