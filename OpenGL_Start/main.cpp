/*Несколько моментов:
 * Первый Qt не поддерживает русские символы совсем(кроме комментариев, так что вывод в консоль цифры или инглиш
 * Второе программа ниже анимирует движение треугольника по окружности используя параметрические уравнения
 * Третье причина по кторой нужно открывать именно это проект, а не создавать самостоятельно новый, и почему
 *  если захочешь создать свой новый проект, то легче скопировать это проект и переименовать имя папки с проектом и pro файла
 * на имя твоего проекта, заключается в наличие файла библиотеки в папке .dll, а также в настройках прописанных в .pro файде
 */

#include <GL/glut.h>
#include<iostream>
#include "drawlib.h"

//функция отрисовки холста
void renderScene(void);

void timer(int value);
int scene = 1;
int Ticks = 20;

void timer(int value)
{

    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,1);
}


int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800, 800);
    glutCreateWindow("OpenGL Start Application");
    glutDisplayFunc(renderScene);
    glutTimerFunc(20, timer, 1);
    glutMainLoop();
    return 0;
}


void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    switch(scene)
    {
    case 1:
    draw_scene_1(scene);
        break;
    case 2:
    draw_scene_2(scene);
        break;
    case 3:
    draw_scene_3(scene);
        break;
    case 4:
    draw_scene_4(scene);
        break;
    case 5:
    draw_scene_5(scene);
        break;
    case 6:
    draw_scene_6(scene);
        break;
    }



    glutSwapBuffers();
}
