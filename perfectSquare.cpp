#include <bits/stdc++.h>
using namespace std;

bool isPerfectSquare(long double x)
{
	if (x >= 0) {

		long long sr = sqrt(x);
		return (sr * sr == x);
	}

	return false;
}

int main()
{
	long long x = 16;
	if (isPerfectSquare(x))
		cout << x<<" is a Perfect Sqaure";
	else
		cout << x<<" is not a Perfect Sqaure";
	
	x = 7;
	if (isPerfectSquare(x))
		cout <<"\n\n"<<x<<" is a Perfect Sqaure";
	else
		cout <<"\n\n"<<x<<" is not a Perfect Sqaure";
	return 0;
}

