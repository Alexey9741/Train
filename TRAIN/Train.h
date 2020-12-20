#pragma once
#include "TRAIN_Form.h"
#include <Windows.h>
#include <list>;
#include <math.h>;
#include <iostream>;

using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
 
int h = 3;// задаёт масштаб 


class myRectangle
{
protected:
	System::Drawing::Rectangle aRect;
	virtual Brush^ Get_Color() = 0;// возвращает цвет, свой для каждого компонента
public:
	myRectangle(int x, int y)
	{
		this->aRect.X = x;
		this->aRect.Y = y;
	}
	void Draw(System::Windows::Forms::PaintEventArgs^ e)
	{
		System::Drawing::Pen^ p;
		p = gcnew Pen(Color::Black, 2);
		e->Graphics->DrawRectangle(p, aRect);
		e->Graphics->FillRectangle(this->Get_Color(), aRect);
	}

};

class mytube :public myRectangle  // труба
{
private:
	Brush^ Get_Color()
	{
		return Brushes::LightGray;
	}

	bool isWork;
	bool up;
	bool down;

	System::Drawing::Rectangle smoke1; // кубы пара
	System::Drawing::Rectangle smoke2;
	System::Drawing::Rectangle smoke3;
	System::Drawing::Rectangle smoke4;
	System::Drawing::Rectangle smoke5;
public:
	mytube(int x, int y) :myRectangle(x, y)
	{
		this->aRect.Width = 5 * h;
		this->aRect.Height = 7 * h;

		this->smoke1.X = x -h;
		this->smoke1.Y = y - 5*h;
		this->smoke1.Width =  4 * h;
		this->smoke1.Height = 4 * h;

		this->smoke2.X = x+4*h;
		this->smoke2.Y = y - 6 * h;
		this->smoke2.Width = 4 * h;
		this->smoke2.Height = 4 * h;

		this->smoke3.X = x+h;
		this->smoke3.Y = y - 10 * h;
		this->smoke3.Width = 5 * h;
		this->smoke3.Height = 5 * h;

		this->smoke4.X = x - h;
		this->smoke4.Y = y - 15 * h;
		this->smoke4.Width = 5 * h;
		this->smoke4.Height = 5 * h;

		this->smoke5.X = x + h;
		this->smoke5.Y = y - 18 * h;
		this->smoke5.Width = 3 * h;
		this->smoke5.Height = 3 * h;

		isWork = 0;
		up = 1;
		down = 0;
	}
	void move() // анимация пара
	{
		isWork = 1;
		if (up)
		{
			up = 0;
			down = 1;

			this->smoke1.X -= 2;
			this->smoke1.Y -= 2;

			this->smoke2.X -= 2;
			this->smoke2.Y -= 2;

			this->smoke3.X -= 2;
			this->smoke3.Y -= 2;

			this->smoke4.X -= 2;
			this->smoke4.Y -= 2;

			this->smoke5.X -= 2;
			this->smoke5.Y -= 2;

		}
		else
		{
			up = 1;
			down = 0;

			this->smoke1.X += 2;
			this->smoke1.Y += 2;

			this->smoke2.X += 2;
			this->smoke2.Y += 2;

			this->smoke3.X += 2;
			this->smoke3.Y += 2;

			this->smoke4.X += 2;
			this->smoke4.Y += 2;

			this->smoke5.X += 2;
			this->smoke5.Y += 2;
		}
	}
	void Draw(System::Windows::Forms::PaintEventArgs^ e)
	{
		myRectangle::Draw(e);
		if (isWork)
		{
			e->Graphics->FillEllipse(Brushes::WhiteSmoke, smoke1);
			e->Graphics->FillEllipse(Brushes::WhiteSmoke, smoke2);
			e->Graphics->FillEllipse(Brushes::WhiteSmoke, smoke3);
			e->Graphics->FillEllipse(Brushes::WhiteSmoke, smoke4);
			e->Graphics->FillEllipse(Brushes::WhiteSmoke, smoke5);
		}
	}
	void relocation() // вызывается при остановке
	{
		isWork = 0;
		if (down)
		{
			this->smoke1.X += 2;
			this->smoke1.Y += 2;

			this->smoke2.X += 2;
			this->smoke2.Y += 2;

			this->smoke3.X += 2;
			this->smoke3.Y += 2;

			this->smoke4.X += 2;
			this->smoke4.Y += 2;

			this->smoke5.X += 2;
			this->smoke5.Y += 2;
		}
	}
};

