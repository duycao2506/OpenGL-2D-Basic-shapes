#pragma once
#include "SP_Shape.h"
#include "P_LINE.h"
#include <vector>
#include <string>
#include <string.h>
#include "ColorAlgorithm.h"
#include "Circle.h"
#include "Ellip.h"
#include "Square.h"
#include "Rectang.h"
#include "Isosceles.h"
#include "Equilateral.h"
#include "Fiveequal.h"
#include "Sixequal.h"
#include "Star.h"
#include "Arrow.h"
#include "ColorPoint.h"
#include "Addsign.h"
#include "Timessign.h"
#include "Dividesign.h"
#include "Substractsign.h"
//#include <gl\glut.h>
using namespace std;

bool isDrawing = false;
enum shape_type{
	LINE,
	VC,
	DEU,
	CN,
	VUONG,
	NGD,
	LGD,
	TRON,
	ELIP,
	MUITEN,
	SAO,
	CONG,
	TRU,
	NHAN,
	CHIA,
	BLUE,
	RED,
	YELLOW,
	BLUE1,
	RED1,
	YELLOW1
};

string MENU_TITLE[] = { "Duong Thang", "Vuong Can", "Deu", "Hinh Chu Nhat", "Hinh Vuong", "Ngu Giac Deu", "Luc Giac Deu", "Hinh Tron", "Elip", "Mui ten", "Ngoi sao", "Cong", "Tru", "Nhan", "Chia", "Xanh (BOUND)", "Do (BOUND)", "Vang (BOUND)", "Xanh (FLOOD)", "Do (FLOOD)", "Vang (FLOOD)" };

class Menu{
private:
	vector <int> chosen;
	vector<Shape*> shapes;
	int currentShape= 0;
	int historyMenu;
	int h = 0;
	int w = 0;
	bool isColoring = false;
public:
	~Menu(){
		for each(Shape* i in shapes){
			delete i;
		}
	}
	Menu(void menu(int), int h,int w ){
		this->h = h;
		int tamgiac = glutCreateMenu(menu);
		glutAddMenuEntry(MENU_TITLE[VC].c_str(), VC);
		glutAddMenuEntry(MENU_TITLE[DEU].c_str(), DEU);
		
		int tugiac = glutCreateMenu(menu);
		glutAddMenuEntry(MENU_TITLE[CN].c_str(), CN);
		glutAddMenuEntry(MENU_TITLE[VUONG].c_str(), VUONG);

		int dagiacdeu = glutCreateMenu(menu);
		glutAddMenuEntry(MENU_TITLE[NGD].c_str(), NGD);
		glutAddMenuEntry(MENU_TITLE[LGD].c_str(), LGD);

		int oval = glutCreateMenu(menu);
		glutAddMenuEntry(MENU_TITLE[TRON].c_str(), TRON);
		glutAddMenuEntry(MENU_TITLE[ELIP].c_str(), ELIP);

		int khac = glutCreateMenu(menu);
		glutAddMenuEntry(MENU_TITLE[MUITEN].c_str(), MUITEN);
		glutAddMenuEntry(MENU_TITLE[SAO].c_str(), SAO);

		int dau = glutCreateMenu(menu);
		glutAddMenuEntry(MENU_TITLE[CONG].c_str(), CONG);
		glutAddMenuEntry(MENU_TITLE[TRU].c_str(), TRU);
		glutAddMenuEntry(MENU_TITLE[NHAN].c_str(), NHAN);
		glutAddMenuEntry(MENU_TITLE[CHIA].c_str(), CHIA);

		int mau = glutCreateMenu(menu);
		glutAddMenuEntry(MENU_TITLE[BLUE].c_str(), BLUE);
		glutAddMenuEntry(MENU_TITLE[RED].c_str(), RED);
		glutAddMenuEntry(MENU_TITLE[YELLOW].c_str(), YELLOW);
		glutAddMenuEntry(MENU_TITLE[BLUE1].c_str(), BLUE1);
		glutAddMenuEntry(MENU_TITLE[RED1].c_str(), RED1);
		glutAddMenuEntry(MENU_TITLE[YELLOW1].c_str(), YELLOW1);

		historyMenu = glutCreateMenu(menu);

		int mainmenu = glutCreateMenu(menu);
		glutAddMenuEntry(MENU_TITLE[LINE].c_str(), 0);
		glutAddSubMenu("Tam giac", tamgiac);
		glutAddSubMenu("Tu giác", tugiac);
		glutAddSubMenu("Da giác deu", dagiacdeu);
		glutAddSubMenu("Oval", oval);
		glutAddSubMenu("Hình Khác", khac);
		glutAddSubMenu("Dáu", dau);
		glutAddSubMenu("Màu", mau);
		glutAddSubMenu("Chon hình", historyMenu);

		glutAttachMenu(GLUT_RIGHT_BUTTON);

		chosen = vector <int>();
		shapes = vector <Shape*>();
	}

