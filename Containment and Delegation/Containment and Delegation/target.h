/*
Target
	Class Target contains an array of circles based on passed in count of rings
*/
#ifndef TARGET_H
#define TARGET_H

#include <iostream>
#include <vector>
using namespace std;

class Target
{
public:
/*
Method Name:  Target()

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
	Target();

/*
Method Name:  Target(x,y,RingRadius,count)

		Constructor given x, y, radius, and count of rings

	Input Only:
		x - x coordinate
		y - y coordinate
		RingRadius - a ring's radius
		count - number of rings in target
	Input & Output:
		None
	Output Only:
		None
	Returns:
		None
	Side Effects:
		None
*/
	Target(int x, int y, int RingRadius, int count);

/*
Method Name:  Target(center, count)

		Constructor given an existing circle and new ring count

	Input Only:
		center - an existing circle
		count - number of rings
	Input & Output:
		None
	Output Only:
		None
	Returns:
		None
	Side Effects:
		None
*/
	Target(Circle center, int count);

/*
Method Name:  Target(center, radius)

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

/*
Method Name:  otherTarget(otherTarget)

		Constructor given an existing target

	Input Only:
		otherTarget - an existing target
	Input & Output:
		None
	Output Only:
		None
	Returns:
		None
	Side Effects:
		None
*/
	Target(const Target &otherTarget);

/*
Method Name:  operator=(otherTarget)

		Sets target equal to another target

	Input Only:
		otherTarget - an existing target
	Input & Output:
		None
	Output Only:
		None
	Returns:
		point to the object
	Side Effects:
		None
*/
	Target operator=(const Target &otherTarget);

/*
Method Name:  ~Target()

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
	~Target();

/*
Method Name:  getBullsEye()

		Retrieves innermost circle

	Input Only:
		None
	Input & Output:
		None
	Output Only:
		None
	Returns:
		Innermost circle
	Side Effects:
		None
*/
	Circle getBullsEye() const;

/*
Method Name:  getCount()

		Retrieves number of rings in target

	Input Only:
		None
	Input & Output:
		None
	Output Only:
		None
	Returns:
		Number of rings
	Side Effects:
		None
*/
	int getCount() const;

/*
Method Name:  getRingRadius(ring)

		Retrieves the radius of a certain ring

	Input Only:
		ringToFindRadiusOf - index of ring to the radius
	Input & Output:
		None
	Output Only:
		None
	Returns:
		radius of a particular ring
	Side Effects:
		None
*/
	int getRingRadius(int ringToFindRadiusOf) const;

/*
Method Name:  getVectorCircles()

		Retrieves array of circles

	Input Only:
		None
	Input & Output:
		None
	Output Only:
		None
	Returns:
		An array of circles
	Side Effects:
		None
*/
	vector<Circle> getVectorCircles() const;


/*
Method Name:  setRingRadius(ringToGetChanged, newRadius)

		Changes a ring's radius to a new value

	Input Only:
		ringToGetChanged - index of ring to be changed
		newRadius - the new radius of ring
	Input & Output:
		None
	Output Only:
		None
	Returns:
		None
	Side Effects:
		None
*/
	void setRingRadius(int ringToGetChanged, int newRadius);


/*
Method Name:  operator==(otherTarget)

		Checks to see if another target is the same

	Input Only:
		otherTarget - an existing target
	Input & Output:
		None
	Output Only:
		None
	Returns:
		True if the other target is the same
	Side Effects:
		None
*/
	bool operator==(Target &otherTarget);


/*
Method Name:  operator!=(otherTarget)

		Checks if another target is not the same

	Input Only:
		otherTarget - an existing target
	Input & Output:
		None
	Output Only:
		None
	Returns:
		True if the other target is not the same
	Side Effects:
		None
*/
	bool operator!=(Target &otherTarget);

/*
Method Name:  move(deltaX,deltaY)

		Shifts target to a new location

	Input Only:
		deltaX - change in x coordinate
		deltaY - change in y coordinate
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
Method Name:  getDistance(otherTarget)

		Retrieves distance from an existing target

	Input Only:
		otherTarget - an existing target
	Input & Output:
		None
	Output Only:
		None
	Returns:
		The distance from another target
	Side Effects:
		None
*/
	double Target::getDistance(const Target &otherTarget) const;


/*
Method Name:  operator<<(os,t)

		Overloads printing operator

	Input Only:
		t - a target
	Input & Output:
		os - output stream
	Output Only:
		None
	Returns:
		A modified printing message
	Side Effects:
		Prints all rings and their radii
*/
	friend ostream& operator<<(ostream &os, Target &t);

private:
	void init(Circle circle, int count);
	void copy(const Target &otherTarget);
	void deleteAll();
	
	vector<Circle> mVectorCircles;
	int mCount;
	//Circle mArrayCircles[5];

};

#endif
