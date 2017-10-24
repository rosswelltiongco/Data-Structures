/*
Circle
	Class Circle contains a center point and radius
*/
#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
using namespace std;

class Circle
{
public:
/*
Method Name:  Circle()

		Default constructor

	Input Only:
		None
	Input & Output:
		None
	Output Only:
		None
	Returns:
		None
	Side Effects:
		None
*/
	Circle();

/*
Method Name:  Circle(x,y,radius)

		Constructor that takes coordinates and radius

	Input Only:
		x - x coordinate
		y - y coordinate
		r - circle radius
	Input & Output:
		None
	Output Only:
		None
	Returns:
		None
	Side Effects:
		None
*/
	Circle(int x, int y, int radius);

/*
Method Name:  Circle(center,radius)

		Constructor that takes existing point and new radius

	Input Only:
		center - a point
		radius - radius of circle
	Input & Output:
		None
	Output Only:
		None
	Returns:
		None
	Side Effects:
		None
*/
	Circle(Point center, int radius);

/*
Method Name:  Circle(otherCircle)

		Copy constructor

	Input Only:
		otherCircle - an existing circle
	Input & Output:
		None
	Output Only:
		None
	Returns:
		None
	Side Effects:
		None
*/
	Circle(const Circle &otherCircle);

/*
Method Name:  operator=(otherCircle)

		Reassigns a circle to an existing circle

	Input Only:
		otherCircle - an existing circle
	Input & Output:
		None
	Output Only:
		None
	Returns:
		point to object
	Side Effects:
		None
*/
	Circle operator=(const Circle &otherCircle);

/*
Method Name:  ~Circle()

		Destructor

	Input Only:
		None
	Input & Output:
		None
	Output Only:
		None
	Returns:
		None
	Side Effects:
		None
*/
	~Circle();


/*
Method Name:  getCenter()

		Retrieves center

	Input Only:
		None
	Input & Output:
		None
	Output Only:
		None
	Returns:
		Center point
	Side Effects:
		None
*/
	Point getCenter() const;

/*
Method Name:  getRadius()

		Retrieves circle's radius

	Input Only:
		None
	Input & Output:
		None
	Output Only:
		None
	Returns:
		radius of circle
	Side Effects:
		None
*/
	int getRadius() const;


/*
Method Name:  operator==(otherCircle)

		Checks if an existing circle is equivalent

	Input Only:
		otherCircle - an existing circle
	Input & Output:
		None
	Output Only:
		None
	Returns:
		True if circles are the same
	Side Effects:
		None
*/
	bool operator==(Circle &otherCircle);
/*
Method Name:  operator !=(otherCircle)

		Checks if an existing circle is inequivalent

	Input Only:
		otherCircle - an existing circle
	Input & Output:
		None
	Output Only:
		None
	Returns:
		True if circles are no the same
	Side Effects:
		None
*/
	bool operator!=(Circle &otherCircle);


/*
Method Name:  move(deltaX,deltaY)

		Shifts circle to new location

	Input Only:
		deltaX - change in x plane
		deltaY - change in y plane
	Input & Output:
		None
	Output Only:
		None
	Returns:
		None
	Side Effects:
		None
*/
	void move(int deltaX, int deltaY);

/*
Method Name:  getDistance(otherCircle)

		Retrieves distance from another circle

	Input Only:
		otherCircle - an existing circle
	Input & Output:
		None
	Output Only:
		None
	Returns:
		Distance from another circle
	Side Effects:
		None
*/
	double Circle::getDistance(const Circle &otherCircle) const;

	
/*
Method Name:  operator<<(os,c)

		Overloads printing operator with new messsage

	Input Only:
		c - a circle
	Input & Output:
		os - output stream
	Output Only:
		None
	Returns:
		A modified print statement
	Side Effects:
		Prints center coordinates and radius
*/
	friend ostream& operator<<(ostream &os, Circle &c);
private:

	void init(Point center, int radius);
	void copy(const Circle &otherCircle);
	void deleteAll();

	Point mCenter;
	int mRadius;
};

#endif
