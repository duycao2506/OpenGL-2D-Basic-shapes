#pragma once
#include "P_Sign.h"
#include "H_Display.h"
#include <math.h>
class Circle;
class Dividesign : public Sign{
protected:
	Circle* above;
	Circle*	below;
public:
	Dividesign(int startx, int starty) :Sign(startx, starty){
		
	}

	void draw() {
		float a = (xS + xF) / 2;
		float b = (yS + yF) / 2;
		//Drawing the above circle
		float xCircle = (xS + a) / 2;
		float yCircle = (yS + b) / 2;
		int d = sqrt(pow(xCircle - a,2) + pow(yCircle - b,2));
		above = new Circle(xCircle, yCircle + d / 2);
		above->setLast(xCircle, yCircle - d / 2);
		above->draw();
		//Drawing the below circle
		xCircle = (xF + a) / 2;
		yCircle = (yF + b) / 2;
		below = new Circle(xCircle, yCircle + d / 2);
		below->setLast(xCircle, yCircle - d / 2);
		below->draw();
		//Drawing the minus
		glBegin(GL_LINE_LOOP);
		float angle = M_PI;
		float shift = -angle / 16;
		float s = sin(shift);
		float c = cos(shift);
		int x1 = (xS - a)*c - (yS - b)*s + a;
		int y1 = (xS - a)*s + (yS - b)*c + b;
		for (int i = 0; i < 2; i++){
			shift = i * angle + M_PI / 2;
			s = sin(shift);
			c = cos(shift);
			glVertex2f((x1 - a)*c - (y1 - b)*s + a, (x1 - a)*s + (y1 - b)*c + b);
			shift = shift + angle / 8;
			s = sin(shift);
			c = cos(shift);
			glVertex2f((x1 - a)*c - (y1 - b)*s + a, (x1 - a)*s + (y1 - b)*c + b);
		}
		glEnd();
	}

	void setLast(int x, int y){
		Shape::setLast(x, y);
	}
};