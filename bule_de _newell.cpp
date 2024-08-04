#include <GL/glut.h>
#include <stdio.h>

void init(void) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Cor de fundo preta
    glEnable(GL_DEPTH_TEST);             // Habilitar teste de profundidade
    gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
}

void display(void) {
    glViewport(0, 0, 1200, 600);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Desenha o Bule de Newell
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -5.0f); // Move o bule para trás para que seja visível
    glColor3f(1.0f, 0.0f, 0.0f);    // Define a cor do bule como vermelho
    glutSolidTeapot(1.0);          // Desenha o bule com raio 1
    glPopMatrix();
    
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1200, 600);
    glutCreateWindow("Bule de Newell");

    glutDisplayFunc(display);

    init();

    glutMainLoop();

    return 0;
}