	vector<int> choice(){
		return chosen;
	}

	vector<Shape*> GetShapes(){	
		return shapes;
	}

	void addHistory(int menu){
		for (int i = 0; i < this->chosen.size(); i++){
			if (menu == this->chosen[i])
				return;
		}

		glutSetMenu(historyMenu);
		glutAddMenuEntry(MENU_TITLE[menu].c_str(), menu);
		addChoice(menu);
	}

	void addChoice(int menunumber){
		this->chosen.push_back(menunumber);
	}

	void addShape(Shape* shape){
		this->shapes.push_back(shape);
	}

	void setCurrentShape(int enumShape){
		this->currentShape = enumShape;
	}

	void curModeAction(int mousex, int mousey){
		Shape* temp = nullptr;
		RGBColor c;
		switch (this->currentShape){
		case LINE:
			temp = new P_Line(mousex, mousey);
			break;
		case VC:
			temp = new Isosceles(mousex, mousey);
			break;
		case VUONG:
			temp = new Square(mousex, mousey);
			break;
		case CN:
			temp = new Rectang(mousex, mousey);
			break;
		case TRON:
			temp = new Circle(mousex, mousey);
			break;
		case ELIP:
			temp = new Ellip(mousex, mousey);
			break;
		case MUITEN:
			temp = new Arrow(mousex, mousey);
			break;
		case CONG:
			temp = new Addsign(mousex, mousey);
			break;
		case TRU:
			temp = new Substractsign(mousex, mousey);
			break;
		case NHAN:
			temp = new Timessign(mousex, mousey);
			break;
		case CHIA:
			temp = new Dividesign(mousex, mousey);
			break;
		case NGD:
			temp = new Fiveequal(mousex, mousey);
			break;
		case LGD:
			temp = new Sixequal(mousex, mousey);
			break;
		case DEU:
			temp = new Equilateral(mousex, mousey);
			break;
		case SAO:
			temp = new Star(mousex, mousey);
			break;
		case BLUE:
			if (isColoring) return;
			c = {30, 139, 195};
			isColoring = true;
			temp = new ColorPoint(w,h,mousex, mousey, c.r,c.g,c.b,BOUNDARY);
			temp->draw();
			isColoring = false;
			break;
		case RED:
			if (isColoring) return;
			c = {239, 72, 54};
			isColoring = true;
			temp = new ColorPoint(w, h, mousex, mousey, c.r, c.g, c.b, BOUNDARY);
			temp->draw();
			isColoring = false;
			break;
		case YELLOW:
			if (isColoring) return;
			c = {247, 202, 24};
			isColoring = true;
			temp = new ColorPoint(w, h, mousex, mousey, c.r, c.g, c.b, BOUNDARY);
			temp->draw();
			isColoring = false;
			break;
		case YELLOW1:
			if (isColoring) return;
			c = { 247, 202, 24 };
			isColoring = true;
			temp = new ColorPoint(w, h, mousex, mousey, c.r, c.g, c.b, FLOOD);
			temp->draw();
			isColoring = false;
			break;
		case RED1:
			if (isColoring) return;
			c = { 239, 72, 54 };
			isColoring = true;
			temp = new ColorPoint(w, h, mousex, mousey, c.r, c.g, c.b, FLOOD);
			temp->draw();
			isColoring = false;
			break;
		case BLUE1:
			if (isColoring) return;
			c = { 30, 139, 195 };
			isColoring = true;
			temp = new ColorPoint(w, h, mousex, mousey, c.r, c.g, c.b, FLOOD);
			temp->draw();
			isColoring = false; 
		default:
			break;
		}
		this->addShape(temp);
		if (temp != nullptr && this->currentShape < BLUE){
			this->addHistory(this->currentShape);
		}
	}
	Shape* GetCurShape(){
		int index = this->shapes.size();
		return index == 0 ? nullptr : this->shapes[index - 1];
	}

	void Draw(){
		for (Shape* a : shapes){
			a->draw();
		}
	}
	
	void changeScreenHeight(int h){
		this->h = h;
	}

	void changeScreenWidth(int w){
		this->w = w;
	}

}* MAIN_MENU;

void menu(int a){
	MAIN_MENU->setCurrentShape(a);
}
