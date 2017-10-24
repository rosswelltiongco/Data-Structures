/*
Point
	Class Point contains an X and Y coordinate
	Point can be moved and displayed as cartesian
	or polar coordinates
*/
#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;

class Point
{
public:
/*
Method Name:  Point(x,y)

		Constructor

	Input Only:
		x - x coordinate
		y - y coordinate
	Input & Output:
		None
	Output Only:
		None
	Returns:
		None
	Side Effects:
		None
*/
	Point(int x = 0, int y = 0);


/*
Method Name:  Point(otherPoint)

		Copy constructor

	Input Only:
		fromPoint - another point
	Input & Output:
		None
	Output Only:
		None
	Returns:
		None
	Side Effects:
		None
*/
	Point(const Point &fromPoint);

/*
Method Name:  operator=(otherPoint)

		Overloads equality operator

	Input Only:
		otherPoint - another point
	Input & Output:
		None
	Output Only:
		None
	Returns:
		*this - Reference to the object
	Side Effects:
		None
*/
	Point operator=(const Point &otherPoint);


/*
Method Name:  ~Point()

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
	~Point();


/*
Method Name:  getX()

		Returns member X

	Input Only:
		None
	Input & Output:
		None
	Output Only:
		None
	Returns:
		x coordinate
	Side Effects:
		None
*/
	int getX() const;

/*
Method Name:  getY()

		Returns member y

	Input Only:
		None
	Input & Output:
		None
	Output Only:
		None
	Returns:
		y coordinate
	Side Effects:
		None
*/
	int getY() const;


/*
Method Name:  operator==(otherPoint)

		Checks if two points are the same

	Input Only:
		otherPoint - another point
	Input & Output:
		None
	Output Only:
		None
	Returns:
		True if points are the same
	Side Effects:
		None
*/
	bool operator==(Point &otherPoint);

/*
Method Name:  operator!=(otherPoint)

		Checks if two points are not the same

	Input Only:
		otherPoint - another point
	Input & Output:
		None
	Output Only:
		None
	Returns:
		True if points are not the same
	Side Effects:
		None
*/
	bool operator!=(Point &otherPoint);

/*
Method Name:  move(deltaX, deltaY)

		Moves a point 

	Input Only:
		deltaX - Change in x coordinate
		deltaY - Change in y coordinate
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
Method Name:  getDistance(otherPoint)

		gets distance between two points

	Input Only:
		otherPoint - another point
	Input & Output:
		None
	Output Only:
		None
	Returns:
		distance between points
	Side Effects:
		None
*/
	double getDistance(const Point &otherPoint) const;

/*
Method Name:  getPolarCoordinate(rho,theta)

		Gets polar coordinates of point

	Input Only:
		rho -polar coordinate
		theta - polar coordinate
	Input & Output:
		None
	Output Only:
		None
	Returns:
		polar coordinates
	Side Effects:
		None
*/
	void getPolarCoordinate(double &rho, double &theta);

/*
Method Name:  operator<<(os, p)

		Overloads printing operator with new message

	Input Only:
		p - a point
	Input & Output:
		os - output stream
	Output Only:
		None
	Returns:
		A modified print statement
	Side Effects:
		Prints x and y coordinates
*/
	friend ostream& operator<<(ostream &os, Point &p);

private:

	void init(int x, int y);
	void copy(const Point &otherPoint);
	void deleteAll();

	int mX;
	int mY;
};

#endif
