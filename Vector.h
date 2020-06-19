#pragma once
#include<iostream>
#include "Point.h"

using namespace std;

template <class T>
class Vector
{
private:
	Point<T>* points;
	int pointsCount;

public:
	Vector()
	{
		points = nullptr;
		pointsCount = 0;
	}

	Vector(Point<T> point)
	{
		AddPoint(point);
	}

	Vector(const Vector& vector)
	{
		pointsCount = vector.pointsCount;
		points = new Point<T>[pointsCount];
		for (int i = 0; i < pointsCount; i++) {
			points[i] = vector.points[i];
		}
	}

	Vector(Vector&& other)
	{
		pointsCount = other.pointsCount;
		points = other.points;

		other.points = nullptr;
		other.pointsCount = 0;
	}

	~Vector()
	{
		if (points != nullptr)
			delete[] points;
	}

	Vector& operator=(const Vector& vector)
	{
		if (this == &vector)
			return *this;

		if (points != nullptr)
			delete[] points;

		pointsCount = vector.pointsCount;
		points = new Point<T>[pointsCount];
		for (int i = 0; i < pointsCount; i++) {
			points[i] = vector.points[i];
		}
		return *this;
	}

	Vector& operator=(Vector&& other)
	{
		if (this == &other)
			return *this;

		if (points != nullptr)
			delete[] points;

		pointsCount = other.pointsCount;
		points = other.points;

		other.points = nullptr;
		other.pointsCount = 0;
		return *this;
	}

	void AddPoint(const Point<T>& point)
	{
		Point<T>* newPoint = new Point<T>[pointsCount + 1];

		for (int i = 0; i < pointsCount; i++) {
			newPoint[i] = points[i];
		}
		newPoint[pointsCount] = point;

		delete[] points;
		points = newPoint;
		++pointsCount;
	}

	void Print() const
	{
		cout << endl;
		cout << "On the plane  " << pointsCount << " points:" << endl;
		for (int i = 0; i < pointsCount; i++) {
			cout << i + 1 << ") ";
			points[i].Print();
		}
	}

};

