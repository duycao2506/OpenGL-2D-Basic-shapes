/*
Name: Cao Khac LE Duy
1351008
Computer Graphic HW2
*/

#pragma once
#include <iostream>
#include <stdlib.h>
#include <gl\glut.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include "Menu.h"
#include "ColorAlgorithm.h"

/////////////////////////
/////Setting up
/////////////////
double h = 1000.0;
double w = 1000;
double oldw = 1000;



//////////////////////////////
//////////////////////////////
////
//Display


void MouseAction(int button, int state, int x, int y){
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && isDrawing != true ){
		isDrawing = true;
		MAIN_MENU->curModeAction(x, y);
	}
	if ( button == GLUT_LEFT_BUTTON && state == GLUT_UP){
		isDrawing = false;
	}
	
}

void MouseMotion(int x, int y){
	if (isDrawing){
		MAIN_MENU->GetCurShape()->setLast(x, y);
		glutPostRedisplay();
	}
}


void init(){
	glClearColor(236/255.0, 236/255.0, 236/255.0,1);
	gluOrtho2D(0.0, w, h, 0.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);//Xóa màn hình
	glColor3d(B_Color.r/255.0,B_Color.g/255.0,B_Color.b/255.0);
	
	MAIN_MENU->Draw();
	glFlush();
}


void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
	h = height;
	MAIN_MENU->changeScreenHeight(h);
	w = width;
	MAIN_MENU->changeScreenWidth(w);
	glutMouseFunc(MouseAction);
	glutMotionFunc(MouseMotion);
	glViewport(0, 0, w, h);
	glLoadIdentity();
	glOrtho(0, w, h, 0, 1.0, -1.0);
	glutPostRedisplay();
}


