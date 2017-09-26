#pragma once
#include "P_Quadrangle.h"
#include "H_Display.h"
#include <math.h>
class Square : public Quadrangle{
protected:

public:
	Square(int startx, int starty) :Quadrangle(startx, starty){

	}

	void draw()  {
		Quadrangle::draw();
	};

	void setLast(int x, int y){
		int dx = x - xS;
		int dy = y - yS;
		int d = 0;
		int absdy = abs(dy);
		int absdx = abs(dx);
		if (absdx < absdy){
			d = absdx * dy;
			d = d / absdy;
			xF = x;
			yF = yS + d;
			return;
		}
		d = absdy * dx;
		d = d / absdx;
		yF = y;
		xF = xS + d;
	}
};