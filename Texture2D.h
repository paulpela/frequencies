#pragma once

#include <GL/glew.h>

class Texture2D {
    public:
        Texture2D(GLsizei width, GLsizei height, GLuint mipmapLevels = 0);
        ~Texture2D();

        void bind(GLuint textureUnit = 0);
        void unbind();

        void updateData(GLfloat data[]);

        void setMinFilter(GLenum mode);
        void setMagFilter(GLenum mode);

        void setWrapModeS(GLenum mode);
        void setWrapModeT(GLenum mode);

        void setMipmapLevels(GLuint levels);

        GLuint getTextureID();
        GLsizei getWidth();
        GLsizei getHeight();

    protected:
        GLuint m_TBO;
        GLsizei m_width;
        GLsizei m_height;
        GLuint m_mipmapLevels;

};
