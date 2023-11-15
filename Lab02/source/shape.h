#pragma once
#include <GL/glut.h>
#include <iostream>

class Shape {
public:
	virtual void draw(int) = 0;
};

class Line : public Shape {
public:
	void draw(int);
};

class Triangle : public Shape {
private:
	enum Type {
		Isosceles,
		Equilateral
	};
public:
	void draw(int);
};

class Quadrilateral : public Shape {
private:
	enum Type {
		Rectangle,
		Square
	};
public:
	void draw(int);
};

class Oval : public Shape {
private:
	enum Type {
		Circle,
		Ellipse
	};
public:
	void draw(int);
};

class Polygon : public Shape {
private:
	enum Type {
		Pentagon,
		Hexagon,
	};
public:
	void draw(int);
};

class Other : public Shape {
private:
	enum Type {
		Arrow,
		Heart,
	};
public:
	void draw(int);
};


class Math : public Shape {
private:
	enum Type{
		Plus,
		Minus,
		Multiply,
		Divide,
	};
public:
	void draw(int);
};
