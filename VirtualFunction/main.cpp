#include <fstream>
#include <iostream>
using namespace std;

class Shape {
public:
	virtual void calculate()
	{
		cout << "Area of your Shape ";
	}
	 ~Shape()
	{
		cout << "Shape Destuctor Call\n";
	}
};

class Rectangle : public Shape {
public:
	int width, height, area;

	void calculate()
	{
		cout << "Enter Width of Rectangle: ";
		cin >> width;

		cout << "Enter Height of Rectangle: ";
		cin >> height;

		area = height * width;
		cout << "Area of Rectangle: " << area << "\n";
	}


	 ~Rectangle()
	{
		cout << "Rectangle Destuctor Call\n";
	}
};


class Square : public Shape {
public:
	int side, area;

	void calculate()
	{
		cout << "Enter one side your of Square: ";
		cin >> side;

		area = side * side;
		cout << "Area of Square: " << area << "\n";
	}


	 ~Square()
	{
		cout << "Square Destuctor Call\n";
	}
};

int main()
{

	//Shape* S;
	Rectangle r;

	//S = &r;

	r.calculate();
	Square sq;

	//S = &sq;

	sq.calculate();


	return 0;
}
