#pragma once
#include "P_Polygon.h"
#include "H_Display.h"

class Sixequal : public Polygon{
protected:

public:
	Sixequal(int startx, int starty) :Polygon(startx, starty){

		

	}

	void draw() {
		Polygon::draw();
	}

	int numEdges(){
		return 6;
	}

	void setLast(int x, int y){
		Polygon::setLast(x, y);
	}
};

/*
glVertex2d((xS - a)*cos(pid3) - (yS - b)*sin(pid3) + a, (xS - a)*sin(pid3) + (yS - b)*cos(pid3) + b);

glVertex2d((xS - a)*cos(2 * pid3) - (yS - b)*sin(2 * pid3) + a, (xS - a)*sin(2 * pid3) + (yS - b)*cos(2 * pid3) + b);
glVertex2d(xF, yF);

glVertex2d((xS - a)*cos(2 * pid3) - (yS - b)*sin(2 * pid3) + a, (xS - a)*sin(2 * pid3) + (yS - b)*cos(2 * pid3) + b);
glVertex2d((xS - a)*cos(pid3) - (yS - b)*sin(pid3) + a, (xS - a)*sin(pid3) + (yS - b)*cos(pid3) + b);

glVertex2d((xS - a)*cos(-2 * pid3) - (yS - b)*sin(-2 * pid3) + a, (xS - a)*sin(-2 * pid3) + (yS - b)*cos(-2 * pid3) + b);
glVertex2d(xF, yF);

glVertex2d((xS - a)*cos(-pid3) - (yS - b)*sin(-pid3) + a, (xS - a)*sin(-pid3) + (yS - b)*cos(-pid3) + b);
glVertex2d((xS - a)*cos(-2 * pid3) - (yS - b)*sin(-2 * pid3) + a, (xS - a)*sin(-2 * pid3) + (yS - b)*cos(-2 * pid3) + b);

*/