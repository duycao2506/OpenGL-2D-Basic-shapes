#pragma once
#include "SP_Shape.h"
#include "H_Display.h"

class Others : public Shape{
protected:
public:
	Others(int startx, int starty) :Shape(startx, starty){

	}

	void draw() = 0;

	void setLast(int x, int y){
		Shape::setLast(x, y);
	}
};