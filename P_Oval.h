#pragma once
#include "SP_Shape.h"
#include "H_Display.h"

class Oval : public Shape{
protected:
	int r1;
	int r2;
public:
	Oval(int startx, int starty) :Shape(startx, starty){

	}

	void draw() = 0;

	void setLast(int x, int y){
		this->xF = (x + xS) / 2;
		this->yF = (y + yS) / 2;
	}
};