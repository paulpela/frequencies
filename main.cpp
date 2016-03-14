#include "config.h"

#include <iostream>
#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

#include "GLUtils.h"
#include "App.h"

App *g_app;

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);
    glutInitWindowSize(SCREEN_X, SCREEN_Y);
    glutCreateWindow(argv[0]);

    if(glewInit() != GLEW_OK) {
        exit(1);
    }

    glutDisplayFunc(render);
    glutKeyboardFunc(keyboardHandler);
    glutMouseFunc(mouseHandler);
    glutReshapeFunc(onResize);
    glutPassiveMotionFunc(passiveMouseMotion);
    glutTimerFunc(1000/FPS, mainLoop, 0);
    glutFullScreen();

    glViewport(0, 0, SCREEN_X, SCREEN_Y);
    glEnable(GL_LINE_SMOOTH);

    g_app = new App();

    glutMainLoop();

    return 0;
}