class mydoor :public myRectangle  // дверь
{
private:
	Brush^ Get_Color()
	{
		return Brushes::DarkOrange;
	}
public:
	mydoor(int x, int y) :myRectangle(x, y)
	{
		this->aRect.Width = 4 * h;
		this->aRect.Height = 8 * h;
	}
};
class myWindow :public myRectangle
{
private:
	Brush^ Get_Color()
	{
		return Brushes::LightSkyBlue;
	}
public:
	myWindow(int x, int y) :myRectangle(x, y)
	{
		this->aRect.Width = 7 * h;
		this->aRect.Height = 7 * h;
	}
};
class myBase :public myRectangle  //фундамент вагона
{
private:
	Brush^ Get_Color()
	{
		return Brushes::Wheat;
	}
public:
	myBase(int x, int y) :myRectangle(x, y)
	{
		this->aRect.Width = 42 * h;
		this->aRect.Height = 14 * h;
	}
	Point location()
	{
		return Point(aRect.X, aRect.Y);
	}
};
class wheel :public myRectangle  //колесо
{
private:
	Point p1, p2, p3, p4, p5, p6, p7, p8;   // координаты спиц
	int x0;                                 // координаты центра колеса
	int y0;
	float alpha = -acos(-1) / 6;             // угол поворота колеса
	Brush^ Get_Color()
	{
		return Brushes::Transparent;
	}
public:
	wheel(int x, int y) :myRectangle(x, y)
	{
		this->aRect.Width = 6 * h;
		this->aRect.Height = 6 * h;
		p1 = Point(aRect.X + aRect.Width / 2, aRect.Y);
		p2 = Point(aRect.X + aRect.Width / 2, aRect.Y + aRect.Height);
		p3 = Point(aRect.X, aRect.Y + aRect.Height / 2);
		p4 = Point(aRect.X + aRect.Width, aRect.Y + aRect.Height / 2);
		p5 = Point(aRect.X + 3 * h + 3 * h * sqrt(2) / 2, aRect.Y + 3 * h + 3 * h * sqrt(2) / 2);
		p6 = Point(aRect.X + 3 * h - 3 * h * sqrt(2) / 2, aRect.Y + 3 * h - 3 * h * sqrt(2) / 2);
		p7 = Point(aRect.X + 3 * h + 3 * h * sqrt(2) / 2, aRect.Y + 3 * h - 3 * h * sqrt(2) / 2);
		p8 = Point(aRect.X + 3 * h - 3 * h * sqrt(2) / 2, aRect.Y + 3 * h + 3 * h * sqrt(2) / 2);
		x0 = aRect.X + 3 * h;
		y0 = aRect.Y + 3 * h;
	}
	 void Draw(System::Windows::Forms::PaintEventArgs^ e) // перекрываем метод myRectangle
	{                                                      // т.к колесо рисуется немного по другому
		System::Drawing::Pen^ p;
		p = gcnew Pen(Color::Black, 2);

		e->Graphics->DrawEllipse(p, aRect);

		e->Graphics->DrawLine(p, p1, p2);
		e->Graphics->DrawLine(p, p3, p4);
		e->Graphics->DrawLine(p, p5, p6);
		e->Graphics->DrawLine(p, p7, p8);
	}
	  void move()  // анимация вращение колеса
	{
		 

		  int x = p1.X;
		  int y = p1.Y;
		  p1.X = x0 + (x - x0) * cos(alpha) - (y - y0) * sin(alpha);  //умножаем координаты 
		  p1.Y = y0 + (y - y0) * cos(alpha) + (x - x0) * sin(alpha);  //на матрицу поворота
		  
		  x = p2.X;
		  y = p2.Y;
		  p2.X = x0 + (x - x0) * cos(alpha) - (y - y0) * sin(alpha);
		  p2.Y = y0 + (y - y0) * cos(alpha) + (x - x0) * sin(alpha);

		  x = p3.X;
		  y = p3.Y;
		  p3.X = x0 + (x - x0) * cos(alpha) - (y - y0) * sin(alpha);
		  p3.Y = y0 + (y - y0) * cos(alpha) + (x - x0) * sin(alpha);

		  x = p4.X;
		  y = p4.Y;
		  p4.X = x0 + (x - x0) * cos(alpha) - (y - y0) * sin(alpha);
		  p4.Y = y0 + (y - y0) * cos(alpha) + (x - x0) * sin(alpha);

		  x = p5.X;
		  y = p5.Y;
		  p5.X = x0 + (x - x0) * cos(alpha) - (y - y0) * sin(alpha);
		  p5.Y = y0 + (y - y0) * cos(alpha) + (x - x0) * sin(alpha);

		  x = p6.X;
		  y = p6.Y;
		  p6.X = x0 + (x - x0) * cos(alpha) - (y - y0) * sin(alpha);
		  p6.Y = y0 + (y - y0) * cos(alpha) + (x - x0) * sin(alpha);
		 
		  x = p7.X;
		  y = p7.Y;
		  p7.X = x0 + (x - x0) * cos(alpha) - (y - y0) * sin(alpha);
		  p7.Y = y0 + (y - y0) * cos(alpha) + (x - x0) * sin(alpha);

		  x = p8.X;
		  y = p8.Y;
		  p8.X = x0 + (x - x0) * cos(alpha) - (y - y0) * sin(alpha);
		  p8.Y = y0 + (y - y0) * cos(alpha) + (x - x0) * sin(alpha);
	}
	  void relocation()  //вызываем при окончании движения 
	  {
		  p1 = Point(aRect.X + aRect.Width / 2, aRect.Y);
		  p2 = Point(aRect.X + aRect.Width / 2, aRect.Y + aRect.Height);
		  p3 = Point(aRect.X, aRect.Y + aRect.Height / 2);
		  p4 = Point(aRect.X + aRect.Width, aRect.Y + aRect.Height / 2);
		  p5 = Point(aRect.X + 3 * h + 3 * h * sqrt(2) / 2, aRect.Y + 3 * h + 3 * h * sqrt(2) / 2);
		  p6 = Point(aRect.X + 3 * h - 3 * h * sqrt(2) / 2, aRect.Y + 3 * h - 3 * h * sqrt(2) / 2);
		  p7 = Point(aRect.X + 3 * h + 3 * h * sqrt(2) / 2, aRect.Y + 3 * h - 3 * h * sqrt(2) / 2);
		  p8 = Point(aRect.X + 3 * h - 3 * h * sqrt(2) / 2, aRect.Y + 3 * h + 3 * h * sqrt(2) / 2);
	  }
};

