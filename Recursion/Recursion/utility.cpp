//Rosswell Tiongco, Assignment 8, 016091762

#include <iostream>
#include "utility.h"

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
	return 0;
}
int Utility::mult(int a, int b)
{
	return 0;
}
void Utility::towers(int n)
{
	//Fill me
}