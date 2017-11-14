//Rosswell Tiongco, Assignment 8, 016091762

#include <iostream>
#include "utility.h"
#include "stack.h"

Utility::Utility()
{
	//Does nothing
	//Just a necessary default constructor
}
string Utility::reverse(string s)
{
	if (s.size() <= 1) return s;
	else return (s.back() + reverse(s.substr(0, s.size() - 1)));
}
int Utility::factorial(int n)
{
	if (n <= 1) return n;
	else return n*factorial(n - 1);
}
int Utility::countOccurances(char a, string s)
{
	if (s.size() == 0) return 0;
	else if (s.size() == 1) return (s[0] == a ? 1 : 0);
	else return (s[0] == a ? 1 : 0) + (countOccurances(a, s.substr(1, s.size())));
}
bool Utility::isPalindrome(string s)
{
	if (s.size() <= 1) return true;
	else if (s[0] != s[s.size() - 1]) return false;
	return isPalindrome((s.substr(1, s.size() - 2)));
}
int Utility::gcd(int a, int b)
{
	if (b != 0)
		return gcd(b, a % b);
	else
		return a;
}
int Utility::mult(int a, int b)
{
	//Recursively adding
	if (b == 0) return 0;
	else if (b == 1) return a;
	else return a + mult(a, b - 1);
}


void solve(Stack &from, Stack &to, Stack &temp, int n);
void move(Stack &from, Stack &to);

void Utility::towers(int n)
{

}


void solve(Stack &from, Stack &to, Stack &temp, int n)
{
	if (n == 0)
	{
		return;
	}
	else if (n == 1)
	{
		move(from, to);
		return;
	}
	//Base case 1: , if only one ring, just call move to last ring
}

void move(Stack &from, Stack &to)
{

}

