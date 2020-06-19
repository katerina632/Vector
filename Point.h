#pragma once
#include<iostream>
#include<math.h>
using namespace std;

template <class T>
class Point
{
private:
	T x;
	T y;
public:	
	Point() : x(0), y(0) {}	
	
	Point(T x, T y)  {
		this->x = x;
		this->y = y;
	}	
	
	void Print() const
	{
		cout << "x=" << x << " y=" << y << endl;
	}
		
	Point& operator++()
	{
		x++;
		y++;
		return *this;
	}
	
	Point operator++(int)
	{
		Point temp = *this;
		x++;
		y++;
		return temp;
	}
	
	Point& operator--()
	{
		x--;
		y--;
		return *this;
	}
	
	Point operator--(int)
	{
		Point temp = *this;
		x--;
		y--;
		return temp;
	}
	
	Point& operator!()
	{
		x *= -1;
		y *= -1;
		return *this;
	}

	bool operator>(const Point & other) {

		return (sqrt(this->x*this->x+ this->y * this->y) > sqrt(other.x * other.x+ other.y * other.y));
	}
	bool operator<(const Point& other) {

		return (sqrt(this->x * this->x + this->y * this->y) < sqrt(other.x * other.x + other.y * other.y));
	}
};











