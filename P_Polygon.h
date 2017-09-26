#pragma once
#include "SP_Shape.h"
#include "H_Display.h"

class Polygon : public Shape{
protected:

public:
	Polygon(int startx, int starty) :Shape(startx, starty){

	}

	virtual void draw() {
		int edgesnum = this->numEdges();
		double pid3 = 2*M_PI / edgesnum;
		int a = (xS + xF) / 2;
		int b = (yS + yF) / 2;
		glBegin(GL_LINES);
		for (int i = 0; i < edgesnum; i++){
			double angle = i*pid3;
			double cosine = cos(angle);
			double sine = sin(angle);
			double cosine1 = cos(angle + pid3);
			double sine1 = sin(angle + pid3);
			glVertex2d((xS - a)*cosine - (yS - b)*sine + a, (xS - a)*sine + (yS - b)*cosine + b);
			glVertex2d((xS - a)*cosine1 - (yS - b)*sine1 + a, (xS - a)*sine1 + (yS - b)*cosine1 + b);
		}
		glEnd();
	}

	virtual int numEdges() = 0;

	void setLast(int x, int y){
		Shape::setLast(x, y);
	}
};