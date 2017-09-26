#pragma once
#include <gl\glut.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <time.h>

using namespace std;

typedef struct{
	unsigned char r;
	unsigned char g;
	unsigned char b;
}RGBColor;


RGBColor B_Color = { 108, 122, 137};
RGBColor Background = { 236, 236, 236 };

typedef struct tEdge
{
	int yUpper;
	float xIntersect, dxPerScan;
	struct tEdge * next;
} Edge;

typedef struct tdcPt
{
	int x;
	int y;
} dcPt;



class ColorAlgorithm {
private:
	int h=0;
	int w = 0;
	RGBColor GetPixel(int x, int y){
		unsigned char* ptr = new unsigned char[3];
		glReadPixels(x, h - y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, ptr);
		RGBColor color;
		color.r = ptr[0];
		color.g = ptr[1];
		color.b = ptr[2];
		return color;
	}


	void PutPixel(int x, int y, RGBColor color){
		unsigned char* ptr = new unsigned char[3];
		ptr[0] = color.r;
		ptr[1] = color.g;
		ptr[2] = color.b;
		glRasterPos2i(x, y);
		glDrawPixels(1, 1, GL_RGB, GL_UNSIGNED_BYTE, ptr);
		glFlush();
	}



	bool IsTheSameColor(RGBColor color1, RGBColor color2){
		if (color1.r != color2.r)
			return false;
		if (color1.g != color2.g)
			return false;
		if (color1.b != color2.b)
			return false;
		return true;
	}

	void BoundaryFill(int x, int y, RGBColor F_Color, RGBColor B_Color){
		clock_t t = clock();
		vector<int> xs = vector<int>();
		vector<int> ys = vector<int>();
		xs.push_back(x); ys.push_back(y);
		while (!xs.empty()) {
			int curx = xs.back();
			xs.pop_back();
			int cury = ys.back();
			ys.pop_back();
			RGBColor current = GetPixel(curx, cury);
			if (!(IsTheSameColor(current,B_Color)) && !(IsTheSameColor(current,F_Color))){
				//bI.setRGB(x, y, fColor.getRGB());
				PutPixel(curx, cury, F_Color);
				xs.push_back(curx + 1); ys.push_back( cury);
				xs.push_back(curx - 1); ys.push_back(cury);
				xs.push_back(curx); ys.push_back(cury+1);
				xs.push_back(curx); ys.push_back(cury-1);
			}
		}
		cout << "Boundary " << (clock() - t) / double(CLOCKS_PER_SEC) * 1000.0 << endl;
	}

	bool isOkayToFill(int x, int y,RGBColor F_Color, RGBColor B_Color){
		RGBColor current = GetPixel(x, y);
		return !(IsTheSameColor(current, B_Color)) && !(IsTheSameColor(current, F_Color));
	}

	void FloodFill(int x, int y, RGBColor newcolor){
		clock_t t = clock();
		vector<int> xs = vector<int>();
		vector<int> ys = vector<int>();
		xs.push_back(x); ys.push_back(y);
		RGBColor old = GetPixel(x, y);
		if (IsTheSameColor(old, newcolor)) return;
		while (!xs.empty()) {
			int curx = xs.back();
			xs.pop_back();
			int cury = ys.back();
			ys.pop_back();
			RGBColor current = GetPixel(curx, cury);
			if (IsTheSameColor(current, old)){
				//bI.setRGB(x, y, fColor.getRGB());
				PutPixel(curx, cury, newcolor);
				xs.push_back(curx + 1); ys.push_back(cury);
				xs.push_back(curx - 1); ys.push_back(cury);
				xs.push_back(curx); ys.push_back(cury + 1);
				xs.push_back(curx); ys.push_back(cury - 1);
			}
		}
		cout << "FloodFill " << clock()-t / double(CLOCKS_PER_SEC) * 1000 << endl;
	}

	
	bool isASeed(int x, int y, RGBColor F_Color, RGBColor B_Color){
		bool con1 = isOkayToFill(x+1, y, F_Color,B_Color);
		bool con2 = isOkayToFill(x, y-1, F_Color, B_Color);
		bool con3 = isOkayToFill(x - 1, y, F_Color, B_Color);
		bool con4 = isOkayToFill(x , y+1, F_Color, B_Color);
		return (con1 || con2 || con3 || con4);
	}

	void FillRow(int x, int y, RGBColor F_Color,RGBColor B_Color, int sign){
		while (!IsTheSameColor(GetPixel(x,y),B_Color)){
			PutPixel(x, y, F_Color);
			x += sign;
		}
	}
	
public:
	ColorAlgorithm(){
		
	}

	void setWidthScreen(int w){
		this->w = w;
	}

	void draw(int algo, int x, int y, RGBColor r){
		RGBColor c;
		switch (algo){
		case 0:
			c = r;
			BoundaryFill(x,y,c,B_Color);
			break;
		case 1:
			c = r;
			FloodFill(x, y, c);
			break;
		case 2:
			break;
		default:
			break;
		}
	}

	void configHeightScreen(int height){
		this->h = height;
	}
};