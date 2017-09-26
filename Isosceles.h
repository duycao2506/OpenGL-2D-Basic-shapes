#pragma once
#include "P_Triangle.h"
#include "H_Display.h"

class Isosceles : public Triangle{
protected:

public:
	Isosceles(int startx, int starty) :Triangle(startx, starty){

	}

	void draw(){
		int a = (xF + xS) / 2;
		int b = (yF + yS) / 2;
		double x1 = -(yF-b) + a ;
		double y1 = (xF-a) + b;
		glBegin(GL_LINES);
		glVertex2d(xS, yS);
		glVertex2d(xF, yF);
		glVertex2d(x1, y1);
		glVertex2d(xS, yS);
		glVertex2d(xF, yF);
		glVertex2d(x1, y1);
		glEnd();
	};

	void setLast(int x, int y){
		Triangle::setLast(x, y);
	}
};