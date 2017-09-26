#pragma once 
# define M_PI 3.14159265358979323846  /* pi */
#include <GL/glut.h>
#include "H_Display.h"

class Shape {
protected:
	int xS;
	int yS;
	int xF;
	int yF;
public:
	Shape(int startx, int starty){
		this->xS = startx;
		this->xF = startx;
		this->yS = starty;
		this->yF = starty;
	}
	virtual void draw() = 0;
	
	virtual void setStart(int x, int y){
		this->xS = x;
		this->yS = y;
	}

	virtual void setLast(int x, int y){
		this->xF = x;
		this->yF = y;
	}

	int getLast(){
		return xF;
	}

	int getStart(){
		return xS;
	}
};