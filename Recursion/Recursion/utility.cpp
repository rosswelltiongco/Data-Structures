//Rosswell Tiongco, Assignment 8, 016091762

#include <iostream>
#include "utility.h"
#include "stack.h"

Utility::Utility()
{
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
	if (b == 0) return 0;
	else if (b == 1) return a;
	else return a + mult(a, b - 1);
}

static void solve(Stack &from, Stack &to, Stack &temp, int n, int &moveCount);
static void move(Stack &from, Stack &to, int &moveCount);
static int moveCount;

void Utility::towers(int n)
{
	moveCount = 0;
	Stack tower1("Tower 1"), tower2("Tower 2"), tower3("Tower 3");
	cout << "TowersOfHanoi(" << n << ")" << endl;

	for (int ii = n; ii > 0; --ii)
	{
		tower1.push(ii);
	}

	solve(tower1, tower2, tower3, n, moveCount);
	if (moveCount > 0) {
		cout << "Required " << moveCount << " moves" << endl;
	}
}

void solve(Stack &from, Stack &to, Stack &temp, int n, int &moveCount)
{
	if (n == 0) return;
	else if (n == 1) move(from, to, moveCount);
	else
	{
		solve(from, temp, to, n - 1,moveCount);
		move(from, to, moveCount);
		solve(temp, to, from, n - 1,moveCount);
	}
}

void move(Stack &from, Stack &to, int &moveCount)
{
	int ring = from.getTop();
	from.pop();
	to.push(ring);
	moveCount++;
	cout << "Moved " << ring << " from Stack " << from.getName() << " to Stack " << to.getName() << endl;
}