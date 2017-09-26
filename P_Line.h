#pragma once
#include "SP_Shape.h"
#include "H_Display.h"

using namespace std;

class P_Line : public Shape{
private: 
public:
	P_Line(int startx, int starty):Shape(startx, starty){
		
	}

	void draw() {
		glBegin(GL_LINES);
		glVertex2d(xS, yS);
		glVertex2d(xF, yF);
		glEnd();
	}

};