class vagon
{
private:
	myBase* Base;
	myWindow* Window1;
	myWindow* Window2;
	myWindow* Window3;
	mydoor* door;
	wheel* wheel1;
	wheel* wheel2;

public:
	vagon(int x, int y)
	{
		Base = new myBase(x, y);
		Window1 = new myWindow(x + 7 * h, y + 6 * h);
		Window2 = new myWindow(x + 17 * h, y + 6 * h);
		Window3 = new myWindow(x + 27 * h, y + 6 * h);
		door = new mydoor(x, y + 6 * h);
		wheel1 = new wheel(x + 4 * h, y + 14 * h);
		wheel2 = new wheel(x + 24 * h, y + 14 * h);
	}
	
	void Draw(System::Windows::Forms::PaintEventArgs^ e)
	{
		Base->Draw(e);
		Window1->Draw(e);
		Window2->Draw(e);
		Window3->Draw(e);
		door->Draw(e);
		wheel1->Draw(e);
		wheel2->Draw(e);
	}
	Point location()
	{
		return Base->location();
	}

	void move()
	{
		wheel1->move();
		wheel2->move();
	}
	void relocation()
	{
		wheel1->relocation();
		wheel2->relocation();
	}

};
class myLine
{
protected:
	Point one;
	Point two;
    virtual  Pen^ get_Color() = 0;  // возвращает цвет для каждого компонента 
public:
	myLine(int x1, int y1, int x2, int y2)
	{
		one.X = x1;
		one.Y = y1;
		two.X = x2;
		two.Y = y2;
	}
	myLine(const myLine& tmp)
	{
		this->one = tmp.one;
		this->two = tmp.two;
	}
	void Draw(System::Windows::Forms::PaintEventArgs^ e)
	{
		System::Drawing::Pen^ p;
		if (this->get_Color() == Pens::Green)
		{
			p = gcnew Pen(Color::Green, 2);
		}
		else
		{
			p = gcnew Pen(Color::Black, 2);
		}
		e->Graphics->DrawLine(p, one, two);
	}
};

