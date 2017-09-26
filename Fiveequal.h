#pragma once
#include "P_Polygon.h"
#include "H_Display.h"

class Fiveequal : public Polygon{
protected:

public:
	Fiveequal(int startx, int starty) :Polygon(startx, starty){
		
	}

	void draw() {
		Polygon::draw();
	}

	int numEdges(){
		return 5;
	}

	void setLast(int x, int y){
		Polygon::setLast(x, y);
	}
};