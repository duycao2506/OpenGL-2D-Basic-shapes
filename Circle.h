#pragma once
#include "P_Oval.h"
#include <math.h>

class Circle : public Oval{
private:
public:
	Circle(int startx, int starty) : Oval(startx, starty){

	}

	void setLast(int x, int y){
		Oval::setLast(x, y);
		this->r1 = sqrt(pow(xF - xS, 2) + pow(yF - yS, 2));
		this->r2 = this->r1;
	}

	void draw(){
		midCircle(xF, yF, r2);
		cout << "Tron Ban kinh r: " << r2 << endl;
	}

	void midCircle(GLint x, GLint y, GLint r1){
		GLint xx, yy, p;
		xx = 0; yy = r1; p = 1 - r1;
		glBegin(GL_POINTS);
		while (true){
			glVertex2d(xx + x, yy + y);
			glVertex2d(-xx + x, yy + y);
			glVertex2d(xx + x, -yy + y);
			glVertex2d(-xx + x, -yy + y);
			glVertex2d(yy + x, xx + y);
			glVertex2d(yy + x, -xx + y);
			glVertex2d(-yy + x, xx + y);
			glVertex2d(-yy + x, -xx + y);

			if (yy <= xx) break;
			if (p < 0){
				p += (2 * (xx)+3);
			}
			else{
				p += (2 * (xx - yy) + 3);
				yy -= 1;
			}
			xx += 1;
		}
		glEnd();
	}

};