#include "config.h"

#include "Texture2D.h"

// TODO set texture unit upfront
Texture2D::Texture2D(GLsizei width, GLsizei height, GLuint mipmapLevels) {
    glEnable(GL_TEXTURE_2D);

    m_width = width;
    m_height = height;
    m_mipmapLevels = 8;

    glGenTextures(1, &m_TBO);
    bind();

    glTexStorage2D(GL_TEXTURE_2D, m_mipmapLevels, GL_RGBA32F, m_width, m_height);

    if(m_mipmapLevels > 0) {
        setMagFilter(GL_LINEAR_MIPMAP_LINEAR);
        setMinFilter(GL_LINEAR_MIPMAP_LINEAR);
    } else {
        setMagFilter(GL_LINEAR);
        setMinFilter(GL_LINEAR);
    }

    setWrapModeS(GL_REPEAT);
    setWrapModeT(GL_REPEAT);
}

Texture2D::~Texture2D() {
    glDeleteTextures(1, &m_TBO);
}

void Texture2D::bind(GLuint textureUnit) {
    if(m_TBO) {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, m_TBO);
    }
}

void Texture2D::unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
    glActiveTexture(GL_TEXTURE0);
}

void Texture2D::updateData(GLfloat data[]) {
    bind();
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, m_width, m_height, GL_RGBA, GL_FLOAT, data);

    glGenerateMipmap(GL_TEXTURE_2D);
}

void Texture2D::setMipmapLevels(GLuint levels) {
    m_mipmapLevels = levels;
    bind();
    // TODO: set other things accordingly
}

void Texture2D::setMinFilter(GLenum mode) {
    bind();
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, mode);
}

void Texture2D::setMagFilter(GLenum mode) {
    bind();
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mode);
}

void Texture2D::setWrapModeS(GLenum mode) {
    bind();
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, mode);
}

void Texture2D::setWrapModeT(GLenum mode) {
    bind();
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, mode);
}

GLuint Texture2D::getTextureID() {
    return m_TBO;
}

GLsizei Texture2D::getWidth() {
    return m_width;
}

GLsizei Texture2D::getHeight() {
    return m_height;
}
