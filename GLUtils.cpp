#include "config.h"

#include <GL/glew.h>
#include <GL/freeglut.h>

#include "GLUtils.h"
#include "App.h"

void render() {
    extern App *g_app;
    g_app->render();
}

void update() {
    extern App *g_app;
    g_app->update();
}

void mainLoop(int t) {
    update();
    render();
    glutTimerFunc(1000/FPS, mainLoop, t);
}

void mouseHandler(int button, int state, int x, int y) {

}

void keyboardHandler(unsigned char key, int x, int y) {
    if(key == 'q') {
        exit(0);
    }
}

void onResize(int x, int y) {
    glViewport(0, 0, x, y);
}

void passiveMouseMotion(int x, int y) {
    extern App *g_app;
    g_app->updateMouseMotion(x, y);
}
