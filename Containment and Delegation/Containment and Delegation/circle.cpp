#include <math.h>
#include <stdio.h>

using namespace std;

#include "point.h"
#include "circle.h"


//////////////////////////////////////////////////////////////
// Public
//////////////////////////////////////////////////////////////
Circle::Circle() {
	init(Point(0, 0), 0);
}
Circle::Circle(int x, int y, int radius)
{
	init(Point(x,y), radius);
}

Circle::Circle(Point center, int radius)
{
	init(center, radius);
}

Circle::Circle(const Circle &otherCircle)
{
	copy(otherCircle);
}

Circle Circle::operator=(const Circle &otherCircle)
{
	deleteAll();
	copy(otherCircle);
	return *this;
}

Circle::~Circle()
{
	deleteAll();
}

void Circle::move(int deltaX, int deltaY)
{
	Point newCenter = getCenter();
	newCenter.move(deltaX, deltaY);
	init(newCenter, getRadius());
}

bool Circle::operator==(Circle &otherCircle)
{
	return ((mCenter == otherCircle.getCenter()) && (mRadius == otherCircle.getRadius()));
}

bool Circle::operator!=(Circle &otherCircle)
{
	return !(*this == otherCircle);
}

double Circle::getDistance(const Circle &otherCircle) const
{
	Point center1 = getCenter();
	Point center2 = otherCircle.getCenter();
	return center1.getDistance(center2);
}


Point Circle::getCenter() const
{
	return mCenter;
}

int Circle::getRadius() const
{
	return mRadius;
}

//////////////////////////////////////////////////////////////
// Friends
//////////////////////////////////////////////////////////////
ostream& operator<<(ostream &os, Circle &c)
{
	//Expected output: Center: (5,5), Radius: 1
	os << "(Center: " << c.getCenter()<< ", Radius: " << c.getRadius();
	return os;
}

//////////////////////////////////////////////////////////////
// Private
//////////////////////////////////////////////////////////////
void Circle::init(Point center, int radius)
{
	mCenter = center;
	mRadius = radius;
}


void Circle::copy(const Circle &otherCircle)
{
	init(otherCircle.getCenter(), otherCircle.getRadius());
}

void Circle::deleteAll()
{

}
