#pragma once
#include "P_Others.h"
#include "H_Display.h"

class Star : public Others{
protected:

public:
	Star(int startx, int starty) : Others(startx, starty){
	}

	void draw()  {
		int a = (xS + xF) / 2;
		int b = (yS + yF) / 2;
		double pid10 = M_PI / 5.0;
		glBegin(GL_LINES);
		for (int i = 0; i <= 10; i++){
			double angle = i*pid10;
			double cosine = cos(angle);
			double sine = sin(angle);
			double cosine1 = cos(angle + pid10);
			double sine1 = sin(angle + pid10);
			int x1temp = (xS - a)*cosine - (yS - b)*sine + a;
			int y1temp = (xS - a)*sine + (yS - b)*cosine + b;
			int x2temp = (xS - a)*cosine1 - (yS - b)*sine1 + a;
			int y2temp = (xS - a)*sine1 + (yS - b)*cosine1 + b;
			if (i % 2 != 0)
			{
				x1temp = (x1temp+a)/2;
				y1temp = (y1temp + b)/2;
			}
			else{
				x2temp = (x2temp + a) / 2;
				y2temp = (y2temp + b) / 2;
			}
			glVertex2d(x1temp, y1temp);
			glVertex2d(x2temp, y2temp );
		}

		glEnd();

	};

	void setLast(int x, int y){
		Others::setLast(x, y);
	}
};