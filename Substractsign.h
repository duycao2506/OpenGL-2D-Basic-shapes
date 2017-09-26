#pragma once
#include "P_Sign.h"
#include "H_Display.h"

class Substractsign : public Sign{
protected:
public:
	Substractsign(int startx, int starty) :Sign(startx, starty){

	}

	void draw() {
		glBegin(GL_LINE_LOOP);
		float a = (xS + xF) / 2;
		float b = (yS + yF) / 2;
		//Move the intial point to the middle
		float angle = M_PI;
		float shift = -angle / 16;
		float s = sin(shift);
		float c = cos(shift);
		int x1 = (xS - a)*c - (yS - b)*s + a;
		int y1 = (xS - a)*s + (yS - b)*c + b;
		for (int i = 0; i < 2; i++){
			shift = i * angle;
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