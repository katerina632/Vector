#include<iostream>
#include "Point.h"
#include "Vector.h"
using namespace std;

int main() {

	Point<int> p1(3, 6);
	p1.Print();
	++p1;
	p1.Print();

	p1--;
	p1.Print();

	!p1;
	p1.Print();

	Vector<int> v1(Point<int>(4,5));
	v1.Print();
	v1.AddPoint(p1);
	v1.Print();

	Point<int> p3(-5, -6);
	Point<int> p4(3, 4);

	if (p3 > p4) {
		cout << "p3 located farther from 0.0"<<endl;
	}
	else {
		cout << "p4 located farther from 0.0" << endl;
	}


	system("pause");
	return 0;
}