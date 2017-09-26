#pragma once
#include "P_Others.h"
#include "H_Display.h"
#include <math.h>
class Arrow : public Others{
protected:

public:
	Arrow(int startx, int starty) : Others(startx, starty){
	}

	void draw()  {
		double pid10 = M_PI / 5.0;
		//Calculating 

		double RATIO1 = 1 / 12;
		double RATIO2 = 1 / 3;

		int xneck = (3 * xF + xS) / 4;
		int yneck = (3 * yF + yS) / 4;

		//One side
		int x1 = -(yF - yneck) + xneck;
		int y1 = (xF - xneck) + yneck;

		int x2 = (2 * xneck + x1) / 3;
		int y2 = (2 * yneck + y1) / 3;

		int xtemp = (xF + 11 * xS) / 12;
		int ytemp = (yF + 11* yS) / 12;

		int x3 = -(ytemp - yS) + xS;
		int y3 = (xtemp - xS) + yS;

		//Other side
		int x1o = 2 * xneck - x1;
		int y1o = 2 * yneck - y1;

		int x2o = 2 * xneck - x2;
		int y2o = 2 * yneck - y2;

		int x3o = 2 * xS - x3;
		int y3o = 2 * yS - y3;
		
		glBegin(GL_LINES);
		
		glVertex2d(x3, y3);
		glVertex2d(x2, y2);
		
		glVertex2d(x2, y2);
		glVertex2d(x1, y1);

		glVertex2d(x1, y1);
		glVertex2d(xF, yF);

		glVertex2d(xF, yF);
		glVertex2d(x1o, y1o);

		glVertex2d(x1o, y1o);
		glVertex2d(x2o, y2o);

		glVertex2d(x2o, y2o);
		glVertex2d(x3o, y3o);

		glVertex2d(x3o, y3o);
		glVertex2d(x3, y3);

		glEnd();

	};

	void setLast(int x, int y){
		Others::setLast(x, y);
	}
};