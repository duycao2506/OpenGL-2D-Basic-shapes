#pragma once
#include "SP_Shape.h"
#include "H_Display.h"

class Sign : public Shape{
protected:
public:
	Sign(int startx, int starty) :Shape(startx, starty){

	}

	void draw() = 0;

	void setLast(int x, int y){
		Shape::setLast(x, y);
	}
};