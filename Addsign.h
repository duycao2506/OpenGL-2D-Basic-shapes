#pragma once
#include "P_Sign.h"
#include "H_Display.h"


class Addsign : public Sign{
protected:
public:
	Addsign(int startx, int starty) :Sign(startx, starty){
		
	}

	void draw() {
		glBegin(GL_LINE_LOOP);
		float angle = M_PI / 2;
		float a = (xS + xF) / 2;
		float b = (yS + yF) / 2;
		//For the open angle
		float xOrigin = xS;
		float yOrigin = yS;
		float scale = 2.7;
		//Move the intial point to the middle
		float shift = -angle / 8;
		float s = sin(shift);
		float c = cos(shift);
		int xxS = (xS - a)*c - (yS - b)*s + a;
		int yyS = (xS - a)*s + (yS - b)*c + b;
		for (int i = 0; i < 4; i++){
			shift = i * angle;
			s = sin(shift);
			c = cos(shift);
			glVertex2f((xxS - a)*c - (yyS - b)*s + a, (xxS - a)*s + (yyS - b)*c + b);
			shift = shift + angle / 4;
			s = sin(shift);
			c = cos(shift);
			glVertex2f((xxS - a)*c - (yyS - b)*s + a, (xxS - a)*s + (yyS - b )*c + b);
			shift = shift + angle / 4;
			s = sin(shift);
			c = cos(shift);
			float x = (xOrigin - a)*c - (yOrigin - b)*s + a;
			float y = (xOrigin - a)*s + (yOrigin - b)*c + b;
			glVertex2f((x + scale*a) / (scale + 1), (y + scale*b) / (scale + 1));
		}
		glEnd();
	}

	void setLast(int x, int y){
		Sign::setLast(x, y);

	}
};