/*
Name: Cao Khac LE Duy
1351008
Computer Graphic HW2
*/

#include <iostream>
#include "H_Display.h"
#include "Menu.h"




void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Homework 2");
	init();
	glLineWidth(2.0);
	glPointSize(2.0);
	glutMouseFunc(MouseAction);
	glutMotionFunc(MouseMotion);
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	//glutIdleFunc(idle);//(NEW) gọi hàm idle()
	MAIN_MENU = new Menu(menu,h,w);
	glutMainLoop();
	delete MAIN_MENU;

}
