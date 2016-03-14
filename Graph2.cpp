#include "config.h"

#include "Graph2.h"

GLfloat Graph2::graphFunction(GLfloat x) {
    GLfloat output = 0.0f;

    output += sin(x / 32.0f) * 10.0f;
    output += randomComponent() * 8.0f;

    if(x > 100.0f && x < 200.0f) {
        output += glm::smoothstep(0.0f, 100.0f, x - 100.0f) * 100.0f;
    }

    if(x >= 200.0f && x < 500.0f) {
        output += glm::smoothstep(100.0f, 0.0f, x - 200.0f) * 100.0f;
    }

    output += sin(x - 3.0f) * 10.0f;

    if(x > 800.0f && x < 1000.0f) {
        output -= glm::smoothstep(0.0f, 200.0f, x - 800.0f) * 100.0f;
    }

    output += SCREEN_Y / 2.0f - 200.0f;

    return output;
}

Graph2::Graph2() : Graph() {

}