class dvizhok :public myLine
{
private:
	Point shoulder11; // плечо двигателя
	Point shoulder12; // когда он находится в рабочем состоянии
	Point shoulder21;
	Point shoulder22;
	bool isWork;
public:
	dvizhok(int x1, int y1, int x2, int y2) :myLine(x1, y1, x2, y2)
	{
		shoulder11 = Point(one.X, one.Y);
		shoulder21 = Point(two.X, two.Y);
		shoulder12 = Point(one.X, one.Y - 2 * h);
		shoulder22 = Point(two.X, two.Y - 2 * h);
		isWork = 0;
	}
	Pen^ get_Color()
	{
		return Pens::Green;
	}
	void Draw(System::Windows::Forms::PaintEventArgs^ e)
	{
		myLine::Draw(e);
		if (isWork)
		{
			e->Graphics->DrawLine(this->get_Color(), shoulder11, shoulder12);
			e->Graphics->DrawLine(this->get_Color(), shoulder21, shoulder22);
		}
	}
	void move()  // анимация работы двигателя
	{
		isWork = 1;
		float alpha = acos(-1) / 6;

		int x = shoulder12.X;
		int y = shoulder12.Y; // по  аналогии с колесом умножаем на матрицу поворота
		shoulder12.X = shoulder11.X + (x - shoulder11.X) * cos(alpha) - (y - shoulder11.Y) * sin(alpha);
		shoulder12.Y = shoulder11.Y + (y - shoulder11.Y) * cos(alpha) + (x - shoulder11.X) * sin(alpha);

		x = shoulder22.X;
		y = shoulder22.Y;
		shoulder22.X = shoulder21.X + (x - shoulder21.X) * cos(alpha) - (y - shoulder21.Y) * sin(alpha);
		shoulder22.Y = shoulder21.Y + (y - shoulder21.Y) * cos(alpha) + (x - shoulder21.X) * sin(alpha);

		one = shoulder12;
		two = shoulder22;
	}
	void relocation() // вызывается при остановке
	{
		isWork = 0;
		one = shoulder11;
		two = shoulder21;
	}
};

class scep :public myLine
{
public:
	scep(int x1, int y1, int x2, int y2) :myLine(x1, y1, x2, y2)
	{}
	
	Pen^ get_Color()
	{
		return Pens::Black;
	}
};

class paravoz
{
private:
	vagon* first;
	mytube* tube;
	dvizhok* engine;
public:
	paravoz(int x, int y)
	{
		first = new vagon(x, y);
		tube = new mytube(x + 28 * h, y - 7 * h);
		engine = new dvizhok(x + 7 * h, y + 17 * h, x + 27 * h, y + 17 * h);
	}
	~paravoz()
	{
		delete first;
		delete tube;
		delete engine;
	}
	void Draw(System::Windows::Forms::PaintEventArgs^ e)
	{
		first->Draw(e);
		tube->Draw(e);
		engine->Draw(e);
	}

	Point location()
	{
		return first->location();
	}
	void move()
	{
		first->move();
		engine->move();
		tube->move();
	}
	void relocation()
	{
		first->relocation();
		engine->relocation();
		tube->relocation();
	}

};

class MyPoezd
{
private:
	paravoz* puffer;
	list <vagon> loco; // используем список, т.к будем добавлять и удалять только с конца
	list <scep> link;
public:
	MyPoezd(int x, int y)
	{
		puffer = new paravoz(x, y);
	}
	~MyPoezd()
	{
		delete puffer;
	}
	void push_vagon()// добавление вагона
	{
		Point p;
		if (loco.empty())
		{
			p = puffer->location();
		}
		else
		{
			vagon v = loco.back(); 
			p = v.location();
		}
		scep tmp1(p.X, p.Y + 12 * h, p.X - 4 * h, p.Y + 12 * h);
		vagon tmp2(p.X - 46 * h, p.Y);
		link.push_back(tmp1); 
		loco.push_back(tmp2);
	}
	void delete_vagon()// в итоге этот метод не используется
	{
		loco.erase(loco.end());
		link.erase(link.end());
	}
	void Draw(System::Windows::Forms::PaintEventArgs^ e)
	{
		puffer->Draw(e);
		for (auto a : loco)
		{
			a.Draw(e);
		}
		for (auto a : link)
		{
			a.Draw(e);
		}
	}
	void move()
	{
		puffer->move();
		for (auto a : loco)
		{
				a.move();
		}
		
	}
	void relocation()
	{
		puffer->relocation();
		for (auto a : loco)
		{
			a.relocation();
		}
	}

};