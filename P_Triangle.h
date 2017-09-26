#pragma once
#include "SP_Shape.h"
#include "H_Display.h"

class Triangle : public Shape{
protected:

public:
	Triangle(int startx, int starty) :Shape(startx, starty){

	}

	virtual void draw() = 0;

	void setLast(int x, int y){
		Shape::setLast(x, y);
	}
};