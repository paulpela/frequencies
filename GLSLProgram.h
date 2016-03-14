#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>

class GLSLProgram {
public:
    GLSLProgram();
    ~GLSLProgram();

    void addVertexShader(const std::string &shaderPath);
    void addFragmentShader(const std::string &shaderPath);
    void addTessellationControlShader(const std::string &shaderPath);
    void addTessellationEvaluationShader(const std::string &shaderPath);
    void addGeometryShader(const std::string &shaderPath);

    void compile();
    void start();
    void stop();
    GLuint getProgramID();
    GLint getUniformLocation(const std::string &uniformName);

    void setMatrix(const glm::mat4 &matrix, const GLenum &type);

private:
    GLuint m_programID;
    
    GLuint loadShaderFromFile(const std::string &filePath, GLenum shaderType);
    void freeProgram();
    void printProgramLog(GLuint program);
    void printShaderLog(GLuint shader);
    void loadShader(const std::string &shaderPath, GLenum type);
};
