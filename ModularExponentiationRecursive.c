#include <stdio.h>

int modularExponent(int A, int B, int C)
{
	// Base cases
	if (A == 0)
		return 0;
	if (B == 0)
		return 1;

	// If B is even
	long y;
	if (B % 2 == 0) {
		y = modularExponent(A, B / 2, C);
		y = (y * y) % C;
	}

	// If B is odd
	else {
		y = A % C;
		y = (y * modularExponent(A, B - 1, C)) % C;
	}

	return (int)((y + C) % C);
}

int main()
{
//	int A = 2, B = 5, C = 13;
	int A=2312,B=3434,C=6789;
	printf("Power is %d", modularExponent(A, B, C));
	return 0;
}

