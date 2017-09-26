#pragma once
#include "SP_Shape.h"


enum coloring_al_type{
	BOUNDARY,
	FLOOD,
	SCANLINE
};
class ColorPoint : public Shape{
private:
	unsigned char r;
	unsigned char g;
	unsigned char b;
	int screenh;
	int screenw;
	int algo;
public:
	bool isDraw = false;
	ColorPoint(int w, int h ,int x, int y, unsigned char r, unsigned char g, unsigned char b, int algo ) : Shape(x, y){
		this->xS = x;
		this->screenh = h;
		this->yS = y;
		this->r = r;
		this->g = g;
		this->b = b;
		this->screenw = w;
		this->algo = algo;
	}
	int getX(){
		return xS;
	}

	void draw(){
		ColorAlgorithm* CA = new ColorAlgorithm();
		CA->configHeightScreen(screenh);
		CA->setWidthScreen(screenw);
		RGBColor c = { r, g, b };
		CA->draw(algo, xS, yS, c);
		delete CA;
	}

	unsigned char getR(){
		return r;
	}

	unsigned char getG(){
		return g;
	}

	unsigned char getB(){
		return b;
	}

	int getY(){
		return yS;
	}
	void setX(int x){
		this->xS = x;
	}

	void setY(int y){
		this->yS = y;
	}

	void setLast(){

	}

};