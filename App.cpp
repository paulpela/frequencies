#include "config.h"

#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "App.h"
#include "Graph1.h"
#include "Graph2.h"
#include "TextureGenerator.h"

void App::render() {
    glClearBufferfv(GL_COLOR, 0, glm::value_ptr(m_clearColor));
    glClearBufferfv(GL_DEPTH, 0, &m_depthBufferDefault);
    m_texture->bind();
    m_shader->start();
    m_shader->setMatrix(m_projectionMatrix, GL_PROJECTION_MATRIX);

    m_graph[0]->render();
    m_graph[1]->render();

    m_shader->stop();
    glutSwapBuffers();
}

App::App() {
    m_clearColor = glm::vec4(0.05f, 0.05f, 0.05f, 1.0f);
    m_depthBufferDefault = 1.0f;
    m_projectionMatrix = glm::ortho(0.0f, (float) SCREEN_X, (float) SCREEN_Y, 0.0f, 0.0f, 1.0f);

    m_shader = new GLSLProgram();
    m_shader->addVertexShader("shaders/plain.vs.glsl");
    m_shader->addFragmentShader("shaders/plain.fs.glsl");
    m_shader->compile();
    m_shader->setMatrix(m_projectionMatrix, GL_PROJECTION_MATRIX);

    m_graph[0] = new Graph1();
    m_graph[0]->setup();

    m_graph[1] = new Graph2();
    m_graph[1]->setup();

    m_texture = new Texture2D(256, 256);

    float *data = new float[256 * 256 * 4];
    textureGenerator(data, 256, 256);
    m_texture->updateData(data);
    delete[] data;
    
}

App::~App() {
    delete m_shader;
}

void App::update() {
    m_graph[0]->update();
    m_graph[1]->update();
}

void App::updateMouseMotion(int x, int y) {
    m_graph[0]->setMousePosition(x, y);
    m_graph[1]->setMousePosition(x, y);
}
