#pragma once
#include "P_Triangle.h"
#include "H_Display.h"

class Equilateral : public Triangle{
protected:

public:
	Equilateral(int startx, int starty) :Triangle(startx, starty){

	}

	void draw(){
		int x1 = (xS - xF)*cos(2 * M_PI / 3) - (yS - yF)*sin(2 * M_PI / 3) + xF;
		int x2 = (xS - xF)*cos(-2 * M_PI / 3) - (yS - yF)*sin(-2 * M_PI / 3) + xF;
		int y1 = (xS - xF)*sin(2 * M_PI / 3) + (yS - yF)*cos(2 * M_PI / 3) + yF;
		int y2 = (xS - xF)*sin(-2 * M_PI / 3) + (yS-yF)*cos(-2 * M_PI / 3) + yF;
		glBegin(GL_LINES);
		glVertex2d(xS, yS);
		glVertex2d(x1, y1);
		glVertex2d(x2, y2);
		glVertex2d(xS, yS);
		glVertex2d(x1, y1);
		glVertex2d(x2, y2);
		glEnd();
	}
	void setLast(int x, int y){
		xF = (2*x + xS)/3;
		yF = (2*y + yS)/3;
		
	}
};