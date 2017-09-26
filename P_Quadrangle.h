#pragma once
#include "SP_Shape.h"
#include "H_Display.h"

class Quadrangle : public Shape{
protected:

public:
	Quadrangle(int startx, int starty) :Shape(startx, starty){

	}

	void draw()  {
		glBegin(GL_LINES);
		glVertex2d(xS, yS);
		glVertex2d(xS, yF);
		glVertex2d(xF, yF);
		glVertex2d(xF, yS);
		glVertex2d(xS, yS);
		glVertex2d(xF, yS);
		glVertex2d(xF, yF);
		glVertex2d(xS, yF);
		glEnd();
	};
	
	void setLast(int x, int y){
		Shape::setLast(x, y);
	}
};