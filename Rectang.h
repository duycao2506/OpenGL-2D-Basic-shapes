#pragma once
#include "P_Quadrangle.h"
#include "H_Display.h"

class Rectang : public Quadrangle{
protected:

public:
	Rectang(int startx, int starty) :Quadrangle(startx, starty){
	}

	void draw()  {
		Quadrangle::draw();
	};

	void setLast(int x, int y){
		Quadrangle::setLast(x, y);
	}
};