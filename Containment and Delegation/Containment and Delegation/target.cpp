#include <math.h>
#include <stdio.h>
#include <vector>
using namespace std;

#include "point.h"
#include "circle.h"
#include "target.h"


//////////////////////////////////////////////////////////////
// Public
//////////////////////////////////////////////////////////////
Target::Target()
{
	init(Circle(0,0,0), 1);
}

Target::Target(int x, int y, int RingRadius, int count)
{
	Circle sampleCircle = Circle(x, y, RingRadius);
	init(sampleCircle, count);
}

Target::Target(Circle sampleCircle, int count)
{
	init(sampleCircle, count);
}

Target::Target(const Target &otherTarget)
{
	copy(otherTarget);
}

Target Target::operator=(const Target &otherTarget)
{
	deleteAll();
	copy(otherTarget);
	return *this;
}

Target::~Target()
{
	deleteAll();
}

void Target::move(int deltaX, int deltaY)
{
	vector <Circle> container = getVectorCircles();
	for (int i = 0; i < container.size(); i++) //For every circle in target
	{
		Circle currentCircle = container.at(i);  //Getting individual circle from target
		Point newPoint = currentCircle.getCenter(); //Getting point from each circle
		newPoint.move(deltaX, deltaY);  //Moving each point
		Circle newCircle = Circle(newPoint, currentCircle.getRadius()); //Making a new circle out of new moved point
		mVectorCircles.at(i) = newCircle;
	}

	//init(newCircle, getCount());
}

bool Target::operator==(Target &otherTarget)
{	//the number of concentric circles of both targets
	if (getCount() == otherTarget.getCount())
	{
		//center and radius of circles
		for (int i = 0; i < getCount(); i++)
		{
			Circle originalCircle = getVectorCircles().at(i);
			Circle otherCircle = otherTarget.getVectorCircles().at(i);
			return ((originalCircle.getCenter() == otherCircle.getCenter()) && (originalCircle.getRadius() == otherCircle.getRadius()));
		}
	}
	else return false; //Why is a false needed here, but not in circle.cpp?
}

bool Target::operator!=(Target  &otherTarget)
{
	return !(*this == otherTarget);
}

double Target::getDistance(const Target &otherTarget) const
{
	Point center1 = getBullsEye().getCenter();
	Point center2 = otherTarget.getBullsEye().getCenter();
	return center1.getDistance(center2);
}

Circle Target::getBullsEye() const {
	vector <Circle> container = getVectorCircles();
	return container.at(0);
}

vector<Circle> Target::getVectorCircles() const {
	return mVectorCircles;
}

int Target::getCount() const
{
	return mCount;
}

int Target::getRingRadius(int ringToFindRadiusOf) const
{
	Circle ring = getVectorCircles().at(ringToFindRadiusOf);
	return ring.getRadius();
}

void Target::setRingRadius(int ringToGetChanged, int newRadius)
{
	int index = ringToGetChanged;
	//Circle testCircle = Circle(get, newRadius);
	Circle newCircle = Circle(getBullsEye().getCenter(), newRadius);
	mVectorCircles.at(index) = newCircle;
}

//////////////////////////////////////////////////////////////
// Friends
//////////////////////////////////////////////////////////////
ostream& operator<<(ostream &os, Target &t)
{
	os << "Target has " << t.getCount() << " rings\n";
	
	for (int i = 0; i < t.getCount(); i++)
	{
		Circle testRing = t.getVectorCircles().at(i);
		os << "Ring " << i << "." << testRing << endl;
	}
	
	return os;
}

//////////////////////////////////////////////////////////////
// Private
//////////////////////////////////////////////////////////////
void Target::init(Circle circle, int count)
{
	vector <Circle> container = getVectorCircles();
	mVectorCircles.clear();
	for (int i = 0; i <= count; i++)
	{
		Circle newCircle = Circle(circle.getCenter(), circle.getRadius()*(i+1));
		mVectorCircles.push_back(newCircle);
	}
	mCount = count;
}

void Target::copy(const Target &otherTarget)
{
	Circle copyCircle = otherTarget.getBullsEye();
	int copyCount = otherTarget.getCount();
	init(copyCircle, copyCount);
}

void Target::deleteAll()
{

}