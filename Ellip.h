#pragma once
#include "P_Oval.h"
#include <math.h>

class Ellip : public Oval{
private:
public:
	Ellip(int startx, int starty) : Oval(startx, starty){
	}

	void setLast(int x, int y){
		Oval::setLast(x, y);
		this->r1 = abs(x - xS) / 2;
		this->r2 = abs(y - yS) / 2;
	}

	void draw(){
		midEllipse(xF, yF, r1, r2);
	}

	void midEllipse(GLint x, GLint y, GLint rh, GLint rv){
		GLint xx = 0;
		GLint yy = rv;
		
		GLint rv2 = rv*rv;
		GLint rh2 = rh*rh;
		GLint tworv2 = 2 * rv2;
		GLint tworh2 = 2 * rh2;
		GLint dx = tworv2*xx;
		GLint dy = tworh2*yy;

		glVertex2d(xx + x, yy + y);
		glVertex2d(-xx + x, yy + y);
		glVertex2d(xx + x, -yy + y);
		glVertex2d(-xx + x, -yy + y);	
		GLint p = round(rv2 - rh2*rv + rh2*0.25);
		GLint p2 = round(rv2*(xx + 0.5)*(xx + 0.5) + rh2*(yy - 1)*(yy - 1) - rh2*rv2);
		
		glBegin(GL_POINTS);
		while (dx<dy){
			xx++;
			dx += tworv2;
			if (p < 0){
				p += dx + rv2;
			}
			else{
				yy--;
				dy -= tworh2;
				p += (dx - dy + rv2);
			}
			glVertex2d(xx + x, yy + y);
			glVertex2d(-xx + x, yy + y);
			glVertex2d(xx + x, -yy + y);
			glVertex2d(-xx + x, -yy + y);
		}


		while (yy>0){
			
			yy--;
			dy -= tworh2;
			if (p2 > 0){
				p2 += (rh2 - dy);
			}
			else{
				xx++;
				dx += tworv2;
				p2 += (rh2 - dy + dx);
			}
			glVertex2d(xx + x, yy + y);
			glVertex2d(-xx + x, yy + y);
			glVertex2d(xx + x, -yy + y);
			glVertex2d(-xx + x, -yy + y);
		}

		glEnd();
	}
	
	double sqr(int b){
		return b*b;
	}

	void ElipDraw(GLint xt, GLint yt, GLint a, GLint b){
		int x = 0, y = b;
		int d1 = sqr(b) - b*sqr(a) + 0.25*sqr(a);
		int d2 = sqr(b)*sqr(x + 0.5) + sqr(a)*sqr(y - 1) - sqr(a)*sqr(b);
		int dx = 2 * x * sqr(b);
		int dy = 2 * y * sqr(a);
		glBegin(GL_POINTS);
		for (; dx < dy; x++){
			glVertex2d(x + xt, y + yt);
			glVertex2d(-x + xt, y + yt);
			glVertex2d(x + xt, -y + yt);
			glVertex2d(-x + xt, -y + yt);
			dx = dx + 2 * sqr(b);
			if (d1 < 0){
				d1 = d1 + dx + sqr(b);
			}
			else{
				y--;
				dy = dy - 2 * sqr(a);
				d1 = d1 + dx - dy + sqr(b);
			}
		}

		for (; y > 0; y--){
			glVertex2d(x + xt, y + yt);
			glVertex2d(-x + xt, y + yt);
			glVertex2d(x + xt, -y + yt);
			glVertex2d(-x + xt, -y + yt);
			dy = dy - 2 * sqr(a);
			if (d2 > 0){
				d2 = d2 - dy + sqr(a);
			}
			else{
				x++;
				dx = dx + 2 * sqr(b);
				d2 = d2 + dx - dy + sqr(a);
			}
		}
		glEnd();
	}
};