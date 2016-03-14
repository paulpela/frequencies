#include "config.h"

#include "Graph1.h"

GLfloat Graph1::graphFunction(GLfloat x) {
    GLfloat output = 0.0f;

    if(x > 100.0f && x < 200.0f) {
        output += glm::smoothstep(0.0f, 100.0f, x - 100.0f) * 100.0f;
    }

    if(x >= 200.0f && x < 500.0f) {
        output += glm::smoothstep(100.0f, 0.0f, x - 200.0f) * 100.0f;
    }

    if(x > 800.0f && x < 1000.0f) {
        output -= glm::smoothstep(0.0f, 200.0f, x - 800.0f) * 100.0f;
    }
    
    output += SCREEN_Y / 2.0f + 200.0f;

    return output;
}

Graph1::Graph1() : Graph() {

}
